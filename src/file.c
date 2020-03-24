/* ---------------------------------------------------------------------------- */
/*  file.c                                                                      */
/*                  Contient les fonctions associées à la file                  */
/* ---------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"


file_t * initFile(int capacite) {
    file_t * file = (file_t *)malloc(sizeof(file_t)); /*File créée*/

    if (file != NULL) {
        file->base = (type *)malloc(capacite * sizeof(capacite));

        /* Erreur de memoire */
        if (file->base == NULL) {
            free(file);
            file = NULL;

        /* Initialisation de la file */
        } else {
            file->capacite         = capacite;
            file->nbElements       = 0;
            file->indexSuppression = 0;
            file->indexInsertion   = 0;
        }
    }

    return file;
}


char estVideFile(file_t * file) {
    return (file->nbElements == 0);
}


char estPleineFile(file_t * file) {
    return (file->nbElements == file->capacite);
}


char enfiler(file_t * file, type valeur) {
    char codeErreur = 1; /*Code erreur*/

    /* Si la file n'est pas déjà remplie, on enfile la valeur */
    if (!estPleineFile(file)) {
        file->base[file->indexInsertion] = valeur;
        file->indexInsertion = (file->indexInsertion + 1) % file->capacite; /*Index d'insertion suivante*/

        file->nbElements += 1;
        codeErreur = 0;

    /* Sinon, il faut redimensionner la file */
    } else {
        int nouvCapacite = 1.5 * file->capacite + 1;

        /* Si la redimension est sans erreur, on enfile la valeur */
        if (redimensionnerFile(file, nouvCapacite)) {
            printf("Redimensionnement impossible\n");
            codeErreur = 1;

        } else {
            enfiler(file, valeur);
            codeErreur = 0;
        }

    }
    return codeErreur;
}


char defiler(file_t * file, type * valeur) {
    char codeErreur = 2; /*Code erreur*/

    /* Si la file n'est pas vide, on defile la valeur */
    if (!estVideFile(file)) {
        *valeur = file->base[file->indexSuppression];
        file->indexSuppression = (file->indexSuppression + 1) % file->capacite;
        file->nbElements -= 1;
        codeErreur = 0;

        /* Si la file est peu utilisée, on la redimensionne */
        if (file->nbElements < 0.25 * file->capacite) {
            int nouvCapacite = 0.5 * file->capacite + 1;

            if (redimensionnerFile(file, nouvCapacite)) {
                printf("Redimensionnement impossible\n");
                codeErreur = 2;
            }
        }

    } else {
        printf("File vide\n");
    }

    return codeErreur;
}


char redimensionnerFile(file_t * file, int nouvCapacite) {
    char codeErreur = 1; /*Code Erreur*/
    int  i          = 0; /*Compteur*/

    type * nouvBase = (type *)malloc(nouvCapacite * sizeof(type));
    
    /* Si l'allocation est sans erreur, on copie la file */
    if (nouvBase != NULL) {
        /* On copie l'ancienne file dans la nouvelle (redimensionnée) */
        for (i=0; i<file->nbElements; i++) {
            nouvBase[i] = file->base[(file->indexSuppression + i) % file->capacite];
        }

        /* On libère l'ancienne file et on actualise les données de la nouvelle */
        free(file->base);
        file->base = nouvBase;

        /* On actualise les données de la file */
        file->indexSuppression = 0;
        file->indexInsertion = file->nbElements;
        file->capacite = nouvCapacite;

        codeErreur = 0;
    }
    return codeErreur;
}


void libererFile(file_t * file) {
    free(file->base);
    free(file);
    file = NULL;
}


void afficherFile(file_t * file, void (*pfAfficher) (type)) {
    int i = 0; /*Compteur*/

    if (!estVideFile(file)) {
        for (i=0; i<file->nbElements; i++) {
            pfAfficher(file->base[(file->indexSuppression + i) % file->capacite]);
        }

    } else {
        printf("File vide\n");
    }
}


void afficherFileInt(int nombre) {
    printf("%d\n", nombre);
}


void afficherFileChar(char caractere) {
    printf("%c\n", caractere);
}


void afficherFileChaineChar(char * chaine) {
    printf("%s\n", chaine);
}
