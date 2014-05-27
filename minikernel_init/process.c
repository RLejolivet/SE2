#include "process.h"
#include "gdt.h"
//#include "alloc.h"

task_struct processes[5];
tss tss_table[5];

unsigned short current_process = 0;
unsigned short focus_process = 1;

unsigned char first_schedule = 0;

void init_tss(tss* ptss)
{
	ptss->retour_arriere = 0;
	// on n'initialise pas esp_0 vu que j'ai la flemme
	// on n'initialise pas ss_0 vu qu'on le connais pas ici
	ptss->null_0 = 0;
	ptss->esp_1 = 0;
	ptss->ss_1 = 0;
	ptss->null_1 = 0;
	ptss->esp_2 = 0;
	ptss->ss_2 = 0;
	ptss->null_2 = 0;
	ptss->cr3 = 0;
	// on n'initialise pas eip vu qu'on le connais pas ici
	ptss->eax = 0;
	ptss->ecx = 0;
	ptss->edx = 0;
	ptss->ebx = 0;
	// on n'initialise pas esp vu que j'ai la flemme
	ptss->ebp = 0;
	ptss->esi = 0;
	ptss->edi = 0;
	// on n'initialise pas es vu qu'on le connais pas ici
	ptss->null_es = 0;
	// on n'initialise pas cs vu qu'on le connais pas ici
	ptss->null_cs = 0;
	// on n'initialise pas ss vu qu'on le connais pas ici
	ptss->null_ss = 0;
	// on n'initialise pas ds vu qu'on le connais pas ici
	ptss->null_ds = 0;
	// on n'initialise pas fs vu qu'on le connais pas ici
	ptss->null_fs = 0;
	// on n'initialise pas gs vu qu'on le connais pas ici
	ptss->null_gs = 0;
	ptss->ldt = 0;
	ptss->null_ldt = 0;
	ptss->fin = 0;
}

