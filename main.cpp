#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

/*cg-branch-1 -> 20-42328-1*/
/*cg-branch-2 -> 20-42192-1*/
/*cg-branch-3 -> 20-43073-1*/
/*cg-branch-4 -> 20-42308-1*/

using namespace std;

void half_circle(GLfloat r, GLfloat cx,GLfloat cy, GLfloat d){ //

    GLfloat x = cx; GLfloat y = cy; GLfloat radius = r;
	int i;
	int lineAmount = 100; //# of triangles used to draw circle
	float PI = 3.1416;

	//GLfloat radius = 0.8f; //radius
	//GLfloat twicePi = 2.0f * PI;
	GLfloat twicePi = PI;

    //glColor3f(0.0f, 1.0f, 1.0f);
    glLineWidth(d);
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	glFlush();  // Render now
}

void fullSky(){
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //set up the gradient

    glColor3ub(150,10,230);

    glBegin(GL_POLYGON);
    glVertex2f(0,430);
    glVertex2f(1000,430);

    glColor3ub(40,120,20);
    glColor3ub(140,220,230);

    glVertex2f(1000,600);
    glVertex2f(0,600);
    glEnd();
}
void right_city(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(800,430);
    glVertex2f(1000,430);
    glVertex2f(1000,0);
    glVertex2f(850,150);
    glEnd();
}

void left_city(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,430);
    glVertex2f(200,430);
    glVertex2f(150,200);
    glVertex2f(0,100);
    glEnd();
}

void bridge(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,260);
    glVertex2f(1000,260);
    glVertex2f(1000,220);
    glVertex2f(0,220);
    glEnd();

    int a = 190;
    int b = 230;

    for(int i=0; i<8; i++){
        glColor3ub(255, 204, 102);
        glBegin(GL_POLYGON);
        glVertex2f(a,250);
        glVertex2f(b,250);
        glVertex2f(b,230);
        glVertex2f(a,230);
        glEnd();

        a += 80;
        b += 80;
    }

    //bridge's half circles
    glColor3ub(0, 0, 0);
    half_circle(80, 330, 260, 5);
    half_circle(80, 310, 260, 5);
    half_circle(90, 500, 260, 5);
    half_circle(90, 480, 260, 5);
    half_circle(80, 650, 260, 5);
    half_circle(80, 670, 260, 5);


    //bridge wire lines
    glBegin(GL_LINES);
    glVertex2f(270,260);
    glVertex2f(270,310);

    glVertex2f(290,260);
    glVertex2f(290,330);

    glVertex2f(310,260);
    glVertex2f(310,340);

    glVertex2f(330,260);
    glVertex2f(330,340);

    glVertex2f(350,260);
    glVertex2f(350,330);

    glVertex2f(370,260);
    glVertex2f(370,310);

    glVertex2f(430,260);
    glVertex2f(430,315);

    glVertex2f(450,260);
    glVertex2f(450,335);

    glVertex2f(470,260);
    glVertex2f(470,345);

    glVertex2f(490,260);
    glVertex2f(490,350);

    glVertex2f(510,260);
    glVertex2f(510,350);

    glVertex2f(530,260);
    glVertex2f(530,335);

    glVertex2f(550,260);
    glVertex2f(550,320);

    glVertex2f(610,260);
    glVertex2f(610,310);

    glVertex2f(630,260);
    glVertex2f(630,330);

    glVertex2f(650,260);
    glVertex2f(650,340);

    glVertex2f(670,260);
    glVertex2f(670,340);

    glVertex2f(690,260);
    glVertex2f(690,330);

    glVertex2f(710,260);
    glVertex2f(710,310);
    glEnd();


}

void fullBottom(){
    glColor3ub(255, 204, 102);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,430);
    glVertex2f(1000,430);
    glVertex2f(1000,0);
    glEnd();
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    fullSky();
    fullBottom();
    bridge();
    left_city();
    right_city();

    glFlush();
}

void init(void){
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1000,0,600);

}

int main()
{
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Scenario");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



