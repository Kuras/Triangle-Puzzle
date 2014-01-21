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
static void testSetGetPixel();
void testTrianglePuzzle(){
	cout << "Testing is started...\n";

	testNewDeleteTrianglePicture();
	testSetGetPixel();

	cout << "All test passed :) yea\n";
}
static void testNewDeleteTrianglePicture(){
	TrianglePicture picture;
	picture = newTrianglePicture(2,3);
	assert(picture != NULL);

	deleteTrianglePicture(picture);
}

static void testSetGetPixel(){
	cout << "	testing setPisel function\n";
	TrianglePicture picture;
	picture = newTrianglePicture(2,3);

	setPixel(picture,0,0);
	Pixel pixelFromGrid = getPixel(picture,0,0);
	color colorPixel = getColorPixel(pixelFromGrid);
	assert( colorPixel == BLACK);

	deleteTrianglePicture(picture);

}
