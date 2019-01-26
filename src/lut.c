#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "lut.h"
#include "image.h"

//init a lut
void initLUT(LutRGB *lut) {
	for (int i=0; i<MAX_SIZE; i++) {
		lut->r[i]=i;
		lut->g[i]=i;
		lut->b[i]=i;
	}
}

/// ADDLUM
void lutADDLUM(LutRGB *lut, int value) {
	for (int i=0; i<MAX_SIZE; i++) {
		lut->r[i]=lut->r[i]+value;
		lut->g[i]=lut->g[i]+value;
		lut->b[i]=lut->b[i]+value;
	}
}

/// DIMLUM
void lutDIMLUM(LutRGB *lut, int value) {
	for (int i=0; i<MAX_SIZE; i++) {
		lut->r[i]=lut->r[i]-value;
		lut->g[i]=lut->g[i]-value;
		lut->b[i]=lut->b[i]-value;
	}
}

/// ADDCON
void lutADDCON(LutRGB *lut, int value) {
	for (int i=0; i<MAX_SIZE; i++){
		lut->r[i]=lut->r[i]+(value*sin(lut->r[i]*((2*M_PI)/255)-M_PI));
		lut->g[i]=lut->g[i]+(value*sin(lut->g[i]*((2*M_PI)/255)-M_PI));
		lut->b[i]=lut->b[i]+(value*sin(lut->b[i]*((2*M_PI)/255)-M_PI));
	}
}

/// DIMCON
void lutDIMCON(LutRGB *lut, int value) {
	for (int i=0; i<MAX_SIZE; i++){
		int red=lut->r[i]-(value*sin(lut->r[i]*((2*M_PI)/255)-M_PI));
		int green=lut->g[i]-(value*sin(lut->g[i]*((2*M_PI)/255)-M_PI));
		int blue=lut->b[i]-(value*sin(lut->b[i]*((2*M_PI)/255)-M_PI));
		if ((lut->r[i]<128 && red>128) || (lut->r[i]>128 && red<128)) {
			red=128;
		}
		if ((lut->g[i]<128 && green>128) || (lut->g[i]>128 && green<128)) {
			green=128;
		}
		if ((lut->b[i]<128 && blue>128) || (lut->b[i]>128 && blue<128)) {
			blue=128;
		}
		lut->r[i]=red;
		lut->g[i]=green;
		lut->b[i]=blue;
	}
}

/// FLOOR
void lutFLOOR(LutRGB *lut, int value) {
	for (int i=0; i<MAX_SIZE; i++) {
		if (lut->r[i]>value) {
			lut->r[i]=255;
		} else {
			lut->r[i]=0;
		}
		if (lut->g[i]>value) {
			lut->g[i]=255;
		} else {
			lut->g[i]=0;
		}
		if (lut->b[i]>value) {
			lut->b[i]=255;
		} else {
			lut->b[i]=0;
		}
	}
}

/// VAPORWAVE
void lutVAPORWAVE(LutRGB *lut, int value, int *histo) {
	for (int i=0; i<MAX_SIZE; i++) {
		lut->r[i]=lut->r[i]*(value/20);
		lut->b[i]=(histo[i]+1);
	}
}

/// INVERT
void lutINVERT(LutRGB *lut) {
	for (int i=0; i<MAX_SIZE; i++) {
		lut->r[i]=255-lut->r[i];
		lut->g[i]=255-lut->g[i];
		lut->b[i]=255-lut->b[i];
	}
}

/// SEPIA 
void lutSEPIA(LutRGB *lut, int value) {
	for (int i=0; i<MAX_SIZE; i++){
		lut->r[i]=((lut->r[i])+(2*value/3));
		lut->g[i]=((lut->g[i])+(1.2*value/3));
	}
}

/// apply the lut to the image
void lutGlobal(Image *image, LutRGB *lut) {
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

/// GRAYSCALE
void GRAYSCALE(Image *image) {
	int average=0;
	unsigned int x, y, r, g, b;
	for(x=0;x<image->width; x++) {
		for(y=0;y<image->height;y++) {
			r = selectPixel(image,x,y,0);
			g = selectPixel(image,x,y,1);
			b = selectPixel(image,x,y,2);
			average=(r+g+b)/3;
			changePixel(image,x,y,0,average);
			changePixel(image,x,y,1,average);
			changePixel(image,x,y,2,average);
		}
	}
}

/// RANDOM
int randomValue () {
	int randValue;
	srand(time(0));
	return randValue = 1+rand()%100;
}