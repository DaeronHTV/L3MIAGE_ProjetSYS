CC = gcc
OBJ = Serveur


all: $(OBJ)

$(OBJ): Serveur.o Train.o Requete.o Time.o 
	$(CC) -o Serveur Serveur.o Train.o Requete.o Time.o 

Serveur.o: Serveur.c ../Common/headers/Serveur.h
	$(CC) -Wall -c Serveur.c

Train.o: ../Common/src/Train.c ../Common/headers/Train.h
	$(CC) -Wall -c ../Common/src/Train.c 
	
Requete.o: ../Common/src/Requete.c ../Common/headers/Requete.h
	$(CC) -Wall -c ../Common/src/Requete.c 
	
	
Time.o: ../Common/src/Time.c ../Common/headers/Time.h
	$(CC) -Wall -c ../Common/src/Time.c 
	
clean:
	@echo "on efface les fichiers objets"
	rm -f *.o $(OBJ)

