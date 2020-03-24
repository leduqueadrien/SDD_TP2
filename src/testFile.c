
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


int testEnfiler() {
    int code = 1;
    file_t * file = initFile(3);
    char * chaine;
    type a;

    enfiler(file, '1');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Emfile 1 element : ");
    if (!strcmp("1 ", chaine)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    enfiler(file, '2');
    enfiler(file, '3');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Emfile jusqu'a ce que le file soit pleine : ");
    if (!strcmp("1 2 3 ", chaine)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    enfiler(file, '4');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Redimensionnement sans avoir defiler : ");
    if (!strcmp("1 2 3 4 ", chaine) && (*file).capacite == 5) {
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
    defiler(file, &a);
    defiler(file, &a);
    enfiler(file, '4');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Enfiler apres avoir defiler : ");
    if (!strcmp("3 4 ", chaine)) {
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
    if (!(strcmp("3 4 5 6 ", chaine) && (*file).capacite == 5)) {
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
    type a = 2;
    
    defiler(file, &a);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Defiler a vide : ");
    if (!strcmp("vide", chaine) && a == 2 && (*file).indexSuppression == 0 && (*file).indexInsertion == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    enfiler(file, '3');
    defiler(file, &a);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Defilage : ");
    if (!strcmp("vide", chaine) && a == '3') {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    enfiler(file, '1');
    enfiler(file, '2');
    enfiler(file, '3');
    defiler(file, &a);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Defilage pile pleine : ");
    if (!strcmp("2 3 ", chaine) && a == '1') { 
        printf("\033[32mbon\033[00m\n") ;
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    libererFile(file);

    file = initFile(10);
    enfiler(file, 1);
    defiler(file, &a);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Redimensionnement : ");
    if (!strcmp("vide", chaine) && (*file).capacite == 6) {
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
