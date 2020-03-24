
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testPile.h"
#include "pile.h"


int testUnitairePile() {
    int code = 1;

    if (testAfficherPile() == 1) {
        printf("\033[32mFonction afficher pile fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction afficher pile ne fonctionne pas\033[00m\n\n");
    }

    if (testInitPile() == 1) {
        printf("\033[32mFonction init pile fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction init pile ne fonctionne pas\033[00m\n\n");
    }

    if (testEstVidePile() == 1) {
        printf("\033[32mFonction pile est vide fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction pile est non vide ne fonctionne pas\033[00m\n\n");
    }

    if (testEstPleinePile() == 1) {
        printf("\033[32mFonction pile est pleine fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction pile est pleine ne fonctionne pas\033[00m\n\n");
    }

    if (testEmpiler() == 1) {
        printf("\033[32mFonction empiler fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction empiler ne fonctionne pas\033[00m\n\n");
    }

    if (testDepiler() == 1) {
        printf("\033[32mFonction depiler fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction depiler ne fonctionne pas\033[00m\n\n");
    }

    return code;
}


int testInitPile() {
    int code = 1;
    pile_t * pile = initPile(3);

    printf("Initialiser capacite : ");
    if ((*pile).capacite == 3) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 1;
        printf("\033[31mfaux\033[00m\n");
    }

    printf("Initialiser sommet : ");
    if ((*pile).sommet == -1) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 1;
        printf("\033[31mfaux\033[00m\n");
    }

    libererPile(pile);

    return code;
}


int testEstVidePile() {
    int code = 1;
    pile_t * pile = initPile(3);
    char v;

    printf("Pile est vide : ");
    if (estVidePile(pile) == 1) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    
    empiler(pile, '1');
    printf("Pile est non vide : ");
    if (estVidePile(pile) == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    depiler(pile,&v);
    printf("Pile est de nouveau vide : ");
    if (estVidePile(pile)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    empiler(pile, '1');
    empiler(pile, '2');
    empiler(pile, '3');
    printf("Pile plein : ");
    if (!estVidePile(pile)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    libererPile(pile);

    return code;
}


int testEstPleinePile() {
    int code = 1;
    pile_t * pile = initPile(2);
    char v;

    printf("Pile est vide : ");
    if (estPleinePile(pile) == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m");
    }

    empiler(pile, '1');
    printf("Pile est partiellement pleine : ");
    if (estPleinePile(pile) == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    empiler(pile, '2');
    printf("Pile pleine : ");
    if (estPleinePile(pile) == 1) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    depiler(pile, &v);
    printf("Pile n'est plus pleine : ");
    if (estPleinePile(pile) == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    empiler(pile, '2');
    printf("Pile de nouveau pleine : ");
    if (estPleinePile(pile) == 1) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    libererPile(pile);

    return code;
}


int testEmpiler() {
    int code = 1;
    pile_t * pile = initPile(3);
    char * chaine;

    empiler(pile, '1');
    chaine = ecrirePileDansChaine(pile, &ecrirePileCharDansChaine, 4);
    printf("empiler un element : ");
    if (!strcmp("1 ", chaine)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    empiler(pile, '2');
    empiler(pile, '4');
    chaine = ecrirePileDansChaine(pile, &ecrirePileCharDansChaine, 4);
    printf("Pile pleine : ");
    if (!strcmp("1 2 4 ", chaine)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    empiler(pile, '1');
    chaine = ecrirePileDansChaine(pile, &ecrirePileCharDansChaine, 4);
    printf("Redimensionnement : ");
    if (!strcmp("1 2 4 1 ", chaine) && (*pile).capacite == 5) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    libererPile(pile);
    
    pile = initPile(0);

    empiler(pile, '1');
    chaine = ecrirePileDansChaine(pile, &ecrirePileCharDansChaine, 4);
    printf("pile de capacite 0 : ");
    if (!strcmp("1 ", chaine) && (*pile).capacite == 1) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    libererPile(pile);

    return code;
}


int testDepiler() {
    int code  = 1;
    pile_t * pile = initPile(3);
    char * chaine;
    char v = '9';

    depiler(pile, &v);
    chaine = ecrirePileDansChaine(pile, &ecrirePileCharDansChaine, 4);
    printf("Depilage a vide : ");
    if (!strcmp("vide", chaine) && v == '9') {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    empiler(pile, '1');
    empiler(pile, '2');
    depiler(pile, &v);
    chaine = ecrirePileDansChaine(pile, &ecrirePileCharDansChaine, 4);
    printf("Depilage : ");
    if (!strcmp("1 ", chaine) && v == '2') {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    empiler(pile, '4');
    empiler(pile, '5');
    depiler(pile, &v);
    chaine = ecrirePileDansChaine(pile, &ecrirePileCharDansChaine, 4);
    printf("Depilage pile pleine : ");
    if (!strcmp("1 4 ", chaine) && v == '5') {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    libererPile(pile);

    pile = initPile(10);

    empiler(pile, '3');
    depiler(pile, &v);
    chaine = ecrirePileDansChaine(pile, &ecrirePileCharDansChaine, 4);
    printf("Redimenionnement : ");
    if (!strcmp("vide", chaine) && (*pile).capacite == 5 && v == '3') {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    libererPile(pile);

    return code;
}



char * ecrirePileDansChaine(pile_t * pile, void (*pfAfficher) (type, char *), int taille) {
    /* On alloc une taille previsionnel de l'affichage de la pile */
    char * chaine = malloc( taille*(*pile).capacite*sizeof(char) ); /* pointeur sur la debut de la chaine */
    char * cour = chaine;   /* pointeur que la fin de la chaine */

    if (!estVidePile(pile)) {

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


void ecrirePileIntDansChaine(int nombre, char * chaine) {
    sprintf(chaine, "%d ", nombre);
}


void ecrirePileCharDansChaine(char carac, char * chaine) {
    sprintf(chaine, "%c ", carac);
}
