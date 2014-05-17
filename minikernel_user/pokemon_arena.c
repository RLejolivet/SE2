#include "pokemon_arena.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	Pokemon bulbizarre, salameche, carapuce, kikoo ;
	Attaque moveset [4] ;
	int resultat ;

	set_seed() ;
	moveset[0] = creerAttaque("fouet liane", 1000, plante) ;
	moveset[1] = creerAttaque("fouet liane", 1000, plante) ;
	moveset[2] = creerAttaque("fouet liane", 1000, plante) ;
	moveset[3] = creerAttaque("fouet liane", 1000, plante) ;
	bulbizarre = creerPokemon("BULBIZARRE", plante, 1000, moveset) ;

	moveset[0] = creerAttaque("flammeche", 1000, feu) ;
	moveset[1] = creerAttaque("flammeche", 1000, feu) ;
	moveset[2] = creerAttaque("flammeche", 1000, feu) ;
	moveset[3] = creerAttaque("flammeche", 1000, feu) ;
	salameche  = creerPokemon("SALAMECHE", feu, 1000, moveset) ;

	moveset[0] = creerAttaque("pistolet a o", 1000, eau) ;
	moveset[1] = creerAttaque("pistolet a o", 1000, eau) ;
	moveset[2] = creerAttaque("pistolet a o", 1000, eau) ;
	moveset[3] = creerAttaque("pistolet a o", 1000, eau) ;
	carapuce   = creerPokemon("CARAPUCE", eau, 1000, moveset) ;

	moveset[0] = creerAttaque("lol", 9999, eau) ;
	moveset[1] = creerAttaque("lol", 9999, eau) ;
	moveset[2] = creerAttaque("lol", 9999, eau) ;
	moveset[3] = creerAttaque("lol", 9999, eau) ;
	kikoo	   = creerPokemon("KIKOO", feu, 9999, moveset) ;

	printf("\n\n\t\tCombat numero 1 !! \n\n") ;
	resultat = combat(&kikoo, &bulbizarre) ;
	if(resultat)
	{
		printf("\n\n\t\tCombat numero 2 !! \n\n") ;
		resultat = combat(&kikoo, &salameche) ;
	}
	else
		printf("perdu !\n") ;
	if(resultat)
	{
		printf("\n\n\t\tCombat numero 3 !! \n\n") ;
		resultat = combat(&kikoo, &carapuce) ;
	}
	else
		printf("perdu !\n") ;
	if(resultat)
		printf("gagne !\n") ;
	else
		printf("perdu !\n") ;

	return 0 ;
}

bool combat(Pokemon* player, Pokemon* adv)
{
	int tour, choix = 1 ;

	tour = player->vit > adv->vit ? 1 : 0 ;

	while(player->hp > 0 && adv->hp > 0)
	{
		print_arena(player, adv) ;
		printf("Quelle attaque ?\n") ;
		scanf("%d", &choix) ;
		--choix ;
		choix %= 4 ;

		if(tour)
		{
			hit(player, choix, adv) ;
			choix = rand() % 4 ;
			hit(adv, choix, player) ;
		}
		else
		{
			choix = rand() % 4 ;
			hit(adv, choix, player) ;
			hit(player, choix, adv) ;
		}

		tour = 1 - tour ;
	}
	if(player->hp <= 0)
	{
		printf("%s est KO.\n", player->nom) ;
		return false ;
	}
	else
	{
		printf("%s est KO.\n", adv->nom) ;
		return true ;
	}
}

char* int_to_type(int type)
{
	switch(type)
	{
		case feu :
			return "feu" ;
		case eau :
			return "eau" ;
		case plante :
			return "plante" ;
		default :
			return "???" ;
	}
}

void print_arena(Pokemon* player, Pokemon* adv)
{
	int i ;
	printf("\n\n\t\t\t\t") ; printf("%s\tN.%d\t%s\t", adv->nom, adv->lvl, int_to_type(adv->type)) ; print_hp(adv) ;

	printf("\n\nVS\n\n") ;

	printf("%s\tN.%d\t%s\t", player->nom, player->lvl, int_to_type(player->type)) ; print_hp(player) ; printf("\tATK: %d, DEF: %d\n", player->atk, player->def) ;

	for(i = 0 ; i < 4 ; i++)
		printf("%d - %s, %s, %d\n", i + 1, player->moveset[i].nom, int_to_type(player->moveset[i].type), player->moveset[i].puiss) ;
}

void print_hp(Pokemon* p)
{
	int dixiemes = 10 * p->hp / p->hpmax, i ;
	printf("[") ;
	for(i = 0 ; i < dixiemes ; i++)
		printf("=") ;
	for(i = 0 ; i < 10 - dixiemes ; i++)
		printf(" ") ;
	printf("]\tPV:%d/%d", p->hp, p->hpmax) ;
}

void mystrncpy(const char* source, char* target, int n)
{
	int i;
	for(i = 0 ; i < n && source[i] != '\0' ; i++)
		target[i] = source[i] ;
	
	target[i] = '\0' ;
}

Pokemon creerPokemon(const char* name, int type, cushort hpmax, const Attaque* mvset)
{
	Pokemon res ;
	int i ;

	mystrncpy(name, res.nom, 10) ;
	res.atk = rand() ;
	res.def = 1 + rand() ;
	res.lvl = 5 ;
	res.hpmax = hpmax ;
	res.hp = hpmax ;
	res.type = type ;
	res.vit = rand() ;
	
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

	target->hp = degats > target->hp ? 0 : target->hp - degats ;

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

	mystrncpy(name, res.nom, 12) ;
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
