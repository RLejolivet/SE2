#include "syscalls.h"
#include "process.h"

void sys_sleep(int time)
{
	current_process->count = 20 * time;
	current_process->state = 'A';
#ifdef DEBUG_SYSCALLS
	vgaprintf("appel a sleep successful\n");
#endif
}

char sys_read()
{
	// lire un caractère dans current_process->stdin
	
#ifdef DEBUG_SYSCALLS
	vgaprintf("Lecture presque successful (en fait, on a rien lu !\n");
#endif

	return 'A';
}

void sys_write(int input)
{
	char affichage = input;

#ifdef DEBUG_SYSCALLS
	vgaprintf("%c", affichage);
	vgaprintf("\naffichage successful ! je crois ?\n");
#endif

}

void kill_process()
{
	current_process->state = 'K';

#ifdef DEBUG_SYSCALLS
	vgaprintf("Et BAM, le process il est mort !\n");
	// lol, à changer hein, il faut appeller schedule
#endif

}
