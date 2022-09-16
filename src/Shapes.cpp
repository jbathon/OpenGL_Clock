//
// Created by jaden on 9/15/2022.
//

#include "Shapes.h"
#include <cmath>
#include <iostream>

void myGLCircle(float xOffset, float yOffset, float scale, Color color) {

    float x,y;
    float radius = 100.0f * scale;
    glBegin(GL_POLYGON);
    for(int i=0; i<= 360; i++) {
        x = radius*cos(i*(M_PI/180.0f)) + xOffset;
        y = radius*sin(i*(M_PI/180.0f)) + yOffset;
        glColor4ub(color.getRed(),color.getBlue(),color.getGreen(),color.getAlpha());
        glVertex2d(x, y);
    }
    glEnd();

}

void myGLClockTicks(float xOffset, float yOffset, float scale) {
    float x,y;
    float radius = 100.0f * scale;

    int tickCount = 0;

    glBegin(GL_LINES);
    for(int i=0; i<= 360; i++) {

        if(i%6 == 0 ){
            /**** Start Point ****/
            x = radius*cos(i*(M_PI/180.0f)) + xOffset;
            y = radius*sin(i*(M_PI/180.0f)) + yOffset;
            glColor3ub(0,0,0);
            glVertex2d(x, y);

            /**** End Point ****/
            float tickLength;
            if (tickCount%5 == 0) tickLength = 15.0f * scale;
            else tickLength =  15.0f/2.0f * scale;
            x = (radius-tickLength)*cos(i*(M_PI/180.0f)) + xOffset;
            y = (radius-tickLength)*sin(i*(M_PI/180.0f)) + yOffset;
            glColor3ub(0,0,0);
            glVertex2d(x, y);

            tickCount++;
        }

    }
    glEnd();
}

void myGLClockNumbers(float xOffset, float yOffset, float scale) {
    float x,y;
    float radius = 100.0f * scale;

    int tickCount = 0;
    int numberCount = 0;

    for(int i=0; i<= 360; i++) {

        if(i%6 == 0 ){
            /**** End Point ****/

            if (tickCount%5 == 0) {
                x = (radius-15)*cos(i*(M_PI/180.0f)) + xOffset;
                y = (radius-15)*sin(i*(M_PI/180.0f)) + yOffset;

                switch (numberCount) {

                    case 1:
                        break;

                    case 2:
                        break;

                    case 3:
                        break;

                    case 4:
                        break;

                    case 5:
                        break;

                    case 6:
                        break;

                    case 7:
                        break;

                    case 8:
                        break;

                    case 9:
                        break;

                    case 10:
                        break;

                    case 11:
                        break;

                    case 12:
                        break;
                }

            }

            tickCount++;
        }

    }
    glEnd();
}

void myGLAnalogClock(float xOffset, float yOffset, float scale) {

    myGLCircle(xOffset, yOffset, scale, Color(255, 255, 255));
    myGLClockTicks(xOffset, yOffset, scale);
    myGLOne(xOffset, yOffset, 0.15f, Color(0, 0, 0));

}

void myGLDigitalDiamondV(float xOffset, float yOffset, float scale, Color color) {
    glBegin(GL_POLYGON);
    glColor4ub(color.getRed(),color.getBlue(),color.getGreen(),color.getAlpha());
    glVertex2d((0.0f*scale)+xOffset,(50.0f*scale)+yOffset);
    glVertex2d((12.5f*scale)+xOffset,(35.0f*scale)+yOffset);
    glVertex2d((12.5f*scale)+xOffset,(0.0f*scale)+yOffset);
    glVertex2d((12.5f*scale)+xOffset,(-35.0f*scale)+yOffset);
    glVertex2d((0.0f*scale)+xOffset,(-50.0f*scale)+yOffset);
    glVertex2d((-12.5f*scale)+xOffset,(-35.0f*scale)+yOffset);
    glVertex2d((-12.5f*scale)+xOffset,(0.0f*scale)+yOffset);
    glVertex2d((-12.5f*scale)+xOffset,(35.0f*scale)+yOffset);
    glEnd();
}
void myGLDigitalDiamondH(float xOffset, float yOffset, float scale, Color color) {
    glBegin(GL_POLYGON);
    glColor4ub(color.getRed(),color.getBlue(),color.getGreen(),color.getAlpha());
    glVertex2d((50.0f*scale)+xOffset,(0.0f*scale)+yOffset);
    glVertex2d((35.0f*scale)+xOffset, (12.5f*scale)+yOffset);
    glVertex2d((0.0f*scale)+xOffset,(12.5f*scale)+yOffset);
    glVertex2d((-35.0f*scale)+xOffset, (12.5f*scale)+yOffset);
    glVertex2d((-50.0f*scale)+xOffset, (0.0f*scale)+yOffset);
    glVertex2d((-35.0f*scale)+xOffset,(-12.5f*scale)+yOffset);
    glVertex2d((0.0f*scale)+xOffset,(-12.5f*scale)+yOffset);
    glVertex2d((35.0f*scale)+xOffset, (-12.5f*scale)+yOffset);
    glEnd();
}

/**** A Whole Lot of Numbers ****/

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
