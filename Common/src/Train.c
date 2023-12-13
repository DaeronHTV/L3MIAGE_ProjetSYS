#include "../headers/Train.h"

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


struct Train * stockageTrain(){
    struct Train * C;
    FILE *file = fopen (PATH, "r" );
    char line [1024];
    int i = 0;
    if (file != NULL){
        while(fgets(line, sizeof line, file) != NULL){
            i++;
        }
        i++;
    }
    fclose(file);
    C = (struct Train *)malloc(sizeof(struct Train) * i);
    file = fopen(PATH, "r");
    if (file != NULL){
        i = 0;
        char line [1024];
        while (fgets (line, sizeof line, file) != NULL){
            int j = 0;
            char *token;
            token = strtok(line, VIRG);
            while(token != NULL){
                switch(j){
                    case 0:
                        C[i].id = atoi(token);
                        token = strtok(NULL, VIRG);
                        break;
                    case 1:
                        strcpy(C[i].depart, token);
                        token = strtok(NULL, VIRG);
                        break;
                    case 2:
                        strcpy(C[i].arrive, token);
                        break;
                    case 3:
                        token = strtok(NULL, ":");
                        C[i].heureD.heure = atoi(token);
                        token = strtok(NULL, VIRG);
                        C[i].heureD.minutes = atoi(token);
                    case 4:
                        token = strtok(NULL, ":"); 
                        C[i].heureA.heure = atoi(token);  
                        token = strtok(NULL, VIRG);
                        C[i].heureA.minutes = atoi(token);
                    case 5:
                        token = strtok(NULL, VIRG);
                        C[i].prix = atof(token);
                    case 6:
                        token = strtok(NULL, VIRG);
                        strcpy(C[i].RS, token);
                        if (strcmp(C[i].RS, "REDUC\n") == 0){
                            strcpy(C[i].RS, "REDUC");
                        }else if (strcmp(C[i].RS, "SUPPL\n") == 0){
                            strcpy(C[i].RS, "SUPPL");
                        }
                        token = strtok(NULL, VIRG);
                    default:
                        break;
                }
                j++;
            }
            i++;
        }
        C[i+1].id = 1010101;
        fclose(file);
        return C;
    }else{
        fprintf(stderr, "Chargement des trajets impossibles !\n");
        C = (struct Train *)malloc(sizeof(struct Train) * 1);
        C[0].id = 1010101;
        return C;
    }
}

void delSTrain(struct Train * C){
    free(C);
    C = NULL;
}

int Trlen(struct Train * C){
    int i = 0;
    if(C != NULL){
        while(C[i].id != 1010101){
            i++;
        }
        return i-1;
    }else{
        return 0;
    }
}
struct Train * bestTrain(struct Train * C, int choix){
    struct Train * list = (struct Train *)malloc(sizeof(struct Train)*Trlen(C));
    int table[25];
    struct Train A;
    struct Train B;
    int i = 0;
    int j = 0;
    int t = 0;
    switch(choix){
        case 1: //En fonction du prix
            A = C[i];
            B = C[i+1];
retour:
            while(i != Trlen(C)){
                if (A.prix < B.prix){
                    if (j == 0){
                        table[j] = i;
                        j++;
                    }
                    i++;
                    B = C[i];
                }else if (A.prix > B.prix){
                    A = B;
                    i++;
                    B = C[i];
                    j = 0;
                    goto vidage;
                }else{
                    table[j] = i;
                    j++;
                    A = B;
                    i++;
                    B = C[i];
                }
            }
            break;
        case 2: //En fonction de la durée
            A = C[i];
            B = C[i+1];
retourner:
            while(i != Trlen(C)){
                if (diffH(A.heureD,B.heureD) < 0){
                    if (j == 0){
                        table[j] = i;
                        j++;
                        //printf("%d\n", j);
                    }
                    i++;
                    B = C[i];
                }else if(diffH(A.heureD,B.heureD) > 0){
                    A = B;
                    i++;
                    B = C[i];
                    j = 0;
                    goto vidage;
                }else{
                    if (diffM(A.heureD, B.heureD) < 0){
                        if (j == 0){
                            table[j] = i;
                            j++;
                            //printf("%d\n", j);
                        }
                        i++;
                        B = C[i];
                    }else if (diffM(A.heureD, B.heureD) > 0){
                        A = B;
                        i++;
                        B = C[i];
                        j = 0;
                        goto vidage;
                    }else{
                        table[j] = i;
                        j++;
                        A = B;
                        i++;
                        B = C[i];
                    }
                }
            }
            break;
        default:
            fprintf(stderr, "\033[31mErreur dans le choix demandé !\033[37m\n");
            break;
    }
    int m = 0;
    while(m != j){
        list[m].id = C[table[m]].id;
        strcpy(list[m].depart, C[table[m]].depart);
        strcpy(list[m].arrive, C[table[m]].arrive);
        list[m].heureD.heure = C[table[m]].heureD.heure;
        list[m].heureD.minutes = C[table[m]].heureD.minutes;
        list[m].heureA.heure = C[table[m]].heureA.heure;
        list[m].heureA.minutes = C[table[m]].heureA.minutes;
        list[m].prix = C[table[m]].prix;
        strcpy(list[m].RS, C[table[m]].RS);
        m++;
    }
    list[m+1].id = 1010101;
    free(C);
    C = NULL;
    return list;
vidage:
    while(t != 25){
        table[t] = 0;
        t++;
    }
    if (choix == 1){
        goto retour;
    }else{
        goto retourner;
    }
}

