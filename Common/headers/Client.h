#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifdef _WIN32
    #define PATH "D:/Université/Système et réseaux/Systeme/Gros projet/ProjetSyst_ABE/doc/Train.txt"
#elif __unix__ 
    #define PATH "/ext/avanzina/Documents/Projet/ProjetSyst_ABE/doc/Trains.txt"
#elif __linux__
    #define PATH "/ext/avanzina/Documents/Projet/ProjectSyst_ABE/doc/Trains.txt"
#endif
/** Méthode :
* connectSocket est la méthode permettant de connecter le client ou le serveur a la socket precedemment crée pour lui.
*/
int connectSocket();

/** Méthode :
* createSocketClient est la méthode permettant de créer une socket utilisée dans connexionClient.
*les paramètres sont : -char* nom (correspond a un pointeur vers l'allocation de mémoire du nom).
*                          -int port (correspond au port de connection du serveur).
*/
int createSocketClient();
