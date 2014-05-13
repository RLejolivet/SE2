#include "syscalls.h"
#include "process.h"

void sys_sleep(int time)
{
	current_process->count = 20 * time;
	current_process->state = 'A';
	vgaprintf("appel a sleep successful\n");
}

char sys_read()
{
	// lire un caractère dans current_process->stdin
	vgaprintf("Lecture presque successful (en fait, on a rien lu !\n");
	return 'A';
}

void sys_write(int input)
{
	char affichage = input;
	vgaprintf("%c", affichage);
	vgaprintf("\naffichage successful ! je crois ?\n");
}

void kill_process()
{
	current_process->state = 'K';
	vgaprintf("Et BAM, le process il est mort !\n");
	// lol, à changer hein, il faut appeller schedule
}
