# compilateur
CC = gcc
# options de compilation
CFLAGS = -Wall -Wextra -pedantic -ansi -g

#liste des fichiers objets
OBJ = fonctions.o enigma.o

all : enigma clean


fonctions.o: fonctions.h fonctions.c
	$(CC) -c fonctions.c $(CFLAGS)


enigma : $(OBJ)
	$(CC) enigma.o fonctions.o -o  enigma  $(CFLAGS)

enigma.o : enigma.c fonctions.h fonctions.c
	$(CC) -c enigma.c  $(CFLAGS)


clean:
	rm -f *.o core
