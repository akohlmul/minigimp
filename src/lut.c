#include <stdio.h>
#include <stdlib.h>
#include "lut.h"
#include "image.h"

/// ADDLUM
int lutADDLUM(Image *image, int value) {
	int x, y;
	int r, v, b;

	for(x=0;x<image->width; x++) {
		for(y=0;y<image->height;y++) {
			r = selectPixel(image,x,y,0);
			v = selectPixel(image,x,y,1);
			b = selectPixel(image,x,y,2);
			changePixel(image,x,y,0,(r+value));
			changePixel(image,x,y,1,(v+value));
			changePixel(image,x,y,2,(b+value));
		}
	}
	return EXIT_SUCCESS;
}


/// DIMLUM
int lutDIMLUM(Image *image, int value) {
	int x, y;
	int r, v, b;

	for(x=0;x<image->width; x++) {
		for(y=0;y<image->height;y++) {
			r = selectPixel(image,x,y,0);
			v = selectPixel(image,x,y,1);
			b = selectPixel(image,x,y,2);
			changePixel(image,x,y,0,(r-value));
			changePixel(image,x,y,1,(v-value));
			changePixel(image,x,y,2,(b-value));
		}
	}
	return EXIT_SUCCESS;
}


/// ADDCON
int lutADDCON(Image *image, int value) {

}

/// DIMCON
int lutDIMCON(Image *image, int value) {

}

/// INVERT
int lutINVERT(Image *image){

}

/// SEPIA
int lutSEPIA(Image *image) {

}

