//
// Created by jaden on 9/15/2022.
//

#include "Shapes.h"
#include <cmath>
#include <iostream>

void glCircle(float xOffset, float yOffset, float scale, Color color) {

    float x,y;
    std::cout << scale << std::endl;
    float radius = 100 * scale;

    glBegin(GL_POLYGON);
    for(int i=0; i<= 360; i++) {
        x = radius*cos(i*(M_PI/180)) + xOffset;
        y = radius*sin(i*(M_PI/180)) + yOffset;
        glColor3ub(color.getRed(),color.getBlue(),color.getGreen());
        glVertex2d(x, y);
    }
    glEnd();

}

void glClockTicks(float xOffset, float yOffset, float scale) {
    float x,y;
    float radius = 100 * scale;

    int tickCount = 0;

    glBegin(GL_LINES);
    for(int i=0; i<= 360; i++) {

        if(i%6 == 0 ){
            /**** Start Point ****/
            x = radius*cos(i*(M_PI/180)) + xOffset;
            y = radius*sin(i*(M_PI/180)) + yOffset;
            glColor3ub(0,0,0);
            glVertex2d(x, y);

            /**** End Point ****/
            int tickLength;
            if (tickCount%5 == 0) tickLength = 15 * scale;
            else tickLength =  15/2 * scale;
            x = (radius-tickLength)*cos(i*(M_PI/180)) + xOffset;
            y = (radius-tickLength)*sin(i*(M_PI/180)) + yOffset;
            glColor3ub(0,0,0);
            glVertex2d(x, y);

            tickCount++;
        }

    }
    glEnd();
}

void glClock(float xOffset, float yOffset, float scale) {

    glCircle(xOffset,yOffset,scale,Color(255,255,255));
    glClockTicks(xOffset,yOffset,scale);

}