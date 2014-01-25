/*
 * main.cpp
 *
 *  Created on: 16 sty 2014
 *      Author: Baraka
 */
#include "../Model/triangle.h"
#include "../Test/testtriangle.h"
#include<iostream>
#include<cstdlib>
#include <stdio.h>
using namespace std;

int steps = 1000;
int width = 1100;
int hight = 600;
static void symulation(int countOfSteps, TrianglePicture picture);

int main (void){

//	testTrianglePuzzle();
//	myTests();
	TrianglePicture picture;
	picture = newTrianglePicture(width,hight);

	symulation(steps,picture);

	savePictureOnDisc(picture);

	deleteTrianglePicture(picture);

	printf("Symulation is ended.");

	return EXIT_SUCCESS;
}

static void symulation(int countOfSteps, TrianglePicture picture){
	Pixel firstPixel = getRandomPixel(picture);
	Pixel secondPixel;
	Pixel centerPixel;

	int step = 0;
	while (step < countOfSteps){
		secondPixel = getRandomPixel(picture);
		centerPixel = getCenterOF(picture,firstPixel,secondPixel);
		drawLine(firstPixel,centerPixel,picture);

		firstPixel = centerPixel;
		step++;
	}
}




