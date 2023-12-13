#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <netdb.h>
#include "../headers/Train.h"
#include "../Config/Config.h"
/** Header du fichier serveur:
 * 
 * L'attribut MAX est initialisé a 50 et sera utilisé dans les fonctions read et write.
 */


/** Méthode :
* createSocket est la méthode permettant de créer la socket du serveur.
*/
int createSocket();



/** Méthode :
* bindSocket est la méthode permettant de bind la socket du serveur.
*/
int bindSocket();


/** Méthode :
* listenSocket est la méthode permettant au serveur de rester passif et d'attendre les connections Client.
*/
int listenSocket();


/** Méthode :
* acceptSocket est la méthode permettant au serveur de traiter la requète du client actuel.
*/
int acceptSocket();

