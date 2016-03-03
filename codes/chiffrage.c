#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"





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

   char         lettre = 'D';
   char         lettrechiffree ;

   int       * choixRotors = {1 , 2 , 3};

   /* On stock l'indice de départ des alphabets dans un tableau d'entier, cette indice
      est initialisée en paramètre par la position de départ, puis modifié par la
      fonction "qui tourne" les rotors */

   char        positionInitialeRotors[3] = {'F','U','L'};
   int         indicePositionInitialeRotors[3] = {-1, -1, -1};
   int         positionRotors[3] ;

   int         i = 0;

   /* ETAPE 1 convertir les lettres en indices de leur position dans l'alphabet */
   /* ETAPE 2 à chaque fois que le rotor passe sur l'indice initiale
              -> incrementer le nombre de tour du rotor 1
              -> à chaque tour du rotor 1, le rotor 2 tourne
              -> à chaque 26 tour du rotor1, le rotor 2 a fait 1 tour
              -> donc le rotor 3 tourne */

  indexPositionDepart(rotor1, rotor2, rotor3, positionInitialeRotors, indicePositionInitialeRotors);

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
