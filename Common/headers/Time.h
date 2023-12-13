/*Importation des librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/*Definition des Structure du programme*/

struct temps{
    int heure;
    int minutes;
};

/*Definition des fonctions*/

int sameT(struct temps A, struct temps B);
/*****************************************
 * retourne 0 si les temps sont identiques
 * sinon retourne -1
 *****************************************/

int diffH(struct temps A, struct temps B);
/***************************g**************
 * retourne la difference d'heure entre
 * deux temps
 *****************************************/

int diffM(struct temps A, struct temps B);
/*****************************************
 * retour la difference de minutes entre
 * deux temps
 *****************************************/

char * affTemps(struct temps A);
/*****************************************
 * Affiche le temps dans un format correcte
 *****************************************/

struct temps ctot(char * C);
/*****************************************
 * Convertie une chaîne de caractère en
 * strcuture temps
 *****************************************/