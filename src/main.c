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

    // ADDLUM, DIMLUM, ADDCON, DIMCON, INVERT, SEPIA
    for (int i = 0; i <argc; i++) {
        if (strcmp(argv[i], "ADDLUM") == 0) {
            lutADDLUM(&image, atoi(argv[i+1]));
        }
        if (strcmp(argv[i], "DIMLUM") == 0) {
            lutDIMLUM(&image, atoi(argv[i+1]));
        }
    }

    /**************
    // modify the image (red pixel in the center)
    unsigned int pixel = (image.width*(image.height) + (image.width))*3;
    printf("%d\n",pixel);
    image.data[pixel + 0] = 255;
    image.data[pixel + 1] = 0;
    image.data[pixel + 2] = 0;

    // histogram
    int histogram[256];
    createHisto(&image, histogram);
    histoPPM(histogram, &image, argv,argc);
    *****************/

    // save the image (if the directory "pics" already exists)
    saveImagePPM(&image, argv[argc-1]);

    // free the image memory
    freeImage(&image);

    return 0;
}
   

