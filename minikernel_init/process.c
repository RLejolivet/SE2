#include "process.h"
//#include "alloc.h"

task_struct process_0;
task_struct process_1;
task_struct process_2;
task_struct process_3;
task_struct process_4;

task_struct* current_process = &process_1;
task_struct* focus_process = &process_1;

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

	/*
	process_0.pile_s = pile_s_0;
	process_1.pile_u = pile_u_1;
	process_1.pile_s = pile_s_1;
	process_2.pile_u = pile_u_2;
	process_2.pile_s = pile_s_2;
	process_3.pile_u = pile_u_3;
	process_3.pile_s = pile_s_3;
	process_4.pile_u = pile_u_4;
	process_4.pile_s = pile_s_4;
	*/

	/* Les pid c'est pas trop dur */
	process_0.pid = 0;
	process_1.pid = 1;
	process_2.pid = 2;
	process_3.pid = 3;
	process_4.pid = 4;

	/* Au début, tous les processus n'existent pas. On va vérifier s'ils existent après */
	process_1.state = 'I';
	process_2.state = 'I';
	process_3.state = 'I';
	process_4.state = 'I';

	/* Init du processus 0, qui est toujours là */
	process_0.state = 'A';
	process_0.pile_s = 0x22000;


	/* Du coup, on dit que les process existent si leur entrée n'est pas zéro */


};
