# compilateur
CC = gcc
# options de compilation
CFLAGS = -Wall -Wextra -pedantic -ansi

#liste des fichiers objets
OBJ = fonctions.o chiffrage.o



fonctions.o: fonctions.h fonctions.c
	$(CC) -c fonctions.c $(CFLAGS)

chiffrage.o : chiffrage.c fonctions.h fonctions.c
	$(CC) -c chiffrage.c $(CFLAGS)

chiffrage : $(OBJ)
	$(CC) $(OBJ) -o chiffrage

clean:
	rm -f *.o core
