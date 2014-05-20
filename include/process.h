#ifndef PROCESS_H
#define PROCESS_H

#include "kernel.h"

#define DEBUG_PROCESS

// avant 1ere commutation : lrt (load registre rt)
typedef struct{
	int retour_arriere;
	int esp_0;
	short ss_0;
	short null_0;
	int esp_1;
	short ss_1;
	short null_1;
	int esp_2;
	short ss_2;
	short null_2;
	int cr3;
	int eip; // adresse code
	int eflags;
	int eax;
	int ecx;
	int edx;
	int ebx;
	int esp; // fin du segment pile
	int ebp;
	int esi;
	int edi;
	short es; // idem ds
	short null_es;
	short cs; // segment code
	short null_cs;
	short ss; // segment pile
	short null_ss;
	short ds; // segment data
	short null_ds;
	short fs; // idem ds
	short null_fs;
	short gs; // idem ds
	short null_gs;
	short ldt;
	short null_ldt;
	int fin;
} __attribute__ ((packed)) tss;

typedef struct{
	tss* ptss;
	char state; // I: inactif, R: actif, A: en attente, K: killed
	char* buffer_read;
	subscreen* stdout;
	unsigned int count;
	unsigned int pid;
	void* pile_u;
	void* pile_s;
} task_struct;

extern task_struct processes[5];

extern unsigned short current_process; // c'est un index pour le tableau processes
extern unsigned short focus_process; // idem current_process

/* Définis si le premier schedule est fait.
 * Une fois fait, on peut communter sur 0 normalement, et surtout les interuptions timer commencent
 */
extern unsigned char first_schedule;

/* Lis la table des points d'entrées et initialise les TSS */
void init_processes();

/* schedule passe la main au prochain processus disponible */
void schedule();



#endif
