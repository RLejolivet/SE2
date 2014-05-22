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
	vgaprintf("Lecture presque successful (en fait, on a rien lu !)\n");
#endif
	
	//beurk, une attente active ! mais ai-je le choix ?
	while(!bouffeur_dinput_lol->unread) ;

	c = bouffeur_dinput_lol->buffer_read[*cursor % BUFFER_SIZE];
	(*cursor)++ ; 

	bouffeur_dinput_lol->unread = *cursor == bouffeur_dinput_lol->pos_ecriture ? false : true ;

	return c ;
}

void sys_write(int input)
{
	char affichage = input;
	// afficher un caractère dans processes[current_process].stdout
	kprintc(processes[current_process].stdout, affichage);
#ifdef DEBUG_SYSCALLS
	vgaprintf("\naffichage successful ! je crois ?\n");
#endif

}

void kill_process()
{
	processes[current_process].state = 'K';

#ifdef DEBUG_SYSCALLS
	vgaprintf("Et BAM, le process il est mort !\n");
#endif

	schedule();

}
