/*
 * triangle.h
 *
 *  Created on: 16 sty 2014
 *      Author: Baraka
 */

#define WHITE 0
#define BLACK 1
typedef struct pixel *Pixel;
typedef struct triangle *TrianglePicture;

//assumes that width and height are pozitive number
//returns grid of pixeles with given size
TrianglePicture newTrianglePicture(int width,int height);

//free memory witch is occupeted by picture
void deleteTrianglePicture(TrianglePicture picture);

//color poixel in position x,y on black
//assume that x and y are possitive
void setPixel(TrianglePicture picture,int x,int y);

//returns pixel for given location in grid
// assumes that x and y are in right range
Pixel getPixel(TrianglePicture picture,int x,int y);

//returns one of three vertex(pixel) of Triangle ABC
Pixel getRandomPixel(TrianglePicture picture);

// assumes that pixel are from picture
// returns pixel witch is on the medium of line between two given pixels
Pixel getCenterOF(Pixel pixelStart, Pixel pixelEnd, TrianglePicture picture);

// draw line in picture between two given pixels (DDA)-algorithm
void drawLine(Pixel pixelStart, Pixel pixelEnd, TrianglePicture picture);

// write picture in file with ppm format
void savePictureOnDisc(TrianglePicture picture);

void myTests();
