#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"


#define DEBUG 1

int cablageInverse (char * cablage, char lettre, int decalage) /* testée ok */
{
  int i = -1 ; /* -1 */
  int trouve = 0 ; /* booleen qui arrete la recherche si lettre trouvee */
  if(DEBUG) printf("%c %c\n", cablage[i%26], lettre);
  do {
    i++;
    if(DEBUG) printf("%c %c\n", cablage[i%25], lettre);
    i = i%25;
    if(cablage[i] == lettre)
    {
      trouve = 1;
    }

  } while(!trouve);
  i = (i - decalage)%26;
  if(DEBUG) printf("i = %d\n", i);
  if(DEBUG) printf("lettre = %c\n", i+65);
     /* retourne l'indice +1 si trouve et incremente sinon */


  return(i+65);
}

int lettreChiffree (char * cablage, char lettre, int decalage)/* non testée avec décalage */
{
  return(cablage[ ((lettre-65) + decalage) % 26]) ;
}

void indexPositionDepart( char * rotor1, char * rotor2, char * rotor3 , char * lettresDepart, int * indices)
{
    /* testée ok mais potentiellement inutile */
    /*
     indices[0] = cablageInverse(rotor1, lettresDepart[0]) - 65;
     indices[1] = cablageInverse(rotor2, lettresDepart[1]) - 65;
     indices[2] = cablageInverse(rotor3, lettresDepart[2]) - 65;
     */
}

void rotationRotor(int (*nbRot)[3], int (*dec)[3] ) /* quand cette fonction est appelée, on considère 1 frappe */ /* FONCTION TESTEE */
{
  int * nbRotation = *nbRot;
  int * decalageRotor = *dec;

    /* le rotor 1 tourne à chaque fois */
    (decalageRotor)[0] = (decalageRotor)[0] + 1;
    (nbRotation)[0] = ((nbRotation)[0] + 1)%26; /* à tester */
        /* si on est à un multiple de 26 -> le rotor 2 tourne */

    if (decalageRotor[0]%26 == 0)
    {

      decalageRotor[1] = decalageRotor[1] + 1;
      nbRotation[1] = (nbRotation[1] + 1)%26; /* à tester */

      /* seulement si le second rotor à tourner, on regarde si le troisième rotor doit lui aussi tourner */
      if(decalageRotor[1]%26 == 0)
      {
        decalageRotor[2] = decalageRotor[2] + 1;
        nbRotation[2] = (nbRotation[2] + 1)%26; /* à tester */

      }
    }
}
