#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int indice_occur(char c,char tab[11]) /*on s'y appuiera pour d�terminer si une lettre est accentu�e ou pas*/
{
    char cour=tab[0]; int i=0; int indice=-1;
    while((i<11)&&(indice<0))
    {
        if (cour==c) indice=i;
        i++;
    }
    return indice;
}
void correction()
{
    FILE* fichier=NULL;
    int caractere=0;
    char tab={'�','�','�','�','�','�','�','�','�','�','�'};
    char tab_c={'a','a','e','e','e','e','i','i','u','u','u'};
    fichier=fopen("message.txt","r+");
    if (fichier!=NULL){
        do
        {
            caractere=fgetc(fichier); /*On se place sur le caract�re courant*/
            if (indice_occur(caractere,tab)<0) /*ce n'est pas une lettre accentu�e*/
            {
                if (isupper(caractere))/*la lettre est majuscule*/
                {
                    caractere=tolower(caractere);/*on la transforme en miniscule*/
                }
            }
            else
            {
                caractere=tab_c[indice_occur(caractere,tab)];/*On matche la lettre avec celle non accentu�e*/
            }

        } while (fgetc(fichier)!=NULL); /*ou EOF ? */

}
