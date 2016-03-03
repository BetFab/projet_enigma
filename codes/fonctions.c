#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"


/* est-ce que cette fonction doit prendre en compte la rotation des rotors ? */

int cablageInverse (char * cablage, char lettre) /* testée ok */
{
  int i = 0 ;
  int trouve = 0 ; /* booleen qui arrete la recherche si lettre trouvee */
  while(!trouve)
  {
    if(cablage[i] == lettre)
    {
      trouve++;
    }
    i++; /* retourne l'indice +1 si trouve et incremente sinon */
  }

  return(i+64);
}

int lettreChiffree (char * cablage, char lettre, int decalage)/* non testée avec décalage */
{
  return(cablage[ ((lettre-65) + decalage) % 26]) ;
}

void indexPositionDepart( char * rotor1, char * rotor2, char * rotor3 , char * lettresDepart, int * indices)
{
    /* testée ok mais potentiellement inutile */
     indices[0] = cablageInverse(rotor1, lettresDepart[0]) - 65;
     indices[1] = cablageInverse(rotor2, lettresDepart[1]) - 65;
     indices[2] = cablageInverse(rotor3, lettresDepart[2]) - 65;
}

void rotationRotor( int compteurFrappes, int * decR1, int * decR2, int * decR3, int * indiceEncoche int * positionInitRotors)
{
    ((*decR1)++) % 26; /* le rotor1 tourne 1 fois */
    if( ((positionInitRotors[0] - compteurFrappes)%26) ==  indiceEncoche[0] )
    {
        /* le rotor 2 tourne 1 fois */
        ((*decR2)++) % 26;
        if( ((positionInitRotors[1] - compteurFrappes)%26) ==  indiceEncoche[1] )
        {
          /* le rotor 3 tourne 1 fois */
          ((*decR3)++) % 26;
        }
    }
}
