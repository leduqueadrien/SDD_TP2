
#ifndef TUFILE
#define TUFILE
#include "file.h"


int testUnitaireFile();
int testInitFile();
int testFileEstVide();
int testEnfiler();
int testDefiler();
int testAfficherFile();


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
