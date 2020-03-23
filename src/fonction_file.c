
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fonction_file.h"


file_t * InitFile(int capacite) {

    /* Allocation de la file */
    file_t * file = malloc(sizeof(file_t));
    
    if (file != NULL) {
        /* Allocation de la base de la file */
        (*file).base = malloc(capacite*sizeof(type));

        if ((*file).base != NULL) {
            (*file).capacite = capacite;
            (*file).sommet = -1;
            (*file).queu = -1;
        } else {    /* Si l'allocation c'est pas faite, on libère la file */
            free(file);
            file = NULL;
        }
    }
    return file;
}


void LibererFile (file_t * file) {
    /* On libère la base */
    free((*file).base);
    /* On libère la file */
    free(file);
}


int EstVideFile (file_t * file) {
    /* La pile est vide que si le sommet et la queu valent -1 */
    return (*file).sommet == -1;
}


int Enfiler (file_t * file, type v) {
    int code = 1;

    int capacite = (*file).capacite;
    int sommet = (*file).sommet;
    int queu = (*file).queu;
    /* Si la file est pleine, on redimensionne, sinon, on enfile */
    if ( ( queu <= 0 && sommet == capacite-1 ) || ( queu == sommet+1 ) ) {

        /* + 1 pour le cas ou la capacite vaut 1 */
        int nvCapacite = 1.5 * (*file).capacite + 1;
        code = RedimensionnerFile(file, nvCapacite);

        /* Si le redimensionnement a fonctionne, on enfile l'elements */
        if (code == 0)
            code = Enfiler(file, v);

    } else {
        code = 0;

        /* Si le sommet est arrive au bout de la base */
        if ((*file).sommet == (*file).capacite-1) {
            /* on met la valeur au debut de la pile */
            (*file).sommet = 0;
        } else {
            (*file).sommet ++;

            /* Si c'est le premier element que l'on enfile
            on change la valeur de la queu */
            if ((*file).queu == -1)
                (*file).queu = 0;
        }
            
        (*file).base [(*file).sommet] = v;
    }

    return code;
}


int Defiler (file_t *file, type * v) {
    int code = 1;

    /* SI la pile est non vide, on defife */
    if (!EstVideFile(file)) {
        code = 0;
        *v = (*file).base [(*file).queu];

        /* Si on defile le dernier element de la file */
        if ((*file).queu == (*file).sommet) {
            /* La pile devient vide */
            (*file).queu = -1;
            (*file).sommet = -1;
        } else {
            /* si la queu est arrive au bout de la file */
            if ((*file).queu == (*file).capacite-1)
            /* le prochain element est au debut de la file */
                (*file).queu = 0;
            else
                (*file).queu ++;
        }
    }

    int queu = (*file).queu;
    int sommet = (*file).sommet;
    int capacite = (*file).capacite;
    /* Si la file est tres peu utilise, on diminue la taille */
    if ( ( queu <= sommet && sommet-queu+1 < 0.25*capacite ) 
                || ( queu > sommet && queu-sommet > 0.5*capacite ) ) {
        int nvCapacite = 0.5 * capacite;
        RedimensionnerFile(file, nvCapacite);
    }
    return code;
}


int RedimensionnerFile (file_t * file, int nvCapacaite) {
    int code = 1;
    
    /* On alloc la mouvelle base */
    type * nvBase = malloc(nvCapacaite*sizeof(type));
    if (nvBase != NULL) {
        code = 0;
        /* Copy des elements que si la file est non vide */
        if (!EstVideFile(file)) {
            int debut = (*file).queu;
            int fin = (*file).sommet;

            if ((*file).queu > (*file).sommet)
                fin = (*file).capacite-1;
                
            int taille = fin - debut + 1;
            
            /* Copy du bloc memoire entre la queu et soit le sommet soit la fin de la file */
            CpyBlocMem(nvBase, (*file).base+debut, (*file).base+fin);

            /* Si la queu est apres le sommet
            cela veut dire que l'on a pas tout copie */
            if ((*file).queu > (*file).sommet) {
                debut = 0;
                fin = (*file).sommet;
                /* Copy du bloc memoire entre la base et le sommet */
                CpyBlocMem(nvBase+taille, (*file).base+debut, (*file).base+fin);
                (*file).sommet = taille + fin - debut;
            } else {
                (*file).sommet = taille - 1;
            }

            (*file).queu = 0;
        }

        (*file).capacite = nvCapacaite;
        free((*file).base);
        (*file).base = nvBase;
    }
    return code;
}


void CpyBlocMem (type *dest, type * deb, type * fin) {

    /* Si le deb est apres la fin, on inverse le debut et la fin */
    if (deb > fin) {
        type * tmp = deb;
        deb = fin;
        fin = tmp;
    }

    while (deb <= fin) {
        *dest = *deb;
        dest ++;
        deb ++;
    }

}


void AfficherFile (file_t * file, void (*pfAfficher) (type)) {

    int fin = (*file).sommet+1;
    printf("File : capacite=%d\n", (*file).capacite);
    printf("       ");

    if (!EstVideFile(file)) {
        if ((*file).sommet < (*file).queu)
            fin = (*file).capacite;
        
        /* On affiche la premiere partie de la file a partir de la queu */
        for (int i=(*file).queu; i<fin; i++)
            (pfAfficher) ((*file).base[i]);

        /* On affiche la deuxieme partie que si elle existe */
        if ((*file).sommet < (*file).queu)
            for (int i=0; i<(*file).sommet; i++)
                (pfAfficher) ((*file).base[i]);
        
    } else {
        printf("vide");
    }
    printf("\n");
}


void AfficherFileInt (int nombre) {
    printf("%d ", nombre);
}


void AfficherFileChar (char caractere) {
    printf("%c ", caractere);
}


void AfficherFileChaineCarac (char * chaine) {
    printf("%s ", chaine);
}


char * AfficherFileDansChaine (file_t * file, void (*pfAfficher) (type, char *), int taille) {
    /* On alloc une taille previsionnel de l'affichage de la file */
    char * chaine = malloc( taille*(*file).capacite*sizeof(int)); /* pointeur sur la debut de la chaine */
    char * cour = chaine;   /* pointeur que la fin de la chaine */


    if (!EstVideFile(file)) {
        
        int fin = (*file).sommet+1;
        if ((*file).sommet < (*file).queu)
            fin = (*file).capacite;

        /* On affiche la premiere partie de la file a partir de la queu */
        for (int i=(*file).queu; i<fin; i++) {
            /* On ajoute l'affichage a la fin de la chaine */
            (*pfAfficher) ((*file).base[i], cour);
            /* On decale le pointeur a la fin de la chaine */
            cour += strlen(cour);
        }

        /* On affiche la deuxieme partie que si elle existe */
        if ((*file).sommet < (*file).queu)
            for (int i=0; i<=(*file).sommet; i++) {
                /* On ajoute l'affichage a la fin de la chaine */
                (*pfAfficher) ((*file).base[i], cour);
                /* On decale le pointeur a la fin de la chaine */
                cour += strlen(cour);
            }
        
    } else {
        strcpy(cour, "vide");
    }

    return chaine;
}

void AfficherFileIntDansChaine(int nombre, char * chaine) {
    sprintf(chaine, "%d ", nombre);
}


void AfficherFileCharDansChaine(char carac, char * chaine) {
    sprintf(chaine, "%c ", carac);
}