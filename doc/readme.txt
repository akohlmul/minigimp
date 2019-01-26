* BOYER Johan, KOHLMULLER Amandine, 26/01/2019

* pour tester sous liunx :
> make
> ./bin/minigimp pics/landscape.ppm ADDLUM 20 SEPIA 50 ADDCON 60 -histo -o pics/outputlandscape1.ppm
> ./bin/minigimp pics/landscape.ppm ADDLUM 10 VAPORWAVE 70 ADDCON 75 -o pics/outputlandscape2.ppm
> ./bin/minigimp pics/landscape.ppm DIMCON 50 GRAYSCALE -o pics/outputlandscape3.ppm
> ./bin/minigimp pics/landscape.ppm INVERT -o pics/outputlandscape4.ppm
> ./bin/minigimp pics/landscape.ppm GRAYSCALE FLOOR 50 -o pics/outputlandscape5.ppm
puis regarder dans pics

* effets disponibles :
ADDLUM + valeur entre 0 et 100 ou "-r" pour une valeur random entre 0 et 100
DIMLUM + valeur entre 0 et 100 ou "-r" pour une valeur random entre 0 et 100
ADDCON + valeur entre 0 et 100 ou "-r" pour une valeur random entre 0 et 100
DIMCON + valeur entre 0 et 100 ou "-r" pour une valeur random entre 0 et 100
SEPIA + valeur entre 0 et 100 ou "-r" pour une valeur random entre 0 et 100
FLOOR + valeur entre 0 et 100
VAPORWAVE + valeur entre 0 et 100
INVERT
GRAYSCALE

* pour enregistrer l'histogramme en .ppm
ajouter "-histo" ou "-h"
regarder dans pics

* pour faire une archive :
> make zip

* pour convertir une image :
> convert image1.jpg image2.ppm

* COMMENTAIRES
L'ordre des effets dans la commande est important, par exemple si on fait ADDLUM avant INVERT le résultat sera plus sombre.
On peut mettre des valeurs supérieurs à 100 mais en général cela ne rend pas bien.