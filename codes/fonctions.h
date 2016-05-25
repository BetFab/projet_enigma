int cablageInverse (char * cablage, char lettre);

int frappe(int l1_i /*lettre*/, int * indicePositionInitialeRotors, int * nbRotation, int * decalageRotor, char * rotor1, char * rotor2, char * rotor3, char * reflecteurB, int fiche1[10], int fiche2[10]);

void rotationRotor(int (*nbRot)[3], int (*dec)[3] ) ;

int permutation_fiche(int fiche1[10], int fiche2[10], int lettre);

void creation_fiches(char * tableau, int (*ptr_fiche1)[10], int (*ptr_fiche2)[10]);

void lettre_indice(char lettre[3], int (*ptr_indice)[3]);

void initialiser(int tab[26]);

float calcul_indice_coincidence(int tab[26]);

int indice_coincidence(char * fichier_entree);
