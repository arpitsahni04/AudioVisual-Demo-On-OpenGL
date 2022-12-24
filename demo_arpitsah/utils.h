#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "string"
#include "yspng.h"
#include "fssimplewindow.h"
#include "ysglfontdata.h"

class utils {

public:
	static void loadTexture(YsRawPngDecoder& theDecoder, GLuint& TextureId);

	static void showImage(GLuint textureID, int x, int y, int sizeX, int sizeY,double angle = 0);

	static void drawTimer(double time);

};