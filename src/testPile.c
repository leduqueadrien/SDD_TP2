
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testPile.h"
#include "pile.h"


int TestUnitairePile() {
    int code = 1;

    if (TestAfficherPile() == 1) {
        printf("\033[32mFonction afficher pile fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction afficher pile ne fonctionne pas\033[00m\n\n");
    }

    if (TestInitPile() == 1) {
        printf("\033[32mFonction init pile fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction init pile ne fonctionne pas\033[00m\n\n");
    }

    if (TestEstVidePile() == 1) {
        printf("\033[32mFonction pile est vide fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction pile est non vide ne fonctionne pas\033[00m\n\n");
    }

    if (TestEstPleinePile() == 1) {
        printf("\033[32mFonction pile est pleine fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction pile est pleine ne fonctionne pas\033[00m\n\n");
    }

    if (TestEmpiler() == 1) {
        printf("\033[32mFonction empiler fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction empiler ne fonctionne pas\033[00m\n\n");
    }

    if (TestDepiler() == 1) {
        printf("\033[32mFonction depiler fonctionne\033[00m\n\n");
    } else {
        code = 0;
        printf("\033[31mFonction depiler ne fonctionne pas\033[00m\n\n");
    }

    return code;
}


int TestAfficherPile() {
    int code = 1;
    pile_t * pile = InitPile(3);
    char * chaine;

    chaine = EcrirePileDansChaine(pile, &EcrirePileCharDansChaine, 4);
    printf("Affichage pile vide : ");
    if (!strcmp("vide", chaine)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);
    
    Empiler(pile, '1');
    chaine = EcrirePileDansChaine(pile, &EcrirePileCharDansChaine, 4);
    printf("Affichage pile 1 element : ");
    if (!strcmp("1 ", chaine)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    Empiler(pile, '2');
    Empiler(pile, '3');
    chaine = EcrirePileDansChaine(pile, &EcrirePileCharDansChaine, 4);
    printf("Affichage pile pleine : ");
    if (!strcmp("1 2 3 ", chaine)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    LibererPile(pile);

    return code;
}


int TestInitPile() {
    int code = 1;
    pile_t * pile = InitPile(3);

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

    LibererPile(pile);

    return code;
}


int TestEstVidePile() {
    int code = 1;
    pile_t * pile = InitPile(3);
    char a;

    printf("Pile est vide : ");
    if (EstVidePile(pile) == 1) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    
    Empiler(pile, '1');
    printf("Pile est non vide : ");
    if (EstVidePile(pile) == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    Depiler(pile,&a);
    printf("Pile est de nouveau vide : ");
    if (EstVidePile(pile)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    LibererPile(pile);

    return code;
}


int TestEstPleinePile() {
    int code = 1;
    pile_t * pile = InitPile(2);
    char a;

    printf("Pile est vide (non pleine) : ");
    if (EstPleinePile(pile) == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m");
    }

    Empiler(pile, '1');
    printf("Pile est partiellement pleine : ");
    if (EstPleinePile(pile) == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    Empiler(pile, '2');
    printf("Pile pleine : ");
    if (EstPleinePile(pile) == 1) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    Depiler(pile, &a);
    printf("Pile n'est plus pleine : ");
    if (EstPleinePile(pile) == 0) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    Empiler(pile, '2');
    printf("Pile de nouveau pleine : ");
    if (EstPleinePile(pile) == 1) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }

    LibererPile(pile);

    return code;
}


int TestEmpiler() {
    int code = 1;
    pile_t * pile = InitPile(3);
    char * chaine;

    Empiler(pile, '1');
    chaine = EcrirePileDansChaine(pile, &EcrirePileCharDansChaine, 4);
    printf("Empiler un element : ");
    if (!strcmp("1 ", chaine)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    Empiler(pile, '2');
    Empiler(pile, '4');
    chaine = EcrirePileDansChaine(pile, &EcrirePileCharDansChaine, 4);
    printf("Pile pleine : ");
    if (!strcmp("1 2 4 ", chaine)) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    Empiler(pile, '1');
    chaine = EcrirePileDansChaine(pile, &EcrirePileCharDansChaine, 4);
    printf("Redimensionnement : ");
    if (!strcmp("1 2 4 1 ", chaine) && (*pile).capacite == 5) {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    LibererPile(pile);
    
    return code;
}


int TestDepiler() {
    int code  = 1;
    pile_t * pile = InitPile(3);
    char * chaine;
    char a = '9';

    Depiler(pile, &a);
    chaine = EcrirePileDansChaine(pile, &EcrirePileCharDansChaine, 4);
    printf("Depilage a vide : ");
    if (!strcmp("vide", chaine) && a == '9') {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    Empiler(pile, '1');
    Empiler(pile, '2');
    Depiler(pile, &a);
    chaine = EcrirePileDansChaine(pile, &EcrirePileCharDansChaine, 4);
    printf("Depilage : ");
    if (!strcmp("1 ", chaine) && a == '2') {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    Empiler(pile, '4');
    Empiler(pile, '5');
    Depiler(pile, &a);
    chaine = EcrirePileDansChaine(pile, &EcrirePileCharDansChaine, 4);
    printf("Depilage pile pleine : ");
    if (!strcmp("1 4 ", chaine) && a == '5') {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    LibererPile(pile);

    pile = InitPile(10);

    Empiler(pile, '3');
    Depiler(pile, &a);
    chaine = EcrirePileDansChaine(pile, &EcrirePileCharDansChaine, 4);
    printf("Redimenionnement : ");
    if (!strcmp("vide", chaine) && (*pile).capacite == 5 && a == '3') {
        printf("\033[32mbon\033[00m\n");
    } else {
        code = 0;
        printf("\033[31mfaux\033[00m\n");
    }
    free(chaine);

    LibererPile(pile);

    return code;
}



char * EcrirePileDansChaine(pile_t * pile, void (*pfAfficher) (type, char *), int taille) {
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


void EcrirePileIntDansChaine(int nombre, char * chaine) {
    sprintf(chaine, "%d ", nombre);
}


void EcrirePileCharDansChaine(char carac, char * chaine) {
    sprintf(chaine, "%c ", carac);
}
