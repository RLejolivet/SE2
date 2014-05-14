#ifndef POKEMON_ARENA_H
#define POKEMON_ARENA_H

#define NB_TYPES 3

enum type {feu, eau, plante} ;
typedef const unsigned short cushort ;
typedef struct Pokemon Pokemon ;
typedef struct Attaque Attaque ;

struct Pokemon
{
	char nom[11] ;
	unsigned short atk ;
	unsigned short def ;
	unsigned short lvl ;
	unsigned short hp ;
	unsigned short hpmax ;
	struct Attaque moveset[4] ;
} ;
Pokemon creerPokemon(const char* name, cushort hpmax, const Attaque* mvset) ;
void hit(Pokemon* launcher, cushort atq, Pokemon* target) ; 
void level_up(Pokemon* pkmn) ;

struct Attaque
{
	char nom[13] ;
	unsigned short puiss ;
	int type ;

} ;
Attaque creerAttaque(const char* name, cushort puiss, short a_type) ;


void strncpy(const char* source, char* target, int n) ;
float effect(int type_atk, int type_poke) ;
#endif
