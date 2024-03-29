/*
 * triangle.cpp
 *
 *  Created on: 18 sty 2014
 *      Author: Baraka
 */

#include "triangle.h"
#include<iostream>
#include<cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstdio>
typedef pixel *arrayPixel;
typedef arrayPixel *gridPixel;

struct pixel {
	color monochromatic = WHITE;
	int coordinateX;
	int coordinateY;
};
struct triangle {
	int width;
	int height;
	Pixel A;
	Pixel B;
	Pixel C;
	gridPixel content;
};

static gridPixel getPixelGrid(int width, int height);
static void testGetDeletePixelGrid();
static void deletePixelGrid(gridPixel grid, int width, int height);
static void setUpPixelGrid(TrianglePicture picture, int width, int height);
static void showPixelGrid(TrianglePicture picture);
TrianglePicture newTrianglePicture(int width, int height) {
	assert(width > 0);
	assert(height > 0);

	TrianglePicture picture;
	picture = (triangle *) malloc(sizeof(triangle));
	//Exception catcher
	assert(picture != NULL);
	picture->width = width;
	picture->height = height;
	picture->content = getPixelGrid(width, height);
	assert(picture->content != NULL);

	setUpPixelGrid(picture, width, height);
//	showPixelGrid(picture);

	return picture;
}

void deleteTrianglePicture(TrianglePicture picture) {
	deletePixelGrid(picture->content, picture->width, picture->height);
	free(picture);
	picture = NULL;
}

void myTests() {
	std::cout << "Starting my testing...\n";
	testGetDeletePixelGrid();
	std::cout << "My tests passed. Yeah\n";
}

static void testGetDeletePixelGrid() {
	gridPixel grid;
	grid = getPixelGrid(1, 1);
	assert(grid != NULL);

	deletePixelGrid(grid, 1, 1);

}

static gridPixel getPixelGrid(int width, int height) {
	gridPixel grid;
	grid = (gridPixel) malloc(height * sizeof(arrayPixel));
	assert(grid != NULL);
	int i = 0;
	while (i < height) {
		grid[i] = (arrayPixel) malloc(width * sizeof(pixel));
		assert(grid[i] != NULL);
		i++;
	}
	assert(i == height);
	return grid;
}

static void deletePixelGrid(gridPixel grid, int width, int height) {
	int i = 0;
	while (i < height) {
		free(grid[i]);
		i++;
	}
	assert(i == height);
	free(grid);
	grid = NULL;
}

static void setUpPixelGrid(TrianglePicture picture, int width, int height) {

	int i = 0;
	int j = 0;
	while (i < height) {
		j = 0;
		while (j < width) {
			picture->content[i][j].coordinateY = i;
			picture->content[i][j].coordinateX = j;
			picture->content[i][j].monochromatic = WHITE;
			j++;
		}
		i++;
	}
	assert(i == height);
	assert(j == width);

	picture->content[height - 1][0].monochromatic = BLACK;
	picture->content[height - 1][width - 1].monochromatic = BLACK;
	picture->content[0][width / 2].monochromatic = BLACK;

	picture->C = &(picture->content[0][width / 2]);
	picture->B = &(picture->content[height - 1][width - 1]);
	picture->A = &(picture->content[height - 1][0]);

}
void setPixel(TrianglePicture picture, int x, int y) {
	assert(x >= 0);
	assert(y >= 0);
	assert(x < picture->width);
	assert(y < picture->height);

	picture->content[y][x].monochromatic = BLACK;
}

Pixel getPixel(TrianglePicture picture, int x, int y) {
	assert(x >= 0);
	assert(y >= 0);
	assert(x < picture->width);
	assert(y < picture->height);
	Pixel pixelFromGrid;
	pixelFromGrid = &(picture->content[y][x]);

	return pixelFromGrid;
}
color getColorPixel(Pixel pixelTriangle) {
	color colorPixel;
	colorPixel = pixelTriangle->monochromatic;
	return colorPixel;
}

