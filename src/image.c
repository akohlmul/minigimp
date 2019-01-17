#include <stdio.h>
#include <stdlib.h>
#include "image.h"


int newImage(Image *image, unsigned int width, unsigned int height)
{
  // memory allocation
  image->data = (unsigned char*) malloc(sizeof(unsigned char) * 3 * width * height);
  if(image->data == NULL){
    printf("newImage : error bad memory allocation.\n");
    return EXIT_FAILURE;
  }

  // update widt and heigh
  image->width  = width;
  image->height = height;

  return EXIT_SUCCESS;
}



void freeImage(Image *image)
{
  if(image != NULL) {
    if(image->data != NULL)	{
	    free(image->data);
      image->data= NULL;
    }

    image->width  = 0;
    image->height = 0;
	}
}



int saveImagePPM(Image *image, char *filename)
{
  // open the file
  FILE *myfile;
  myfile = fopen(filename,"wt");

  // save the data
  if (myfile)
  {
    // generate the header
    char header[100]; // bad way to proceed, but still ok ...
    sprintf(header,"P6\n#M. Nozick is a so nice person ! thanks\n%d %d\n255\n",image->width,image->height);
    fprintf(myfile,"%s",header);

    // write the data
    fwrite(image->data,sizeof(unsigned char),image->width*image->height*3,myfile);

    // close the file
    fclose(myfile);
  }
  else
  {
    printf("saveImagePPM : error opening file %s.\n",filename);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}



// reads only P6
int loadImagePPM(Image *image, char *filename)
{
  FILE *myFile = NULL;
  char chaine[255];
  unsigned int width,height;

  // open the file
  if (!(myFile = fopen(filename, "rt")))
    {
      printf("loadImagePPM : error opening file %s.\n",filename);
      return EXIT_FAILURE;
    }

  // read header
  fscanf(myFile,"%s\n",chaine);

  // read comments ...
  do{ 
    fgets(chaine,255,myFile);
  } while (chaine[0]=='#');
  
  // read width and height
  sscanf(chaine,"%d %d",&width,&height);
  printf("width:  %d\nheight: %d\n",width,height);

  // read the "255"
  fscanf(myFile,"%s\n",chaine);

  // memory allocation
  if(newImage(image,width,height) == EXIT_FAILURE){
    printf("loadImagePPM : memory allocation error\n");
    return EXIT_FAILURE;
  }

  // read the data
  fread(image->data, sizeof (unsigned char), width*height * 3, myFile);

  // close the file
  fclose(myFile);

  return EXIT_SUCCESS;
}



// Select the pixel
int selectPixel(Image *image, unsigned int x, unsigned int y, unsigned int color) {
  unsigned int pixel = ((image->width)*y*3) + (x*3);
  return image->data[pixel + color];
}



// change with new value
void changePixel(Image *image, unsigned int x, unsigned int y, unsigned int color, int value) {
  // if value is smaller than 0 : takes 0, if it's larger than 255 : takes 255, else takes the new value
  if (value < 0) {
    image->data[((image->width)*y*3) + (x*3) + color] = 0;
  } else if (value >= 255) {
    image->data[((image->width)*y*3) + (x*3) + color] = 255;
  } else {
    image->data[((image->width)*y*3) + (x*3) + color] = value;
  }
}
