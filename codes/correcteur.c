#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int accent(char c,char tab[11]) /*retourne 1 si le caractère n'appartient pas à la chaine, 0 sinon*/
{
    int res=1; int i=0;
    while((i<11) && (res!=0))
    {
        if (tab[i]==c) res=0;
        i++;
    }
    return res;
}
void correction()
{
    FILE* fichier=NULL;
    int caractere=0;
    char tab={'à','ä','é','è','ë','ê','î','ï','ù','ü','û'};
    fichier=fopen("message.txt","r+");
    if (fichier!=NULL){
        do
        {
            caractere=fgetc(fichier); /*On se place sur le caractère courant*/
            if (!accent(caractere,tab)) /*ce n'est pas une lettre accentuée*/
            {
                if isupper(caractere)/*la lettre est majuscule*/
                {
                    caractere=tolower(caractere);/*on la transforme en miniscule*/
                }
            }
            else
            {
                    /*Fonction à définir pour les accents*/
            }

    }

}
