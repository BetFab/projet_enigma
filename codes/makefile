# compilateur
CC = gcc
# options de compilation
CFLAGS = -Wall -Wextra -pedantic -ansi

#liste des fichiers objets
OBJ = fonctions.o chiffrage.o

all : chiffrage correcteur clean

chiffrage : $(OBJ)
	$(CC) $(OBJ) -o chiffrage $(CFLAGS)

fonctions.o: fonctions.h fonctions.c
	$(CC) -c fonctions.c $(CFLAGS)

chiffrage.o : chiffrage.c fonctions.h fonctions.c
	$(CC) -c chiffrage.c $(CFLAGS)

correcteur : correcteur.o
	$(CC) correcteur.o -o correcteur $(CFLAGS)

correcteur.o : correcteur.c
	$(CC) -c correcteur.c $(CFLAGS)


clean:
	rm -f *.o core