Pixel getRandomPixel(TrianglePicture picture) {
	Pixel randPixel;
	enum {
		VERTEX_A, VERTEX_B, VERTEX_C
	};
	//srand(time(NULL));
	int randVertex = rand() % 3;
	switch (randVertex) {
	case VERTEX_A:
		randPixel = picture->A;
		break;
	case VERTEX_B:
		randPixel = picture->B;
		break;
	case VERTEX_C:
		randPixel = picture->C;
		break;
	default:
		randPixel = picture->A;
	}

	return randPixel;
}

Pixel getCenterOF(TrianglePicture picture, Pixel pixelStart, Pixel pixelEnd) {
	Pixel centerPixel;
	int centerOfXline, centerOfYline;
	if (pixelStart->coordinateX <= pixelEnd->coordinateX) {
		centerOfXline = pixelStart->coordinateX
				+ (pixelEnd->coordinateX - pixelStart->coordinateX) / 2;
	} else {
		centerOfXline = pixelEnd->coordinateX
				+ (pixelStart->coordinateX - pixelEnd->coordinateX) / 2;
	}

	if (pixelStart->coordinateY <= pixelEnd->coordinateY) {
		centerOfYline = ((pixelEnd->coordinateY - pixelStart->coordinateY) / 2)
				+ pixelStart->coordinateY;
	} else {
		centerOfYline = ((pixelStart->coordinateY - pixelEnd->coordinateY) / 2)
				+ pixelEnd->coordinateY;
	}
	centerPixel = getPixel(picture, centerOfXline, centerOfYline);
	return centerPixel;
}

static void showPixelGrid(TrianglePicture picture) {
	int i = 0;
	int j = 0;
	while (i < picture->height) {
		j = 0;
		while (j < picture->width) {
			std::cout << "(" << picture->content[i][j].coordinateY << ","
					<< picture->content[i][j].coordinateX << ")";
			//std::cout << "("<< i << ","<< j << ")";
			j++;
		}
		std::cout << "\n";
		i++;
	}
	assert(i == picture->height);
	assert(j == picture->width);

}
void drawLine(Pixel pixelStart, Pixel pixelEnd, TrianglePicture picture) {
	Pixel startPixel = pixelStart;
	Pixel endPixel = pixelEnd;
	unsigned int diffInXLine, diffInYLine;
	int coeficient;
	double angleOfInclination;

	if (pixelStart->coordinateX >= pixelEnd->coordinateX) {
		startPixel = pixelEnd;
		endPixel = pixelStart;
	}
	if (startPixel->coordinateY <= endPixel->coordinateY) {
		coeficient = 1;
	} else {
		coeficient = -1;
	}
	diffInXLine = abs(endPixel->coordinateX - startPixel->coordinateX) + 1;
	diffInYLine = abs(endPixel->coordinateY - startPixel->coordinateY) + 1;
	angleOfInclination = (double) diffInYLine / (double) diffInXLine;
	unsigned int i = 0, j = 0;
	double increaser = 0.0;
	if (angleOfInclination <= 1) {
		while (i < diffInXLine) {
			setPixel(picture, startPixel->coordinateX + i,
					startPixel->coordinateY + (int) increaser * coeficient);
			i++;
			increaser += angleOfInclination;
		}
		assert(i == diffInXLine);
	} else {
		angleOfInclination = 1.0 / angleOfInclination;
		while (j < diffInYLine) {
			setPixel(picture, startPixel->coordinateX + (int) increaser,
					startPixel->coordinateY + j * coeficient);
			j++;
			increaser += angleOfInclination;
		}
		assert(j == diffInYLine);
	}

}

void savePictureOnDisc(TrianglePicture picture) {
	FILE *pictureFile;
	pictureFile = fopen("trianglePicture.ppm", "w");
	assert(pictureFile != NULL);
	fputs("P1\n", pictureFile);
	fprintf(pictureFile,"%d ",picture->width);
	fprintf(pictureFile,"%d\n",picture->height);

	int i = 0, j = 0;
	while (i < picture->height) {
		j = 0;
		while (j < picture->width) {
			putc(getColorPixel(getPixel(picture, j, i)), pictureFile);
			j++;
		}
		i++;
	}
	fclose(pictureFile);
	assert(i == picture->height);
	assert(j == picture->width);
}
