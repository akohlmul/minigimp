#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "histo.h"
#include "lut.h"

int main(int argc, char **argv) {
    
    // create an image
    Image image;

    // load a ppm file
    if(loadImagePPM(&image, argv[1]) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // create a Lut RGB
    LutRGB lut;

    // inite the lut
    initLUT(&lut);

    //
    for (int i = 0; i <argc; i++) {
        if (strcmp(argv[i], "-histo") == 0) {
            int *histogram = (int*)malloc(sizeof(int)*256);
            createHisto(&image, histogram);
            histoPPM(histogram, argv,argc);
        }
        if (strcmp(argv[i], "ADDLUM") == 0) {
            lutADDLUM(&lut, atoi(argv[i+1]));
        }
        if (strcmp(argv[i], "DIMLUM") == 0) {
            lutDIMLUM(&lut, atoi(argv[i+1]));
        }
        if (strcmp(argv[i], "ADDCON") == 0) {
            lutADDCON(&lut, atoi(argv[i+1]));
        }
        if (strcmp(argv[i], "DIMCON") == 0) {
            lutDIMCON(&lut, atoi(argv[i+1]));
        }
        if (strcmp(argv[i], "FLOOR") == 0) {
            lutFLOOR(&lut, atoi(argv[i+1]));
        }
        if (strcmp(argv[i], "INVERT") == 0) {
            lutINVERT(&lut);
        }
        if (strcmp(argv[i], "SEPIA") == 0) {
            GRAYSCALE(&image);
            lutSEPIA(&lut, atoi(argv[i+1]));    
        }
        if (strcmp(argv[i], "GRAYSCALE") == 0) {
            GRAYSCALE(&image);
        }
    }

    // 
    lutGlobal(&image, &lut);

    // save the image (if the directory "pics" already exists)
    saveImagePPM(&image, argv[argc-1]);

    // free the image memory
    freeImage(&image);

    return 0;
}