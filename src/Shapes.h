//
// Created by jaden on 9/15/2022.
//

#ifndef OPENGL_CLOCK_SHAPES_H
#define OPENGL_CLOCK_SHAPES_H

#include <GL/gl.h>
#include <GL/freeglut.h>
#include "Color.h"

void glCircle(float xOffset, float yOffset, float scale, Color color);

void glClockTicks(float xOffset, float yOffset, float scale);

void glClock(float xOffset, float yOffset, float scale);

#endif //OPENGL_CLOCK_SHAPES_H
