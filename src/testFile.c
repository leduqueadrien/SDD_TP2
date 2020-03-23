
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testFile.h"
#include "file.h"

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
    file_t * file = initFile(3);

    printf("Initialiser capacite : ");
    if ((*file).capacite == 3) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    printf("Initialiser indexInsertion : ");
    if ((*file).indexInsertion == 0) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    printf("Initialiser indexSuppression : ");
    if ((*file).indexSuppression == 0) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    libererFile(file);

    return code;
}


int TestFileEstVide () {
    int code = 1;
    file_t * file = initFile(3);
    type v;

    printf("File vide : ");
    if (estVideFile(file)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    enfiler(file, '2');
    printf("File non vide : ");
    if (!estVideFile(file)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    defiler(file, &v);
    printf("File de nouveau vide : ");
    if (estVideFile(file)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }

    libererFile(file);

    return code;
}


int TestEnfiler () {
    int code = 1;
    file_t * file = initFile(3);
    char * chaine;
    type a;

    enfiler(file, '1');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Emfile 1 element : ");
    if (!strcmp("1 ", chaine)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    enfiler(file, '2');
    enfiler(file, '3');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Emfile jusqu'a ce que le file soit pleine : ");
    if (!strcmp("1 2 3 ", chaine)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    enfiler(file, '4');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Redimensionnement sans avoir defiler : ");
    if (!strcmp("1 2 3 4 ", chaine) && (*file).capacite == 5) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
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
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    enfiler(file, '5');
    enfiler(file, '6');
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Redimensionnement apres avoir defiler : ");
    if (!(strcmp("3 4 5 6 ", chaine) && (*file).capacite == 5)) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    libererFile(file);

    return code;
}


int TestDefiler () {
    int code = 1;
    file_t * file = initFile(3);
    char * chaine;
    type a = 2;
    
    defiler(file, &a);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Defiler a vide : ");
    if (!strcmp("vide", chaine) && a == 2 && (*file).indexSuppression == 0 && (*file).indexInsertion == 0) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    enfiler(file, '3');
    defiler(file, &a);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Defilage : ");
    if (!strcmp("vide", chaine) && a == '3') {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    enfiler(file, '1');
    enfiler(file, '2');
    enfiler(file, '3');
    defiler(file, &a);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Defilage pile pleine : ");
    if (!strcmp("2 3 ", chaine) && a == '1') { 
        printf("bon\n") ;
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    libererFile(file);

    file = initFile(10);
    defiler(file, &a);
    chaine = ecrireFileDansChaine(file, ecrireFileCharDansChaine, 4);
    printf("Redimensionnement : ");
    if (!strcmp("vide", chaine) && (*file).capacite == 5) {
        printf("bon\n");
    } else {
        code = 0;
        printf("faux\n");
    }
    free(chaine);

    libererFile(file);

    return code;
}