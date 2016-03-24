#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

#define DEBUG 1

/* tableau des correspondances indice de l'alphabet/lettre */
/* A B C D E F G H I J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z */
/* 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 */



int main()
{

   /* CABLAGE DES ROTORS */
   char       * rotor1 = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
   char       * rotor2 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
   char       * rotor3 = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
   char       * rotor4 = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
   char       * rotor5 = "VZBRGITYUPSDNHLXAWMJQOFECK";



   /* CABLAGE DES REFLECTEURS */
   char       * reflecteurA = "EJMZALYXVBWFCRQUONTSPIKHGD";
   char       * reflecteurB = "YRUHQSLDPXNGOKMIEBFZCWVJAT" ;

   int         choixRotors[3] = {1 , 2 , 3};
   char        positionIntialeRotors[3] = {'A' , 'A' , 'A'}; /* position des rotors */ /* choix de l'alphabet initial */
   int         indicePositionInitialeRotors[3] = {0, 0, 0}; /* fonction à implementer /!\ */

   /* On stock l'indice de départ des alphabets dans un tableau d'entier, cette indice
      est initialisée en paramètre par la position de départ, puis modifié par la
      fonction "qui tourne" les rotors */

   char        positionEncocheRotors[3] = {'Q','E','V'}; /* encoche sur l'alphabet(anneau) ou le rotor ? */
   int         indicePositionEncocheRotors[3] = {7, 25, 11};
   int         positionRotors[3] ;

   int         i = 0;
   int         nbFrappes = 0;

   int        decalageRotor1 = indicePositionInitialeRotors[0];
   int        decalageRotor2 = indicePositionInitialeRotors[1];
   int        decalageRotor3 = indicePositionInitialeRotors[3];



   /* On va essayer d'encrypter KCH */
   char l1 = 'K';
   char l2 = 'C';
   char l3 = 'H';

   printf("%c %c %c :",l1,l2,l3);

   if (DEBUG)
   {
     printf("Frappe 1\n");
     printf("decalage: %d %d %d \n", decalageRotor1, decalageRotor2, decalageRotor3);
     printf("l1: %c ", l1);
     printf("l2: %c ", l2);
     printf("l3: %c \n", l3);
   }

   nbFrappes++ ;
   decalageRotor1+=1;
   l1 = lettreChiffree(rotor1, l1, decalageRotor1);
   if (DEBUG) printf("%c %d ",l1, decalageRotor1);
   l1 = lettreChiffree(rotor2, l1-1, decalageRotor2);
   if (DEBUG) printf("%c %d ",l1, decalageRotor2);
   l1 = lettreChiffree(rotor3, l1, decalageRotor3);
   if (DEBUG) printf("%c %d \n",l1, decalageRotor3);
   l1 = lettreChiffree(reflecteurB, l1, 0);
   if (DEBUG) printf("reflecteur : %c\n ",l1);
   l1 = cablageInverse(rotor3, l1, decalageRotor3);
   if (DEBUG) printf("%c ",l1);
   l1 = cablageInverse(rotor2, l1, decalageRotor2);
   if (DEBUG) printf("%c ",l1);
   l1 = cablageInverse(rotor1, l1+1, decalageRotor1);
   if (DEBUG) printf("%c ",l1);
if (DEBUG) printf("%c %d ",l1, decalageRotor2);
   l1 = lettreChiffree(rotor3, l1, decalageRotor3);

   /*rotationRotor( nbFrappes, &decalageRotor1, &decalageRotor2, &decalageRotor3, indicePositionEncocheRotors ,indicePositionInitialeRotors);
	*/
   if (DEBUG)
   {
     printf("Frappe 2\n");
     printf("decalage: %d %d %d \n", decalageRotor1, decalageRotor2, decalageRotor3);
     printf("l1: %c ", l1);
     printf("l2: %c ", l2);
     printf("l3: %c \n", l3);
   }

   nbFrappes++;
   decalageRotor1+=1;
   l2 = lettreChiffree(rotor1, l2, decalageRotor1);
   if (DEBUG) printf("%c %d ",l2, decalageRotor1);
   l2 = lettreChiffree(rotor2, l2-2, decalageRotor2);
   if (DEBUG) printf("%c %d ",l2, decalageRotor2);
   l2 = lettreChiffree(rotor3, l2, decalageRotor3);
   if (DEBUG) printf("%c %d ",l2, decalageRotor3);
   l2 = lettreChiffree(reflecteurB, l2, 0);
   if (DEBUG) printf("reflecteur : %c\n ",l2);
   l2 = cablageInverse(rotor3, l2, decalageRotor3);
   if (DEBUG) printf("%c ",l2);
   l2 = cablageInverse(rotor2, l2, decalageRotor2);
   if (DEBUG) printf("%c ",l2);
   l2 = cablageInverse(rotor1,l2+2, decalageRotor1);
   if (DEBUG) printf("%c ",l2);
   /*rotationRotor( nbFrappes, &decalageRotor1, &decalageRotor2, &decalageRotor3, indicePositionEncocheRotors ,indicePositionInitialeRotors);
	*/
   if (DEBUG)
   {
     printf("Frappe 3\n");
     printf("decalage: %d %d %d \n", decalageRotor1, decalageRotor2, decalageRotor3);
     printf("l1: %c ", l1);
     printf("l2: %c ", l2);
     printf("l3: %c \n", l3);
   }

  nbFrappes++;
  decalageRotor1+=1; /* ça compile ça ? */
  l3 = lettreChiffree(rotor1, l3, decalageRotor1);
  if (DEBUG) printf("%c %d ",l3, decalageRotor1);
  l3 = lettreChiffree(rotor2, l3-3, decalageRotor2);
  if (DEBUG) printf("%c %d ",l3, decalageRotor2);
  l3 = lettreChiffree(rotor3, l3, decalageRotor3);
  if (DEBUG) printf("%c %d ",l3, decalageRotor3);
  l3 = lettreChiffree(reflecteurB, l3, 0);
  if (DEBUG) printf("reflecteur : %c\n ",l3);
  l3 = cablageInverse(rotor3, l3, decalageRotor3);
  if (DEBUG) printf("%c ",l2);
  l3 = cablageInverse(rotor2, l3, decalageRotor2);
  if (DEBUG) printf("%c ",l2);
  l3 = cablageInverse(rotor1, l3+3, decalageRotor1);
  if (DEBUG) printf("%c ",l3);
  rotationRotor( nbFrappes, &decalageRotor1, &decalageRotor2, &decalageRotor3, indicePositionEncocheRotors ,indicePositionInitialeRotors);

   /* ETAPE 1 convertir les lettres en indices de leur position dans l'alphabet */
   /* ETAPE 2 à chaque fois que le rotor passe sur l'indice mkaeinitiale
              -> incrementer le nombre de tour du rotor 1
              -> à chaque tour du rotor 1, le rotor 2 tourne
              -> à chaque 26 tour du rotor1, le rotor 2 a fait 1 tour
              -> donc le rotor 3 tourne */

  indexPositionDepart(rotor1, rotor2, rotor3, positionEncocheRotors, indicePositionEncocheRotors);
  printf("enfin : ");
  printf("%c %c %c \n",l1,l2,l3);

  /*test*/
  /*
  for (i = 0; i<3 ; i++)
  {
    printf("position initiale rotor %d:%d \n",i, indicePositionInitialeRotors[i] );
  }
  */

   /* On teste les fonction de chiffrement d'une lettre */
   /*
   printf("%c %d \n", lettreChiffree(rotor1, lettre), lettreChiffree(rotor1, lettre));
   lettrechiffree = cablageInverse(rotor1, lettreChiffree(rotor1, lettre));
   printf("%c\n", lettrechiffree);
   */
   return 0;
}
