/* ---------------------------------------------------------------------------- */
/*  pile.h                                                                      */
/*          Contient les déclarations des fonctions du fichiers pile.c          */
/* ---------------------------------------------------------------------------- */

#ifndef PILE
#define PILE

/* ------------ */
/* Type utilisé */
/* ------------ */
typedef char type;


/* -------------------- */
/* Structure de la pile */
/* -------------------- */
typedef struct Pile {
    int   capacite;
    int   sommet;
    type * base;
} pile_t;


/* -------------------------------------------------------------- */
/* InitPile     Initialise une pile de taille le paramètre taille */
/*                                                                */
/* En entrée :  taille (int) : taille de la pile                  */
/*                                                                */
/* En sortie :  pile : pointeur sur la pile (pile_t *)            */
/* -------------------------------------------------------------- */
pile_t * initPile(int);

/* --------------------------------------------------------------------- */
/* EstVidePile  Indique si la pile passée en paramètre est vide ou non   */
/*                                                                       */
/* En entrée :  pile (pile_t *) : pile à tester                          */
/*                                                                       */
/* En sortie :  estVide (int) booléen : 1 si la pile est vide, 0 sinon  */
/* --------------------------------------------------------------------- */
int estVidePile(pile_t *);

/* ------------------------------------------------------------------------- */
/* EstPleinePile  Indique si la pile passée en paramètre est pleine ou non   */
/*                                                                           */
/* En entrée :  pile (pile_t *) : pile à tester                              */
/*                                                                           */
/* En sortie :  (int) booléen : 1 si la pile est pleine, 0 sinon             */
/* ------------------------------------------------------------------------- */
int estPleinePile(pile_t *);

/* ------------------------------------------------------------------ */
/* Empiler      Empile une valeur au sommet de la pile,               */
/*                          et l'aggrandit si elle est trop petite    */
/*                                                                    */
/* En entrée :  pile (pile_t *) : pile à remplir                      */
/*              valeur (type)   : élément à empiler                   */
/*                                                                    */
/* En sortie :  codeErreur (int) booléen : 1 si erreur, 0 sinon       */
/* ------------------------------------------------------------------ */
int empiler(pile_t *, type);

/* -------------------------------------------------------------- */
/* Depiler      Dépile la valeur au sommet de la pile,            */
/*                          et la réduit si elle peu utilisée     */
/*                                                                */
/* En entrée :  pile (pile_t *) : pile à vider                    */
/*              valeur (type)   : élément dépilée                 */
/*                                                                */
/* En sortie :  codeErreur (int) booléen : 2 si erreur, 0 sinon   */
/* -------------------------------------------------------------- */
int depiler(pile_t *, type *);

/* --------------------------------------------------------------------- */
/* RedimensionerPile    Redimensionne la base de la pile                 */
/*                                                                       */
/* En entrée : pile (pile_t *) : pile a redimensionner                   */
/*             nvCapacité (int) : taille que la nouvelle base doit avoir */
/*                                                                       */
/* En sortie : codeErreur (int) booléen : 1 si le redimensionnement      */
/*                                  n'a pas pu être fait, 0 sinon        */
/* --------------------------------------------------------------------- */
int redimensionerPile(pile_t *, int);

/* --------------------------------------------------------- */
/* LibererPile  Libère la mémoire utilisée par la pile       */
/*                                                           */
/* En entrée :  pile (pile_t *) : pile à libérer             */
/*                                                           */
/* En sortie :  void                                         */
/* --------------------------------------------------------- */
void libererPile(pile_t *);

/* ----------------------------------------------------------------------------------------- */
/* AfficherPile     Affiche le pile                                                          */
/*                                                                                           */
/* En entrée : pile (pile_t *) : pile a afficher                                             */
/*             pfAfficher (void (*)(type)) : pointeur sur la fonction qui affiche un élément */
/*                                                                                           */
/* En sortie : void                                                                          */
/* ----------------------------------------------------------------------------------------- */
void afficherPile(pile_t *, void (*) (type));


/* --------------------------------------------------- */
/* AfficherPileInt      Affiche un élément de type int */
/*                                                     */
/* En entrée : nombre (int) : nombre a afficher        */
/*                                                     */
/* En sortie : void                                    */
/* --------------------------------------------------- */
void afficherPileInt(int);

/* ---------------------------------------------------- */
/* AfficherPileChar      Affiche un élément de type char */
/*                                                      */
/* En entrée : caractere (char) : carectere a afficher  */
/*                                                      */
/* En sortie : void                                     */
/* ---------------------------------------------------- */
void afficherPileChar(char);

/* --------------------------------------------------------------------------- */
/* AfficherPileChaineCarac      Affiche un élément de type chaine de caractère */
/*                                                                             */
/* En entrée : chaine (char *) : chaine a afficher                             */
/*                                                                             */
/* En sortie : void                                                            */
/* --------------------------------------------------------------------------- */
void afficherPileChaineCarac(char *);


#endif