struct Train findTrain(struct Train * C, char ** D){
    int i = 0;
    struct Train solution;
    solution.id = 1010101;
    struct temps Tclient;
    char *token;
    token = strtok(D[2], ":");
    Tclient.heure = atoi(token);
    token = strtok(NULL, ":");
    Tclient.minutes = atoi(token);
    while(i != (Trlen(C)-1)){
        if (strcmp(D[0], "Paris") == 0){
            strcpy(D[0], "Paris Gare de Lyon");
        }
        if (strcmp(D[1], "Paris") == 0){
            strcpy(D[1], "Paris Gare de Lyon");
        }
        if(strcmp(C[i].depart, D[0]) == 0){
            if(sameT(Tclient, C[i].heureD) == 0){
                if(strcmp(C[i].arrive, D[1]) == 0){
                    solution = C[i];
                    return solution;
                }
            }
        }else{
            if(strcmp(C[i].arrive, D[1]) == 0){
                if(sameT(Tclient, C[i].heureD) == 0){
                    solution = C[i];
                }
            }
        }
        i++;
    }
    if(solution.id == 1010101){
        printf("\033[31mAucun trajet ne correspond a horaires !\n");
        return solution;
    }
    return solution;
}

struct Train * findLTrain(struct Train * C, char ** D){
    struct Train * list = (struct Train *)malloc(sizeof(struct Train)*Trlen(C));
    struct Train * list2 = (struct Train *)malloc(sizeof(struct Train)*Trlen(C));
    int i = 0;
    int j = 0;
    struct temps debut = ctot(D[2]);
    struct temps fin = ctot(D[3]);
    while(i != Trlen(C)){
        if (strcmp(D[0], "Paris") == 0){
            strcpy(D[0], "Paris Gare de Lyon");
        }
        if (strcmp(D[1], "Paris") == 0){
            strcpy(D[1], "Paris Gare de Lyon");
        }
        if (strcmp(C[i].depart, D[0]) == 0){
            if (strcmp(C[i].arrive, D[1]) == 0){
                list[j].id = C[i].id;
                strcpy(list[j].depart, C[i].depart);
                strcpy(list[j].arrive, C[i].arrive);
                list[j].heureD.heure = C[i].heureD.heure;
                list[j].heureD.minutes = C[i].heureD.minutes;
                list[j].heureA.heure = C[i].heureA.heure;
                list[j].heureA.minutes = C[i].heureA.minutes;
                list[j].prix = C[i].prix;
                strcpy(list[j].RS, C[i].RS);
                j++;
            }
        }
        i++;
    }
    list[j+1].id = 1010101;
    i = 0;
    j = 0;
    while(i != Trlen(list)){
        if (diffH(debut, list[i].heureD) < 0){
            if (diffH(list[i].heureD, fin) < 0){
                list2[j].id = list[i].id;
                strcpy(list2[j].depart, list[i].depart);
                strcpy(list2[j].arrive, list[i].arrive);
                list2[j].heureD.heure = list[i].heureD.heure;
                list2[j].heureD.minutes = list[i].heureD.minutes;
                list2[j].heureA.heure = list[i].heureA.heure;
                list2[j].heureA.minutes = list[i].heureA.minutes;
                list2[j].prix = list[i].prix;
                strcpy(list2[j].RS, list[i].RS);
                j++;
            }else if (diffH(list[i].heureD, fin) == 0){
                if (diffM(list[i].heureD, fin) < 0){
                    list2[j].id = list[i].id;
                    strcpy(list2[j].depart, list[i].depart);
                    strcpy(list2[j].arrive, list[i].arrive);
                    list2[j].heureD.heure = list[i].heureD.heure;
                    list2[j].heureD.minutes = list[i].heureD.minutes;
                    list2[j].heureA.heure = list[i].heureA.heure;
                    list2[j].heureA.minutes = list[i].heureA.minutes;
                    list2[j].prix = list[i].prix;
                    strcpy(list2[j].RS, list[i].RS);
                    j++;    
                }else if (diffM(list[i].heureD, fin) == 0){
                    list2[j].id = list[i].id;
                    strcpy(list2[j].depart, list[i].depart);
                    strcpy(list2[j].arrive, list[i].arrive);
                    list2[j].heureD.heure = list[i].heureD.heure;
                    list2[j].heureD.minutes = list[i].heureD.minutes;
                    list2[j].heureA.heure = list[i].heureA.heure;
                    list2[j].heureA.minutes = list[i].heureA.minutes;
                    list2[j].prix = list[i].prix;
                    strcpy(list2[j].RS, list[i].RS);
                    j++;
                }
            }
        }else if (diffH(debut, list[i].heureD) == 0){
            if (diffM(debut, list[i].heureD) < 0){
                if (diffH(list[i].heureD, fin) < 0){
                    list2[j].id = list[i].id;
                    strcpy(list2[j].depart, list[i].depart);
                    strcpy(list2[j].arrive, list[i].arrive);
                    list2[j].heureD.heure = list[i].heureD.heure;
                    list2[j].heureD.minutes = list[i].heureD.minutes;
                    list2[j].heureA.heure = list[i].heureA.heure;
                    list2[j].heureA.minutes = list[i].heureA.minutes;
                    list2[j].prix = list[i].prix;
                    strcpy(list2[j].RS, list[i].RS);
                    j++; 
                }else if (diffH(list[i].heureD, fin) == 0){
                    if (diffM(list[i].heureD, fin) < 0){
                        list2[j].id = list[i].id;
                        strcpy(list2[j].depart, list[i].depart);
                        strcpy(list2[j].arrive, list[i].arrive);
                        list2[j].heureD.heure = list[i].heureD.heure;
                        list2[j].heureD.minutes = list[i].heureD.minutes;
                        list2[j].heureA.heure = list[i].heureA.heure;
                        list2[j].heureA.minutes = list[i].heureA.minutes;
                        list2[j].prix = list[i].prix;
                        strcpy(list2[j].RS, list[i].RS);
                        j++; 
                    }else if (diffM(list[i].heureD, fin) == 0){
                        list2[j].id = list[i].id;
                        strcpy(list2[j].depart, list[i].depart);
                        strcpy(list2[j].arrive, list[i].arrive);
                        list2[j].heureD.heure = list[i].heureD.heure;
                        list2[j].heureD.minutes = list[i].heureD.minutes;
                        list2[j].heureA.heure = list[i].heureA.heure;
                        list2[j].heureA.minutes = list[i].heureA.minutes;
                        list2[j].prix = list[i].prix;
                        strcpy(list2[j].RS, list[i].RS);
                        j++; 
                    }  
                }  
            }else if (diffM(debut, list[i].heureD) == 0){
                if (diffH(list[i].heureD, fin) < 0){
                    list2[j].id = list[i].id;
                    strcpy(list2[j].depart, list[i].depart);
                    strcpy(list2[j].arrive, list[i].arrive);
                    list2[j].heureD.heure = list[i].heureD.heure;
                    list2[j].heureD.minutes = list[i].heureD.minutes;
                    list2[j].heureA.heure = list[i].heureA.heure;
                    list2[j].heureA.minutes = list[i].heureA.minutes;
                    list2[j].prix = list[i].prix;
                    strcpy(list2[j].RS, list[i].RS);
                    j++; 
                }else if (diffH(list[i].heureD, fin) == 0){
                    if (diffM(list[i].heureD, fin) < 0){
                        list2[j].id = list[i].id;
                        strcpy(list2[j].depart, list[i].depart);
                        strcpy(list2[j].arrive, list[i].arrive);
                        list2[j].heureD.heure = list[i].heureD.heure;
                        list2[j].heureD.minutes = list[i].heureD.minutes;
                        list2[j].heureA.heure = list[i].heureA.heure;
                        list2[j].heureA.minutes = list[i].heureA.minutes;
                        list2[j].prix = list[i].prix;
                        strcpy(list2[j].RS, list[i].RS);
                        j++; 
                    }else if (diffM(list[i].heureD, fin) == 0){
                        list2[j].id = list[i].id;
                        strcpy(list2[j].depart, list[i].depart);
                        strcpy(list2[j].arrive, list[i].arrive);
                        list2[j].heureD.heure = list[i].heureD.heure;
                        list2[j].heureD.minutes = list[i].heureD.minutes;
                        list2[j].heureA.heure = list[i].heureA.heure;
                        list2[j].heureA.minutes = list[i].heureA.minutes;
                        list2[j].prix = list[i].prix;
                        strcpy(list2[j].RS, list[i].RS);
                        j++; 
                    }  
                }
            }
        }
        i++;
    }
    free(list);
    list = NULL;
    list2[j+1].id = 1010101;
    return list2;
}

