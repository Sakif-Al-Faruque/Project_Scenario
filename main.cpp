#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

/*cg-branch-1 -> 20-42328-1*/
/*cg-branch-2 -> 20-42192-1*/

using namespace std;

int main()
{
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Scenario");

    init();

    glutDisplayFunc();
    glutMainLoop();
    return 0;
}



