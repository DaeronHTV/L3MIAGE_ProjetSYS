#ifndef RESEAU_H
#define RESEAU_H

int socketClient(char nomServeur[], int port);

int socketServeur(char nomClient[], int port);

#endif