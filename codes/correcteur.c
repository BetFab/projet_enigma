#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int indice_occur(char c,char * tab) /*on s'y appuiera pour déterminer si une lettre est accentuée ou pas*/
{
    int      i = 0;
    int      indice = -1;

    while( (i<11) && (indice<0) )
    {
        if (tab[i] == c) indice = i;
        i++;
    }
    return indice;
}

void correction(FILE* source, FILE* dest,char tab[12], char tab_c[12])
{

    int caractere=0; int indice;

    while ((caractere = fgetc(source))!= EOF )
        {
            if (indice_occur(caractere,tab)<0) /*ce n'est pas une lettre accentuée*/
                {
                if (isupper(caractere))/*la lettre est majuscule*/
                {
                    caractere=tolower(caractere);/*on la transforme en miniscule*/

                }
                }
            else
                {   indice=indice_occur(caractere,tab);
                    caractere=tab_c[indice];/*On matche la lettre avec celle non accentuée*/
                }
            fprintf(dest, "%c", caractere);
        }


}





 int main()
 {
   FILE* dest = NULL;
   FILE* source = NULL;
   source = fopen("source.txt", "r");
   dest = fopen("destination.txt", "a");
   char * tab = "àäéèëêîïùüû";
   char * tab_c = "aaeeeeiiuuu";/* à priori on utlise l'indice d'occurance jusqu'à trouver une meilleure sol */

   /* ----- TEST DE CORRECTION ---- */
    if(source != NULL && dest != NULL) correction(source,dest,tab,tab_c);
    fclose(source);
    fclose(dest);
    return 0;
 }
