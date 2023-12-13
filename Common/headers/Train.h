/*Importation des librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../headers/Time.h"
#include "../headers/Requete.h"

/*Definition des constantes*/

#define TAILLE 128
#define VIRG ";"
#ifdef _WIN32
    #define PATH "D:/Université/Système et réseaux/Systeme/Gros projet/ProjetSyst_ABE/doc/Trains.txt"
#elif __unix__
    #define PATH "/mnt/d/Trains.txt"
#endif

/*Definition des Structure du programme*/

struct Train{
    int id;
    char depart[50];
    char arrive[50];
    struct temps heureD;
    struct temps heureA;
    double prix;
    char RS[5];
};

/*Definition des fonctions*/

struct Train * stockageTrain();
/*****************************************
 * Enregistre la liste des trains
 * disponibles avec toutes les informations
 *****************************************/

int Trlen(struct Train *);
/*****************************************
 * Renvoie la longueur d'une chaine ou
 * d'un tableau de train
 *****************************************/

struct Train * bestTrain(struct Train * C, int choix);
/*****************************************
 * Affiche la liste organisée en fonction
 * du prix ou du temps optimale demandée
 * par le client
 *****************************************/

struct Train findTrain(struct Train * C, char ** D);
/*****************************************
 * Retourne le train correspondant aux
 * critères de l'utilisateur
 * La ville de depart
 * La ville d'arrivée
 * L'heure de départ
 *****************************************/

struct Train * findLTrain(struct Train * C, char ** D);
/*****************************************
 * Affiche la liste de trains satisfaisant
 * la plage horaire demandée par le client
 *****************************************/

struct Train * findAllTrain(struct Train * C, char ** D);
/*****************************************
 * Affiche la liste de train satisfaisant
 * La ville de départ et la ville d'arrivée
 * donnée par le client
 *****************************************/

char * RS(struct Train C);
/*****************************************
 * Affiche la reduction ou supplement
 * du train si il y en a un
 *****************************************/

char * affTrain(struct Train C);
/*****************************************
 * Affiche l'ensemble des informations
 * d'un train
 *****************************************/

char * affLTrain(struct Train * C);
/*****************************************
 * Affiche la liste de train dans un format
 * agréable à lire
 *****************************************/

void delSTrain(struct Train * C);
/*****************************************
 * Efface le tableau de train alloué en
 * mémoire
 *****************************************/

void delDTrain(struct Train ** C);
/*****************************************
 * Efface le tableau de train alloué en
 * mémoire
 *****************************************/