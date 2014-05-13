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
	process_0.pid = 0;
	process_1.pid = 1;
	process_2.pid = 2;
	process_3.pid = 3;
	process_4.pid = 4;

	process_1.state = 'I';
	process_2.state = 'I';
	process_3.state = 'I';
	process_4.state = 'I';


};
