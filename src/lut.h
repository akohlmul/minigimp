#ifndef LUT_H__
#define LUT_H__
#include "image.h"

/// \brief structure that contains Look-up tables.
typedef struct LutRGB {
	int r[256];
	int g[256];
	int b[256];
} LutRGB;

/// INIT LUT
/// \brief create new lutRGB.
/// \param lut: pointer on the lutRGB.
void initLUT (LutRGB *lut);

/// ADDLUM
/// \brief add luminosity on the image.
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutADDLUM(LutRGB *lut, int value);

/// DIMLUM
/// \brief reduce luminosity on the image.
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutDIMLUM(LutRGB *lut, int value);

/// ADDCON
/// \brief add contrast on the image.
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutADDCON(LutRGB *lut, int value);

/// DIMCON
/// \brief reduce contrast on the image.
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutDIMCON(LutRGB *lut, int value);

/// FLOOR
/// \brief
/// \param lut: pointer on the lutRGB.
/// \param value: new pixel value entered by command lines.
void lutFLOOR(LutRGB *lut, int value);

/// INVERT
/// \brief create a negative image.
/// \param lut: pointer on the lutRGB.
void lutINVERT(LutRGB *lut);

/// SEPIA WITH PARAM
/// \brief apply a sepia effect on the image.
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

#endif