struct Train * findAllTrain(struct Train * C, char ** D){
    struct Train * list = (struct Train *)malloc(sizeof(struct Train)*Trlen(C));
    int i = 0;
    int j = 0;
    if (strcmp(D[0], "Paris") == 0){
        strcpy(D[0], "Paris Gare de Lyon");
    }
    if (strcmp(D[1], "Paris") == 0){
        strcpy(D[1], "Paris Gare de Lyon");
    }
    while(i != Trlen(C)){
        if (strcmp(C[i].depart, D[0]) == 0){
            if (strcmp(C[i].arrive, D[1]) == 0){
                list[j].id = C[i].id;
                strcpy(list[j].depart, C[i].depart);
                strcpy(list[j].arrive, C[i].arrive);
                list[j].heureD.heure = C[i].heureD.heure;
                list[j].heureD.minutes = C[i].heureD.minutes;
                list[j].heureA.heure = C[i].heureA.heure;
                list[j].heureA.minutes = C[i].heureA.minutes;
                list[j].prix = C[i].prix;
                strcpy(list[j].RS, C[i].RS);
                j++;
            }
        }
        i++;
    }
    list[j+1].id = 1010101;
    return list;
}

char * RS(struct Train C){
	char * RS = (char*)malloc(sizeof(char)*100);
	char tampon[16];
    if(strcmp(C.RS, "SUPPL") == 0){
    	RS = strcpy(RS, "\nLe trajet a un supplement de 10% : ");
    	sprintf(tampon, "%.2f", (C.prix*1.1));
    	RS = strcat(RS, tampon);
    	RS = strcat(RS, " €\n");
    }else if(strcmp(C.RS, "REDUC") == 0){
        RS = strcpy(RS, "\nLe trajet a une reduction de 20% : ");
        sprintf(tampon, "%.2f", (C.prix*0.8));
    	RS = strcat(RS, tampon);
    	RS = strcat(RS, " €\n");
    }else{
    	RS = strcpy(RS, "\nAucun supplement/reduction sur ce trajet\n");
    }
    return RS;
}

