
#ifndef TUPILE
#define TUPILE
#include "pile.h"

int TestUnitairePile();
int TestAfficherPile();
int TestInitPile();
int TestEstVidePile();
int TestEstPleinePile();
int TestEmpiler();
int TestDepiler();


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
char * EcrirePileDansChaine(pile_t *, void (*) (type, char *), int);


/* ---------------------------------------------------------------------- */
/* AfficherPileIntDansChaine      Retourne un élément de type int         */
/*                                 dans une chaine de caractère           */
/*                                                                        */
/* En entrée : nombre (int)    : nombre a afficher                        */
/*             chaine (char *) : chaine dans lequel on afficher le nombre */
/*                                                                        */
/* En sortie : void                                                       */
/* ---------------------------------------------------------------------- */
void EcrirePileIntDansChaine(int, char *);


/* -------------------------------------------------------------------------- */
/* AfficherPileCharDansChaine      Retourne un élément de type char           */
/*                                 dans une chaine de caractère               */
/*                                                                            */
/* En entrée : caractere (char) : caractère a afficher                        */
/*             chaine (char *) : chaine dans lequel on afficher le caractere  */
/*                                                                            */
/* En sortie : void                                                           */
/* -------------------------------------------------------------------------- */
void EcrirePileCharDansChaine(char, char *);


#endif
