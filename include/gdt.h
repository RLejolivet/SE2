#ifndef GDT_H
#define GDT_H

/* init_gdt est une fonction magique qui fait tout :
 * Crétation et initialisation de la GDT
 * Changement du registre de la GDT dans le processeur 
 *
 * Une fois appellée, on a plus rien à faire, ça fonctionne */
void init_gdt();

#endif
