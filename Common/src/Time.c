#include "../headers/Time.h"

/******************************************************************
 * Requete.c contient l'ensemble des fonctions permettant la 
 * recherche des réponses attendus par le client en fonction de la
 * requete envoyée par ce dernier
 *
 * Pour le path du fichier Train.txt veuillez modifier en
 * conséquence ceux donnés en paramètre pour correspondre au votre
 * Le PATHLA n'est pas à utiliser, il s'agit du path de mon linux
 * sur windows 10
 ******************************************************************/

/**************************************/
/*******Fonction du programme*********/
/************************************/

int sameT(struct temps A, struct temps B){
    if ((A.minutes - B.minutes)==0 && (A.heure - B.heure)==0){
        return 0;
    }else{
        return -1;
    }
}

int diffH(struct temps A, struct temps B){
    int diff = A.heure - B.heure;
    return diff;
}

int diffM(struct temps A, struct temps B){
    int diff = A.minutes - B.minutes;
    return diff;
}

struct temps ctot(char * C){
    struct temps time;
    char * token;
    token = strtok(C, ":");
    time.heure = atoi(token);
    token = strtok(NULL, ":");
    time.minutes = atoi(token);
    return time;
}

char * affTemps(struct temps A){
	char temps[200];
    char * time = (char*)malloc(sizeof(char)*20);
    sprintf(temps,"%d:%d", A.heure, A.minutes);
    return time;
}
