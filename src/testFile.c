
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testFile.h"
#include "file.h"


int testUnitaireFile() {
    int code = 1;

    if (testInitFile()) {
        printf("\033[32mInitialisation file fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mInitialisation file ne fonctionne pas\033[00m\n\n");
    }

    if (testFileEstVide()) {
        printf("\033[32mFonction file est vide fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction file est vide ne fonctionne pas\033[00m\n\n");
    }

    if (testEnfiler()) {
        printf("\033[32mFonction enfiler fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction enfiler ne fonctionne pas\033[00m\n\n");
    }

    if (testDefiler()) {
        printf("\033[32mFonction defiler fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction defiler ne fonctionne pas\033[00m\n\n");
    }

    return code;
}


int testInitFile() {
    int code = 1;
    file_t * file = initFile(3);

    printf("Initialiser capacite : ");
    if ((*file).capacite == 3) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    printf("Initialiser indexInsertion : ");
    if ((*file).indexInsertion == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    printf("Initialiser indexSuppression : ");
    if ((*file).indexSuppression == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    printf("Initialiser nombre d'element : ");
    if ((*file).nbElements == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    libererFile(file);

    return code;
}


int testFileEstVide() {
    int code = 1;
    file_t * file = initFile(3);
    type v;

    printf("File vide : ");
    if (estVideFile(file)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    enfiler(file, '2');
    printf("File non vide : ");
    if (!estVideFile(file)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    defiler(file, &v);
    printf("File de nouveau vide : ");
    if (estVideFile(file)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    libererFile(file);

    return code;
}


int testEstPleineFile() {
    int code = 1;
    file_t * file = initFile(3);
    type v;

    printf("File vide : ");
    if (!estPleineFile(file)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    enfiler(file, '1');
    printf("File partiellement pleine : ");
    if (!estPleineFile(file)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    enfiler(file, '2');
    enfiler(file, '3');
    printf("File pleine : ");
    if (estPleineFile(file)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    defiler(file, &v);
    defiler(file, &v);
    printf("File plus pleine : ");
    if (!estPleineFile(file)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    enfiler(file, '1');
    enfiler(file, '2');
    printf("File de nouveau pleine : ");
    if (estPleineFile(file)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    return code;
}


int testEnfiler() {
    int code = 1;
    file_t * file = initFile(3);
    char * chaine;
    type v;

    enfiler(file, '1');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Emfilage file vide : ");
    if (!strcmp("1 ", chaine) && (*file).indexSuppression == 0 && (*file).indexInsertion == 1 && (*file).nbElements == 1) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    enfiler(file, '2');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Enfilage jusqu'a file presque pleine : ");
    if (!strcmp("1 2 ", chaine) && (*file).indexSuppression == 0 && (*file).indexInsertion == 2 && (*file).nbElements == 2) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }


    enfiler(file, '3');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Enfile jusqu'a file pleine : ");
    if (!strcmp("1 2 3 ", chaine) && (*file).indexSuppression == 0 && (*file).indexInsertion == 0 && (*file).nbElements == 3) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    enfiler(file, '4');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Redimensionnement sans avoir defiler : ");
    if (!strcmp("1 2 3 4 ", chaine) && (*file).capacite == 5 && (*file).indexSuppression == 0 && (*file).indexInsertion == 4 && (*file).nbElements == 4) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    libererFile(file);

    file = initFile(3);
    enfiler(file, '1');
    enfiler(file, '2');
    enfiler(file, '3');
    defiler(file, &v);
    defiler(file, &v);
    enfiler(file, '4');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Enfiler apres avoir defiler : ");
    if (!strcmp("3 4 ", chaine) && (*file).indexSuppression == 2 && (*file).indexInsertion == 1  && (*file).nbElements == 2) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    enfiler(file, '5');
    enfiler(file, '6');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Redimensionnement apres avoir defiler : ");
    if (!(strcmp("3 4 5 6 ", chaine) && (*file).capacite == 5) && (*file).indexSuppression == 0 && (*file).indexInsertion == 4 && (*file).nbElements == 4) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    libererFile(file);

    return code;
}


int testDefiler() {
    int code = 1;
    file_t * file = initFile(3);
    char * chaine;
    type v = 2;
    
    defiler(file, &v);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Defiler a vide : ");
    if (!strcmp("vide", chaine) && v == 2 && (*file).indexSuppression == 0 && (*file).indexInsertion == 0 && (*file).nbElements == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    enfiler(file, '3');
    defiler(file, &v);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Defilage file 1 element : ");
    if (!strcmp("vide", chaine) && v == '3' && (*file).indexSuppression == 0 && (*file).indexInsertion == 0 && (*file).nbElements == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    enfiler(file, '1');
    enfiler(file, '2');
    enfiler(file, '3');
    defiler(file, &v);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Defilage pile pleine : ");
    if (!strcmp("2 3 ", chaine) && v == '1' && (*file).indexSuppression == 1 && (*file).indexInsertion == 3 && (*file).nbElements == 2) { 
        printf("\033[32mbon\033[00m\n") ;
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    libererFile(file);

    file = initFile(10);
    enfiler(file, 1);
    defiler(file, &v);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Redimensionnement : ");
    if (!strcmp("vide", chaine) && (*file).capacite == 6 && (*file).indexSuppression == 0 && (*file).indexInsertion == 0 && (*file).nbElements == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    libererFile(file);

    return code;
}


char * ecrireFileDansChaine(file_t * file, void (*pfEcrire) (type, char *), int taille) {
    /* On alloc une taille previsionnel de l'affichage de la file */
    char * chaine = malloc(taille * file->capacite * sizeof(int)); /*Pointeur sur la debut de la chaine*/
    char * cour   = chaine;                                      /*Pointeur sur la fin de la chaine */

    int i = 0; /*Compteur*/

    if (!estVideFile(file)) {
        for (i=0; i<file->nbElements; i++) {
            pfEcrire(file->base[(file->indexSuppression + i) % file->capacite], cour);
            cour += strlen(cour);
        }

    } else {
        sprintf(cour, "vide");
    }

    return chaine;
}


void ecrireFileIntDansChaine(int nombre, char * chaine) {
    sprintf(chaine, "%d ", nombre);
}


void ecrireFileCharDansChaine(char caractere, char * chaine) {
    sprintf(chaine, "%c ", caractere);
}
