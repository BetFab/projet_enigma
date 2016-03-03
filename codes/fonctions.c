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

int lettreChiffree (char * cablage, char lettre) /*testée ok */
{
  return(cablage[lettre-65]) ;
}

void indexPositionDepart( char * rotor1, char * rotor2, char * rotor3 , char * lettresDepart, int * indices)
{
     indices[0] = cablageInverse(rotor1, lettresDepart[0]) - 65;
     indices[1] = cablageInverse(rotor2, lettresDepart[1]) - 65;
     indices[2] = cablageInverse(rotor3, lettresDepart[2]) - 65;
}
