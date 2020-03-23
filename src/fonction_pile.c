
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fonction_pile.h"


pile_t * InitPile(int capacite) {

    /* Allocation de la pile */
    pile_t * pile = (pile_t*) malloc(sizeof(pile_t));
    if (pile != NULL) { 
        (*pile).base = NULL;
        /* Allocation de la base de la pile */
        (*pile).base = (type*)malloc(capacite*sizeof(type));
        
        if ((*pile).base != NULL) {
            (*pile).capacite = capacite;
            (*pile).sommet = -1;
        } else {    /* Si l'allocation c'est pas faite, on libère la pile */
            free(pile);     
            pile = NULL;
        }
    }
    return pile;
}


void LibererPile (pile_t * pile) {
    /* On libère la base */
    free((*pile).base);
    /* On libère la pile */
    free(pile);
}


int EstVidePile (pile_t * pile) {
    return (*pile).sommet == -1;
}


int EstPleinePile (pile_t * pile) {
    return (*pile).capacite == (*pile).sommet + 1;
}


int Empiler(pile_t * pile, type v) {
    int codeErreur = 1;

    /* Si la pile est pleine, on redimensionne, sinon, on empile */
    if (EstPleinePile(pile)) {

        int nvCapacite = 1.5*(*pile).capacite + 1;
        /* + 1 pour le cas ou la capacite vaut 1 */
        codeErreur = RedimensionerPile(pile, nvCapacite);

        /* Si le redimensionnement a fonctionne, on empile la valeur */
        if (codeErreur == 0)
            codeErreur = Empiler(pile, v);

    } else {
        codeErreur = 0;
        (*pile).sommet ++;
        (*pile).base [(*pile).sommet] = v;
    }

    return codeErreur;
}


int Depiler (pile_t * pile, type * v) {
    int codeErreur = 1;
    
    /* Si la pile est non vide, on depile */
    if (!EstVidePile(pile)) {
        codeErreur = 0;
        *v = (*pile).base [(*pile).sommet];
        (*pile).sommet --;
    }

    /* Si la pile est tres peu utilise, on diminue la taille */
    if ((*pile).sommet < (int)0.25*(*pile).capacite) {
        int nvCapacite = 0.5*(*pile).capacite;
        RedimensionerPile(pile, nvCapacite);
    }
    return codeErreur;
}


int RedimensionerPile (pile_t * pile, int nvCapacite) {
    int codeErreur = 1;

    /* On realloc la base */
    type * nvBase = realloc((*pile).base, nvCapacite*sizeof(type));
    if (nvBase != NULL) {
        codeErreur = 0;
        /* Si l'allocation c'est bien faite, on modifie la base et la capacite */
        (*pile).base = nvBase;
        (*pile).capacite = nvCapacite;
    }
    return codeErreur;
}


void AfficherPile (pile_t * pile, void (*pfAfficher) (type)) {

    printf("Pile : capacite=%d\n", (*pile).capacite);
    printf("       ");
    
    if(!EstVidePile(pile)) {
        /* On affiche chaque element un par un en appellant la fonction d'aafichage */
        for (int i=0; i <=(*pile).sommet; i++)
            (*pfAfficher) ( (*pile).base[i] );
    } else {
        printf("vide");
    }

    printf("\n");
}


void AfficherPileInt (int nombre) {
    printf("%d ", nombre);
}


void AfficherPileChar (char caractere) {
    printf("%c ", caractere);
}


void AfficherPileChaineCarac (char * chaine) {
    printf("%s ", chaine);
}


char * AfficherPileDansChaine (pile_t * pile, void (*pfAfficher) (type, char *), int taille) {
    /* On alloc une taille previsionnel de l'affichage de la pile */
    char * chaine = malloc( taille*(*pile).capacite*sizeof(char) ); /* pointeur sur la debut de la chaine */
    char * cour = chaine;   /* pointeur que la fin de la chaine */

    if (!EstVidePile(pile)) {

        int n = (*pile).sommet + 1;
        for (int i=0; i<n; i++) {
            /* On ajoute l'affichage a la fin de la chaine */
            (*pfAfficher) ((*pile).base[i], cour);
            /* On decale le pointeur a la fin de la chaine */
            cour += strlen(cour);
        }
    } else {
        strcpy(cour, "vide");
    }

    return chaine;
}


void AfficherPileIntDansChaine(int nombre, char * chaine) {
    sprintf(chaine, "%d ", nombre);
}


void AfficherPileCharDansChaine(char carac, char * chaine) {
    sprintf(chaine, "%c ", carac);
}