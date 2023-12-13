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

/** 
 * Méthode permettant de connecter le client ou le 
 * serveur a la socket precedemment crée pour lui.
 * @author l3miage-ZBS
 * @version 1.0
 * @since 2020
 */
int connectSocket();

/** 
 * Méthode permettant de créer une socket utilisée dans 
 * connexionClient. 
 * @author l3miage-ZBS
 * @version 1.0
 * @since 2020
 */
int createSocketClient();
