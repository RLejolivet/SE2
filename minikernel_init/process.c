#include "process.h"
//#include "alloc.h"

task_struct processes[5];

unsigned short current_process = 1;
unsigned short focus_process = 1;

void init_processes(){

	/* Je SAIS où est ma table. Du coup j'y vais, comme ça, trop facile */
	int* table_entry_1 = (int*) 0x9000;
	int* table_entry_2 = (int*) 0x9004;
	int* table_entry_3 = (int*) 0x9008;
	int* table_entry_4 = (int*) 0x900c;
	
#ifdef DEBUG_PROCESS
	/* En fait, je savais pas tellement où était ma table :/ */
	vgaprintf("JE SUIS LAAAA : %x\n%x\n%x\n%x (ici)\n",
			*table_entry_1, *table_entry_2, 
			*table_entry_3, *table_entry_4);
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
	processes[0].state = 'A';
	processes[0].pile_s = (void*) 0x22000;


	/* Du coup, on dit que les process existent si leur entrée n'est pas zéro */
	if (*table_entry_1 != 0)
	{
		processes[1].state = 'A';
		processes[1].pile_u = (void*) 0x24000;
		processes[1].pile_s = (void*) 0x26000;
		processes[1].stdout = &sc_p1;
	}

	if (*table_entry_2 != 0)
	{
		processes[2].state = 'A';
		processes[2].pile_u = (void*) 0x28000;
		processes[2].pile_s = (void*) 0x30000;
		processes[2].stdout = &sc_p2;
	}

	if (*table_entry_3 != 0)
	{
		processes[3].state = 'A';
		processes[3].pile_u = (void*) 0x32000;
		processes[3].pile_s = (void*) 0x34000;
		processes[3].stdout = &sc_p3;
	}

	if (*table_entry_4 != 0)
	{
		processes[4].state = 'A';
		processes[4].pile_u = (void*) 0x36000;
		processes[4].pile_s = (void*) 0x38000;
		processes[4].stdout = &sc_p4;
	}


};
