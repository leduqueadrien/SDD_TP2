/* ---------------------------------------------------------------------------- */
/*  main.c                                                                      */
/*           Contient le programme principal et l'inversion d'une pile          */
/* ---------------------------------------------------------------------------- */

#include <stdio.h>
#include "testPile.h"
#include "testFile.h"
#include "pile.h"
#include "file.h"

/* -------------------------------------------------------------- */
/* inverserPile     Inverse la pile passée en paramètre           */
/*                                                                */
/* En entrée :  pile (pile *) : Pile à inverser                   */
/*                                                                */
/* En sortie :  codeErreur (char) booléen : 1 si erreur, 0 sinon  */
/* -------------------------------------------------------------- */
char inverserPile(pile_t * pile) {
	char     codeErreur = 1;
	int      i          = 0;                 /*Compteur*/
	type     valeur     = 0;                 /*Valeur d'entrée/sortie de la pile ou file*/
	int      nbElems    = pile->sommet + 1;  /*Nombre d'elements dans la pile, à inverser*/
	file_t * file       = initFile(nbElems); /*File temporaire permettant d'inverser la pile*/

	/* Inversion de la pile */
	if (file != NULL) {
		/* On vide la pile, on rempli la file */
		for (i=0; i<nbElems; i++) {
			codeErreur = depiler(pile, &valeur);
			codeErreur = enfiler(file, valeur);
		}

		/* On vide la file, on rempli la pile */
		for (i=0; i<nbElems; i++) {
			codeErreur = defiler(file, &valeur);
			codeErreur = empiler(pile, valeur);
		}

		/* La pile est alors inversée */
		printf("La pile est inversée\n");

		libererFile(file);
	}

	return codeErreur;
}


int main(int argc, char const *argv[]) {

	if (argc >= 2 && *argv[1] == '1') {

		if (testUnitairePile() == 1)
			printf("\033[33m     Fonctions pile \033[32mfonctionne\033[00m\n\n");
		else
			printf("\033[33m     Fonctions pile \033[31mne fonctionne pas\033[00m\n\n");


		if (testUnitaireFile())
			printf("\033[33m     Fonctions file \033[32mfonctionne\033[00m\n\n");
		else
			printf("\033[33m     Fonctions file \033[31mne fonctoinne pas\033[00m\n\n");

	} else {

		int n = 10;
		pile_t * pile = initPile(n);

		for (int i=0; i<n; i++)
			empiler(pile, 97+i);

		afficherPile(pile, afficherPileChar);
		if (!inverserPile(pile))
			afficherPile(pile, afficherPileChar);
		else
			printf("Erreur lors de l'inversion de la pile\n");

		libererPile(pile);
	}

	return 0;
}