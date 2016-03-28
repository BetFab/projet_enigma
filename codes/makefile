# compilateur
CC = gcc
# options de compilation
CFLAGS = -Wall -Wextra -pedantic -ansi -g

#liste des fichiers objets
OBJ = fonctions.o chiffrage.o

all : chiffrage correcteur enigma clean

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

enigma : enigma.o fonctions.o
	$(CC) enigma.o fonctions.o -o  enigma  $(CFLAGS)

enigma.o : enigma.c fonctions.h fonctions.c
	$(CC) -c enigma.c  $(CFLAGS)


clean:
	rm -f *.o core
