/*Importation des librairies*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include "../Config/Config.h"

/*Definition des fonctions*/

void decoupage(char * C, char ** D);
/*****************************************
 * Decoupage de la requete donnée par le
 * client et stockage de ce dernier dans
 * un double tableau de char
 *****************************************/

void lecture(char * C);
/***************************g**************
 * Processus permettant la lecture d'un
 * fichier et de son affichage sur console
 *****************************************/

void ecrire(char * C);
/*****************************************
 * Permet au client de taper sa requete
 * serveur et remplace le \n par \0 a la
 * fin de la chaine de caractères
 *****************************************/

void delST(char * C);
/*****************************************
 * Vide le tableau alloué en mémoire
 *****************************************/

int correct(char ** D, int fct);
/*****************************************
 * Vérifie si la requete demandé par
 * l'utilisateur contient bient toute les
 * informations
 *****************************************/

int correctC(int choix);
/*****************************************
 * Vérifie si le client a fait un bon choix
 * de triage
 *****************************************/