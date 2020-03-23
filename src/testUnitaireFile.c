
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"testUnitaireFile.h"
#include"fonction_file.h"

int TestUnitaireFile () {
    int code = 1;

    if (TestInitFile()) {
        printf("Initialisation file fonctionne\n\n");
    } else {
        code = 0;
        printf("Initialisation file ne fonctionne pas\n\n");
    }

    if (TestFileEstVide()) {
        printf("Fonction file est vide fonctionne\n\n");
    } else {
        code = 0;
        printf("Fonction file est vide ne fonctionne pas\n\n");
    }

    if (TestEnfiler()) {
        printf("Fonction Enfiler fonctionne\n\n");
    } else {
        code = 0;
        printf("Fonction Enfiler ne fonctionne pas\n\n");
    }

    if (TestDefiler()) {
        printf("Fonction defiler fonctionne\n\n");
    } else {
        code = 0;
        printf("Fonction defiler ne fonctionne pas\n\n");
    }

    return code;
}


int TestInitFile () {
    int code = 1;
    file_t * file = InitFile(3);

    printf("Initialiser capacite : ");
    if ((*file).capacite == 3) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    printf("Initialiser sommet : ");
    if ((*file).sommet == -1) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    printf("Initialiser queu : ");
    if ((*file).queu == -1) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    LibererFile(file);

    return code;
}


int TestFileEstVide () {
    int code = 1;
    file_t * file = InitFile(3);
    type a;

    printf("File vide : ");
    if (EstVideFile(file) && (*file).sommet == -1 && (*file).queu == -1) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    Enfiler(file, '2');
    printf("File non vide : ");
    if (!EstVideFile(file)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    Defiler(file, &a);
    printf("File de nouveau vide : ");
    if (EstVideFile(file) && (*file).sommet == -1 && (*file).queu == -1) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    LibererFile(file);

    return code;
}


int TestEnfiler () {
    int code = 1;
    file_t * file = InitFile(3);
    char * chaine;
    type a;

    Enfiler(file, '1');
    chaine = AfficherFileDansChaine(file, &AfficherFileCharDansChaine, 4);
    printf("Emfile 1 element : ");
    if (!strcmp("1 ", chaine)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    Enfiler(file, '2');
    Enfiler(file, '3');
    chaine = AfficherFileDansChaine(file, &AfficherFileCharDansChaine, 4);
    printf("Emfile jusqu'a ce que le file soit pleine : ");
    if (!strcmp("1 2 3 ", chaine)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    Enfiler(file, '4');
    chaine = AfficherFileDansChaine(file, &AfficherFileCharDansChaine, 4);
    printf("Redimensionnement sans avoir defiler : ");
    if (!strcmp("1 2 3 4 ", chaine) && (*file).capacite == 5) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    LibererFile(file);

    file = InitFile(3);
    Enfiler(file, '1');
    Enfiler(file, '2');
    Enfiler(file, '3');
    Defiler(file, &a);
    Defiler(file, &a);
    Enfiler(file, '4');
    chaine = AfficherFileDansChaine(file, &AfficherFileCharDansChaine, 4);
    printf("Enfiler apres avoir defiler : ");
    if (!strcmp("3 4 ", chaine)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    Enfiler(file, '5');
    Enfiler(file, '6');
    chaine = AfficherFileDansChaine(file, &AfficherFileCharDansChaine, 4);
    printf("Redimensionnement apres avoir defiler : ");
    if (!(strcmp("3 4 5 6 ", chaine) && (*file).capacite == 5)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    LibererFile(file);

    return code;
}


int TestDefiler () {
    int code = 1;
    file_t * file = InitFile(3);
    char * chaine;
    type a = 2;
    
    Defiler(file, &a);
    chaine = AfficherFileDansChaine(file, &AfficherFileCharDansChaine, 4);
    printf("Defiler a vide : ");
    if (!strcmp("vide", chaine) && a == 2 && (*file).queu == -1 && (*file).sommet == -1) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    Enfiler(file, '3');
    Defiler(file, &a);
    chaine = AfficherFileDansChaine(file, &AfficherFileCharDansChaine, 4);
    printf("Defilage : ");
    if (!strcmp("vide", chaine) && a == '3') {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    Enfiler(file, '1');
    Enfiler(file, '2');
    Enfiler(file, '3');
    Defiler(file, &a);
    chaine = AfficherFileDansChaine(file, &AfficherFileCharDansChaine, 4);
    printf("Defilage pile pleine : ");
    if (!strcmp("2 3 ", chaine) && a == '1') { 
        printf("bon\n") ;
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    LibererFile(file);

    file = InitFile(10);
    Defiler(file, &a);
    chaine = AfficherFileDansChaine(file, &AfficherFileCharDansChaine, 4);
    printf("Redimensionnement : ");
    if (!strcmp("vide", chaine) && (*file).capacite == 5) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    LibererFile(file);

    return code;
}