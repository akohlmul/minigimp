#ifndef HISTO_H__
#define HISTO_H__

#include "image.h"

// create the histogramme in an array
void createHisto(Image * image, int *histo);

//If the histogramme is asked: ppm created and saved
int histoPPM(int *histo,char *commands[],int nbCommands );

#endif