char * affTrain(struct Train C){
    if (C.id == 1010101){
        fprintf(stderr, "Aucun train n'est enregistré actuellement !\n");
        char tampon[2048];
        char * reponse = (char*)malloc(sizeof(char)*200);
        sprintf(tampon, "%d", C.id);
        reponse = strcpy(reponse, tampon);
        return reponse;
    }else{
    	char tampon[2048];
    	char * reponse = (char*)malloc(sizeof(char)*200); 
        reponse = strcpy(reponse, "ID : ");
    	sprintf(tampon, "%d", C.id);
    	reponse = strcat(reponse, tampon);
    	reponse = strcat(reponse,"\nDepart : ");
    	reponse = strcat(reponse, C.depart);
    	reponse = strcat(reponse,"\nArrive : ");
    	reponse = strcat(reponse, C.arrive);
    	reponse = strcat(reponse,"\nHeure de départ : ");
    	sprintf(tampon, "%d", C.heureD.heure); 
    	reponse = strcat(reponse, tampon);
    	reponse = strcat(reponse,":");
    	sprintf(tampon, "%d", C.heureD.minutes);
    	reponse = strcat(reponse, tampon);
        reponse = strcat(reponse, "\nHeure d'arrivé : ");
        sprintf(tampon, "%d", C.heureA.heure);
        reponse = strcat(reponse, tampon);
    	reponse = strcat(reponse,":");
    	sprintf(tampon, "%d", C.heureA.minutes);
    	reponse = strcat(reponse, tampon);
        reponse = strcat(reponse, "\nPrix : ");
        sprintf(tampon, "%.2f €", C.prix);
        reponse = strcat(reponse, tampon);
        //reponse = strcat(reponse, " €\n");
        reponse = strcat(reponse, RS(C));
        return reponse;
    }
}

char * affLTrain(struct Train * C){
    int i = 0;
    char * res2 = (char*)malloc(sizeof (char)*300);
    res2 = strcpy(res2, "\0");
    char res[300];
    while(i != Trlen(C)){
        sprintf(res, "ID : %d\t", C[i].id);
        sprintf(res, "%sD : %s\t A : %s\t HD : %d:%d",res, C[i].depart, C[i].arrive, C[i].heureD.heure, C[i].heureD.minutes);
        sprintf(res,"%s\tHA : %d:%d",res, C[i].heureA.heure, C[i].heureA.minutes);
        sprintf(res,"%s\tPrix : %.2f €\n",res, C[i].prix);
        res2 = strcat(res2, res);
        i++;
    }
    return res2;
}