void init_processes()
{

	/* Je SAIS où est ma table. Du coup j'y vais, comme ça, trop facile */
	int* table_entry_1 = (int*) 0xB000;
	int* exists_entry_1 = (int*) 0xB004;
	int* table_entry_2 = (int*) 0xB008;
	int* exists_entry_2 = (int*) 0xB00c;
	int* table_entry_3 = (int*) 0xB010;
	int* exists_entry_3 = (int*) 0xB014;
	int* table_entry_4 = (int*) 0xB018;
	int* exists_entry_4 = (int*) 0xB01c;

	int eflags;
	
#ifdef DEBUG_PROCESS
	/* En fait, je savais pas tellement où était ma table :/ */
	vgaprintf("JE SUIS LAAAA : %x %x %x %x (ici)\nAdresses : %x %x %x %x\n",
			*table_entry_1, *table_entry_2, 
			*table_entry_3, *table_entry_4,
			table_entry_1, table_entry_2, table_entry_3, table_entry_4);
#endif


	/* Les pid c'est pas trop dur */
	processes[0].pid = 0;
	processes[1].pid = 1;
	processes[2].pid = 2;
	processes[3].pid = 3;
	processes[4].pid = 4;

	/* Au début, tous les processus n'existent pas. On va vérifier s'ils existent après */
	processes[1].state = 'I';
	processes[2].state = 'I';
	processes[3].state = 'I';
	processes[4].state = 'I';

	/* Init du processus 0, qui est toujours là */
	processes[0].ptss = tss_table;
	processes[0].tss_entry = 0x23;
	processes[0].state = 'R';
	processes[0].pile_s = (void*) 0x22000;


	asm volatile("pushf\n\t"
			"popl %%eax\n\t"
			"movl %%eax, %0\n\t"
			: "=m" (eflags)
		);

	/* Du coup, on dit que les process existent si leur entrée n'est pas zéro */
	if (*exists_entry_1 != 0)
	{
		processes[1].ptss = &tss_table[1];
		processes[1].state = 'R';
		processes[1].pile_u = (void*) 0x24000;
		processes[1].pile_s = (void*) 0x26000;
		processes[1].stdin = &in1;
		processes[1].stdout = &sc_p1;

		processes[1].tss_entry = 0x28;
		init_tss(processes[1].ptss);
		processes[1].ptss->esp_0 = 0x1FF0;
		processes[1].ptss->ss_0 = 0xB0;
		processes[1].ptss->eip = *table_entry_1;
		processes[1].ptss->esp = 0x1FF0;
		processes[1].ptss->ebp = processes[1].ptss->esp;
		processes[1].ptss->cs = 0x48;
		processes[1].ptss->ds = 0x68;
		processes[1].ptss->ss = 0x88;
		processes[1].ptss->es = processes[1].ptss->ds;
		processes[1].ptss->fs = processes[1].ptss->ds;
		processes[1].ptss->gs = processes[1].ptss->ds;
		processes[1].ptss->eflags = eflags;

	}

	if (*exists_entry_2 != 0)
	{
		processes[2].ptss = &tss_table[2];
		processes[2].state = 'R';
		processes[2].pile_u = (void*) 0x28000;
		processes[2].pile_s = (void*) 0x30000;
		processes[2].stdin = &in2;
		processes[2].stdout = &sc_p2;

		processes[2].tss_entry = 0x30;
		init_tss(processes[1].ptss);
		processes[2].ptss->esp_0 = 0x1FF0;
		processes[2].ptss->ss_0 = 0xB8;
		processes[2].ptss->eip = *table_entry_2;
		processes[2].ptss->esp = 0x1FF0;
		processes[2].ptss->ebp = processes[2].ptss->esp;
		processes[2].ptss->cs = 0x50;
		processes[2].ptss->ds = 0x70;
		processes[2].ptss->ss = 0x90;
		processes[2].ptss->es = processes[2].ptss->ds;
		processes[2].ptss->fs = processes[2].ptss->ds;
		processes[2].ptss->gs = processes[2].ptss->ds;
		processes[2].ptss->eflags = eflags;
	}

	if (*exists_entry_3 != 0)
	{
		processes[3].ptss = &tss_table[3];
		processes[3].state = 'R';
		processes[3].pile_u = (void*) 0x32000;
		processes[3].pile_s = (void*) 0x34000;
		processes[3].stdin = &in3;
		processes[3].stdout = &sc_p3;

		processes[3].tss_entry = 0x38;
		init_tss(processes[1].ptss);
		processes[3].ptss->esp_0 = 0x1FF0;
		processes[3].ptss->ss_0 = 0xC0;
		processes[3].ptss->eip = *table_entry_3;
		processes[3].ptss->esp = 0x1FF0;
		processes[3].ptss->ebp = processes[3].ptss->esp;
		processes[3].ptss->cs = 0x58;
		processes[3].ptss->ds = 0x78;
		processes[3].ptss->ss = 0x98;
		processes[3].ptss->es = processes[3].ptss->ds;
		processes[3].ptss->fs = processes[3].ptss->ds;
		processes[3].ptss->gs = processes[3].ptss->ds;
		processes[3].ptss->eflags = eflags;
	}

	if (*exists_entry_4 != 0)
	{
		processes[4].ptss = &tss_table[4];
		processes[4].state = 'R';
		processes[4].pile_u = (void*) 0x36000;
		processes[4].pile_s = (void*) 0x38000;
		processes[4].stdin = &in4;
		processes[4].stdout = &sc_p4;
		
		processes[4].tss_entry = 0x40;
		init_tss(processes[1].ptss);
		processes[4].ptss->esp_0 = 0x1FF0;
		processes[4].ptss->ss_0 = 0xC8;
		processes[4].ptss->eip = *table_entry_4;
		processes[4].ptss->esp = 0x1FF0;
		processes[4].ptss->ebp = processes[4].ptss->esp;
		processes[4].ptss->cs = 0x60;
		processes[4].ptss->ds = 0x80;
		processes[4].ptss->ss = 0xA0;
		processes[4].ptss->es = processes[4].ptss->ds;
		processes[4].ptss->fs = processes[4].ptss->ds;
		processes[4].ptss->gs = processes[4].ptss->ds;
		processes[4].ptss->eflags = eflags;
	}

	init_gdt();
	init_buffers() ;
}

