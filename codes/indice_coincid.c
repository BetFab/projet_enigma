#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    float indice;
    for (i=0;i<26;i++) nb_lettres+=tab[i];
    for (j=0;j<26;j++)
    {
        nb_occurences = tab[j]*(tab[j]-1);
        indice+=(float)nb_occurences/(nb_lettres * (nb_lettres-1));
    }

    return indice;
}
int main()
{
    int j;
    int tab[26];
    float indice_coincid;
    int caractere_courant=0;
    int emplacement;
    FILE* test = NULL;
    initialiser(tab);
    test = fopen("indice.txt", "r");
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

    return 0;
}
