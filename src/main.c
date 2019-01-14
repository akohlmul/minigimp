#include <stdio.h>
#include <stdlib.h>

#include "image.h"
#include "lut.h"

int main(int argc, char **argv)
{
    // create an image
    Image image;

    // load a ppm file
    if(loadImagePPM(&image, argv[1]) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // modify the image (red pixel in the center)
    unsigned int pixel = (image.width*(image.height/2) + (image.width/2))*3;
    printf("%d\n",pixel);
    image.data[pixel + 0] = 255;
    image.data[pixel + 1] = 0;
    image.data[pixel + 2] = 0;

    // save the image (if the directory "pics" already exists)
    saveImagePPM(&image, argv[argc-1]);

    // free the image memory
    freeImage(&image);

    return 0;
}
   

