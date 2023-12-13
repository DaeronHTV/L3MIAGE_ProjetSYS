#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../headers/Requete.h"
#include "../Modules/Time.h"
#include "../Structure/StructTime.h"

/**
 * Structure permettant de définir les informations d'un train
 * @param id Identifiant unique du train
 * @param depart Ville de depart du train
 * @param arrive Ville d'arrivee du train
 * @param heureD Heure de depart du train
 * @param heureA Heure d'arrive du train
 * @param prix Prix du billet de train
 * @param RS IDK
 * @author Avanzino A.
 * @version 1.0
 * @since 2019
 **/
typedef struct {
    int id;
    char depart[50];
    char arrive[50];
    struct Time heureD;
    struct Time heureA;
    double prix;
    char RS[5];
}Train;

/**
 * Enregistre la liste des trains disponibles
 * @author Avanzino A.
 * @return Un pointeur sur la liste de train
 **/
Train * stockageTrain();

/**
 * Retourne la longueur d'une liste de train
 * @param liste La liste de train
 * @author Avanzino A.
 * @return La longueur de la liste
 **/
int Trlen(Train * liste);

/**
 * Effectue un tri complet sur la liste de train en
 * fonction des paramètres du client
 * @param C La liste de train à trier
 * @param choix Choix du client pour le tri
 * @author Avanizno A.
 * @return La liste de train triee
 **/
Train * bestTrain(Train * C, int choix);

/**
 * Retourne le train correspondant a la ville de depart,
 * d'arrive et l'heure de depart renseigne par le client
 * @param C La liste ou faire la recherche
 * @param D Les criteres de recherches de l'utilisateur
 * @return Le train correspondant aux critères de recherche
 * @author Avanzino.A
 **/
Train findTrain(Train * C, char ** D);

/**
 * Retourne le train correspondant a la ville de depart,
 * d'arrive et l'heure de depart renseigne par le client
 * @param C La liste ou faire la recherche
 * @param D Les criteres de recherches de l'utilisateur
 * @return Le train correspondant aux critères de recherche
 * @author Avanzino.A
 **/
Train * findLTrain(Train * C, char ** D);

/**
 * Retourne le train correspondant a la ville de depart,
 * d'arrive renseigne par le client
 * @param C La liste ou faire la recherche
 * @param D Les criteres de recherches de l'utilisateur
 * @return Le train correspondant aux critères de recherche
 * @author Avanzino.A
 **/
Train * findAllTrain(Train * C, char ** D);

char * RS(Train C);
/*****************************************
 * Affiche la reduction ou supplement
 * du train si il y en a un
 *****************************************/

/**
 * Affiche les informations d'un train
 * @param C Le train a afficher
 * @return Les informations du train
 * @author Avanzino.A
 **/
char * affTrain(Train C);

/**
 * Affiche la liste de train dans un format 
 * agreable a lire
 * @param C La liste de train
 * @return La liste des informations des trains 
 * @author Avanzino.A
 **/
char * affLTrain(Train * C);

/**
 * Efface la liste de train alloue en memoire
 * @param C La liste de train a effacer
 * @author Avanzino.A
 **/
void delSTrain(Train * C);

/**
 * Efface le tableau de train alloue en memoire
 * @param C Le tableau de train a effacer
 * @author Avanzino.A
 **/
void delDTrain(Train ** C);