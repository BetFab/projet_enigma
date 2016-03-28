#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

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




  return 0;
}
