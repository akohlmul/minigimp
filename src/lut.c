#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lut.h"
#include "image.h"



//init a lut
void initLUT(LutRGB *lut){
	for (int i=0; i<256; i++){
		lut->r[i]=i;
		lut->g[i]=i;
		lut->b[i]=i;
	}
}

/// ADDLUM
void lutADDLUM(LutRGB *lut, int value) {
	for (int i=0; i<256; i++){
		lut->r[i]=lut->r[i]+value;
		lut->g[i]=lut->g[i]+value;
		lut->b[i]=lut->b[i]+value;
	}
}

/// DIMLUM
void lutDIMLUM(LutRGB *lut, int value) {
	for (int i=0; i<256; i++){
		lut->r[i]=lut->r[i]-value;
		lut->g[i]=lut->g[i]-value;
		lut->b[i]=lut->b[i]-value;
	}
}

/// ADDCON
void lutADDCON(LutRGB *lut, int value) {
	for (int i=0; i<256; i++){
		lut->r[i]=lut->r[i]+(value*sin(lut->r[i]*((2*M_PI)/255)-M_PI));
		lut->g[i]=lut->g[i]+(value*sin(lut->g[i]*((2*M_PI)/255)-M_PI));
		lut->b[i]=lut->b[i]+(value*sin(lut->b[i]*((2*M_PI)/255)-M_PI));
	}
}

/// DIMCON
void lutDIMCON(LutRGB *lut, int value) {

}

/// INVERT
void lutINVERT(LutRGB *lut){
	for (int i=0; i<256; i++){
		lut->r[i]=255-lut->r[i];
		lut->g[i]=255-lut->g[i];
		lut->b[i]=255-lut->b[i];
	}
}

/// SEPIA 
void lutSEPIA(LutRGB *lut, int value) {
	for (int i=0; i<256; i++){
		lut->r[i]=((lut->r[i])+(2*value));
		lut->g[i]=((lut->g[i])+(1*value));
		lut->b[i]=((lut->b[i])+(0*value));
	}
}

/// apply the lut to the image
void lutGLOBAL(Image *image, LutRGB *lut){
	unsigned int x, y, r, g, b;
	for(x=0;x<image->width; x++) {
		for(y=0;y<image->height;y++) {
			r = selectPixel(image,x,y,0);
			g = selectPixel(image,x,y,1);
			b = selectPixel(image,x,y,2);
			changePixel(image,x,y,0,lut->r[r]);
			changePixel(image,x,y,1,lut->g[g]);
			changePixel(image,x,y,2,lut->b[b]);
		}
	}
}

/*
/// SEPIA
void lutSEPIA(Image *image) {
	unsigned int x, y, r, v, b;
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
}

/// GRAYSCALE
void lutGRAYSCALE(Image *image) {
	unsigned int x, y, r, v, b;
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
}
*/