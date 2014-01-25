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
#define NUM_OF_TESTS_RAND 100
using namespace std;

static void testNewDeleteTrianglePicture();
static void testGetSetGetColorPixel();
static void testGetRandomPixel();
static void testGetCenterOF();
static void testDrawLine();
void testTrianglePuzzle() {
	cout << "Testing is started...\n";

	testNewDeleteTrianglePicture();
	testGetSetGetColorPixel();
	testGetRandomPixel();
	testGetCenterOF();
	testDrawLine();

	cout << "All test passed :) yea\n";
}
static void testNewDeleteTrianglePicture() {
	TrianglePicture picture;
	picture = newTrianglePicture(20, 30);
	assert(picture != NULL);

	deleteTrianglePicture(picture);
}

static void testGetSetGetColorPixel() {
	cout << "	testing setPisel, getPixel, getColorPixel functions\n";
	TrianglePicture picture;
	picture = newTrianglePicture(10, 10);
	color colorPixel;
	Pixel pixelFromGrid;

	setPixel(picture, 0, 0);
	pixelFromGrid = getPixel(picture, 0, 0);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == BLACK);

	pixelFromGrid = getPixel(picture, 9, 0);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == WHITE);

	pixelFromGrid = getPixel(picture, 9, 9);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == BLACK);

	pixelFromGrid = getPixel(picture, 10 / 2, 0);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == BLACK);

	pixelFromGrid = getPixel(picture, 0, 9);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == BLACK);

	setPixel(picture, 5, 5);
	pixelFromGrid = getPixel(picture, 5, 5);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == BLACK);

	setPixel(picture, 0, 4);
	pixelFromGrid = getPixel(picture, 0, 4);
	colorPixel = getColorPixel(pixelFromGrid);
	assert(colorPixel == BLACK);

	deleteTrianglePicture(picture);

}
static void testGetRandomPixel() {
	cout << "	testing getRandomPixel\n";

	TrianglePicture picture = newTrianglePicture(20, 30);
	Pixel randPixel = getRandomPixel(picture);
	bool isVertex;

	srand(1);
	int randVertex = rand() % 3;
	switch (randVertex) {
	case 0:
		assert(randPixel == getPixel(picture, 0, 29));
		break;
	case 1:
		assert(randPixel == getPixel(picture, 19, 29));
		break;
	case 2:
		assert(randPixel == getPixel(picture, 10, 0));
		break;
	}
	//getPixel(picture,0,29);//A
	//getPixel(picture,19,29);//B
	//getPixel(picture,10,0);//C
	int counterTest = 0;
	while (counterTest < NUM_OF_TESTS_RAND) {
		randPixel = getRandomPixel(picture);
		isVertex = (getPixel(picture, 0, 29) == randPixel)
				|| (getPixel(picture, 19, 29) == randPixel)
				|| (getPixel(picture, 10, 0) == randPixel);
		assert(isVertex);
		counterTest++;
	}
	deleteTrianglePicture(picture);
}
static void testGetCenterOF() {
	cout << "	testing getCenterOf function...\n";
	TrianglePicture picture = newTrianglePicture(20, 30);
	// centor of horizontal line
	Pixel startPixel, endPixel, midlePixel;
	startPixel = getPixel(picture, 0, 0);
	endPixel = getPixel(picture, 19, 0);
	midlePixel = getPixel(picture, 9, 0);	//19 - 0 / 2
	assert(midlePixel == getCenterOF(picture, startPixel, endPixel));
	// 15 ----- 2
	startPixel = getPixel(picture, 15, 0);
	endPixel = getPixel(picture, 2, 0);
	midlePixel = getPixel(picture, 8, 0);		//2 + 15 - 2 / 2
	assert(midlePixel == getCenterOF(picture, startPixel, endPixel));
	// center of vertical line
	// 0 ------ 29
	startPixel = getPixel(picture, 0, 0);
	endPixel = getPixel(picture, 0, 29);
	midlePixel = getPixel(picture, 0, 14);	//|2 - 0| / 2
	assert(midlePixel == getCenterOF(picture, startPixel, endPixel));
	// 6 ------ 21
	startPixel = getPixel(picture, 0, 20);
	endPixel = getPixel(picture, 0, 5);
	midlePixel = getPixel(picture, 0, 12);	    // 5 + (|5 - 20| / 2)
	assert(midlePixel == getCenterOF(picture, startPixel, endPixel));
	// for any line
	startPixel = getPixel(picture, 5, 5);
	endPixel = getPixel(picture, 10, 10);
	midlePixel = getPixel(picture, 7, 7);
	assert(midlePixel == getCenterOF(picture, startPixel, endPixel));

	startPixel = getPixel(picture, 5, 10);
	endPixel = getPixel(picture, 10, 5);
	midlePixel = getPixel(picture, 7, 7);
	assert(midlePixel == getCenterOF(picture, startPixel, endPixel));

	startPixel = getPixel(picture, 12, 12);
	endPixel = getPixel(picture, 12, 15);
	midlePixel = getPixel(picture, 12, 13);
	assert(midlePixel == getCenterOF(picture, startPixel, endPixel));

	startPixel = getPixel(picture, 12, 15);
	endPixel = getPixel(picture, 12, 12);
	midlePixel = getPixel(picture, 12, 13);
	assert(midlePixel == getCenterOF(picture, startPixel, endPixel));

	startPixel = getPixel(picture, 0, 0);
	endPixel = getPixel(picture, 0, 0);
	midlePixel = getPixel(picture, 0, 0);
	assert(midlePixel == getCenterOF(picture, startPixel, endPixel));

	deleteTrianglePicture(picture);
}
static void testDrawLine() {
	cout << "	testing drawLine function...\n";

	TrianglePicture picture = newTrianglePicture(20, 30);
	Pixel startPixel, endPixel;
	//--- test if draw horizontal line
	startPixel = getPixel(picture, 0, 0);
	endPixel = getPixel(picture, 19, 0);
	drawLine(startPixel, endPixel, picture);
	assert(getColorPixel (getPixel (picture,1,0)) == BLACK);
	//if is consist and for every one pixel in horizontal line
	int i = 0;
	while (i < 20) {
		assert(getColorPixel (getPixel (picture,i,0)) == BLACK);
		assert(getColorPixel (getPixel (picture,i,1)) == WHITE); // !!!!!!!!!
		i++;
	}

	//--- test if draw vertical line
	startPixel = getPixel(picture, 1, 0);
	endPixel = getPixel(picture, 1, 20);
	drawLine(startPixel, endPixel, picture);
	assert(getColorPixel (getPixel (picture,1,1)) == BLACK);
	//if is consist and for every one pixel in horizontal line
	i = 0;
	while (i < 21) {
		assert(getColorPixel (getPixel (picture,1,i)) == BLACK);
		assert(getColorPixel (getPixel (picture,2,(i != 0 ? i: 1))) == WHITE);
		assert(getColorPixel (getPixel (picture,0,(i != 0 ? i: 1))) == WHITE);
		i++;
	}

	//--- test if draw cross line
	// case 3x3
	startPixel = getPixel(picture, 0, 2);
	endPixel = getPixel(picture, 2, 0);
	drawLine(startPixel, endPixel, picture);
	assert(getColorPixel (getPixel (picture,1,1)) == BLACK);
	assert(getColorPixel (getPixel (picture,2,1)) == WHITE); // !!!!!!
	assert(getColorPixel (getPixel (picture,0,1)) == WHITE); // !!!!!!
	// cause 5x5
	startPixel = getPixel(picture, 5, 10);
	endPixel = getPixel(picture, 9, 6);
	drawLine(startPixel, endPixel, picture);
	i = 0;
	while (i < 5) {
		assert(getColorPixel (getPixel (picture,5+i,10+i)) == BLACK);
		assert(getColorPixel (getPixel (picture,4+i,10+i)) == WHITE); // !!!!!!
		assert(getColorPixel (getPixel (picture,6+i,10+i)) == WHITE); // !!!!!!
		i++;
	}

	// cause 4x2
	// cause 8x5
	// cause 2x9
	deleteTrianglePicture(picture);

}
