#include <stdio.h>
#include <stdlib.h>
#include "histo.h"
#include "image.h"

// create the histogram in an array
void createHisto(Image * image, int *histo) {
    int average;
    for (int i=0; i<256; i++){
        histo[i]=0;

    }
    for (int i=0; i<3*image->height*image->width-2; i=i+3){
        average=(image->data[i]/3)+(image->data[i+1]/3)+(image->data[i+2]/3);
        histo[average]=histo[average]+1;
    }
}

//If the histogram is asked: ppm created and saved
int histoPPM(int *histo,char *commands[],int nbCommands){
    // create an image 
    Image histoppm;     
    int width=256;
    int height=0;
    for (int i=0; i<256; i++){
        if (height<histo[i]) 
            height=histo[i];
    }
    height=0.1*height;
    printf("bonjour");
    newImage(&histoppm, width, height);
    printf("bonjour2");
    // create a ppm file
    if(newImage(&histoppm, width, height) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    printf("bonjour3");
    //draw the histogram
    int r, v, b;
    for (int i=0; i<256; i++){
        for (int j=histoppm.height-1; j>=0; j--){
            r=selectPixel(&histoppm, i, j, 0);
            v=selectPixel(&histoppm, i, j, 1);
            b=selectPixel(&histoppm, i, j, 2);
            int value=0;
            if (histo[i]<height-j) {
                int value=255;
            changePixel(&histoppm, i, j, r, value);
            changePixel(&histoppm, i, j, v, value);
            changePixel(&histoppm, i, j, b, value);
            }
        }
    }
    printf("bonjour4");
    // save the histoppm (if the directory "pics" already exists)
    saveImagePPM(&histoppm, "histo");
    printf("je suis là6\n");
    // free the histoppm memory
    freeImage(&histoppm);
    printf("je suis là7\n");
    return EXIT_SUCCESS;

}
