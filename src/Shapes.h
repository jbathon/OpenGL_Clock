//
// Created by jaden on 9/15/2022.
//

#ifndef OPENGL_CLOCK_SHAPES_H
#define OPENGL_CLOCK_SHAPES_H

#include <GL/gl.h>
#include <GL/freeglut.h>
#include "Color.h"


/**** Shapes ****/
void myGLCircle(float xOffset, float yOffset, float scale, Color color);

void myGLRectangleOutline(float width, float height, float xOffset, float yOffset, Color color);

void myGLDigitalDiamondV(float xOffset, float yOffset, float scale, Color color);

void myGLDigitalDiamondH(float xOffset, float yOffset, float scale, Color color);

/**** Numbers ****/
void myGLZero(float xOffset, float yOffset, float scale, Color color);

void myGLOne(float xOffset, float yOffset, float scale, Color color);

void myGLTwo(float xOffset, float yOffset, float scale, Color color);

void myGLThree(float xOffset, float yOffset, float scale, Color color);

void myGLFour(float xOffset, float yOffset, float scale, Color color);

void myGLFive(float xOffset, float yOffset, float scale, Color color);

void myGLSix(float xOffset, float yOffset, float scale, Color color);

void myGLSeven(float xOffset, float yOffset, float scale, Color color);

void myGLEight(float xOffset, float yOffset, float scale, Color color);

void myGLNine(float xOffset, float yOffset, float scale, Color color);


/** Clock Shapes **/

void myGLClockTicks(float xOffset, float yOffset, float scale);

void glClockNumbers(float xOffset, float yOffset, float scale);

void myGLHourHand(int h, float xOffset, float yOffset, float scale);

void myGLMinuteHand(int min, float xOffset, float yOffset, float scale);

void myGLSecondHand(int sec, float xOffset, float yOffset, float scale);

void myGLClockHands(float xOffset, float yOffset, float scale);

void myGLDigitalClock(float xOffset, float yOffset, float scale);

void myGLAnalogClock(float xOffset, float yOffset, float scale);

#endif //OPENGL_CLOCK_SHAPES_H
