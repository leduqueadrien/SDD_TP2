/* ---------------------------------------------------------------------------- */
/*  file.h                                                                      */
/*          Contient les déclarations des fonctions du fichiers file.c          */
/* ---------------------------------------------------------------------------- */

#ifndef FILE_H
#define FILE_H

/* ------------ */
/* Type utilisé */
/* ------------ */
typedef char type;


/* -------------------- */
/* Structure de la file */
/* -------------------- */
typedef struct file {
	int    capacite;
	int    nbElements;
	int    indexInsertion;
	int    indexSuppression;
	type * base;
}file_t;


/* --------------------------------------------------------------------- */
/* initFile     Initialise une file de taille le paramètre taille        */
/*                                                                       */
/* En entrée :  file : file_t * : File à tester                          */
/*                                                                       */
/* En sortie :  file : Pointeur sur la file (file_t *)                   */
/* --------------------------------------------------------------------- */
file_t * initFile(int);


/* --------------------------------------------------------------------- */
/* estVideFile  Indique si la file passée en paramètre est vide ou non   */
/*                                                                       */
/* En entrée :  file (file_t *) : File à tester                          */
/*                                                                       */
/* En sortie :  (char) booléen : 1 si la file est vide, 0 sinon          */
/* --------------------------------------------------------------------- */
char estVideFile(file_t *);


/* ------------------------------------------------------------------------ */
/* estPleineFile  Indique si la file passée en paramètre est pleine ou non  */
/*                                                                          */
/* En entrée :  file (file_t *) : File à tester                             */
/*                                                                          */
/* En sortie :  (char) booléen : 1 si la file est pleine, 0 sinon           */
/* ------------------------------------------------------------------------ */
char estPleineFile(file_t * file);


/* ------------------------------------------------------------------ */
/* enfiler      Enfile une valeur à la fin de la file,                */
/*                          et l'aggrandit si elle est trop petite    */
/*                                                                    */
/* En entrée :  file (file_t *) : File à remplir                      */
/*              valeur (int)    : Valeur à enfiler                    */
/*                                                                    */
/* En sortie :  codeErreur (char) booléen : 1 si erreur, 0 sinon      */
/* ------------------------------------------------------------------ */
char enfiler(file_t * file, type valeur);


/* -------------------------------------------------------------- */
/* defiler      Défile la valeur en tête de la file,              */
/*                          et la réduit si elle peu utilisée     */
/*                                                                */
/* En entrée :  file (file_t *) : File à vider                    */
/*              valeur (int)    : Valeur dépifée (par adresse)    */
/*                                                                */
/* En sortie :  codeErreur (char) booléen : 2 si erreur, 0 sinon  */
/* -------------------------------------------------------------- */
char defiler(file_t * file, type * valeur);


/* --------------------------------------------------------------------- */
/* redimensionnerFile   Redimensionne la file en copiant les valeurs     */
/*                                                                       */
/* En entrée :  file (file_t *)    : File à redimmensionner              */
/*              nouvCapacite (int) : Taille de la nouvelle file          */
/*                                                                       */
/* En sortie :  codeErreur (char) booléen : 1 si erreur, 0 sinon         */
/* --------------------------------------------------------------------- */
char redimensionnerFile(file_t * file, int nouvCapacite);


/* --------------------------------------------------------- */
/* libererFile  Libère la mémoire utilisée par la file       */
/*                                                           */
/* En entrée :  file (file_t *) : File à libérer             */
/*                                                           */
/* En sortie :  void                                         */
/* --------------------------------------------------------- */
void libererFile(file_t * file);


/* --------------------------------------------------------- */
/* afficherFile   Affiche la file passée en paramètre        */
/*                                                           */
/* En entrée :  file (file_t *) : File à afficher            */
/*              pfAfficher (void (*)(type)) : pointeur sur   */
/*                       la fonction d'affichage du bon type */
/*                                                           */
/* En sortie :  void                                         */
/* --------------------------------------------------------- */
void afficherFile(file_t * file, void (*pfAfficher) (type));


/* --------------------------------------------------------- */
/* afficherFileInt   Affiche un entier                       */
/*                                                           */
/* En entrée :  nombre (int) : int à afficher                */
/*                                                           */
/* En sortie :  void                                         */
/* --------------------------------------------------------- */
void afficherFileInt(int nombre);


/* --------------------------------------------------------- */
/* afficherFileChar   Affiche un caractère                   */
/*                                                           */
/* En entrée :  file (char) : char à afficher                */
/*                                                           */
/* En sortie :  void                                         */
/* --------------------------------------------------------- */
void afficherFileChar(char caractere);


/* --------------------------------------------------------- */
/* afficherFileChaineChar   Affiche une chaine de caractères */
/*                                                           */
/* En entrée :  chaine (char *) : Chaine à afficher          */
/*                                                           */
/* En sortie :  void                                         */
/* --------------------------------------------------------- */
void afficherFileChaineChar(char * chaine);


#endif
