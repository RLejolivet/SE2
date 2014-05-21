#include "process.h"
//#include "alloc.h"

task_struct processes[5];
tss tss_table[5];

unsigned short current_process = 0;
unsigned short focus_process = 1;

unsigned char first_schedule = 0;

void init_tss(tss* ptss){
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
	ptss->eflags = 0;
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

void init_processes(){

	/* Je SAIS où est ma table. Du coup j'y vais, comme ça, trop facile */
	int* table_entry_1 = (int*) 0x9000;
	int* exists_entry_1 = (int*) 0x9004;
	int* table_entry_2 = (int*) 0x9008;
	int* exists_entry_2 = (int*) 0x900c;
	int* table_entry_3 = (int*) 0x9010;
	int* exists_entry_3 = (int*) 0x9014;
	int* table_entry_4 = (int*) 0x9018;
	int* exists_entry_4 = (int*) 0x901c;
	
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


	/* Du coup, on dit que les process existent si leur entrée n'est pas zéro */
	if (*exists_entry_1 != 0)
	{
		processes[1].ptss = &tss_table[1];
		processes[1].state = 'R';
		processes[1].pile_u = (void*) 0x24000;
		processes[1].pile_s = (void*) 0x26000;
		processes[1].stdin = &in1;
		processes[1].stdout = &sc_p1;

		processes[1].tss_entry = 0x2B;
		init_tss(processes[1].ptss);
		processes[1].ptss->esp_0 = 0x1FFF;
		processes[1].ptss->ss_0 = 0xB0;
		processes[1].ptss->eip = *table_entry_1;
		processes[1].ptss->esp = 0x1FFF;
		processes[1].ptss->cs = 0x4B;
		processes[1].ptss->ds = 0x6B;
		processes[1].ptss->ss = 0x8B;
		processes[1].ptss->es = processes[1].ptss->ds;
		processes[1].ptss->fs = processes[1].ptss->ds;
		processes[1].ptss->gs = processes[1].ptss->ds;
	}

	if (*exists_entry_2 != 0)
	{
		processes[2].ptss = &tss_table[2];
		processes[2].state = 'R';
		processes[2].pile_u = (void*) 0x28000;
		processes[2].pile_s = (void*) 0x30000;
		processes[2].stdin = &in2;
		processes[2].stdout = &sc_p2;

		processes[2].tss_entry = 0x33;
		init_tss(processes[1].ptss);
		processes[2].ptss->esp_0 = 0x1FFF;
		processes[2].ptss->ss_0 = 0xB8;
		processes[2].ptss->eip = *table_entry_1;
		processes[2].ptss->esp = 0x1FFF;
		processes[2].ptss->cs = 0x53;
		processes[2].ptss->ds = 0x73;
		processes[2].ptss->ss = 0x93;
		processes[2].ptss->es = processes[2].ptss->ds;
		processes[2].ptss->fs = processes[2].ptss->ds;
		processes[2].ptss->gs = processes[2].ptss->ds;
	}

	if (*exists_entry_3 != 0)
	{
		processes[3].ptss = &tss_table[3];
		processes[3].state = 'R';
		processes[3].pile_u = (void*) 0x32000;
		processes[3].pile_s = (void*) 0x34000;
		processes[3].stdin = &in3;
		processes[3].stdout = &sc_p3;

		processes[3].tss_entry = 0x3B;
		init_tss(processes[1].ptss);
		processes[3].ptss->esp_0 = 0x1FFF;
		processes[3].ptss->ss_0 = 0xC0;
		processes[3].ptss->eip = *table_entry_1;
		processes[3].ptss->esp = 0x1FFF;
		processes[3].ptss->cs = 0x5B;
		processes[3].ptss->ds = 0x7B;
		processes[3].ptss->ss = 0x9B;
		processes[3].ptss->es = processes[3].ptss->ds;
		processes[3].ptss->fs = processes[3].ptss->ds;
		processes[3].ptss->gs = processes[3].ptss->ds;
	}

	if (*exists_entry_4 != 0)
	{
		processes[4].ptss = &tss_table[4];
		processes[4].state = 'R';
		processes[4].pile_u = (void*) 0x36000;
		processes[4].pile_s = (void*) 0x38000;
		processes[4].stdin = &in4;
		processes[4].stdout = &sc_p4;
		
		processes[4].tss_entry = 0x43;
		init_tss(processes[1].ptss);
		processes[4].ptss->esp_0 = 0x1FFF;
		processes[4].ptss->ss_0 = 0xC8;
		processes[4].ptss->eip = *table_entry_1;
		processes[4].ptss->esp = 0x1FFF;
		processes[4].ptss->cs = 0x63;
		processes[4].ptss->ds = 0x83;
		processes[4].ptss->ss = 0xA3;
		processes[4].ptss->es = processes[4].ptss->ds;
		processes[4].ptss->fs = processes[4].ptss->ds;
		processes[4].ptss->gs = processes[4].ptss->ds;
	}


}

void commute_to(int index_processes)
{
	/* Ici, on fait la commutation sur un processus, sauf s'il est déjà actif */
	if (current_process == index_processes) return;

	current_process = index_processes;
	// a rajouter : sauvegarde des piles, jmp de TSS et un SLI !!!
	/*
	__asm__ __volatile__(
		"sli\n\t"
		"jmp %0"
		:
		: "m" (processes[index_processes].tss_entry)
	);
	 */

#ifdef DEBUG_PROCESS
	//kprintf(processes[current_process].stdout, "J'ai le CPU !\n");
#endif
}

void schedule()
{
	int i;
	int suivant;

	first_schedule = 1;

	for (i=1; i<=4; i++)
	{
		/* On ne compte pas le processus 0 comme faisant partit de la boucle des processus */
		suivant = ((current_process + i)%4 == 0) ? 4 : (current_process + i)%4;
		if(processes[suivant].state == 'R'){
			commute_to(suivant);
			return;
		}
	}

	/* Si on arrive ici, c'est qu'aucun des processus utilisateurs n'est dispo. On va sur 0 */
	commute_to(0);
}
