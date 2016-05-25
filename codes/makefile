# compilateur
CC = gcc
# options de compilation
CFLAGS = -Wall -Wextra -pedantic -ansi -g

#liste des fichiers objets
OBJ = fonctions.o enigma.o

all :  enigma decodage correcteur clean

fonctions.o: fonctions.h fonctions.c
	$(CC) -c fonctions.c $(CFLAGS)

enigma : $(OBJ)
	$(CC) enigma.o fonctions.o -o  enigma  $(CFLAGS)

enigma.o : enigma.c fonctions.h fonctions.c
	$(CC) -c enigma.c  $(CFLAGS)

decodage : decodage.o fonctions.o
	$(CC) decodage.o fonctions.o -o decodage $(CFLAGS)

decodage.o : decodage.c fonctions.h fonctions.c
	$(CC) -c decodage.c $(CFLAGS)

correcteur: correcteur.o
	$(CC) correcteur.o -o  correcteur  $(CFLAGS)

correcteur.o: correcteur.c
	$(CC) -c correcteur.c $(CFLAGS)

clean:
	rm -f *.o core
