#include "glew.h"
#include "freeglut.h"
#include <iostream>
#include <cmath>
#define PI 3.14159


void changeSize(int w, int h) 
{
	//This function activates when size of window is changed


}

void display(void)
{
	//Draw a blue circle
	

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(EXIT_SUCCESS);
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(800, 0);
	glutCreateWindow("My window");
	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}