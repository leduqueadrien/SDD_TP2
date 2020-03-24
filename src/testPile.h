/* ----------------------------------------------------------------------------- */
/*  testPile.h                                                                   */
/*      Contient tous les tests pour les fonctions de manipulation de la pile    */
/* ----------------------------------------------------------------------------- */

#ifndef TUPILE
#define TUPILE
#include "pile.h"

/* ----------------------------------------------------------------------------- */
/* testUnitairePile    Fonction appelant toutes les fonctions de test de la pile */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testUnitairePile();


int testAfficherPile();

/* ----------------------------------------------------------------------------- */
/* testInitPile     Fonction qui test la fonction d'initialisation de la pile    */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testInitPile();


/* ----------------------------------------------------------------------------- */
/* testPileEstVide   Fonction qui test la fonction testant si la pile est vide   */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testEstVidePile();

/* ----------------------------------------------------------------------------- */
/* testPileEstVide   Fonction qui test la fonction testant si la pie est pleine  */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testEstPleinePile();


/* ----------------------------------------------------------------------------- */
/* testEnfiler      Fonction qui test si la fonction d'enfilage de la pile       */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testEmpiler();


/* ----------------------------------------------------------------------------- */
/* testDefiler      Fonction qui test si la fonction de défilage de la pile      */
/*                                                                               */
/* En entrée : void                                                              */
/* En sortie : void                                                              */
/* ----------------------------------------------------------------------------- */
int testDepiler();


/* ----------------------------------------------------------------------------------------- */
/* AfficherPileDansChaine       Retourne l'affichage la pile dans une chaine de caractère    */
/*                                                                                           */
/* En entrée : pile (pile_t *) : pile a afficher                                             */
/*             pfAfficher (void (*)(type)) : pointeur sur la fonction qui affiche un élément */
/*                                              dans une chaine de caractère                 */
/*             tailleElement (int) : taille moyenne que prend un élément à être affiché      */
/*                                                                                           */
/* En sortie : chaine (char *) : chaine de caractère contenant l'affichage de la pile        */
/* ----------------------------------------------------------------------------------------- */
char * ecrirePileDansChaine(pile_t *, void (*) (type, char *), int);


/* ---------------------------------------------------------------------- */
/* AfficherPileIntDansChaine      Retourne un élément de type int         */
/*                                 dans une chaine de caractère           */
/*                                                                        */
/* En entrée : nombre (int)    : nombre a afficher                        */
/*             chaine (char *) : chaine dans lequel on afficher le nombre */
/*                                                                        */
/* En sortie : void                                                       */
/* ---------------------------------------------------------------------- */
void ecrirePileIntDansChaine(int, char *);


/* -------------------------------------------------------------------------- */
/* AfficherPileCharDansChaine      Retourne un élément de type char           */
/*                                 dans une chaine de caractère               */
/*                                                                            */
/* En entrée : caractere (char) : caractère a afficher                        */
/*             chaine (char *) : chaine dans lequel on afficher le caractere  */
/*                                                                            */
/* En sortie : void                                                           */
/* -------------------------------------------------------------------------- */
void ecrirePileCharDansChaine(char, char *);


#endif
