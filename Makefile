
all:  
	make serveur
	make client

client: 
	cd Client;make Client
	
serveur: 
	cd Serveur;make Serveur

	
clean:
	cd Serveur;make clean
	cd Client;make clean
	@echo "on efface les fichiers objets"
	rm -f ./a.out
	
	



