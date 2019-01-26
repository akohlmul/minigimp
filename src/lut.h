#ifndef LUT_H__
#define LUT_H__
#include "image.h"
#define MAX_SIZE 256

/// \brief structure that contains Look-up tables.
typedef struct LutRGB {
	unsigned int r[MAX_SIZE];
	unsigned int g[MAX_SIZE];
	unsigned int b[MAX_SIZE];
} LutRGB;

/// INIT LUT
/// \brief create new lutRGB.
/// \param lut: pointer on the lutRGB.
void initLUT (LutRGB *lut);

/// ADDLUM
/// \brief add luminosity.
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutADDLUM(LutRGB *lut, int value);

/// DIMLUM
/// \brief reduce luminosity.
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutDIMLUM(LutRGB *lut, int value);

/// ADDCON
/// \brief add contrast.
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutADDCON(LutRGB *lut, int value);

/// DIMCON
/// \brief reduce contrast.
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutDIMCON(LutRGB *lut, int value);

/// FLOOR
/// \brief 
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutFLOOR(LutRGB *lut, int value);

/// VAPORWAVE
/// \brief change value of the red and use histogram for the blue
/// \pram lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
/// \param histo: pointer on the histogram.
void lutVAPORWAVE(LutRGB *lut, int value, int *histo);

/// INVERT
/// \brief invert values to create a negative image.
/// \param lut: pointer on the lutRGB.
void lutINVERT(LutRGB *lut);

/// SEPIA 
/// \brief add a sepia effect.
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutSEPIA(LutRGB *lut, int value);

/// GLOBAL LUT
/// \brief apply the lut to the image.
/// \param image: pointer on the Image.
/// \param lut: pointer on the lutRGB.
void lutGlobal(Image *image, LutRGB *lut);

/// GRAYSCALE
/// \brief put the image in grayscales.
/// \param image: pointer on the image.
void GRAYSCALE(Image *image);

/// RANDOM
/// \brief create a random value.
/// \return a random value.
int randomValue();

#endif