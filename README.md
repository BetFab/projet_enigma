#Projet Enigma

Le dossier contient deux executables, un pour chiffrer un texte, un autre pour déchiffrer un texte.

Pour obtenir les executables:
=============================
Se placer dans le fichier "sources"
Dans un terminal:
>>make

Pour chiffrer un texte:
=======================
>>./codage
	Simulateur machine enigma:
	Entrer le nom d'un fichier qui contiendra la configuration de la machine et le texte à coder
#ce fichier contiendra la configuration de la machine
>>configuration.txt
	--Configuration de la machine--
	Choix des rotors et réflécteur
	Tapez les numéros correspondants aux rotors, et la lettre 	correspondant au réflécteur 
	Exemple : 1 2 3 B :
#il faut taper les rotors de 1, 2, ou 3 dans l'ordre de passage du signal et non de gauche à droite, ainsi que la lettre correspondant au réflecteur en majuscule. Chaque caractère doit être séparé d'un espace.
>> 3 2 1 B
 	Tapez les lettres où se situent les encoches sur les rotors : 
	Exemple : VEQ 
#il faut taper trois lettres majuscules sans espace, correspondant donc à la position des encoches sur les rotors rentrés dans l'ordre précédent.
>>XDH
	--Chiffrage d'un texte--
	Position initiale des rotors:
	Exemple "AAA"
	
#ici l'utilisateur doit rentrer la position intitiale des rotors, les lettres qu'il verrait dans la fenêtre s'il avait une machine Enigma devant lui. Il faut taper trois lettres majuscules sans espace, comme précédement.
>>ZRT
	Tapez le tableau des fiches: 
	Exemple AB CD EF GH IJ KL MN OP QR ST 
	
#ici il faut taper obligatoirement 10 paires de lettres en majuscule avec un espace entre chaque paire. Si l'utilisateur ne veut pas brancher 10 fiches, il doit mettre des doubles par exemple 'AA' à la place.
>> AZ TY UI OP JH LL LL LL LL LL
	Entrer le nom d'un fichier qui contient le texte (ENCODE EN NORME WESTERN ET NON UTF-8) à coder
	
#ici il faut taper le nom du fichier contenant le texte à chiffrer. Attention avant le passage dans la machine Enigma, le programme formate le texte en enlevant la ponctuation ,en remplaçant les caractères accentués par leur équivalent en majuscule sans accent, et en passant toutes les lettres en majuscule. 

# Attention: pour que le formatage fonctionne il faut que le texte soit encodé selon la norme Western et non en UTF-8. 

# Pour un meilleur résultat, nous conseillons à l'utilisateur de formater son texte (enlever les accents, la ponctuation, et mettre que des majuscules) à préalable.
>> texte.txt
	Entrez le nom d'un fichier qui contiendra votre texte codé :
#il faut entrer le fichier destination du texte crypté par la machine
#si celui-ci n'existe pas, il sera créé
>> texte_code.txt

#normalement dans votre fichier destination vous aurez votre texte codé, et vous pouvez récupérer votre configuration dans le fichier de configuration.

Pour déchiffrer un texte:
=========================
#il faut préparer au préalable un fichier texte de cette forme:
1 2 3 B
VEQ
AAA
AA AA AA AA AA AA AA AA AA AA
TEXTE A DECHIFFRER 
#Les trois premières lignes seront modifiées par le programme
#Il est important de n'avoir aucune permutation au départ (10 doubles) sur la quatrième ligne
#Sur la cinquième ligne, il faut mettre votre texte à déchiffrer en majuscule, formaté comme pour le programme de codage.

>>./decodage
	Entrez le nom d'un fichier contenant la configuration des rotors 		et votre texte chiffré : 
#il faut rentrer ici le nom du fichier préalablement créé.
>>configuration.txt
	Entrez le nom du fichier où vous voulez stocker le texte décodé: 
#il faut rentrer ici votre fichier source
>>texte_decode.txt
	entrez les encoches des rotors (ordre : 1 2 3) exemple VEQ
#On fait l'hypothèse ici, que l'utilisateur possède une machine Enigma et donc connait la position des encoches sur les rotors numéro 1 2 et 3
#Il faut donc rentrer ici les lettres en majuscule correspondantes à ces encoches, sans espace, et dans le bon ordre
>> HDX
#normalement, ici le programme va tester toutes les possibilités (cela peut prendre plusieurs minutes ).A la fin, il affiche la configuration qu'il considère la plus probable.
#le texte décodé sera alors stocké dans le fichier destination
#Attention, ici si l'indice de coïncidence maximal n'est pas supérieur à 0.055, il est probable que la méthode de l'indice de coïncidence n'a pas fonctionné. Le texte est probablement trop court pour utiliser cette méthode.

