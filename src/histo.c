#include <stdio.h>
#include <stdlib.h>
#include "histo.h"


// create the histogramme in an array
void createHisto(Image * image, int histo[]) {
    int average;
    for (int i=0; i<256; i++){
        histo[i]=0;
    }
    for (int j=0; j<3*image->height*image->width; j++){
        average=(image->data[j]+image->data[j+1]+image->data[j+2])/3;
        histo[average]++;
    }
}

//If the histogramme is asked: ppm created and saved
void histoPPM(int *histo[], Image *image,char commands[],int nbCommands){
	// create an image
    Image histoppm;
    histoppm.data=histo;
    histoppm.width=256;
    histoppm.height=0;
    for(int i=0; i<(3*(image->height)*(image->width)); i++)
    	if (histoppm.data[i]>histoppm.height) histoppm.height=histoppm.data[i];

    // load a ppm file
    if(loadImagePPM(&histoppm,&commands[1]) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // save the histoppm (if the directory "pics" already exists)
    saveImagePPM(&histoppm, &commands[nbCommands-1]);

    // free the histoppm memory
    freeImage(&histoppm);
}