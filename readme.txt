* pour tester sous liunx :
> make
> ./bin/minigimp pics/landscape.ppm ADDLUM 20 SEPIA 50 ADDCON 60 -histo -o pics/outputlandscape1.ppm
> ./bin/minigimp pics/landscape.ppm ADDLUM 10 VAPORWAVE 70 ADDCON 75 -o pics/outputlandscape2.ppm
> ./bin/minigimp pics/landscape.ppm DIMCON 50 GRAYSCALE -o pics/outputlandscape3.ppm
> ./bin/minigimp pics/landscape.ppm INVERT-o pics/outputlandscape4.ppm
> ./bin/minigimp pics/landscape.ppm FLOOR 50 -o pics/outputlandscape4.ppm
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
Sous linux, pour convertir une image d'un format à un autre : convert image1.jpg image2.ppm


//
Si on fait ADDLUM avant INVERT ça fait plus sombre
On peut faire des valeurs supérieurs à 100 mais en général c'est pas beau