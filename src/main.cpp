#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
#include "Shapes.h"

int screen_width = 500, screen_height = 500;

int size = std::min(screen_width, screen_height);

int xOffset = size / 2.0f;

int yOffset = size / 2.0f;

float scale = size / 200.0f;

void display(void) {
    // Sets pixels to default values
    glClear(GL_COLOR_BUFFER_BIT);

    myGLAnalogClock(xOffset, yOffset, scale);

    glutSwapBuffers();

    glutPostRedisplay();
}

void idle(void) {
}

void reshape(int w, int h) {
    size = std::min(w, h);
//    xOffset = size/2.0f;
//    yOffset = size/2.0f;
//    scale = size/200.0f;

    glViewport((w - size) / 2.0f, (h - size) / 2.0f, size, size);
}

void init() {

    // Setting the default color of the window
    glClearColor(0, 0, 0, 0.0);

    // Setting window defaults
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT), -1.0, 1.0);

}

int main(int argc, char **argv) {
    /* Do all the general purpose startup stuff...*/
    glutInit(&argc, argv);

    /* we got a RGBA buffer and we're double buffering! */
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    /* set some size for the window. */
    glutInitWindowSize(screen_width, screen_height);

    /* arbitrarily set an initial window position... */
    glutInitWindowPosition(100, 100);

    /* make the window.  give it a cool title */
    glutCreateWindow("Clock");

    init();

    /* set the callback functions */
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    /* start it! */
    glutMainLoop();
    return 0;
}
