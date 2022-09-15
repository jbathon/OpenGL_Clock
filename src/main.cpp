#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>

int screen_width = 500, screen_height = 500;

void display ( void )
{

    // Sets pixels to default values
    glClear(GL_COLOR_BUFFER_BIT);


    // Ends drawing on the window
    glEnd();
    glutSwapBuffers();
}

void idle ( void )
{
}

void reshape( int w, int h )
{
    /* width & height don't change */
    glutPostRedisplay();
}

void init() {

    // Setting the default color of the window
    glClearColor(0, 0, 0, 0.0);

    // Setting window defaults
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT), -1.0, 1.0);

}

int main(int argc, char** argv)
{
    /* Do all the general purpose startup stuff...*/
    glutInit(&argc, argv);

    /* we got a RGBA buffer and we're double buffering! */
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );

    /* set some size for the window. */
    glutInitWindowSize( screen_width, screen_height );

    /* arbitrarily set an initial window position... */
    glutInitWindowPosition( 100, 100 );

    /* make the window.  give it a cool title */
    glutCreateWindow("Bresenham Line Algorithm");

    init();

    /* set the callback functions */
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    glutIdleFunc( idle );

    /* start it! */
    glutMainLoop();
    return 0;
}
