#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

/*#define DEBUG 0 */
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

   int        choixRotors[3] = {3 , 2 , 1};
   char       positionIntialeRotors[3] = {'U' , 'D' , 'Y'};
   int        indicePositionInitialeRotors[3] = {20, 3, 24}; /* fonction à implementer /!\ */

   /* On stock l'indice de départ des alphabets dans un tableau d'entier, cette indice
      est initialisée en paramètre par la position de départ, puis modifié par la
      fonction "qui tourne" les rotors */

   char       positionEncocheRotors[3] = {'V','E','Q'}; /* encoche sur l'alphabet(anneau) ou le rotor ? */
   int        indicePositionEncocheRotors[3]  = {21, 4, 16}; /* fonction à implementer */

   int         i = 0;
   int         nbFrappes = 0;

   int       decalageRotor[3] ;

   decalageRotor[0] = - indicePositionEncocheRotors[0] + indicePositionInitialeRotors[0] ;
   decalageRotor[1] = - indicePositionEncocheRotors[1] + indicePositionInitialeRotors[1] ;
   decalageRotor[2] = - indicePositionEncocheRotors[2] + indicePositionInitialeRotors[2] ;

   int        nbRotation[3] = {0,0,0};

   /* On va essayer d'encrypter KCH */
   char l1 = 'K';
   char l2 = 'C';
   char l3 = 'H';

   int l1_i, l2_i, l3_i;

   char* tableau_fiche = {"AZ ER TY UI OP QS DF GH JK LM"};
   int fiche1[10];
   int fiche2[10];
   int c;

   creation_fiches(tableau_fiche, &fiche1, &fiche2);
   if(DEBUG)
   {
     printf("AFFICHAGE DU TABLEAU DE FICHE\n");
     for(c= 0; c<10; c++)
     {
       printf("%d %d \n", fiche1[c], fiche2[c]);
     }
   }

   /* transformation des lettres en indices / testé*/
   l1_i = l1-65;
   l2_i = l2-65;
   l3_i = l3-65 ;

  printf("%c %c %c\n", l1_i+65, l2_i+65, l3_i+65);
  rotationRotor(&nbRotation, &decalageRotor );
  l1_i =  frappe(l1_i /*lettre*/, indicePositionInitialeRotors, nbRotation,  decalageRotor, rotor1, rotor2,  rotor3, reflecteurB);
  rotationRotor(&nbRotation, &decalageRotor );
  l2_i =  frappe(l2_i , indicePositionInitialeRotors, nbRotation,  decalageRotor, rotor1, rotor2,  rotor3, reflecteurB);
  rotationRotor(&nbRotation, &decalageRotor );
  l3_i =  frappe(l3_i , indicePositionInitialeRotors, nbRotation,  decalageRotor, rotor1, rotor2,  rotor3, reflecteurB);
  printf("%c %c %c\n", l1_i+65, l2_i+65, l3_i+65);
  l1_i = permutation_fiche(fiche1, fiche2, l1_i);
  if(DEBUG) printf("%c\n", l1_i+65);
   return 0;
}
