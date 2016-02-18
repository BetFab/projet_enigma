CC = gcc
CFLAGS = -Wall -Wextra -pedantic -ansi


all : chiffrage

chiffrage: chiffrage.o fonctions.o
	$(CC) -o

fonctions.o: fonctions.h fonctions.c
	$(CC) $(CFLAGS)

chiffrage.o: chiffrage.c
	$(CC) $(CFLAGS)

clean:
	rm -f *.o core
mrproper: clean
	rm -f chiffrage
