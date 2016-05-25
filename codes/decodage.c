#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

#define SEUIL 0.6
/* tableau des correspondances indice de l'alphabet/lettre */
/* A B C D E F G H I J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z */
/* 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 */

/* hypothèse : il n'y a que 3 rotors I II III
   variable : - l'ordre des rotors
              - positions initiales */

/* ordre des rotors sotckés dans un tableau */

int main()
{
  FILE       *fichier;
  FILE       *fichier2;

  int         ind;
  int         o=0; /* indice dans le tableau d'ordre des rotors entre 0 et 5 */
  char       *ordre_rotor[6]={"1 2 3", "1 3 2", "2 1 3", "2 3 1", "3 1 2", "3 2 1"};
  int         fin=0; /* booléen qui indique que le seuil a été dépassé */
  char        L1 = 'A';
  char        L2 = 'A';
  char        L3 = 'A'; /* lettres correspondantes aux positions initiales courantes*/
  char       *encoche;


  /* --------------- ouverture du fichier à décoder ----------------*/
  printf("ok");
  fichier = fopen("./texte_test.txt", "r+");
  /*fichier2 = fopen("./decod_temp.txt", "rw");*/

  printf("ok");

  encoche = (char *)(malloc(50*sizeof(char)));

  /*ind = indice_coincidence("texte_code.txt");*/

  printf("%s ", ordre_rotor[0]);

  while(!(fin) && o<6) /* tant que seuil non dépassé & ordre non tous passé */
  {
      while(!(fin) && L3<='Z')
      {
            while(!(fin) && L2<='Z')
            {
                  while(!(fin) && L1<='Z')
                  {

                      fprintf(fichier,"%s B", ordre_rotor[o]);
                      fscanf(fichier, "%s", encoche);
                      fprintf(fichier, "\n%c%c%c\n", L1, L2, L3);
                      printf("ok | ");


                      /*fin = 1;*/

                      L1++;
                  }

                  L2++;
                  L1 = 'A';
            }

            L3++;
            L1 = 'A';
            L2 = 'A';

      }
      o++;
      L1 = 'A';
      L2 = 'A';
      L3 = 'A';
  }

  /*fclose(fichier2);*/
  fclose(fichier);


  free(encoche);
  return 0;
}
