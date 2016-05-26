#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

int permutation_fiche(int fiche1[10], int fiche2[10], int lettre)
{
  int i;
  int nouv_lettre = lettre;
  for(i = 0; i<10 ; i++)
  {
    if(fiche1[i] == lettre) nouv_lettre = fiche2[i];
    if(fiche2[i] == lettre) nouv_lettre = fiche1[i];
  }
  return nouv_lettre;
}

int frappe(int l1_i /*lettre*/, int * indicePositionInitialeRotors, int * nbRotation, int * decalageRotor, char * rotor1, char * rotor2, char * rotor3, char * reflecteurB, int fiche1[10], int fiche2[10])
{

  /*APRES ROTOR1*/
  /*lettre reellement codée */
  l1_i = permutation_fiche(fiche1, fiche2, l1_i-65);
  l1_i = (indicePositionInitialeRotors[0] + nbRotation[0] + l1_i)%26;
  /* passage dans le cablage */
  l1_i = rotor1[l1_i] - 65; /* implementer une fonction après les tests */
  /* APRES ROTOR 2*/
  l1_i = (l1_i - nbRotation[0] - indicePositionInitialeRotors[0] +indicePositionInitialeRotors[1] + nbRotation[1] + (26*30))%26;
  l1_i = rotor2[l1_i] - 65; /* implementer une fonction après les tests */
  /* APRES ROTOR 3*/
  l1_i = (l1_i - nbRotation[1] - indicePositionInitialeRotors[1] +indicePositionInitialeRotors[2] + nbRotation[2] +(26*30) )%26;
  l1_i = rotor3[l1_i] - 65; /* implementer une fonction après les tests */
  l1_i =( l1_i - nbRotation[2] - indicePositionInitialeRotors[2] + (26*30))%26;
  l1_i = reflecteurB[l1_i] - 65;

  /* passage inverse rotor 3 */
  l1_i = (l1_i + indicePositionInitialeRotors[2] + nbRotation[2])%26;
  l1_i = cablageInverse (rotor3, l1_i + 65);
  l1_i = (l1_i - nbRotation[2] - indicePositionInitialeRotors[2] +indicePositionInitialeRotors[1] + nbRotation[1] +(26*30) )%26;
  l1_i = cablageInverse (rotor2, l1_i + 65);
  l1_i = (l1_i - nbRotation[1] - indicePositionInitialeRotors[1] +indicePositionInitialeRotors[0] + nbRotation[0] +(26*30) )%26;
  l1_i = cablageInverse (rotor1, l1_i + 65);
  /* il faut pas redécaler mais passer dans les fiches */
  l1_i = (l1_i - indicePositionInitialeRotors[0] - nbRotation[0] + (26*30))%26;
  l1_i = permutation_fiche(fiche1, fiche2, l1_i);

  return(l1_i);
}

void rotationRotor(int (*nbRot)[3], int (*dec)[3] ) /* quand cette fonction est appelée, on considère 1 frappe */ /* FONCTION TESTEE */
{
  int * nbRotation = *nbRot;
  int * decalageRotor = *dec;



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
  int *liste = *ptr_indice;


  for(i=0 ; i<3; i++)
  {
    liste[i] = lettre[i] - 65;
  }
}

void initialiser(int tab[26])
{
    int i;
    for (i=0;i<26;i++)
    {
        tab[i]=0;
    }
}

float calcul_indice_coincidence(int tab[26])
{
    int i,j;
    int nb_lettres=0;
    int nb_occurences=0;
    float indice=0;
    for (i=0;i<26;i++) nb_lettres+=tab[i]; /* nombre de lettre total */
    for (j=0;j<26;j++)
    {
        nb_occurences = tab[j]*(tab[j]-1);
        indice+=(float)nb_occurences/((float)(nb_lettres * (nb_lettres-1)));
    }

    return indice;
}

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
       /*printf("indice de coincidence : %f \n",indice_coincid);*/
    }
    fclose(test);

    return indice_coincid;
}
