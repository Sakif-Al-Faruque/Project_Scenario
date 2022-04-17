#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

using namespace std;

//main branch is started
void init(void){
    glClearColor(0,0,0,0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity(); // Load Matrix
    gluOrtho2D(0,1000,600,0); //set total 4 quadrant(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)

}
//main branch is ended

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT); //main



    glPushMatrix();//main

	glPopMatrix();//main

    glFlush();//main
}

//main branch is started
int main(){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Project Scenario");

    init();

    glutDisplayFunc(Draw);

    glutMainLoop();
    return 0;
}
//main branch is ended



