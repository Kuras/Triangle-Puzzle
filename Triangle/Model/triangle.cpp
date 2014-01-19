/*
 * triangle.cpp
 *
 *  Created on: 18 sty 2014
 *      Author: Baraka
 */

#include "triangle.h"
#include<iostream>
#include<cstdlib>
#include <assert.h>
typedef int color;
typedef pixel *arrayPixel;
typedef arrayPixel *gridPixel;

struct pixel{
	color monochromatic = WHITE;
	int coordinateX;
	int coordinateY;
};
struct triangle{
	pixel A;
	pixel B;
	pixel C;
	gridPixel content;
};

TrianglePicture newTrianglePicture(int width,int height){
	assert(width > 0); assert(height > 0);

	TrianglePicture picture;
	picture = (triangle *)malloc(sizeof (triangle));
	//Exception catcher
	assert(picture != NULL);
		arrayPixel arrayRow = (arrayPixel)malloc(width * sizeof (pixel));
		assert(arrayRow != NULL);
		picture->content = (gridPixel)malloc(height * sizeof (arrayRow));
		assert(picture->content != NULL);


	return picture;
}
