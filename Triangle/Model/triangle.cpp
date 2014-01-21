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
typedef pixel *arrayPixel;
typedef arrayPixel *gridPixel;

struct pixel{
	color monochromatic = WHITE;
	int coordinateX;
	int coordinateY;
};
struct triangle{
	int width;
	int height;
	pixel A;
	pixel B;
	pixel C;
	gridPixel content;
};

static gridPixel getPixelGrid(int width,int height);
static void testGetDeletePixelGrid();
static void deletePixelGrid(gridPixel grid,int width,int height);
static void setUpPixelGrid(TrianglePicture picture,int width,int height);

TrianglePicture newTrianglePicture(int width,int height){
	assert(width > 0); assert(height > 0);

	TrianglePicture picture;
	picture = (triangle *)malloc(sizeof (triangle));
	//Exception catcher
	assert(picture != NULL);
	picture->width = width;
	picture->height= height;
	picture->content = getPixelGrid(width,height);
	assert(picture->content != NULL);

	setUpPixelGrid(picture,width,height);

	return picture;
}

void deleteTrianglePicture(TrianglePicture picture){
	deletePixelGrid(picture->content,picture->width,picture->height);
	free (picture);
	picture = NULL;
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
	assert(i == height);
	return grid;
}

static void deletePixelGrid(gridPixel grid,int width,int height){
	int i = 0;
	while (i<height){
		free(grid[i]);
		i++;
	}
	assert(i == height);
	free(grid);
	grid = NULL;
}

static void setUpPixelGrid(TrianglePicture picture,int width,int height){
	picture->C.coordinateY = 0;
	picture->C.coordinateX = width/2;
	picture->C.monochromatic = BLACK;

	picture->B.coordinateY = height - 1;
	picture->B.coordinateX = width  - 1;
	picture->B.monochromatic = BLACK;

	picture->A.coordinateY = height - 1;
	picture->A.coordinateX = 0;
	picture->A.monochromatic = BLACK;
	int i = 0;
	int j = 0;
	while (i < height){
		while(j < width){
			picture->content[i][j].coordinateY = i;
			picture->content[i][j].coordinateX = j;
			picture->content[i][j].monochromatic = WHITE;
			j++;
		}
		i++;
	}
	assert(i == height);assert(j == width);
	picture->content[picture->A.coordinateY][picture->A.coordinateX].monochromatic = BLACK;
	picture->content[picture->B.coordinateY][picture->B.coordinateX].monochromatic = BLACK;
	picture->content[picture->C.coordinateY][picture->C.coordinateX].monochromatic = BLACK;
}
void setPixel(TrianglePicture picture,int x,int y){
	assert(x >= 0);assert(y >= 0);
	assert(x < picture->width);assert(y < picture->height);

	picture->content[y][x].monochromatic = BLACK;
}

Pixel getPixel(TrianglePicture picture,int x,int y){
	assert(x >= 0);assert(y >= 0);
	assert(x < picture->width);assert(y < picture->height);
	Pixel pixelFromGrid;
	pixelFromGrid = &(picture->content[y][x]);
	return pixelFromGrid;
}
color getColorPixel(Pixel pixelTriangle){
	color colorPixel;
	colorPixel = pixelTriangle->monochromatic;
	return colorPixel;
}
