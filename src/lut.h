#ifndef LUT_H__
#define LUT_H__

#include "image.h"

/// ADDLUM
int lutADDLUM(Image *image, int value);

/// DIMLUM
int lutDIMLUM(Image *image, int value);

/// ADDCON
int lutADDCON(Image *image, int value);

/// DIMCON
int lutDIMCON(Image *image, int value);

/// INVERT
int lutINVERT(Image *image);

/// SEPIA
int lutSEPIA(Image *image);

/// GRAYSCALE
int lutGRAYSCALE(Image *image);

#endif
