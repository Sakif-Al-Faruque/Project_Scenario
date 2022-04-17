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


//main branch is started
void init(void){
    glClearColor(0,0,0,0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity(); // Load Matrix
    gluOrtho2D(0,1000,600,0); //set total 4 quadrant(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)

}
//main branch is ended


/*cg-branch-2 p1 is started */
//set limit to move the cloud in y axis
float left_to_right=-800;
float right_to_left = 100;

static float tx	= 0.0;
static float ty	= 0.0;

void circleRain(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){ //radius_x,radius_y,certre_position_x,centre_position_y

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++){
        float angle = 2.0f * 3.1416f * i/100; //this expression evaluate the unit angle which is 3.6 degree

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void rain(){
    for(int i=0;i<20;i++){
        for(int j=0;j<15;j++){
            glColor3ub(242,242,242);
            circleRain(1,2,(i*1)+rand()%1000+0,(i*1)+rand()%600+0);
            glFlush();
        }
    }
}


void lefttoright_cloud(){
    if(left_to_right<=1000){ //moving limit with the display measurement
        left_to_right=left_to_right+1; // changing the object position for redisplaying
    }else{
        left_to_right=-100; // For backing the object continuously
    }
    glutPostRedisplay(); // To redraw the object in the display
}

void righttoleft_cloud(){
    if(right_to_left>=-1000){ //moving limit with the display measurement
        right_to_left=right_to_left-1; // changing the object position for redisplaying
    }else{
        right_to_left=100; // For backing the object continuously
    }
    glutPostRedisplay(); // To redraw the object in the display
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){ //radius_x,radius_y,certre_position_x,centre_position_y

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++){
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void circle1(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){ //radius_x,radius_y,certre_position_x,centre_position_y
    lefttoright_cloud();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(left_to_right+cx,cy);

    for(int i=0;i<=100;i++){
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+left_to_right+cx),(y+cy));
    }
    glEnd();
}

void circle2(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){ //radius_x,radius_y,certre_position_x,centre_position_y

    righttoleft_cloud();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(right_to_left+cx,cy);

    for(int i=0;i<=100;i++){
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+right_to_left+cx),(y+cy));
    }
    glEnd();
}

void circle3(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){ //radius_x,radius_y,certre_position_x,centre_position_y

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++){
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}
/*cg-branch-2 p1 is finished */


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
/*cg-branch-1 p1 is ended*/



/*cg-branch-2 p2 is started */
void sun(){
    glColor3ub(255,140,0);
    circle(192,192,500,280);
}

void cloud1(){
    glColor3ub(128,128,128);
    circle1(80,5,100,260);
    circle1(35,5,75,250);
    circle1(20,20,90,240);
    circle1(20,10,115,250);
}
void cloud2(){
    glColor3ub(169,169,169);
    circle1(80,5,620,70);
    circle1(35,5,595,60);
    circle1(20,20,610,50);
    circle1(20,10,635,60);
}


void cloud3(){
    glColor3ub(105,105,105);
    circle2(100,10,900,150);
    circle2(35,5,875,160);
    circle2(20,15,890,160);
    circle2(20,10,920,165);
    circle2(80,10,910,135);
}
/*cg-branch-2 p2 is ended */



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


