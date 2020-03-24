/* ----------------------------------------------------------------------------- */
/*  testFile.h                                                                   */
/*      Contient tous les tests pour les fonctions de manipulation de la file    */
/* ----------------------------------------------------------------------------- */

#ifndef TUFILE
#define TUFILE
#include "file.h"

/* ----------------------------------------------------------------------------- */
/* testUnitaireFile    Fonction appelant toutes les fonctions de test de la file */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testUnitaireFile();

/* ----------------------------------------------------------------------------- */
/* testInitFile     Fonction qui test la fonction d'initialisation de la file    */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testInitFile();

/* ----------------------------------------------------------------------------- */
/* testFileEstVide   Fonction qui test la fonction testant si la file est vide   */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testFileEstVide();

/* ----------------------------------------------------------------------------- */
/* testEstPleineFile  Fonction qui test la fonction testant si la pie est pleine */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testEstPleineFile();

/* ----------------------------------------------------------------------------- */
/* testEnfiler      Fonction qui test si la fonction d'enfilage de la file       */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testEnfiler();

/* ----------------------------------------------------------------------------- */
/* testDefiler      Fonction qui test si la fonction de défilage de la file      */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testDefiler();


/* ----------------------------------------------------------------------------------------- */
/* AfficherFileDansChaine       Affiche la File dans une chaine de caractère                 */
/*                                                                                           */
/* En entrée : file (file_t *)             : File a afficher                                 */
/*             pfAfficher (void (*)(type)) : pointeur sur la fonction qui affiche un élément */
/*                                              dans une chaine de caractère                 */
/*             tailleElement (int)         : taille moyenne que prend                        */
/*                                              un élément à être affiché                    */
/*                                                                                           */
/* En sortie : chaine (char *) : chaine de caractère contenant l'affichage de la File        */
/* ----------------------------------------------------------------------------------------- */
char * ecrireFileDansChaine(file_t *, void (*) (type, char *), int);


/* ---------------------------------------------------------------------- */
/* AfficherFileIntDansChaine      Affiche un élément de type int          */
/*                                 dans une chaine de caractère           */
/*                                                                        */
/* En entrée : nombre (int)    : nombre a afficher                        */
/*             chaine (char *) : chaine dans lequel on afficher le nombre */
/*                                                                        */
/* En sortie : void                                                       */
/* ---------------------------------------------------------------------- */
void ecrireFileIntDansChaine(int, char *);


/* -------------------------------------------------------------------------- */
/* AfficherFileCharDansChaine      Affiche un élément de type char            */
/*                                 dans une chaine de caractère               */
/*                                                                            */
/* En entrée : caractere (char) : caractère a afficher                        */
/*             chaine (char *)  : chaine dans lequel on afficher le caractere */
/*                                                                            */
/* En sortie : void                                                           */
/* -------------------------------------------------------------------------- */
void ecrireFileCharDansChaine(char, char *);


#endif
