#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int indice_occur(char c,char * tab)
{
    int      i = 0;
    int      indice = -1;

    while((indice<0)&& (i<14))
    {
        if (tab[i] == c) indice = i;
        i++;
    }
    return indice;
}

void correction(FILE* source, FILE* dest,char tab[15], char tab_c[15])
{

    int caractere=0; int indice;

    while ((caractere = fgetc(source))!= EOF )
        {
            if (indice_occur(caractere,tab)<0)
                {
                if (islower(caractere))
                {
                    caractere=toupper(caractere);

                }
                }
            else
                {
                    indice=indice_occur(caractere,tab);
                    caractere=tab_c[indice];
                }
            fprintf(dest, "%c", caractere);
        }


}

 int main()
 {
    FILE* dest = NULL;
    FILE* source = NULL;
    char * tab = "àäéèëêîïùüûôöç";
    char * tab_c = "AAEEEEIIUUUOOC";
    source = fopen("source.txt", "r");
    dest = fopen("destination.txt", "a");
    if(source != NULL && dest != NULL) correction(source,dest,tab,tab_c);
    fclose(source);
    fclose(dest);
    return 0;
 }
