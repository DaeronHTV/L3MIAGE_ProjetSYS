#include "../Common/headers/Tests/Testrequete.h"
#include "../Common/headers/Requete.h"

/******************************************************************
 * Testrequete.c contient l'ensemble des fonctions permettant le
 * test des fonctions du fichier Requete.c
 ******************************************************************/

/**************************************/
/*********Fonction de test************/
/************************************/

int testDecoupage(char C[]){
    char * testCom = (char*)malloc(sizeof(char) * TAILLE);
    char ** testRequete = (char**)malloc(sizeof(char) * TAILLE);
    strcpy(testCom, C);
    decoupage(testCom, testRequete);
    return 0;
}

/*void testEcrire(){
    printf("Test de la fonction Ecrire\n");
}

void testLecture(){
    printf("Test de la fonction Lecture\n");
}*/

/**************************************/
/*********Main du programme***********/
/************************************/

int main(int argc, char const *argv[]){
    printf("Lancement des tests requetes : ");
    testDecoupage("bonjour ceci est un test");
    /*testEcrire();
    testLecture();*/
}