void init_buffers()
{
	int i = 0 , p = 0 ;

	for (p = 0 ; p < 5 ; p++)
	{
		for(i = 0 ; i < BUFFER_SIZE ; i++)
		{
			processes[p].stdin->buffer_read[i] = '\0' ;
		}
		processes[p].stdin->pos_lecture = 0 ;
		processes[p].stdin->pos_ecriture = 0 ;
		processes[p].stdin->unread = false ;
	}
}


#ifdef DEBUG_COMMUTE
void dump_tss()
{
	vgaprintf("%x  ", processes[current_process].ptss->retour_arriere);
	vgaprintf("%x  ", processes[current_process].ptss->esp_0);
	vgaprintf("%x  ", processes[current_process].ptss->ss_0);
	vgaprintf("%x  ", processes[current_process].ptss->esp_1);
	vgaprintf("%x\n", processes[current_process].ptss->ss_1);
	vgaprintf("%x  ", processes[current_process].ptss->esp_2);
	vgaprintf("%x  ", processes[current_process].ptss->ss_2);
	vgaprintf("%x  ", processes[current_process].ptss->cr3);
	vgaprintf("%x  ", processes[current_process].ptss->eip);
	vgaprintf("%x\n", processes[current_process].ptss->eflags);
	vgaprintf("%x  ", processes[current_process].ptss->eax);
	vgaprintf("%x  ", processes[current_process].ptss->ecx);
	vgaprintf("%x  ", processes[current_process].ptss->edx);
	vgaprintf("%x  ", processes[current_process].ptss->ebx);
	vgaprintf("%x\n", processes[current_process].ptss->esp);
	vgaprintf("%x  ", processes[current_process].ptss->ebp);
	vgaprintf("%x  ", processes[current_process].ptss->esi);
	vgaprintf("%x  ", processes[current_process].ptss->edi);
	vgaprintf("%x  ", processes[current_process].ptss->es);
	vgaprintf("%x\n", processes[current_process].ptss->cs);
	vgaprintf("%x  ", processes[current_process].ptss->ss);
	vgaprintf("%x  ", processes[current_process].ptss->ds);
	vgaprintf("%x  ", processes[current_process].ptss->fs);
	vgaprintf("%x  ", processes[current_process].ptss->gs);
	vgaprintf("%x  ", processes[current_process].ptss->ldt);
	vgaprintf("%x\n", processes[current_process].ptss->null_ldt);
}
#endif

void commute_to(int index_processes)
{
	/* Ici, on fait la commutation sur un processus, sauf s'il est déjà actif */
	if (current_process == index_processes) return;

	current_process = index_processes;
#ifdef DEBUG_COMMUTE
	dump_tss();
#endif

#ifdef COMMUTE_ON
	//kprintf(processes[current_process].stdout,"J'ai envie de commuter sur %d\n", index_processes);
	if (first_schedule == 0)
	{
		first_schedule = 1;
	}
	else
	{
		__asm__ __volatile__("sti");
	}
	switch(index_processes)
	{
	case 0:
		__asm__ __volatile__(
			"ljmp $0x0020,$0x0"
		);
		break;
	case 1:
		__asm__ __volatile__(
			"ljmp $0x0028,$0x0"
		);
		break;
	case 2:
		__asm__ __volatile__(
			"ljmp $0x0030,$0x0"
		);
		break;
	case 3:
		__asm__ __volatile__(
			"ljmp $0x0038,$0x0"
		);
		break;
	case 4:
		__asm__ __volatile__(
			"ljmp $0x0040,$0x0"
		);
		break;
	}
#endif

#ifdef DEBUG_PROCESS
	//kprintf(processes[current_process].stdout, "J'ai le CPU !\n");
#endif
}

void schedule()
{
	int i;
	int suivant;

#ifdef DEBUG_SYSCALLS
	//kprintf(&sc_p4, "Appel de schedule\n");
#endif

	for (i=1; i<=4; i++)
	{
		/* On ne compte pas le processus 0 comme faisant partit de la boucle des processus */
		suivant = ((current_process + i)%4 == 0) ? 4 : (current_process + i)%4;

		if(processes[suivant].state == 'R')
		{
			commute_to(suivant);
			return;
		}
	}

	/* Si on arrive ici, c'est qu'aucun des processus utilisateurs n'est dispo. On va sur 0 */
	commute_to(0);
}
