#include "gdt.h"
#include "process.h"

/* Cet structure incompréhensible est un "champ de bits" qui représente une entrée de la GDT */
typedef struct {

	/* Premier word */
	unsigned short limit_15_0;	/* 16 bits, morceau de la limite */
	unsigned short base_addr_15_0;	/* 16 bits, premiere moitier de l'adresse physique */

	/* Deuxième word */
	unsigned char base_addr_23_16;	/* 8 bits, troisième quart de l'adresse physique */

	unsigned char seg_type:4;	/* 4 bits, data=0011 code=1011 tss=1001 */
	unsigned char desc_type:1;	/* 1 bit, tss=0 reste=1 (?) */
	unsigned char dpl:2;		/* 2 bits, 00=system, 11=user */
	unsigned char present:1;	/* 1 bit, le segment est-il là ? */

	unsigned char limit_19_16:4;	/* 4 bits, le reste de la limite */

	unsigned char g_d_b_avl:4;	/* 4 bits, granularity / operator size / zero / custom 
					   tss=0000, reste=0100 */

	unsigned char base_addr_31_24;	/* 8 bits, dernier quart de l'adresse physique */

} __attribute__ ((packed, aligned(8))) gdt_entry;

gdt_entry gdt[26];

typedef struct {
	unsigned short padding; // il parait qu'il en faut ?
	unsigned short limit; // l'offset maximum dans la GDT -> 25 pour nous
	unsigned int base_addr; // l'adresse de la gdt : gdt (c'était super dur)
} __attribute__ ((packed, aligned(4))) gdt_register;

gdt_register gdtr;

/* Arguments : entry -> &gdt[x] pour modifier l'entrée x+1 
 * base : l'adresse physique de la TSS dans la mémoire 
 */
void init_desc_tss(gdt_entry* entry, unsigned int base)
{
	entry->limit_15_0 = 0x67; /* 104 octets */
	entry->base_addr_15_0 = base & 0xFFFF;
	entry->base_addr_23_16 = (base >> 16) & 0xFF;
	
	entry->seg_type = 0x9;
	entry->desc_type = 0;
	entry->dpl = 0x3;
	entry->present = 1;

	entry->limit_19_16 = 0;

	entry->g_d_b_avl = 0;

	entry->base_addr_31_24 = (base >> 24) & 0xFF;
}

/* Arguments : entry -> &gdt[x] pour modifier l'entrée x+1
 * code : 'T' pour texte, 'D' pour data ou 'P' pour pile
 * base : l'adresse de base en fait */
void init_segment_user(gdt_entry* entry, char code, unsigned int base)
{
	entry->limit_15_0 = (code == 'P') ? 0x2000:0x4000;
	entry->base_addr_15_0 = base & 0xFFFF;
	entry->base_addr_23_16 = (base >> 16) & 0xFF;

	entry->seg_type = (code == 'T') ? 0xB: 0x3;
	entry->desc_type = 1;
	entry->dpl = 0x3;
	entry->present = 1;

	entry->limit_19_16 = 0;

	entry->g_d_b_avl = 0x4;

	entry->base_addr_31_24 = (base >> 24) & 0xFF;
}

/* Arguments : entry -> &gdt[x] pour modifier l'entrée x+1
 * code : 'T' pour texte, 'D' pour data ou 'P' pour pile
 */
void init_segment_noyau(gdt_entry* entry, char code)
{
	entry->limit_15_0 = 0xFFFF;
	entry->base_addr_15_0 = 0;
	entry->base_addr_23_16 = 0;

	entry->seg_type = (code == 'T') ? 0xB: 0x3;
	entry->desc_type = 1;
	entry->dpl = 0;
	entry->present = 1;

	entry->limit_19_16 = 0xF;

	entry->g_d_b_avl = 0xC;

	entry->base_addr_31_24 = 0;
}

/* Cette fonction est censée être magique, donc forcément elle va pas être facile à faire */
void init_gdt()
{
	gdt[0] = (gdt_entry) {0};
	gdt[1] = (gdt_entry) {0};

	init_segment_noyau(&gdt[2], 'T');
	init_segment_noyau(&gdt[3], 'D');

	init_desc_tss(&gdt[4], (unsigned int) processes[0].ptss);
	init_desc_tss(&gdt[5], (unsigned int) processes[1].ptss);
	init_desc_tss(&gdt[6], (unsigned int) processes[2].ptss);
	init_desc_tss(&gdt[7], (unsigned int) processes[3].ptss);
	init_desc_tss(&gdt[8], (unsigned int) processes[4].ptss);

	init_segment_user(&gdt[9], 'T', 0xC000);
	init_segment_user(&gdt[10], 'T', 0x10000);
	init_segment_user(&gdt[11], 'T', 0x14000);
	init_segment_user(&gdt[12], 'T', 0x18000);

	init_segment_user(&gdt[13], 'D', 0xC000);
	init_segment_user(&gdt[14], 'D', 0x10000);
	init_segment_user(&gdt[15], 'D', 0x14000);
	init_segment_user(&gdt[16], 'D', 0x18000);

	init_segment_user(&gdt[17], 'P', 0x1E000);
	init_segment_user(&gdt[18], 'P', 0x22000);
	init_segment_user(&gdt[19], 'P', 0x26000);
	init_segment_user(&gdt[20], 'P', 0x2A000);

	init_segment_user(&gdt[21], 'P', 0x1C000);
	init_segment_user(&gdt[22], 'P', 0x20000);
	init_segment_user(&gdt[23], 'P', 0x24000);
	init_segment_user(&gdt[24], 'P', 0x28000);
	init_segment_user(&gdt[24], 'P', 0x2C000);

	gdtr.padding = ~0;
	gdtr.limit = sizeof(gdt) -1;
	gdtr.base_addr = (int) gdt;


#ifdef COMMUTE_ON
	__asm__ __volatile__(
			"lgdt %0		\n\t"
			"ljmp $0x10,$1f		\n\t"
			"1:			\n\t"
			"movw $0x18, %%ax	\n\t"
			"movw %%ax, %%ss	\n\t"
			"movw %%ax, %%ds	\n\t"
			"movw %%ax, %%es	\n\t"
			"movw %%ax, %%fs	\n\t"
			"movw %%ax, %%gs	\n\t"
			:
			: "m" (gdtr.limit)
			: "eax"
			);

#endif

}
