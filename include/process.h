#ifndef PROCESS_H
#define PROCESS_H

// #define DEBUG_PROCESS

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
	int eip;
	int eflags;
	int eax;
	int ecx;
	int edx;
	int ebx;
	int esp;
	int ebp;
	int esi;
	int edi;
	short es;
	short null_es;
	short cs;
	short null_cs;
	short ss;
	short null_ss;
	short ds;
	short null_ds;
	short fs;
	short null_fs;
	short gs;
	short null_gs;
	short ldt;
	short null_ldt;
	int fin;
} __attribute__ ((packed)) tss;

typedef struct{
	tss* ptss;
	char state; // I: inactif, R: actif, A: en attente, K: killed
	char* buffer_read;
	// il manque le subscreen pour les print
	unsigned int count;
	unsigned int pid;
	void* pile_u;
	void* pile_s;
} task_struct;

extern task_struct processes[5];

extern unsigned short current_process; // c'est un index pour le tableau processes
extern unsigned short focus_process; // idem current_process

/* Lis la table des points d'entrées et initialise les TSS */
void init_processes();



#endif
