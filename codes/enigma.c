#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

  FILE       * fichier;

  int         choixRotors[3] = {0 , 0 , 0};
  char        choixRotor1[26];
  char        choixRotor2[26];
  char        choixRotor3[26];
  char        choixReflecteur2[26];
  char        choixReflecteur = 'A';
  char        positionIntialeRotors[3] = {'A' , 'A' , 'A'};
  int         indicePositionInitialeRotors[3] = {0, 0, 0}; /* fonction à implementer /!\ */


  char        positionEncocheRotors[3] = {'A','A','A'}; /* encoche sur l'alphabet(anneau) ou le rotor ? */
  int         indicePositionEncocheRotors[3]  = {0, 0, 0}; /* fonction à implementer */

  int         i = 0;
  int         nbFrappes = 0;

  int         decalageRotor[3] = {0, 0, 0} ;
  int         nbRotation[3] = {0,0,0} ;

  char       *tableau_fiche =(char*)malloc(30*sizeof(char));
  int         fiche1[10];
  int         fiche2[10];
  char        c;
  char        line[10];



  /* Lecture des données de configuration dans le fichier */
  fichier = fopen("./fichier_test.txt", "r");

/* --------------------------------------------------------------------- */
/* 1ere ligne : choix des rotos et du reflecteur */
/* --------------------------------------------------------------------- */

  fscanf(fichier, "%d %d %d %c", &choixRotors[2], &choixRotors[1], &choixRotors[0], &choixReflecteur );
  while ((c = fgetc(fichier)) != '\n' && c != EOF);
  printf("%d %d %d %c\n",choixRotors[2], choixRotors[1], choixRotors[0], choixReflecteur );
  /* Cablage 3e rotor (le plus à gauche) */
  switch(choixRotors[2]) {

     case 1  :
        strcpy(choixRotor3 ,rotor1);
        break;

     case 2  :
        strcpy(choixRotor3 ,rotor2);
        break;

     case 3  :
        strcpy(choixRotor3,rotor3);
        break;

     case 4 :
        strcpy(choixRotor3,rotor4);
        break;

     case 5  :
        strcpy(choixRotor3 ,rotor5);
        break;

/* Cablage 2e rotor */
     default :
     strcpy(choixRotor3,rotor3);
   }

   switch(choixRotors[1]) {

      case 1  :
         strcpy(choixRotor2,rotor1);
         break;

      case 2  :
         strcpy(choixRotor2, rotor2);
         break;

      case 3  :
         strcpy(choixRotor2,rotor3);
         break;

      case 4 :
         strcpy(choixRotor2,rotor4);
         break;

      case 5  :
         strcpy(choixRotor2,rotor5);
         break;


      default :
      strcpy(choixRotor2,rotor2);
    }

/* Cablage 1e rotor (le plus à droite) */
    switch(choixRotors[0]) {

       case 1  :
          strcpy(choixRotor1,rotor1);
          break;

       case 2  :
          strcpy(choixRotor1,rotor2);
          break;

       case 3  :
          strcpy(choixRotor1, rotor3);
          break;

       case 4 :
          strcpy(choixRotor1 ,rotor4);
          break;

       case 5  :
          strcpy(choixRotor1 ,rotor5);
          break;


       default :
       strcpy(choixRotor1 ,rotor3);
     }

     if(choixReflecteur == 'A')
     {
       strcpy(choixReflecteur2,reflecteurA);
     }else{
       strcpy(choixReflecteur2 ,reflecteurB);
     }

     /* --------------------------------------------------------------------- */
     /* 2nde ligne : positions des encoches */
     /* --------------------------------------------------------------------- */

  fscanf(fichier, "%c %c %c", &positionEncocheRotors[0], &positionEncocheRotors[1], &positionEncocheRotors[2] );
  while ((c = fgetc(fichier)) != '\n' && c != EOF);
  printf("%c %c %c\n", positionEncocheRotors[0], positionEncocheRotors[1], positionEncocheRotors[2]);
  lettre_indice(positionEncocheRotors, &indicePositionEncocheRotors);

  /* --------------------------------------------------------------------- */
  /* 3e ligne : positions initiales des rotors */
  /* --------------------------------------------------------------------- */

  fscanf(fichier, "%c %c %c", &positionIntialeRotors[0], &positionIntialeRotors[1], &positionIntialeRotors[2] );
  while ((c = fgetc(fichier)) != '\n' && c != EOF);
  printf("%c %c %c\n", positionIntialeRotors[0], positionIntialeRotors[1],positionIntialeRotors[2] );
  lettre_indice(positionIntialeRotors, &indicePositionInitialeRotors);


  /* --------------------------------------------------------------------- */
  /* 3e ligne : tableau des fiches */
  /* --------------------------------------------------------------------- */

  fscanf(fichier, "%[^\n]s", tableau_fiche);
  printf("%s\n", tableau_fiche);

  creation_fiches(tableau_fiche, &fiche1, &fiche2);
  printf("%d", fiche1[2]);

  decalageRotor[0] = - indicePositionEncocheRotors[0] + indicePositionInitialeRotors[0] ;
  decalageRotor[1] = - indicePositionEncocheRotors[1] + indicePositionInitialeRotors[1] ;
  decalageRotor[2] = - indicePositionEncocheRotors[2] + indicePositionInitialeRotors[2] ;

  
  free(tableau_fiche);
  fclose(fichier);
  return 0;
}
