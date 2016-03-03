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
   char      * positionIntialeRotors{'O' , 'Y' , 'H'}; /* clé du jour */
   int       * indicePositionInitialeRotors{12, 21, 3}; /* fonction à implementer /!\ */

   /* On stock l'indice de départ des alphabets dans un tableau d'entier, cette indice
      est initialisée en paramètre par la position de départ, puis modifié par la
      fonction "qui tourne" les rotors */


  /* /!\ /!\ SEULE UNE ENCOCHE EST UTILE ? PREMIERE ? */

   char        positionEncocheRotors[3] = {'F','U','L'};
   int         indicePositionEncocheRotors[3] = {-1, -1, -1};
   int         positionRotors[3] ;

   int         i = 0;
   int         nbFrappes = 0;

   int        decalageRotor1 = indicePositionInitialeRotors[0];
   int        decalageRotor2 = indicePositionInitialeRotors[1];
   int        decalageRotor3 = indicePositionInitialeRotors[3];

   /* On va essayer d'encrypter TES */
   char l1 = 'T';
   char l2 = 'E';
   char l3 = 'S';

   nbFrappes++ ;
   l1 = lettreChiffree(rotor1, l1, decalageRotor1);
   l1 = lettreChiffree(rotor2, l1, decalageRotor2);
   l1 = lettreChiffree(rotor3, l1, decalageRotor3);
   l1 = lettreChiffree(reflecteurA, l1, 0);
   l1 = cablageInverse(rotor1, lettreChiffree(rotor1, l1));
   rotationRotor( nbFrappes, &decalageRotor1, &decalageRotor2, &decalageRotor3, indicePositionEncocheRotors ,indicePositionInitialeRotors)

   nbFrappes++;
   l2 = lettreChiffree(rotor1, l2, decalageRotor1);
   l2 = lettreChiffree(rotor2, l2, decalageRotor2);
   l2 = lettreChiffree(rotor3, l2, decalageRotor3);
   l2 = lettreChiffree(reflecteurA, l1, 0);
   rotationRotor( nbFrappes, &decalageRotor1, &decalageRotor2, &decalageRotor3, indicePositionEncocheRotors ,indicePositionInitialeRotors)

   nbFrappes++;
   l3 = lettreChiffree(rotor1, l3, decalageRotor1);
   l3 = lettreChiffree(rotor2, l3, decalageRotor2);
   l3 = lettreChiffree(rotor3, l3, decalageRotor3);
   l1 = lettreChiffree(reflecteurA, l1, 0);
   rotationRotor( nbFrappes, &decalageRotor1, &decalageRotor2, &decalageRotor3, indicePositionEncocheRotors ,indicePositionInitialeRotors)

   /* ETAPE 1 convertir les lettres en indices de leur position dans l'alphabet */
   /* ETAPE 2 à chaque fois que le rotor passe sur l'indice initiale
              -> incrementer le nombre de tour du rotor 1
              -> à chaque tour du rotor 1, le rotor 2 tourne
              -> à chaque 26 tour du rotor1, le rotor 2 a fait 1 tour
              -> donc le rotor 3 tourne */

  indexPositionDepart(rotor1, rotor2, rotor3, positionEncocheRotors, indicePositionEncocheRotors);



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
