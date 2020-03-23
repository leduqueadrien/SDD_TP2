/* ------------------------------------------------------------------- */
/*  file.h                                                             */
/*          Contient les déclarations des fonctions du fichiers file.c */
/* ------------------------------------------------------------------- */
#ifndef FILE
#define FILE


/* ------------------------------------------------- */
/* Renommage du type dont que l'on souhaite utiliser */
/* ------------------------------------------------- */
typedef char type;


/* -------------------- */
/* Structure de la file */
/* -------------------- */
typedef struct file {
    int capacite;
    int sommet;
    int queu;
    type * base;
} file_t;


/* -------------------------------------------------------------- */
/* InitFile     Initialise une file de taille le paramètre taille */
/*                                                                */
/* En entrée :  taille (int) : taille de la file                  */
/*                                                                */
/* En sortie :  file : pointeur sur la file (file_t *)            */
/* -------------------------------------------------------------- */
file_t * InitFile (int);

/* --------------------------------------------------------------------- */
/* EstVideFile  Indique si la file passée en paramètre est vide ou non   */
/*                                                                       */
/* En entrée :  file (file_t *) : file à tester                          */
/*                                                                       */
/* En sortie :  estVide (int) booléen : 1 si la File est vide, 0 sinon  */
/* --------------------------------------------------------------------- */
int EstVideFile (file_t *);

/* ------------------------------------------------------------------ */
/* Enfiler      Emfile une valeur à la queu de la file,               */
/*                          et l'aggrandit si elle est trop petite    */
/*                                                                    */
/* En entrée :  file (file_t *) : file à remplir                      */
/*              valeur (type)   : élément à enfiler                   */
/*                                                                    */
/* En sortie :  codeErreur (int) booléen : 1 si erreur, 0 sinon       */
/* ------------------------------------------------------------------ */
int Enfiler (file_t *, type);

/* -------------------------------------------------------------- */
/* Defiler      Défile la valeur au sommet de la File,            */
/*                          et la réduit si elle peu utilisée     */
/*                                                                */
/* En entrée :  file (file_t *) : file à vider                    */
/*              valeur (type)   : élément défilée                 */
/*                                                                */
/* En sortie :  codeErreur (int) booléen : 2 si erreur, 0 sinon   */
/* -------------------------------------------------------------- */
int Defiler (file_t *, type *);

/* --------------------------------------------------------------------- */
/* RedimensionerFile    Redimensionne la base de la file                 */
/*                                                                       */
/* En entrée : file (file_t *) : file a redimensionner                   */
/*             nvCapacité (int) : taille que la nouvelle base doit avoir */
/*                                                                       */
/* En sortie : codeErreur (int) booléen : 1 si le redimensionnement      */
/*                                  n'a pas pu être fait, 0 sinon        */
/* --------------------------------------------------------------------- */
int RedimensionnerFile (file_t *, int);

/* ------------------------------------------------------------------ */
/* CpyBlocMem       Copy le bloc mémoire d'adresse de debut "deb"     */
/*                   et d'adresse de fin "fin" à l'adresse "dest"     */
/*                                                                    */
/* En entrée : deb (int *) : adresse du debut du boc mémoire a copier */
/*             fin (int *) : adresse de fin du bloc mémoire a copier  */
/*             dest (int *) : adresse ou l'on copy le bloc mémoire    */
/*                                                                    */
/* En sortie : void                                                   */
/* ------------------------------------------------------------------ */
void CpyBlocMem (type *, type *, type *);

/* --------------------------------------------------------- */
/* LibererFile  Libère la mémoire utilisée par la file       */
/*                                                           */
/* En entrée :  file (file_t *) : File à libérer             */
/*                                                           */
/* En sortie :  void                                         */
/* --------------------------------------------------------- */
void LibererFile (file_t *);

/* ----------------------------------------------------------------------------------------- */
/* AfficherFile     Affiche le file                                                          */
/*                                                                                           */
/* En entrée : file (file_t *) : file a afficher                                             */
/*             pfAfficher (void (*)(type)) : pointeur sur la fonction qui affiche un élément */
/*                                                                                           */
/* En sortie : void                                                                          */
/* ----------------------------------------------------------------------------------------- */
void AfficherFile (file_t *, void (*) (type));


/* --------------------------------------------------- */
/* AfficherFileInt      Affiche un élément de type int */
/*                                                     */
/* En entrée : nombre (int) : nombre a afficher        */
/*                                                     */
/* En sortie : void                                    */
/* --------------------------------------------------- */
void AfficherFileInt (int);

/* ---------------------------------------------------- */
/* AfficherFileChar      Affiche un élément de type char */
/*                                                      */
/* En entrée : caractere (char) : carectere a afficher  */
/*                                                      */
/* En sortie : void                                     */
/* ---------------------------------------------------- */
void AfficherFileChar (char);

/* --------------------------------------------------------------------------- */
/* AfficherFileChaineCarac      Affiche un élément de type chaine de caractère */
/*                                                                             */
/* En entrée : chaine (char *) : chaine a afficher                             */
/*                                                                             */
/* En sortie : void                                                            */
/* --------------------------------------------------------------------------- */
void AfficherFileChaineCarac (char *);

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
char * AfficherFileDansChaine (file_t *, void (*) (type, char *), int);


/* ---------------------------------------------------------------------- */
/* AfficherFileIntDansChaine      Affiche un élément de type int          */
/*                                 dans une chaine de caractère           */
/*                                                                        */
/* En entrée : nombre (int)    : nombre a afficher                        */
/*             chaine (char *) : chaine dans lequel on afficher le nombre */
/*                                                                        */
/* En sortie : void                                                       */
/* ---------------------------------------------------------------------- */
void AfficherFileIntDansChaine(int, char *);

/* -------------------------------------------------------------------------- */
/* AfficherFileCharDansChaine      Affiche un élément de type char            */
/*                                 dans une chaine de caractère               */
/*                                                                            */
/* En entrée : caractere (char) : caractère a afficher                        */
/*             chaine (char *)  : chaine dans lequel on afficher le caractere */
/*                                                                            */
/* En sortie : void                                                           */
/* -------------------------------------------------------------------------- */
void AfficherFileCharDansChaine(char, char *);

#endif