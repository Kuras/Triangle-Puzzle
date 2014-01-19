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

struct pixel{
	color monochromatic = WHITE;
	int coordinateX;
	int coordinateY;
};
///////////////////////////Create a user input size
//int size = 5;

//Create the array with the size the user input
//	int *myArray = new int[size];
//Delete the array
//	delete[] myArray;
//---------------- in C ----------
//int *myArray = (int *) malloc(size*2);
//char *myChar = (char *) malloc(size);

struct triangle{
	pixel A;
	pixel B;
	pixel C;
	//pixel content [][];
	pixel **content;
	// starats fro one dim. array
};

TrianglePicture newTrianglePicture(int width,int height){
	assert(width > 0); assert(height > 0);

	TrianglePicture picture;
	picture = (triangle *)malloc(sizeof (triangle));
	//Exception catcher
	assert(picture != NULL);
	//create pixel grid with certain size
	pixel *contentRow = (pixel *)malloc(width * sizeof (pixel));
	assert(contentRow != NULL);
	picture->content = (pixel **)malloc(height * sizeof (contentRow));
	assert(picture->content != NULL);

	return picture;
}