/*cg-branch-3 p1 is started */
void right_city(){
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(610,270);
    glVertex2f(660,270);
    glVertex2f(660,180);
    glVertex2f(610,180);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(580,330);
    glVertex2f(640,340);
    glVertex2f(640,200);
    glVertex2f(580,230);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(750,300);
    glVertex2f(790,300);
    glVertex2f(790,150);
    glVertex2f(750,150);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(810,250);
    glVertex2f(850,250);
    glVertex2f(850,190);
    glVertex2f(810,190);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(860,270);
    glVertex2f(910,270);
    glVertex2f(910,155);
    glVertex2f(860,155);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(920,300);
    glVertex2f(980,300);
    glVertex2f(980,180);
    glVertex2f(920,180);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(640,340);
    glVertex2f(670,340);
    glVertex2f(670,255);
    glVertex2f(640,255);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(690,370);
    glVertex2f(750,380);
    glVertex2f(750,220);
    glVertex2f(690,220);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(700,220);
    glVertex2f(740,220);
    glVertex2f(740,200);
    glVertex2f(700,200);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(710,200);
    glVertex2f(730,200);
    glVertex2f(730,180);
    glVertex2f(710,180);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(720,180);
    glVertex2f(720,150);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(780,390);
    glVertex2f(840,390);
    glVertex2f(840,240);
    glVertex2f(780,240);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(795,240);
    glVertex2f(825,240);
    glVertex2f(825,220);
    glVertex2f(795,220);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(805,220);
    glVertex2f(815,220);
    glVertex2f(815,205);
    glVertex2f(805,205);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(840,390);
    glVertex2f(900,390);
    glVertex2f(900,230);
    glVertex2f(840,230);
    glEnd();
    glColor3ub(251, 252, 164);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(840,260);
    glVertex2f(900,260);

    glVertex2f(840,290);
    glVertex2f(900,290);

    glVertex2f(840,320);
    glVertex2f(900,320);

    glVertex2f(840,350);
    glVertex2f(900,350);

    glVertex2f(840,380);
    glVertex2f(900,380);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(770,410);
    glVertex2f(820,420);
    glVertex2f(820,270);
    glVertex2f(770,270);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(895,465);
    glVertex2f(965,465);
    glVertex2f(965,265);
    glVertex2f(895,265);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(895,465);
    glVertex2f(965,465);
    glVertex2f(965,265);
    glVertex2f(895,265);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(725,400);
    glVertex2f(770,400);
    glVertex2f(770,295);
    glVertex2f(725,295);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(965,470);
    glVertex2f(1000,470);
    glVertex2f(1000,300);
    glVertex2f(965,300);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(830,470);
    glVertex2f(875,470);
    glVertex2f(875,330);
    glVertex2f(830,300);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(880,490);
    glVertex2f(940,490);
    glVertex2f(940,325);
    glVertex2f(880,370);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(950,520);
    glVertex2f(1000,520);
    glVertex2f(1000,400);
    glVertex2f(950,400);
    glEnd();

    glColor3ub(251, 252, 164);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(640,340);
    glVertex2f(640,255);

    glVertex2f(670,340);
    glVertex2f(670,255);

    glVertex2f(640,255);
    glVertex2f(670,255);

    glVertex2f(640,270);
    glVertex2f(670,270);

    glVertex2f(640,285);
    glVertex2f(670,285);

    glVertex2f(640,300);
    glVertex2f(670,300);

    glVertex2f(640,315);
    glVertex2f(670,315);

    glVertex2f(640,330);
    glVertex2f(670,330);

    glVertex2f(725,400);
    glVertex2f(725,295);

    glVertex2f(725,295);
    glVertex2f(770,295);

    glVertex2f(725,315);
    glVertex2f(770,315);

    glVertex2f(725,335);
    glVertex2f(770,335);

    glVertex2f(725,355);
    glVertex2f(770,355);

    glVertex2f(725,375);
    glVertex2f(770,375);

    glVertex2f(725,395);
    glVertex2f(770,395);

    glVertex2f(770,410);
    glVertex2f(770,270);

    glVertex2f(770,270);
    glVertex2f(820,270);

    glVertex2f(820,270);
    glVertex2f(820,420);

    glVertex2f(770,290);
    glVertex2f(820,290);

    glVertex2f(770,310);
    glVertex2f(820,310);

    glVertex2f(770,330);
    glVertex2f(820,330);

    glVertex2f(770,350);
    glVertex2f(820,350);

    glVertex2f(770,370);
    glVertex2f(820,370);

    glVertex2f(770,390);
    glVertex2f(820,390);

    glVertex2f(950,520);
    glVertex2f(950,400);

    glVertex2f(950,400);
    glVertex2f(1000,400);

    glVertex2f(880,490);
    glVertex2f(880,370);

    glVertex2f(880,370);
    glVertex2f(940,325);

    glVertex2f(940,325);
    glVertex2f(940,490);

    glVertex2f(830,470);
    glVertex2f(830,300);

    glVertex2f(830,300);
    glVertex2f(875,330);

    glVertex2f(875,330);
    glVertex2f(875,470);

    glVertex2f(875,330);
    glVertex2f(875,470);

    glVertex2f(960,400);
    glVertex2f(960,300);

    glVertex2f(960,300);
    glVertex2f(1000,300);

    glVertex2f(840,305);
    glVertex2f(840,230);

    glVertex2f(840,230);
    glVertex2f(900,230);

    glVertex2f(900,230);
    glVertex2f(900,265);
    glEnd();
}
/*cg-branch-3 p1 is ended */



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

glColor3ub(255,255,102);
    circle(95,2,485,335);

    glColor3ub(255,140,0);
    circle(95,2,485,335);
    circle(50,1,430,340);
    circle(95,2,495,345);
    circle(50,1,450,320);
    circle(50,1,465,323);
    circle(50,1,495,315);
    circle(95,2,488,330);
    circle(50,1,480,350);
    circle(80,2,485,355);
    circle(95,2,510,365);
    circle(95,2,480,375);
    circle(70,1,483,383);
    circle(95,2,520,390);
    circle(95,2,420,390);
    circle(95,2,425,395);
    circle(70,1,483,400);
    circle(50,1,483,405);
    circle(50,2,490,410);
    circle(65,1,490,420);
    circle(35,1,490,425);
    circle(20,2,490,430);
    circle(30,1,490,435);
    circle(18,1,490,440);
    circle(10,1,490,445);
    circle(5,1,490,450);
}
/*cg-branch-1 p2 is ended*/

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT); //main


    fullSky(); //mira
    sun();//nushrat

    fullBottom();//mira

    cloud1();//nushrat
    cloud2();//nushrat
    cloud3();//nushrat


    bridge_pillar();//sakif
    bridge_road();//sakif
    bridge_body();//sakif
    bridge_under();//sakif
    left_city();//sakif
    right_city();//faiza
    lake();//mira
    rain();//nushrat


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
//main branch is started
