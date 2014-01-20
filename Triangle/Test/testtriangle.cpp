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
void testTrianglePuzzle(){
	cout << "Testing is started...\n";

	testNewDeleteTrianglePicture();

	cout << "All test passed :) yea\n";
}
static void testNewDeleteTrianglePicture(){
	TrianglePicture picture;
	picture = newTrianglePicture(2,3);
	assert(picture != NULL);

//	deleteTrianglePicture(picture);
}

