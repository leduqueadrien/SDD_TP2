/* ---------------------------------------------------------------------------- */
/*  main.c                                                                      */
/*           Contient le programme principal et l'inversion d'une pile          */
/* ---------------------------------------------------------------------------- */

#include <stdio.h>
#include "testPile.h"
#include "testFile.h"
#include "pile.h"
#include "file.h"


void InverserPile(pile_t * pile) {
	int      i        = 0;                 /*Compteur*/
	type     valeur   = 0;                 /*Valeur d'entrée/sortie de la pile ou file*/
	int      nbElems  = pile->sommet + 1;  /*Nombre d'elements dans la pile, à inverser*/
	file_t * file     = initFile(nbElems); /*File temporaire permettant d'inverser la pile*/

	/* Inversion de la pile */
	if (file != NULL) {
		/* On vide la pile, on rempli la file */
		for (i=0; i<nbElems; i++) {
			Depiler(pile, &valeur);
			enfiler(file, valeur);
		}

		/* On vide la file, on rempli la pile */
		for (i=0; i<nbElems; i++) {
			defiler(file, &valeur);
			Empiler(pile, valeur);
		}

		/* La pile est alors inversée */
		printf("La pile est inversée\n");

		libererFile(file);
	}
}


int main(int argc, char const *argv[]) {

	if (1 /*argc >= 2 && *argv[1] == '1'*/) {

		if (TestUnitairePile() == 1)
			printf("\033[33m     Fonctions pile \033[32mfonctionne\033[00m\n\n");
		else
			printf("\033[33m     Fonctions pile \033[31mne fonctionne pas\033[00m\n\n");


		if (TestUnitaireFile())
			printf("\033[33m     Fonctions file \033[32mfonctionne\033[00m\n\n");
		else
			printf("\033[33m     Fonctions file \033[31mne fonctoinne pas\033[00m\n\n");

	} else {

		int n = 26;
		pile_t * pile = InitPile(n);

		for (int i=0; i<n; i++)
			Empiler(pile, 97+i);

		AfficherPile(pile, AfficherPileChar);
		InverserPile(pile);
		AfficherPile(pile, AfficherPileChar);

		LibererPile(pile);
	}

	return 0;
}