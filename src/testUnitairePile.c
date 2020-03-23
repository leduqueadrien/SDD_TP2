
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"testUnitairePile.h"
#include"fonction_pile.h"


int TestUnitairePile () {
    int code = 1;

    if (TestAfficherPile() == 1) {
        printf("Fonction afficher pile fonctionne\n\n");
    } else {
        code = 0;
        printf("Fonction afficher pile ne fonctionne pas\n\n");
    }

    if (TestInitPile() == 1) {
        printf("Fonction init pile fonctionne\n\n");
    } else {
        code = 0;
        printf("Fonction init pile ne fonctionne pas\n\n");
    }

    if (TestEstVidePile() == 1) {
        printf("Fonction pile est vide fonctionne\n\n");
    } else {
        code = 0;
        printf("Fonction pile est non vide ne fonctionne pas\n\n");
    }

    if (TestEstPleinePile() == 1) {
        printf("Fonction pile est pleine fonctionne\n\n");
    } else {
        code = 0;
        printf("Fonction pile est pleine ne fonctionne pas\n\n");
    }

    if (TestEmpiler() == 1) {
        printf("Fonction empiler fonctionne\n\n");
    } else {
        code = 0;
        printf("Fonction empiler ne fonctionne pas\n\n");
    }

    if (TestDepiler() == 1) {
        printf("Fonction depiler fonctionne \n\n");
    } else {
        code = 0;
        printf("FOnction depiler ne fonctionne pas\n\n");
    }

    return code;
}


int TestAfficherPile () {
    int code = 1;
    pile_t * pile = InitPile(3);
    char * chaine;

    chaine = AfficherPileDansChaine(pile, &AfficherPileCharDansChaine, 4);
    printf("Affichage pile vide : ");
    if (!strcmp("vide", chaine)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);
    
    Empiler(pile, '1');
    chaine = AfficherPileDansChaine(pile, &AfficherPileCharDansChaine, 4);
    printf("Affichage pile 1 element : ");
    if (!strcmp("1 ", chaine)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    Empiler(pile, '2');
    Empiler(pile, '3');
    chaine = AfficherPileDansChaine(pile, &AfficherPileCharDansChaine, 4);
    printf("Affichage pile pleine : ");
    if (!strcmp("1 2 3 ", chaine)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    LibererPile(pile);

    return code;
}


int TestInitPile () {
    int code = 1;
    pile_t * pile = InitPile(3);

    printf("Initialiser capacite : ");
    if ((*pile).capacite == 3) {
        printf("bon\n");
    } else {
        code = 1;
        printf("faux\n");
    }

    printf("Initialiser sommet : ");
    if ((*pile).sommet == -1) {
        printf("bon\n");
    } else {
        code = 1;
        printf("faux\n");
    }

    LibererPile(pile);

    return code;
}


int TestEstVidePile () {
    int code = 1;
    pile_t * pile = InitPile(3);
    char a;

    printf("Pile est vide");
    if (EstVidePile(pile) == 1) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    
    Empiler(pile, '1');
    printf("Pile est non vide : ");
    if (EstVidePile(pile) == 0) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    Depiler(pile,&a);
    printf("Pile est de nouveau vide : ");
    if (EstVidePile(pile)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    LibererPile(pile);

    return code;
}


int TestEstPleinePile () {
    int code = 1;
    pile_t * pile = InitPile(2);
    char a;

    printf("Pile est vide (non pleine) : ");
    if (EstPleinePile(pile) == 0) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux");
    }

    Empiler(pile, '1');
    printf("Pile est partiellement pleine : ");
    if (EstPleinePile(pile) == 0) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    Empiler(pile, '2');
    printf("Pile pleine : ");
    if (EstPleinePile(pile) == 1) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    Depiler(pile, &a);
    printf("Pile n'est plus pleine : ");
    if (EstPleinePile(pile) == 0) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    Empiler(pile, '2');
    printf("Pile de nouveau pleine : ");
    if (EstPleinePile(pile) == 1) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    LibererPile(pile);

    return code;
}


int TestEmpiler () {
    int code = 1;
    pile_t * pile = InitPile(3);
    char * chaine;

    Empiler(pile, '1');
    chaine = AfficherPileDansChaine(pile, &AfficherPileCharDansChaine, 4);
    printf("Empiler un element : ");
    if (!strcmp("1 ", chaine)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    Empiler(pile, '2');
    Empiler(pile, '4');
    chaine = AfficherPileDansChaine(pile, &AfficherPileCharDansChaine, 4);
    printf("Pile pleine : ");
    if (!strcmp("1 2 4 ", chaine)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    Empiler(pile, '1');
    chaine = AfficherPileDansChaine(pile, &AfficherPileCharDansChaine, 4);
    printf("Redimensionnement : ");
    if (!strcmp("1 2 4 1 ", chaine) && (*pile).capacite == 5) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    LibererPile(pile);
    
    return code;
}


int TestDepiler () {
    int code  = 1;
    pile_t * pile = InitPile(3);
    char * chaine;
    char a = '9';

    Depiler(pile, &a);
    chaine = AfficherPileDansChaine(pile, &AfficherPileCharDansChaine, 4);
    printf("Depilage a vide : ");
    if (!strcmp("vide", chaine) && a == '9') {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    Empiler(pile, '1');
    Empiler(pile, '2');
    Depiler(pile, &a);
    chaine = AfficherPileDansChaine(pile, &AfficherPileCharDansChaine, 4);
    printf("Depilage : ");
    if (!strcmp("1 ", chaine) && a == '2') {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    Empiler(pile, '4');
    Empiler(pile, '5');
    Depiler(pile, &a);
    chaine = AfficherPileDansChaine(pile, &AfficherPileCharDansChaine, 4);
    printf("Depilage pile pleine : ");
    if (!strcmp("1 4 ", chaine) && a == '5') {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    LibererPile(pile);

    pile = InitPile(10);

    Empiler(pile, '3');
    Depiler(pile, &a);
    chaine = AfficherPileDansChaine(pile, &AfficherPileCharDansChaine, 4);
    printf("Redimenionnement : ");
    if (!strcmp("vide", chaine) && (*pile).capacite == 5 && a == '3') {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    LibererPile(pile);

    return code;
}

