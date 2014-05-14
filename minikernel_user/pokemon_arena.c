#include "pokemon_arena.h"

int main()
{
	Pokemon bulbizarre, salameche, carapuce ;
	Attaque moveset [4] ;

	moveset[0] = creerAttaque("fouet liane", 1000, plante) ;
	moveset[1] = creerAttaque("fouet liane", 1000, plante) ;
	moveset[2] = creerAttaque("fouet liane", 1000, plante) ;
	moveset[3] = creerAttaque("fouet liane", 1000, plante) ;
	bulbizarre = creerPokemon("BULBIZARRE", 1000, moveset) ;

	moveset[0] = creerAttaque("flammeche", 1000, feu) ;
	moveset[1] = creerAttaque("flammeche", 1000, feu) ;
	moveset[2] = creerAttaque("flammeche", 1000, feu) ;
	moveset[3] = creerAttaque("flammeche", 1000, feu) ;
	salameche  = creerPokemon("SALAMECHE", 1000, moveset) ;

	moveset[0] = creerAttaque("pistolet a o", 1000, eau) ;
	moveset[1] = creerAttaque("pistolet a o", 1000, eau) ;
	moveset[2] = creerAttaque("pistolet a o", 1000, eau) ;
	moveset[3] = creerAttaque("pistolet a o", 1000, eau) ;
	carapuce   = creerPokemon("CARAPUCE", 1000, moveset) ;

	return 0 ;
}

void strncpy(const char* source, char* target, int n)
{
	int i;
	for(i = 0 ; i < n && source[i] != '\0' ; i++)
		target[i] = source[i] ;
	
	target[i] = '\0' ;
}

Pokemon creerPokemon(const char* name, cushort hpmax, const Attaque* mvset)
{
	Pokemon res ;
	int i ;

	strncpy(name, res.nom, 10) ;
	res.atk = rand() ;
	res.def = rand() ;
	res.lvl = 5 ;
	res.hpmax = hpmax ;
	res.hp = hpmax ;
	
	for(i = 0 ; i < 4 ; i++)
	{
		res.moveset[i] = mvset[i] ;
	}

	return res ;
}

void hit(Pokemon* launcher, cushort atq, Pokemon* target)
{
	float effet = effect((launcher->moveset[atq]).type, target->type) ;
	int degats = effet*(launcher->atk + (launcher->moveset[atq]).puiss) / target->def ;

	target->hp -= degats ;

	if(effet == 0)
		printf("Ca n'a aucun effet...\n") ;
	else
		printf("%s lance %s ! %s perd %d HP !\n", launcher->nom, (launcher->moveset[atq]).nom, target->nom, degats) ;

	if(effet > 0 && effet < 1)
		printf("Ce n'est pas très efficace...\n") ;
	else if (effet > 1)
		printf("C'est super efficace !\n") ;
}

void level_up(Pokemon* pkmn)
{
	pkmn->atk += rand() % 4 + pkmn->lvl ;
	pkmn->def += rand() % 4 + pkmn->lvl ;
	pkmn->lvl++ ;
}

Attaque creerAttaque(const char* name, cushort puiss, short a_type)
{
	Attaque res ;

	strncpy(name, res.nom, 12) ;
	res.puiss = puiss ;
	res.type = a_type ;

	return res ;
}

float effect(int type_atk, int type_poke)
{
	float tab[NB_TYPES][NB_TYPES] ;
	tab[feu][feu]		=	0.75	;	tab[feu][eau]		=	0.5		;	tab[feu][plante]	=	2.0		;
	tab[eau][feu]		=	2.0		;	tab[eau][eau]		=	0.75	;	tab[eau][plante]	=	0.5		;
	tab[plante][feu]	=	0.5		;	tab[plante][eau]	=	2		;	tab[plante][plante]	=	0.75	;

	return tab[type_atk][type_poke] ;
}
