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
	int x, y;
	int r, v, b;

	for(x=0;x<image->width; x++) {
		for(y=0;y<image->height;y++) {
			r = selectPixel(image,x,y,0);
			v = selectPixel(image,x,y,1);
			b = selectPixel(image,x,y,2);
			changePixel(image,x,y,0,(255-r));
			changePixel(image,x,y,1,(255-v));
			changePixel(image,x,y,2,(255-b));
		}
	}
	return EXIT_SUCCESS;
}

/// SEPIA
int lutSEPIA(Image *image) {
	int x, y;
	int r, v, b;

	for(x=0;x<image->width; x++) {
		for(y=0;y<image->height;y++) {
			r = selectPixel(image,x,y,0);
			v = selectPixel(image,x,y,1);
			b = selectPixel(image,x,y,2);
			changePixel(image,x,y,0,(r*0.40+v*0.80+b*0.25));
			changePixel(image,x,y,1,(r*0.3+v*0.7+b*0.15));
			changePixel(image,x,y,2,(r*0.25+v*0.65+b*0.1));
		}
	}
	return EXIT_SUCCESS;
}

/// GRAYSCALE
int lutGRAYSCALE(Image *image) {
	int x, y;
	int r, v, b;

	for(x=0;x<image->width; x++) {
		for(y=0;y<image->height;y++) {
			r = selectPixel(image,x,y,0);
			v = selectPixel(image,x,y,1);
			b = selectPixel(image,x,y,2);
			changePixel(image,x,y,0,(r*0.3+v*0.59+b*0.11));
			changePixel(image,x,y,1,(r*0.3+v*0.59+b*0.11));
			changePixel(image,x,y,2,(r*0.3+v*0.59+b*0.11));
		}
	}
	return EXIT_SUCCESS;
}