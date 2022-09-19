//
// Created by jaden on 9/15/2022.
//

#include "Shapes.h"
#include <cmath>
#include <time.h>
#include <iostream>

/********************/
/**  Basic Shapes  **/
/********************/

void myGLCircle(float xOffset, float yOffset, float scale, Color color) {

    float x, y;
    float radius = 100.0f * scale;
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        x = radius * cos(i * (M_PI / 180.0f)) + xOffset;
        y = radius * sin(i * (M_PI / 180.0f)) + yOffset;
        glColor4ub(color.getRed(), color.getBlue(), color.getGreen(), color.getAlpha());
        glVertex2d(x, y);
    }
    glEnd();

}

void myGLRectangle(float width, float height, float xOffset, float yOffset, Color color) {
    glBegin(GL_POLYGON);
    glColor4ub(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    glVertex2d(xOffset, yOffset + height);
    glVertex2d(xOffset + (width / 2), yOffset + height);
    glVertex2d(xOffset + (width / 2), yOffset - height);
    glVertex2d(xOffset, yOffset - height);
    glVertex2d(xOffset - (width / 2), yOffset - height);
    glVertex2d(xOffset - (width / 2), yOffset + height);
    glEnd();
}

void myGLRectangleOutline(float width, float height, float xOffset, float yOffset, Color color) {
    glBegin(GL_LINE_LOOP);
    glColor4ub(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    glVertex2d(xOffset, yOffset + height);
    glVertex2d(xOffset + (width / 2), yOffset + height);
    glVertex2d(xOffset + (width / 2), yOffset - height);
    glVertex2d(xOffset, yOffset - height);
    glVertex2d(xOffset - (width / 2), yOffset - height);
    glVertex2d(xOffset - (width / 2), yOffset + height);
    glEnd();
}

/*******************/
/**  Clock Parts  **/
/*******************/


void myGLClockTicks(float xOffset, float yOffset, float scale) {
    float x, y;
    float radius = 100.0f * scale;

    glBegin(GL_LINES);
    for (int i = 0; i <= 360; i = i + 6) {

        /**** Start Point ****/
        x = radius * cos(i * (M_PI / 180.0f)) + xOffset;
        y = radius * sin(i * (M_PI / 180.0f)) + yOffset;
        glColor3ub(0, 0, 0);
        glVertex2d(x, y);

        /**** End Point ****/
        float tickLength;
        if (i % 5 == 0) tickLength = 15.0f * scale;
        else tickLength = 15.0f / 2.0f * scale;
        x = (radius - tickLength) * cos(i * (M_PI / 180.0f)) + xOffset;
        y = (radius - tickLength) * sin(i * (M_PI / 180.0f)) + yOffset;
        glColor3ub(0, 0, 0);
        glVertex2d(x, y);
    }
    glEnd();
}

void myGLClockNumbers(float xOffset, float yOffset, float scale) {

    const float NUM_SCALE = 0.04 * scale;
    float x, y;
    float radius = 100.0f * scale;

    Color black = Color(0, 0, 0);

    int numberCount = 3;


    for (int i = 0; i <= 360; i = i + 30) {

        x = (radius - 55) * cos(i * (M_PI / 180.0f)) + xOffset;
        y = (radius - 55) * sin(i * (M_PI / 180.0f)) + yOffset;

        switch (numberCount) {

            case 1:
                myGLOne(x, y, NUM_SCALE, black);
                numberCount = 12;
                break;

            case 2:
                myGLTwo(x, y, NUM_SCALE, black);
                numberCount--;
                break;

            case 3:
                myGLThree(x, y, NUM_SCALE, black);
                numberCount--;
                break;

            case 4:
                myGLFour(x, y, NUM_SCALE, black);
                numberCount--;
                break;

            case 5:
                myGLFive(x, y, NUM_SCALE, black);
                numberCount--;
                break;

            case 6:
                myGLSix(x, y, NUM_SCALE, black);
                numberCount--;
                break;

            case 7:
                myGLSeven(x, y, NUM_SCALE, black);
                numberCount--;
                break;

            case 8:
                myGLEight(x, y, NUM_SCALE, black);
                numberCount--;
                break;

            case 9:
                myGLNine(x, y, NUM_SCALE, black);
                numberCount--;
                break;

            case 10:
                myGLOne(x - (50 * NUM_SCALE), y, NUM_SCALE, black);
                myGLZero(x + (50 * NUM_SCALE), y, NUM_SCALE, black);
                numberCount--;
                break;

            case 11:
                myGLOne(x - (50 * NUM_SCALE), y, NUM_SCALE, black);
                myGLOne(x + (50 * NUM_SCALE), y, NUM_SCALE, black);
                numberCount--;
                break;

            case 12:
                myGLOne(x - (50 * NUM_SCALE), y, NUM_SCALE, black);
                myGLTwo(x + (50 * NUM_SCALE), y, NUM_SCALE, black);
                numberCount--;
                break;
        }

    }
    glEnd();
}

void myGLHourHand(int h, int min, float xOffset, float yOffset, float scale) {
    float theta = (-h + 3) * 30 - (min / 2);
    float xOut, yOut, xIn, yIn;
    float radiusOut = (100.0f - 35.0f) * scale;
    float radiusIn = 10.0f * scale;
    xOut = radiusOut * cos(theta * (M_PI / 180.0f)) + xOffset;
    yOut = radiusOut * sin(theta * (M_PI / 180.0f)) + yOffset;
    xIn = -radiusIn * cos(theta * (M_PI / 180.0f)) + xOffset;
    yIn = -radiusIn * sin(theta * (M_PI / 180.0f)) + yOffset;

    myGLCircle(xOffset, yOffset, 0.02 * scale, Color(0, 0, 0));

    glLineWidth(1.5f * scale);
    glBegin(GL_LINES);
    glVertex2d(xIn, yIn);
    glVertex2d(xOut, yOut);
    glEnd();
}

void myGLMinuteHand(int min, int sec, float xOffset, float yOffset, float scale) {
    float theta = (-min + 15) * 6 - (sec / 10);
    float xOut, yOut, xIn, yIn;
    float radiusOut = (100.0f - 20.0f) * scale;
    float radiusIn = 15.0f * scale;
    xOut = radiusOut * cos(theta * (M_PI / 180.0f)) + xOffset;
    yOut = radiusOut * sin(theta * (M_PI / 180.0f)) + yOffset;
    xIn = -radiusIn * cos(theta * (M_PI / 180.0f)) + xOffset;
    yIn = -radiusIn * sin(theta * (M_PI / 180.0f)) + yOffset;

    myGLCircle(xOffset, yOffset, 0.015 * scale, Color(0, 0, 0));

    glLineWidth(1.0f * scale);
    glBegin(GL_LINES);
    glVertex2d(xIn, yIn);
    glVertex2d(xOut, yOut);
    glEnd();

}

void myGLSecondHand(int sec, float xOffset, float yOffset, float scale) {
    float theta = ((-sec + 15) * 6);
    float xOut, yOut, xIn, yIn;
    float radiusOut = 100.0f * scale;
    float radiusIn = 20.0f * scale;
    xOut = radiusOut * cos(theta * (M_PI / 180.0f)) + xOffset;
    yOut = radiusOut * sin(theta * (M_PI / 180.0f)) + yOffset;
    xIn = -radiusIn * cos(theta * (M_PI / 180.0f)) + xOffset;
    yIn = -radiusIn * sin(theta * (M_PI / 180.0f)) + yOffset;

    myGLCircle(xOffset, yOffset, 0.010 * scale, Color(255, 0, 0));

    glLineWidth(0.5f * scale);
    glBegin(GL_LINES);
    glVertex2d(xIn, yIn);
    glVertex2d(xOut, yOut);
    glEnd();
}


void myGLClockHands(float xOffset, float yOffset, float scale) {
    time_t t = time(0);
    struct tm *lt = localtime(&t);

    myGLHourHand(lt->tm_hour, lt->tm_min, xOffset, yOffset, scale);
    myGLMinuteHand(lt->tm_min, lt->tm_sec, xOffset, yOffset, scale);
    myGLSecondHand(lt->tm_sec, xOffset, yOffset, scale);
}

/***************/
/**  Clocks  **/
/**************/

void myGLDigitalClock(float xOffset, float yOffset, float scale) {
    myGLRectangle(50 * scale, 7 * scale, xOffset, yOffset - (40 * scale), Color(224.5, 224.5, 224.5));
    myGLRectangleOutline(50 * scale, 7 * scale, xOffset, yOffset - (40 * scale), Color(0, 0, 0));
}


void myGLAnalogClock(float xOffset, float yOffset, float scale) {

    myGLCircle(xOffset, yOffset, scale, Color(255, 255, 255));
    myGLClockTicks(xOffset, yOffset, scale);
    myGLClockNumbers(xOffset, yOffset, scale);
    myGLDigitalClock(xOffset, yOffset, scale);
    myGLClockHands(xOffset, yOffset, scale);
}


/****************/
/**  Numbers  **/
/**************/



/** Shapes for Numbers **/

void myGLDigitalDiamondV(float xOffset, float yOffset, float scale, Color color) {
    glBegin(GL_POLYGON);
    glColor4ub(color.getRed(), color.getBlue(), color.getGreen(), color.getAlpha());
    glVertex2d((0.0f * scale) + xOffset, (50.0f * scale) + yOffset);
    glVertex2d((12.5f * scale) + xOffset, (35.0f * scale) + yOffset);
    glVertex2d((12.5f * scale) + xOffset, (0.0f * scale) + yOffset);
    glVertex2d((12.5f * scale) + xOffset, (-35.0f * scale) + yOffset);
    glVertex2d((0.0f * scale) + xOffset, (-50.0f * scale) + yOffset);
    glVertex2d((-12.5f * scale) + xOffset, (-35.0f * scale) + yOffset);
    glVertex2d((-12.5f * scale) + xOffset, (0.0f * scale) + yOffset);
    glVertex2d((-12.5f * scale) + xOffset, (35.0f * scale) + yOffset);
    glEnd();
}

void myGLDigitalDiamondH(float xOffset, float yOffset, float scale, Color color) {
    glBegin(GL_POLYGON);
    glColor4ub(color.getRed(), color.getBlue(), color.getGreen(), color.getAlpha());
    glVertex2d((50.0f * scale) + xOffset, (0.0f * scale) + yOffset);
    glVertex2d((35.0f * scale) + xOffset, (12.5f * scale) + yOffset);
    glVertex2d((0.0f * scale) + xOffset, (12.5f * scale) + yOffset);
    glVertex2d((-35.0f * scale) + xOffset, (12.5f * scale) + yOffset);
    glVertex2d((-50.0f * scale) + xOffset, (0.0f * scale) + yOffset);
    glVertex2d((-35.0f * scale) + xOffset, (-12.5f * scale) + yOffset);
    glVertex2d((0.0f * scale) + xOffset, (-12.5f * scale) + yOffset);
    glVertex2d((35.0f * scale) + xOffset, (-12.5f * scale) + yOffset);
    glEnd();
}


/** Numbers using the Shapes **/
void myGLZero(float xOffset, float yOffset, float scale, Color color) {
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset + (100.0f * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset - (100.0f * scale), scale, color);
}

void myGLOne(float xOffset, float yOffset, float scale, Color color) {
    myGLDigitalDiamondV(xOffset, yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset, yOffset - (50 * scale), scale, color);
}

void myGLTwo(float xOffset, float yOffset, float scale, Color color) {
    myGLDigitalDiamondH(xOffset, yOffset, scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset + (100.0f * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset - (100.0f * scale), scale, color);
}

void myGLThree(float xOffset, float yOffset, float scale, Color color) {
    myGLDigitalDiamondH(xOffset, yOffset, scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset + (100.0f * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset - (100.0f * scale), scale, color);
}

void myGLFour(float xOffset, float yOffset, float scale, Color color) {
    myGLDigitalDiamondH(xOffset, yOffset, scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset - (50 * scale), scale, color);
}

void myGLFive(float xOffset, float yOffset, float scale, Color color) {
    myGLDigitalDiamondH(xOffset, yOffset, scale, color);;
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset + (100.0f * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset - (100.0f * scale), scale, color);
}

void myGLSix(float xOffset, float yOffset, float scale, Color color) {
    myGLDigitalDiamondH(xOffset, yOffset, scale, color);
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset + (100.0f * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset - (100.0f * scale), scale, color);
}

void myGLSeven(float xOffset, float yOffset, float scale, Color color) {
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset + (100.0f * scale), scale, color);
}

void myGLEight(float xOffset, float yOffset, float scale, Color color) {
    myGLDigitalDiamondH(xOffset, yOffset, scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset + (100.0f * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset - (100.0f * scale), scale, color);
}

void myGLNine(float xOffset, float yOffset, float scale, Color color) {
    myGLDigitalDiamondH(xOffset, yOffset, scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset - (50.0f * scale), yOffset + (50 * scale), scale, color);
    myGLDigitalDiamondV(xOffset + (50.0f * scale), yOffset - (50 * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset + (100.0f * scale), scale, color);
    myGLDigitalDiamondH(xOffset, yOffset - (100.0f * scale), scale, color);
}

