#ifndef PROCESS_H
#define PROCESS_H

#include "kernel.h"

// #define DEBUG_PROCESS

// avant 1ere commutation : lrt (load registre rt)
typedef struct{
	unsigned int retour_arriere;
	unsigned int esp_0;
	unsigned short ss_0;
	unsigned short null_0;
	unsigned int esp_1;
	unsigned short ss_1;
	unsigned short null_1;
	unsigned int esp_2;
	unsigned short ss_2;
	unsigned short null_2;
	unsigned int cr3;
	unsigned int eip; // adresse code
	unsigned int eflags;
	unsigned int eax;
	unsigned int ecx;
	unsigned int edx;
	unsigned int ebx;
	unsigned int esp; // fin du segment pile
	unsigned int ebp;
	unsigned int esi;
	unsigned int edi;
	unsigned short es; // idem ds
	unsigned short null_es;
	unsigned short cs; // segment code
	unsigned short null_cs;
	unsigned short ss; // segment pile
	unsigned short null_ss;
	unsigned short ds; // segment data
	unsigned short null_ds;
	unsigned short fs; // idem ds
	unsigned short null_fs;
	unsigned short gs; // idem ds
	unsigned short null_gs;
	unsigned short ldt;
	unsigned short null_ldt;
	unsigned int fin;
} __attribute__ ((packed)) tss;

typedef struct{
	tss* ptss;
	char state; // I: inactif, R: actif, A: en attente, K: killed, B: blocked
	input_buffer* stdin;
	subscreen* stdout;
	unsigned int count;
	unsigned int pid;
	void* pile_u;
	void* pile_s;
	
	//sélecteur de tss
	int tss_entry;
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

/* Initialise les buffers */
void init_buffers() ;


/* schedule passe la main au prochain processus disponible */
void schedule();



#endif
