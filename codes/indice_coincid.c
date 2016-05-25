#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

#define SEUIL 0.6



int indice_coincidence(char * fichier_entree)
{
    /*int j;*/
    int tab[26];
    float indice_coincid;
    int caractere_courant=0;
    int emplacement;
    FILE* test = NULL;
    initialiser(tab);
    test = fopen(fichier_entree, "r");
    if (test!= NULL)
    {
       while ((caractere_courant = fgetc(test))!= EOF )
       {
           emplacement=caractere_courant-65;
           tab[emplacement]+=1;
       }
       /*for (j=0;j<26;j++) printf("frequence de %c : %d  \n",j+65,tab[j]);*/
       indice_coincid=calcul_indice_coincidence(tab);
       printf("indice de coincidence : %f \n",indice_coincid);
    }
    fclose(test);

    return indice_coincid;
}
