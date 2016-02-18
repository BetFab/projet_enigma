#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"



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
