* pour tester sous liunx :
> make
> ./bin/minigimp pics/landscape.ppm ADDLUM 100 -o pics/outputlandscape.ppm
./bin/minigimp pics/landscape.ppm ADDCON 50 -h -o pics/outputlandscape50.ppm
puis regarder dans pics

* pour faire une archive :
> make zip


* pour convertir une image
Sous linux, pour convertir une image d'un format à un autre : convert image1.jpg image2.ppm




//
Sepia fait des trucs chelou
Si on fait ADDLUM avant INVERT ça fait plus sombre