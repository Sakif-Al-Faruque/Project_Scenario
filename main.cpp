#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

/*cg-branch-1 -> 20-42328-1*/

using namespace std;


/*cg-branch-1 p1 is started*/
void fullSky(){

    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //set up the gradient


    //glColor3ub(50,60,130);
    glColor3ub(244,164,96);

    glBegin(GL_POLYGON);
    glVertex2f(0,300);
    glVertex2f(1000,300);

    glColor3ub(105,105,105);
    glColor3ub(105,105,105);

    glVertex2f(1000,0);
    glVertex2f(0,0);
    glEnd();
}

void fullBottom(){
    glColor3ub(0,0,0);
    //glColor3ub(143,188,143);//
    glBegin(GL_POLYGON);
    glVertex2f(0,600);
    glVertex2f(1000,600);
    glVertex2f(1000,300);
    glVertex2f(0,300);
    glEnd();
}
/*cg-branch-1 p2 is ended*/

/*cg-branch-1 p2 is started*/
void lake(){
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3ub(255,165,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,600);
    glVertex2f(1000,600);
    glColor3ub(255,255,102);
    glVertex2f(580,330);
    glVertex2f(390,330);
    glEnd();

}
/*cg-branch-1 p2 is ended*/


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
  
    fullSky(); //mira
    fullBottom();//mira
    lake();//mira


    



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

