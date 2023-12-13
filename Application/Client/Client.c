#include "./../Common/headers/Client.h"


#define TAILLE 1024
#define PORT 7777
#define SOCKET_ERROR -1
struct sockaddr_in client;
struct hostent *host; //récupération des informations relatives à cette machine 
char tampon[1024]; //stock les messages
int connexion,menu;

	int createSocketClient(){

		//On instancie la socket client.
		connexion = socket(AF_INET, SOCK_STREAM, 0);
		//Catch d'erreur.
		if(connexion==-1){
			printf("ERROR creation socket\n");
			return 1;
		}
		//Création de la socket client dans la mémoire. On instancie la famille et le port du client.
		client.sin_family = AF_INET;
		client.sin_port = htons(PORT);
		client.sin_addr.s_addr = htonl(INADDR_ANY); //pour l'adresse IP
		//On recupère le domaine.
		host=gethostbyname("localhost");
		//Copie de l'adresse domaine, dans l'adresse de la structure client.
		memcpy(&client.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
		puts("Socket created");
		return 0;
	}

	int connectSocket(){
	
		if(connexion == SOCKET_ERROR){
			printf("Erreur de connexion.\n");
		}else{
			printf("Client en ligne\n");
		}

	    if(connect(connexion, (struct sockaddr *)&client, sizeof(client)) != SOCKET_ERROR){
			printf("Connexion à %s sur le port %d\n", inet_ntoa(client.sin_addr), htons(client.sin_port));
	     	}else{
			printf("Impossible de se connecter\n");
			exit(1);
		}
	return 0;
	}

	int main(int argc, char* argv[]){
		createSocketClient();
		connectSocket();
		while(1){
			printf("---------------------------------------------------------------------------\n");
			printf("\t\t\t\t  Bonjour !\n");
			printf(" Selectionnez votre demande en entrant le numéro correspondant ci-dessous :\n");
			printf("1.Afficher le premier train allant d'un point A à un point B\n");
			printf("2.Afficher une liste de train allant d'un point A à un point B selon une plage horaire\n");
			printf("3.Afficher tout les trains d'aujourd'hui d'un point A à un point B\n");
			printf("4.Afficher l'ensemble des trajets disponibles\n");
			printf("5.Quitter\n");
			printf("---------------------------------------------------------------------------\n");
			printf("Client: ");
			fgets(tampon,TAILLE,stdin);
			write(connexion, tampon, strlen(tampon));
			char* reponse = (char*)malloc(sizeof(char)*128);
			int rd = read(connexion, tampon, TAILLE);
			int triage = 0;
			if(rd == SOCKET_ERROR){
			    printf("Fin programme\n");
			    exit(1);
			}
			if(strcmp (tampon,"E")==0){
				printf("\033[31mVeuillez entrer un chiffre entre 1 et 5 selon les choix ci dessus\n\033[37m");
			}
			if(strcmp (tampon,"A")==0){
				bzero(tampon, sizeof(tampon));
				printf("\033[37mEntrez la ville de départ, la ville d'arrivée, et l'heure de départ, sous le format 'DDDD AAAA HH:MM'\n\n");
				fgets(tampon,TAILLE,stdin);
				write(connexion, tampon, strlen(tampon));
				printf("------------------------------------\n");
				printf("Resultat de la commande\n");
				printf("------------------------------------\n");
				read(connexion, reponse, TAILLE);
				if(strcmp(tampon,"F")==0){
					printf("\033[31mVeuillez entrer les informations dans le bon format\n\033[37m");
					exit(1);
				}
				printf("\n");
				printf("\033[33m%s\033[37m",reponse);
			}
			if(strcmp (tampon,"B")==0){
				bzero(tampon, sizeof(tampon));
				printf("\033[37mEntrez la ville de départ, la ville d'arrivée, l'heure de départ,et l'heure d'arrivée, sous le format 'DDDD AAAA HH:MM HH:MM'\n\n");
				fgets(tampon,TAILLE,stdin);
				write(connexion, tampon, strlen(tampon));
				printf("------------------------------------\n");
				printf("Resultat de la commande :\n");
				printf("------------------------------------\n");
				read(connexion, reponse, TAILLE);
				printf("\033[33m%s\033[37m",reponse);
	free(reponse);
	reponse = NULL;
			}			
			if(strcmp (tampon,"C")==0){
				bzero(tampon, sizeof(tampon));
				printf("\033[37mEntrez la ville de départ, la ville d'arrivée, sous le format 'DDDD AAAA'\n\n");
				fgets(tampon,TAILLE,stdin);
				write(connexion, tampon, strlen(tampon));
				printf("------------------------------------\n");
				printf("Resultat de la commande\n");
				printf("------------------------------------\n");
				read(connexion, reponse, TAILLE);
				printf("\033[33m%s\033[37m",reponse);
				triage = 1;
	free(reponse);
	reponse = NULL;
			}
			if(strcmp (tampon,"D")==0){
				printf("\033[31mMerci d'avoir utiliser ABE SNCF\n\033[37m");
				exit(1);
			}
			if (strcmp(tampon, "L")==0){
				bzero(tampon, sizeof(tampon));
				read(connexion, reponse, TAILLE);
				printf("%s\n", reponse);
			}
			if (triage == 1){
			char * reponse = (char*)malloc(sizeof(char)*128);
				char test[500];
				printf("---------------------------------\n");
				printf("Souhaitez-vous trier ce résultat ? :\n");
				printf("---------------------------------\n");
				printf("1. Dans l'ordre des prix attractif\n");
				printf("2. Dans l'heure des départ\n");
				printf("---------------------------------\n");
				fgets(tampon,TAILLE,stdin);
				write(connexion, tampon, strlen(tampon));
				int test2 =read(connexion, test, TAILLE);
				printf("\n");
				printf("\033[33m%s\033[37m",test);
				bzero(test, sizeof(test));
			free(reponse);
			reponse = NULL;

			}
			
		 }
    		return 0;
	}




