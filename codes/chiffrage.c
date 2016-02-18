#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

int main()
{

   /* CABLAGE DES ROTORS */
   char * rotor1 = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
   char * rotor2 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
   char * rotor3 = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
   char * rotor4 = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
   char * rotor5 = "VZBRGITYUPSDNHLXAWMJQOFECK";

   /* CABLAGE DES REFLECTEURS */
   char * reflecteurA = "EJMZALYXVBWFCRQUONTSPIKHGD";
   char * reflecteurB = "YRUHQSLDPXNGOKMIEBFZCWVJAT" ;

   char lettre = 'D';
   char lettrechiffree ;

   /*
   printf("%c %d \n", lettreChiffree(rotor1, lettre), lettreChiffree(rotor1, lettre));
   lettrechiffree = cablageInverse(rotor1, lettreChiffree(rotor1, lettre));
   printf("%c\n", lettrechiffree);
   */

   return 0;
}
