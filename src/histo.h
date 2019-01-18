#ifndef HISTO_H__
#define HISTO_H__
#include "image.h"

/// \brief create the histogramme in an array.
/// \param image: pointer on the Image.
/// \param histo:
void createHisto(Image * image, int *histo);

/// \brief create the graph of the histogramme and save in .ppm.
/// \param histo:
/// \param 
/// \param 
/// \return EXIT_FAILURE in case of problem, else EXIT_SUCCESS.
int histoPPM(int *histo, char *commands[], int nbCommands );

#endif