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

static gridPixel getPixelGrid(int width,int height);
static void testGetDeletePixelGrid();
static void deletePixelGrid(gridPixel grid,int width,int height);
TrianglePicture newTrianglePicture(int width,int height){
	assert(width > 0); assert(height > 0);

	TrianglePicture picture;
	picture = (triangle *)malloc(sizeof (triangle));
	//Exception catcher
	assert(picture != NULL);
	picture->content = getPixelGrid(width,height);
	assert(picture->content != NULL);


	return picture;
}

void myTests(){
	std::cout << "Starting my testing...\n";
	testGetDeletePixelGrid();
	std::cout << "My tests passed. Yeah\n";
}

static void testGetDeletePixelGrid(){
	gridPixel grid;
	grid = getPixelGrid(1,1);
	assert(grid != NULL);

	deletePixelGrid(grid,1,1);

}

static gridPixel getPixelGrid(int width,int height){
	gridPixel grid;
	grid = (gridPixel)malloc(height * sizeof (arrayPixel));
	int i = 0;
	while (i<height){
		grid[i] = (arrayPixel)malloc(width * sizeof (pixel));
		i++;
	}
	return grid;
}

static void deletePixelGrid(gridPixel grid,int width,int height){
	int i = 0;
	while (i<height){
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}
