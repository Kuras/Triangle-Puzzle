/*
 * main.cpp
 *
 *  Created on: 16 sty 2014
 *      Author: Baraka
 */
#include "../Model/triangle.h"
#include<iostream>
#include<cstdlib>
using namespace std;

int steps = 1000;
int width = 1000;
int hight = 1000;
static void symulation(int step, TrianglePicture picture);

int main (void){

	TrianglePicture picture;
	picture = newTrianglePicture(width,hight);

	symulation(steps,picture);

	savePictureOnDisc(picture);

	deleteTrianglePicture(picture);

	return EXIT_SUCCESS;
}

static void symulation(int countOfSteps, TrianglePicture picture){
	pixel firstPixel = getRandomPixel(picture);
	pixel secondPixel;
	pixel centerPixel;

	int step = 0;
	while (step < countOfSteps){
		secondPixel = getRandomPixel(picture);
		centerPixel = getCenterOF(firstPixel,secondPixel,picture);
		drawLine(firstPixel,centerPixel,picture);

		firstPixel = centerPixel;
		step++;
	}
}




