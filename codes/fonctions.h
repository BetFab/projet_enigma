int cablageInverse (char * cablage, char lettre);

int frappe(int l1_i /*lettre*/, int * indicePositionInitialeRotors, int * nbRotation, int * decalageRotor, char * rotor1, char * rotor2, char * rotor3, char * reflecteurB);

void rotationRotor(int (*nbRot)[3], int (*dec)[3] ) ;

int permutation_fiche(int fiche1[10], int fiche2[10], int lettre);

void creation_fiches(char * tableau, int (*ptr_fiche1)[10], int (*ptr_fiche2)[10]);
