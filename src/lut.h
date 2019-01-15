#ifndef LUT_H__
#define LUT_H__

#include "image.h"

/// ADDLUM
/// \brief add luminosity on the image.
/// \param image: pointer on the image.
/// \param value: new pixel value entered by command lines.
void lutADDLUM(Image *image, int value);

/// DIMLUM
/// \brief reduce luminosity on the image.
/// \param image: pointer on the image.
/// \param value: new pixel value entered by command lines.
void lutDIMLUM(Image *image, int value);

/// ADDCON
/// \brief add contrast on the image.
/// \param image: pointer on the image.
/// \param value: new pixel value entered by command lines.
void lutADDCON(Image *image, int value);

/// DIMCON
/// \brief reduce contrast on the image.
/// \param image: pointer on the image.
/// \param value: new pixel value entered by command lines.
void lutDIMCON(Image *image, int value);

/// INVERT
/// \brief create a negative image
/// \param image: pointer on the image.
void lutINVERT(Image *image);

/// SEPIA
/// \brief apply a sepia effect on the image.
/// \param image: pointer on the image.
void lutSEPIA(Image *image);

/// GRAYSCALE
/// \brief put the image in grayscales.
/// \param image: pointer on the image.
void lutGRAYSCALE(Image *image);

#endif
