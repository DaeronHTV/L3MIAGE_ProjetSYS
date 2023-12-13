#define TAILLE 128
#define COMA ";"
//Fichiers de train
#ifdef _WIN32
   #define PATH "D:/Université/Système et réseaux/Systeme/Gros projet/ProjetSyst_ABE/doc/Trains.txt"
#elif __unix__
   #define PATH "/mnt/d/Trains.txt"
#elif __linux__
   #define PATH "/ext/avanzina/Documents/Projet/ProjetSyst_ABE/doc/Trains.txt"
#endif
//Config Serveur
#define PORTSERVEUR 7777
#define SOCKET_ERROR -1
#define MAX 50
//Config requete
#define CHARN '\0'
#define SPACE " "
#define ALLOC 64
#define TEMPS 1024