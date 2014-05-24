
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

} __attribute__ ((packed)) gdt_entry;

gdt_entry gdt[26];

/* Cette fonction est censée être magique, donc forcément elle va pas être facile à faire */
void init_gdt()
{

}
