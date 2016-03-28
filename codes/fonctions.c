#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"


#define DEBUG 0

int cablageInverse (char * cablage, char lettre) /* testée ok */
{
  int i = -1 ; /* -1 */
  int trouve = 0 ; /* booleen qui arrete la recherche si lettre trouvee */
  do {
    i++;
    i = i%26;
    if(cablage[i] == lettre)
    {
      trouve = 1;
    }

  } while(!trouve);
  return(i);
}

int frappe(int l1_i /*lettre*/, int * indicePositionInitialeRotors, int * nbRotation, int * decalageRotor, char * rotor1, char * rotor2, char * rotor3, char * reflecteurB)
{

  /*APRES ROTOR1*/
  /*lettre reellement codée */
  l1_i = (indicePositionInitialeRotors[0] + nbRotation[0] + l1_i)%26;
  /* passage dans le cablage */
  l1_i = rotor3[l1_i] - 65; /* implementer une fonction après les tests */
  /* APRES ROTOR 2*/
  l1_i = (l1_i - nbRotation[0] - indicePositionInitialeRotors[0] +indicePositionInitialeRotors[1] + nbRotation[1] + 26)%26;
  l1_i = rotor2[l1_i] - 65; /* implementer une fonction après les tests */
  /* APRES ROTOR 3*/
  l1_i = (l1_i - nbRotation[1] - indicePositionInitialeRotors[1] +indicePositionInitialeRotors[2] + nbRotation[2] +26 )%26;
  l1_i = rotor1[l1_i] - 65; /* implementer une fonction après les tests */
  l1_i =( l1_i - nbRotation[2] - indicePositionInitialeRotors[2] + 26 )%26;
  l1_i = reflecteurB[l1_i] - 65;

  /* passage inverse rotor 3 */
  l1_i = (l1_i + indicePositionInitialeRotors[2] + nbRotation[2])%26;
  l1_i = cablageInverse (rotor1, l1_i + 65);
  l1_i = (l1_i - nbRotation[2] - indicePositionInitialeRotors[2] +indicePositionInitialeRotors[1] + nbRotation[1] +26 )%26;
  l1_i = cablageInverse (rotor2, l1_i + 65);
  l1_i = (l1_i - nbRotation[1] - indicePositionInitialeRotors[1] +indicePositionInitialeRotors[0] + nbRotation[0] +26 )%26;
  l1_i = cablageInverse (rotor3, l1_i + 65);
  l1_i = (l1_i - indicePositionInitialeRotors[0] - nbRotation[0] + 26)%26;

  return(l1_i);
}

void rotationRotor(int (*nbRot)[3], int (*dec)[3] ) /* quand cette fonction est appelée, on considère 1 frappe */ /* FONCTION TESTEE */
{
  int * nbRotation = *nbRot;
  int * decalageRotor = *dec;

    if (DEBUG) printf("decalage1: %d %d %d\n", decalageRotor[0], decalageRotor[1], decalageRotor[2]);


    if ((decalageRotor[1]+26)%26 == 0)
    {

      decalageRotor[2] = decalageRotor[2] + 1;
      nbRotation[2] = (nbRotation[2] +1)%26;

      decalageRotor[1] = decalageRotor[1] + 1;
      nbRotation[1] = (nbRotation[1] +1)%26;
  }
   else{
      if ((decalageRotor[0]+26)%26 == 0)
      {
        decalageRotor[1] = decalageRotor[1] + 1;
        nbRotation[1] = (nbRotation[1] +1)%26;
      }
   }
   decalageRotor[0] = decalageRotor[0] + 1;
   nbRotation[0] = (nbRotation[0] +1)%26;

    if (DEBUG) printf("decalage2: %d %d %d\n", decalageRotor[0], decalageRotor[1], decalageRotor[2]);
}

int permutation_fiche(int fiche1[10], int fiche2[10], int lettre)
{
  int i;
  int nouv_lettre;
  for(i = 0; i<10 ; i++)
  {
    if(fiche1[i] == lettre) nouv_lettre = fiche2[i];
    if(fiche2[i] == lettre) nouv_lettre = fiche1[i];
  }
  return nouv_lettre;
}

/* fonction création des listes de fiches correspondantes . Entrée: "AR TG BU JI KL MO PN YX WQ SD" Sortie: [0 5 6 4 8] [5 4 1 2 3]*/

void creation_fiches(char * tableau, int (*ptr_fiche1)[10], int (*ptr_fiche2)[10])
{
  int * fiche1 = *ptr_fiche1;
  int * fiche2 = *ptr_fiche2;
  int i ;

  for (i = 0; i<10; i++)
  {
    fiche1[i] = tableau[3*i]-65;
    fiche2[i] = tableau[3*i+1]-65;
  }
}

void lettre_indice(char lettre[3], int (*ptr_indice)[3])
{
  int i ;
  int taille = strlen(lettre);

  for(i=0 ; i<taille; i++)
  {
    (*ptr_indice)[i] = lettre[i] - 65;
  }
}
