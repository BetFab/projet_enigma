#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int indice_occur(char c,char * tab) /*on s'y appuiera pour déterminer si une lettre est accentuée ou pas*/
{
    int      i = 0;
    int      indice = -1;
    char     cour = tab[i];

    while( (i<11) && (indice<0) )
    {
        printf("%c %c %d \n", cour, c, indice);
        printf("%d \n", cour==c); /* ici ça marche pas, test à changer */
        if (cour == c)
        {
          indice = i;
        }
        i++;
    }
    return indice;
}





void correction(FILE* fichier, char tab[12], char tab_c[12])
{

    char caractere; int indice;

      do
        {
            caractere=fgetc(fichier); /*On se place sur le caractère courant*/
            if (indice_occur(caractere,tab)<0) /*ce n'est pas une lettre accentuée*/
            {
                if isupper(caractere)/*la lettre est majuscule*/
                {
                    caractere=tolower(caractere);/*on la transforme en miniscule*/
                }
            }
            else
            {
				indice=indice_occur(caractere,tab);
                caractere=tab_c[indice];/*On matche la lettre avec celle non accentuée*/
            }

        } while (fgetc(fichier)!=EOF);

}





 int main(int argc, char* argv[])
 {
	 FILE* fichier=NULL;
   char * tab = "àäéèëêîïùüû";
   char * tab_c = "aaeeeeiiuuu";/* à priori on utlise l'indice d'occurance jusqu'à trouver une meilleure sol */

   /* ----- TEST DE CORRECTION ---- */

   printf("%d \n",indice_occur(tab[4], tab));

  /*
	 if (argc >1){
			fichier=fopen(argv[1],"r+");
		}
	 if (fichier){
			correction(fichier,tab,tab_c);
		}
		fclose(fichier);
  */

	 return 0;
 }
