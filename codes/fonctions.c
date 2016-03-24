#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"


#define DEBUG 1

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
  if(DEBUG) printf("%d \n", l1_i);
  if(DEBUG) printf("%d %d %d rotation\n", nbRotation[0],nbRotation[1],nbRotation[2]);
  l1_i = (indicePositionInitialeRotors[0] + nbRotation[0] + l1_i)%26;
  /* passage dans le cablage */
  if(DEBUG) printf("%d \n", l1_i);
  l1_i = rotor3[l1_i] - 65; /* implementer une fonction après les tests */
  /* APRES ROTOR 2*/
  if(DEBUG) printf("%d \n", l1_i);
  l1_i = (l1_i - nbRotation[0] - indicePositionInitialeRotors[0] +indicePositionInitialeRotors[1] + nbRotation[1] + 26)%26;
  if(DEBUG) printf("%d \n", l1_i);
  l1_i = rotor2[l1_i] - 65; /* implementer une fonction après les tests */
  /* APRES ROTOR 3*/
  if(DEBUG) printf("%d \n", l1_i);
  l1_i = (l1_i - nbRotation[1] - indicePositionInitialeRotors[1] +indicePositionInitialeRotors[2] + nbRotation[2] +26 )%26;
  if(DEBUG) printf("%d \n", l1_i);
  l1_i = rotor1[l1_i] - 65; /* implementer une fonction après les tests */
  /* Réflecteur */
  if(DEBUG) printf("%d \n", l1_i);
  l1_i =( l1_i - nbRotation[2] - indicePositionInitialeRotors[2] + 26 )%26;
  if(DEBUG) printf("%d \n", l1_i);
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
    /* le rotor 1 tourne à chaque fois */
    (decalageRotor)[0] = (decalageRotor)[0] + 1;
    (nbRotation)[0] = ((nbRotation)[0] +1)%26; /* à tester */
        /* si on est à un multiple de 26 -> le rotor 2 tourne */

    if ((decalageRotor[0])%26 == 0)
    {

      decalageRotor[1] = decalageRotor[1] + 1;
      nbRotation[1] = (nbRotation[1] +1)%26; /* à tester */

      /* seulement si le second rotor à tourner, on regarde si le troisième rotor doit lui aussi tourner */
      if((decalageRotor[1] == -1) || (decalageRotor[1]%26 == 0))
      {

        decalageRotor[2] = decalageRotor[2] + 1;
        nbRotation[2] = (nbRotation[2] +1 )%26; /* à tester */

      }
    }
    if (DEBUG) printf("decalage2: %d %d %d\n", decalageRotor[0], decalageRotor[1], decalageRotor[2]);
}
