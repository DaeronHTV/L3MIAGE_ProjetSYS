#include "./../Common/headers/Serveur.h"

#define SIZEMAX 1024
int socketS, descripeur,echange,menu;
char tampon[1024];
pid_t childpid;
socklen_t addr_size;
struct sockaddr_in servAddr;
struct sockaddr_in autreAdd;
char **requete;
struct Train* table;


	int createSocket(){
		//On instancie la socket client.
		socketS = socket(AF_INET,SOCK_STREAM,0);
		//Catch d'erreur.
		if(socketS < 0){
			printf("ERROR creation socket\n");
			return 1;
		}
		//Création de la socket serveur dans la mémoire. On instancie la famille et le port du serveur.
	    servAddr.sin_family = AF_INET;
	   	servAddr.sin_port = htons(PORT); //doit être supérieur à 1024
		//Formatage des adresses, afin d'être pret a reçevoir n'importe quel client (ANY ADDR).
	   	servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //pour l'adresse IP
		//Instanciation de la taille du serveur.
		puts("Socket created");
		return 0;
	}
	
	int bindSocket(){
		//Bind du serveur a la socket.
	    	descripeur = bind(socketS, (struct sockaddr*)&servAddr, sizeof(servAddr)); //etablir une connexion avec le client	
		//Catch d'erreur.	
		if(descripeur == SOCKET_ERROR){// gestion des problèmes de liaison
			printf("Erreur de liaison\n");
			exit(1);
	    	}
    	printf("Serveur lié au port %d\n", PORT);
	return 0;
	} 
	
	int listenSocket(){
		//Mise du serveur en état passif listen.
		if(listen(socketS, 5) == 0){  //mise en place du socket dans un état d'écoute 
        		printf("Serveur en attente de connexion...\n");
    		}else{
        		printf("Erreur\n");
    		}
		return 0;
	}

    int acceptSocket(){	
			echange = accept(socketS,(struct sockaddr*)&servAddr, &addr_size); //echange represente la socket client
			if(echange == SOCKET_ERROR){
		   		 exit(1);
			}
			printf("Connexion accepté de %s sur le port %d\n", inet_ntoa(servAddr.sin_addr), ntohs(servAddr.sin_port));
		return 0;
		}
	
	void closeSocket(){
	//Fermeture de la socket serveur.
	close(socketS);
	}


	
	
	int main(int argc, char* argv[]){

		createSocket();
		bindSocket();
		listenSocket();
		table = stockageTrain();
		if (table[0].id == 1010101){
			exit(1);
		}
		while(1){
			acceptSocket();
			if((childpid = fork()) == 0){
				close(socketS);
			    while(1){
					int nb = read(echange, tampon, SIZEMAX);
					if(nb <= 0){
						printf("Deconnexion de %s sur le port %d\n", inet_ntoa(servAddr.sin_addr), ntohs(servAddr.sin_port));
						exit(1);
					}else{ 
						menu = atoi(tampon);
						char* reponse = (char*)malloc(sizeof(char)*128);
						struct Train *V;
						switch(menu){
							case 1:								
								requete = (char**)malloc(sizeof(char*)*64);
					    		write(echange, "A", strlen(tampon));
					    		bzero(tampon, sizeof(tampon));
					    		read(echange, tampon, SIZEMAX);
					    		printf("%s\n",tampon);
					    		decoupage(tampon,requete);
					    		struct Train T = findTrain(table,requete);	
					    		reponse = affTrain(T);
					    		printf("%s",reponse);
					    		if (T.id != 1010101 && strcmp(T.depart, requete[0]) == 0){
					    			write(echange,reponse, strlen(reponse));
					    		}else if (T.id != 1010101 && strcmp(T.depart, requete[0]) != 0){
					    			char * indication = (char *)malloc(sizeof(char)*128);
					    			indication = strcpy(indication, "Un trajet avec un depart different correspond\n");
					    			indication = strcat(indication, reponse);
					    			write(echange, reponse, strlen(reponse));
					    		}else{
					    			char * erreur = (char*)malloc(sizeof(char)*128);
					    			erreur = strcpy(erreur, "Aucun trajet ne correspond a vos horaires !\n");
					    			printf("%s\n", erreur);
					    			write(echange, erreur, strlen(erreur));
					    		}
								free(reponse);
								reponse = NULL;
								break;
							case 2:
						     	requete = (char**)malloc(sizeof(char*)*64);
					    		write(echange, "B", strlen(tampon));
					    		bzero(tampon, sizeof(tampon));
					    		read(echange, tampon, SIZEMAX);
					    		printf("%s\n", tampon);
					    		decoupage(tampon,requete);
					    		V = findLTrain(table,requete);
					    		reponse = affLTrain(V);
					    		printf("%d", Trlen(V));
								if (V[1].id == 1010101){
									char * erreur = (char*)malloc(sizeof(char)*128);
									erreur = strcpy(erreur, "Aucun trajet disponible\n");
									write(echange, erreur, strlen(erreur));	
								}else{
									printf("%s\n", reponse);
									write(echange, reponse,strlen(reponse));
								}
								free(reponse);
								reponse = NULL;
								break;
						    case 3:
						      	requete = (char**)malloc(sizeof(char*)*200);
					    		write(echange, "C", strlen(tampon));
					    		bzero(tampon, sizeof(tampon));
					    		read(echange, tampon, SIZEMAX);
						   		printf("%s", tampon);
					    		ecrire(tampon);
					    		decoupage(tampon,requete);
					    		V = findAllTrain(table,requete);
					    		reponse = affLTrain(V);
					    		printf("%s",reponse);
					    		write(echange,reponse, strlen(reponse));
					    		free(reponse);
					    		reponse = NULL;
								break;
							case 4:
								write(echange, "L", strlen(tampon));
								bzero(tampon, sizeof(tampon));
								reponse = affLTrain(table);
								printf("%s\n", reponse);
								write(echange, reponse, strlen(reponse));
								break;
						    case 5:
					    		write(echange, "D", strlen(tampon)); 
					    		bzero(tampon, sizeof(tampon)); 
						    	break;  
						    default:
					    		write(echange, "E", strlen(tampon)); // envoi message
					    		bzero(tampon, sizeof(tampon)); //vider le tampon
						    	break;
						}
						if (menu == 3){
							bzero(tampon, sizeof(tampon));
					    	read(echange, tampon, SIZEMAX);
							printf("%s\n", tampon);
							int choix = atoi(tampon);
							reponse = (char*)malloc(sizeof(char)*200);
							switch(choix){
								case 1:
										V = bestTrain(V,1);
										reponse = affLTrain(V);
										printf("%s\n", reponse);
										write(echange,reponse, strlen(reponse));
									break;
								case 2:
										V = bestTrain(V, 2);
										reponse = affLTrain(V);
										printf("%s\n", reponse);
										write(echange,reponse, strlen(reponse));
									break;
								default:
									write(echange, "E", strlen(tampon)); // envoi message
					    			bzero(tampon, sizeof(tampon)); //vider le tampon
									break;
							}
						}else{
							write(echange, NULL, strlen(tampon));
							bzero(tampon, sizeof(tampon));
						}
					}
				}
			}
		}	
	close(echange);
	return 0;
}
