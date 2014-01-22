/*
 * testtriangle.cpp
 *
 *  Created on: 18 sty 2014
 *      Author: Baraka
 */

#include "testtriangle.h"
#include "../Model/triangle.h"
#include<iostream>
#include<cstdlib>
#include<assert.h>
using namespace std;

static void testNewDeleteTrianglePicture();
static void testGetSetGetColorPixel();
static void testGetRandomPixel();

void testTrianglePuzzle(){
	cout << "Testing is started...\n";

	testNewDeleteTrianglePicture();
	testGetSetGetColorPixel();
//	testGetRandomPixel();

	cout << "All test passed :) yea\n";
}
static void testNewDeleteTrianglePicture(){
	TrianglePicture picture;
	picture = newTrianglePicture(2,3);
	assert(picture != NULL);

	deleteTrianglePicture(picture);
}

static void testGetSetGetColorPixel(){
	cout << "	testing setPisel, getPixel, getColorPixel functions\n";
	TrianglePicture picture;
	picture = newTrianglePicture(10,10);
	color colorPixel;
	Pixel pixelFromGrid;

	setPixel(picture,0,0);
	pixelFromGrid = getPixel(picture,0,0);
	colorPixel = getColorPixel(pixelFromGrid);
	assert( colorPixel == BLACK);

	pixelFromGrid = getPixel(picture,9,0);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == WHITE);

	pixelFromGrid = getPixel(picture,9,9);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == BLACK);

	pixelFromGrid = getPixel(picture,10/2,0);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == BLACK);

	pixelFromGrid = getPixel(picture,0,9);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == BLACK);

	setPixel(picture,5,5);
	pixelFromGrid = getPixel(picture,5,5);
	colorPixel = getColorPixel(pixelFromGrid);
	assert( colorPixel == BLACK);

	deleteTrianglePicture(picture);

}
static void testGetRandomPixel(){
	cout << "	testing getRandomPixel";

	TrianglePicture picture = newTrianglePicture(20,30);
	Pixel randPixel = getRandomPixel(picture);
	bool isVertex;
	//getPixel(picture,0,29);//A
	//getPixel(picture,19,29);//B
	//getPixel(picture,10,0);//C
	isVertex = (getPixel(picture,0,29) == randPixel)||(getPixel(picture,19,29) == randPixel)||(getPixel(picture,10,0) == randPixel);
	assert(isVertex);

}
