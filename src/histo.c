/* BOYER Johan, KOHLMULLER Amandine, 26/01/2019 */
#include <stdio.h>
#include <stdlib.h>
#include "histo.h"
#include "image.h"

// create the histogram in an array
void createHisto(Image *image, int *histo) {
    int average;
    for (int i=0; i<256; i++) {
        histo[i]=0;
    }
    for (int i=0; i<3*image->height*image->width-2; i=i+3) {
        average=(image->data[i]/3)+(image->data[i+1]/3)+(image->data[i+2]/3);
        histo[average]=histo[average]+1;
    }
}

// if the histogram is asked: ppm created and saved
int histoPPM(int *histo) {
    // create an image 
    Image histoppm;     
    int width=256;
    int height=0;
    for (int i=0; i<256; i++) {
        histo[i]=histo[i]*0.1;
        if (height<histo[i]) {
            height=histo[i];
        }
    }
    newImage(&histoppm, width, height);

    // create a ppm file
    if(newImage(&histoppm, width, height) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // draw the histogram
    for (int i=0; i<256; i++){
        for (int j=histoppm.height-1; j>=0; j--) {
            int value=50;
            if (histo[i]<height-j) {
                value=255;
            }
            changePixel(&histoppm, i, j, 0, value);
            changePixel(&histoppm, i, j, 1, value);
            changePixel(&histoppm, i, j, 2, value);
        }
    }

    // save the histoppm (if the directory "pics" already exists)
    saveImagePPM(&histoppm, "pics/histo.ppm");

    // free the histoppm memory
    freeImage(&histoppm);

    return EXIT_SUCCESS;
}
