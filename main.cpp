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

/*cg-branch-4 p1 is started */
void bridge_pillar(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(490,280);
    glVertex2f(500,280);
    glVertex2f(500,205);
    glVertex2f(490,205);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(520,280);
    glVertex2f(530,280);
    glVertex2f(530,195);
    glVertex2f(520,195);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(500,250);
    glVertex2f(520,250);
    glVertex2f(520,240);
    glVertex2f(500,240);
    glEnd();

    glColor3ub(44,33,41);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(480,280);
    glVertex2f(490,270);

    glVertex2f(460,280);
    glVertex2f(490,250);

    glVertex2f(440,280);
    glVertex2f(490,230);

    glVertex2f(420,280);
    glVertex2f(490,210);

    glVertex2f(530,260);
    glVertex2f(550,280);

    glVertex2f(530,240);
    glVertex2f(570,280);

    glVertex2f(530,220);
    glVertex2f(580,270);

    glVertex2f(530,200);
    glVertex2f(580,250);
    glEnd();
}

void bridge_road(){
    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    glVertex2f(390,320);
    glVertex2f(580,320);
    glVertex2f(580,280);
    glVertex2f(390,280);
    glEnd();
}

void bridge_body(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(390,330);
    glVertex2f(580,330);
    glVertex2f(580,290);
    glVertex2f(390,290);
    glEnd();
}

void bridge_under(){
    glColor3ub(255,255,102);
    circle(95,20,485,330);
}

void left_city(){
    glColor3ub(0,0,0);   //first building of the bridge//
    glBegin(GL_POLYGON);
    glVertex2f(310,300);
    glVertex2f(390,330);
    glVertex2f(390,200);
    glVertex2f(310,230);
    glEnd();

    glColor3ub(0,0,0);  // backside building of first building//
    glBegin(GL_POLYGON);
    glVertex2f(240,380);
    glVertex2f(300,350);
    glVertex2f(300,170);
    glVertex2f(240,190);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(230,370);
    glVertex2f(280,290);
    glVertex2f(280,180);
    glVertex2f(230,150);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(150,250);
    glVertex2f(190,230);
    glVertex2f(190,190);
    glVertex2f(150,190);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(40,380);
    glVertex2f(110,380);
    glVertex2f(110,190);
    glVertex2f(40,230);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(240,380);
    glVertex2f(280,360);
    glVertex2f(280,240);
    glVertex2f(240,260);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(280,360);
    glVertex2f(330,360);
    glVertex2f(330,230);
    glVertex2f(280,230);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(330,360);
    glVertex2f(370,340);
    glVertex2f(370,260);
    glVertex2f(330,230);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(90,370);
    glVertex2f(140,370);
    glVertex2f(140,240);
    glVertex2f(90,240);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(130,410);
    glVertex2f(170,410);
    glVertex2f(170,220);
    glVertex2f(130,250);
    glEnd();

    glColor3ub(251, 252, 164);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(130,270);
    glVertex2f(170,240);

    glVertex2f(130,290);
    glVertex2f(170,270);

    glVertex2f(130,310);
    glVertex2f(170,300);

    glVertex2f(130,330);
    glVertex2f(170,330);

    glVertex2f(130,350);
    glVertex2f(170,360);

    glVertex2f(130,370);
    glVertex2f(170,390);
    glEnd();

    glColor3ub(251, 252, 164);
    //glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(170,410);
    glVertex2f(170,220);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(170,410);
    glVertex2f(220,390);
    glVertex2f(220,220);
    glVertex2f(170,220);
    glEnd();

    glColor3ub(251, 252, 164);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(170,240);
    glVertex2f(220,240);

    glVertex2f(170,270);
    glVertex2f(220,270);

    glVertex2f(170,300);
    glVertex2f(220,300);

    glVertex2f(170,330);
    glVertex2f(220,330);

    glVertex2f(170,360);
    glVertex2f(220,360);

    glVertex2f(170,390);
    glVertex2f(220,390);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,520);
    glVertex2f(60,470);
    glVertex2f(60,300);
    glVertex2f(0,300);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(100,450);
    glVertex2f(150,450);
    glVertex2f(150,310);
    glVertex2f(100,310);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(70,480);
    glVertex2f(110,480);
    glVertex2f(110,360);
    glVertex2f(70,360);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(20,540);
    glVertex2f(70,520);
    glVertex2f(70,350);
    glVertex2f(20,390);
    glEnd();

    glColor3ub(251, 252, 164);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(20,540);
    glVertex2f(20,390);

    glVertex2f(20,390);
    glVertex2f(70,350);

    glVertex2f(70,350);
    glVertex2f(70,520);

    glVertex2f(70,360);
    glVertex2f(110,360);

    glVertex2f(70,380);
    glVertex2f(110,380);

    glVertex2f(70,400);
    glVertex2f(110,400);

    glVertex2f(70,420);
    glVertex2f(110,420);


    glVertex2f(70,440);
    glVertex2f(110,440);

    glVertex2f(70,460);
    glVertex2f(110,460);

    glVertex2f(110,360);
    glVertex2f(110,460);


    glVertex2f(100,360);
    glVertex2f(100,310);

    glVertex2f(100,310);
    glVertex2f(150,310);

    glVertex2f(150,310);
    glVertex2f(150,450);

    glVertex2f(130,310);
    glVertex2f(130,250);

    glVertex2f(130,250);
    glVertex2f(170,220);

    glVertex2f(170,220);
    glVertex2f(220,220);

    glVertex2f(220,220);
    glVertex2f(220,400);

    glVertex2f(240,380);
    glVertex2f(240,260);

    glVertex2f(240,260);
    glVertex2f(280,260);

    glVertex2f(280,260);
    glVertex2f(280,240);

    glVertex2f(280,240);
    glVertex2f(240,260);

    glVertex2f(280,370);
    glVertex2f(280,230);

    glVertex2f(280,230);
    glVertex2f(330,230);

    glVertex2f(330,230);
    glVertex2f(330,360);

    glVertex2f(330,230);
    glVertex2f(370,260);

    glVertex2f(370,260);
    glVertex2f(370,330);
    glEnd();
}
/*cg-branch-4 p1 is ended */

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

    bridge_pillar();//sakif
    bridge_road();//sakif
    bridge_body();//sakif
    bridge_under();//sakif
    left_city();//sakif

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
//main branch is started
