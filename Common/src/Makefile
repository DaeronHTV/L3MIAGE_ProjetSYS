CC = gcc
OBJS = requete.o Reseau.o Train.o Time.o
EXEC = requete


all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o  $(EXEC) $(OBJS)

requete.o: requete.c ../headers/Requete.h 
	$(CC) -Wall -c requete.c

Reseau.o: Reseau.c ../headers/Reseau.h 
	$(CC) -Wall -c Reseau.c

Train.o: Train.c ../headers/Train.h
	$(CC) -Wall -c Train.c
	
Time.o: Time.c ../headers/Time.h
	$(CC) -Wall -c Time.c
	
clean:
	@echo "on efface les fichiers objets"
	rm -f *.o $(OBJS)
