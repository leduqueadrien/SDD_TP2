
#include <stdio.h>
#include "testUnitairePile.h"
#include "testUnitaireFile.h"
#include "fonction_pile.h"
#include "fonction_file.h"



void InverserPile(pile_t * pile) {
	int  i        = 0;                 /*Compteur*/
	type valeur   = 0;                 /*Valeur d'entrée/sortie de la pile ou file*/
	int  nbElems  = pile->sommet + 1;  /*Nombre d'elements dans la pile, à inverser*/
	file_t * file = initFile(nbElems); /*File temporaire permettant d'inverser la pile*/

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
    if (argc >= 2 && *argv[1] == '1') {
        if (TestUnitairePile() == 1)
            printf("Fonctions pile fonctionne\n\n");
        else
            printf("Fonctions pile ne fonctionne pas\n\n");


        if (TestUnitaireFile())
            printf("Fonctions file fonctionne\n\n");
        else
            printf("Fonctions file ne fonctoinne pas\n\n");
    } else {

        int n = 26;
        pile_t * pile = InitPile(n);
        for (int i=0; i<n; i++)
            Empiler(pile, 97+i);
        
        AfficherPile(pile, &AfficherPileChar);
        InverserPile(pile);
        AfficherPile(pile, &AfficherPileChar);

        LibererPile(pile);
    }

    return 0;
}