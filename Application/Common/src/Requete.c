#include "../headers/Requete.h"

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

void decoupage(char * C, char ** D){
    int i = 0;
    char * Paris;
    char *token;
    token = strtok(C, SPACE);
    while(token != NULL){
        D[i] = (char*)malloc(sizeof(char) * ALLOC);
        if (strcmp(token, "Paris") == 0){
            strcpy(D[i], token);
            token = strtok(NULL, SPACE);
            while(strcmp(token, "Lyon") != 0){
                token = strtok(NULL, SPACE);
            }
            token = strtok(NULL, SPACE);
            i++;
        }else{
            strcpy(D[i], token);
            token = strtok(NULL, SPACE);
            i++;
        }
    }
    D[i] = (char *)malloc(sizeof(char) * ALLOC);
    strcpy(D[i], "FIN");
}

void ecrire(char * C){
    int i = (strlen(C) - 1);
    C[i] = '\0';
}

void delST(char * C){
    free(C);
    C = NULL;
}

int correct(char ** D, int fct){
    int i = 0;
    switch(fct){
        case 1: //Depart/Arrive/HD
            while(i != 3){
                if (strcmp(D[i], "FIN") == 0){
                    fprintf(stderr, "\033[31mErreur dans la requete, retaper la commande !\033[37m\n");
                    return -1;
                    break;
                }
                i++;
            }
            return 0;
            break;
        case 2: //Depart/Arrive/plage horaire
            while(i != 4){
                if (strcmp(D[i], "FIN") == 0){
                    fprintf(stderr, "\033[31mErreur dans la requete, retaper la commande !\033[37m\n");
                    return -1;
                    break;
                }
                i++;
            }
            return 0;
            break;
        case 3: //Depart/Arrive
            while(i != 2){
                if (strcmp(D[i], "FIN") == 0){
                    fprintf(stderr, "\033[31mErreur dans la requete, retaper la commande !\033[37m\n");
                    return -1;
                    break;
                }
                i++;
            }
            return 0;
        default:
            fprintf(stderr, "\033[31mErreur dans la lecture du choix !\033[37m\n");
            return -1;
            break;
    }
}

int correctC(int choix){
    if(choix != 1 && choix != 2){
        fprintf(stderr, "\033[31mErreur de choix ! Retapez la commande !\033[37m\n");
        return -1;
    }else{
        return 0;
    }
}
