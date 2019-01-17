#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "histo.h"
#include "lut.h"

int main(int argc, char **argv)
{
    // create an image
    Image image;

    // load a ppm file
    if(loadImagePPM(&image, argv[1]) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // 
    LutRGB lut;
    initLUT(&lut);

    //
    for (int i = 0; i <argc; i++) {
        if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "-histo") == 0)) {
            int *histogram = (int*)malloc(sizeof(int)*256);
            printf("coucou \n");
            createHisto(&image, histogram);
            printf("coucou2 \n");
            histoPPM(histogram, argv,argc);
            printf("jai tout lu!\n");
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
        if (strcmp(argv[i], "INVERT") == 0) {
            lutINVERT(&lut);
        }
        if (strcmp(argv[i], "SEPIA") == 0) {
            lutSEPIA(&lut, atoi(argv[i+1]));
        }
        /*
        if (strcmp(argv[i], "GRAYSCALE") == 0) {
            lutGRAYSCALE(&lut);
        }
        */
    }
    lutGLOBAL(&image, &lut);
    

    /*
    // histogram
    int *histogram = (int*)malloc(sizeof(int)*256);
    printf("coucou \n");
    createHisto(&image, histogram);
    printf("coucou2 \n");
    histoPPM(histogram, argv,argc);
    printf("jai tout lu!\n");
    */


    /*
    // modify the image (red pixel in the center)
    unsigned int pixel = (image.width*(image.height) + (image.width))*3;
    printf("%d\n",pixel);
    image.data[pixel + 0] = 255;
    image.data[pixel + 1] = 0;
    image.data[pixel + 2] = 0;
    */

    // save the image (if the directory "pics" already exists)
    saveImagePPM(&image, argv[argc-1]);

    // free the image memory
    freeImage(&image);

    return 0;
}
   

