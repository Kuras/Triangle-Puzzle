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
typedef struct triangle trainglePicture;
typedef struct pixel pixel;
typedef int color;

struct pixel{
	color monochromatic = WHITE;
	int coordinateX;
	int coordinateY;
};
struct triangle{
	pixel A;
	pixel B;
	pixel C;
	//pixel content [][];
	pixel **content;
};

TrianglePicture newTrianglePicture(int width,int height){
	assert(width > 0); assert(height > 0);

	TrianglePicture picture;
	picture = (TrianglePicture *)malloc(sizeof(trainglePicture));

	return picture;
}
