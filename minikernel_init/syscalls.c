#include "syscalls.h"
#include "process.h"
#include "kernel.h"

void sys_sleep(int time)
{
	processes[current_process].count = 20 * time;
	processes[current_process].state = 'A';
	schedule();
#ifdef DEBUG_SYSCALLS
	vgaprintf("appel a sleep successful\n");
#endif
}

// lire un caractère dans processes[current_process].stdin
char sys_read()
{
	char c ;
	input_buffer* bouffeur_dinput_lol = processes[current_process].stdin ;
	int* cursor = &(bouffeur_dinput_lol->pos_lecture) ;
#ifdef DEBUG_SYSCALLS
	bouffeur_dinput_lol = &in3 ;
#endif
	
	if(!bouffeur_dinput_lol->unread)
	{
		processes[current_process].state = 'B' ;
		schedule() ;
	}

	c = bouffeur_dinput_lol->buffer_read[*cursor % BUFFER_SIZE];
	(*cursor)++ ; 

	bouffeur_dinput_lol->unread = (*cursor == bouffeur_dinput_lol->pos_ecriture) ? false : true ;

	return c ;
}

void sys_write(int input)
{
	char affichage = input;
#ifdef DEBUG_SYSCALLS
	//vgaprintf("\naffichage successful ! je crois ?\n");
#endif
	// afficher un caractère dans processes[current_process].stdout
	kprintc(processes[current_process].stdout, affichage);

}

void kill_process()
{
	processes[current_process].state = 'K';

//#ifdef DEBUG_SYSCALLS
	kprintf(processes[current_process].stdout,"\nProcessus %d mort\n", current_process);
//#endif

	schedule();

}
