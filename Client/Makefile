CC = gcc
OBJ = Client

all: $(OBJ)

Client: Client.o 
	$(CC) -o $(OBJ) Client.o 

Client.o: Client.c ../Common/headers/Client.h
	$(CC) -Wall -c Client.c

clean:
	@echo "on efface les fichiers objets"
	rm -f *.o $(OBJ)

