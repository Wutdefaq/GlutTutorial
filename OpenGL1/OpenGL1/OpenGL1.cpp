#include "glew.h"
#include "freeglut.h"
#include <iostream>
#include <cmath>
#define PI 3.14159


void changeSize(int w, int h) 
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = 1.0 * w / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45, ratio, 1, 1000);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);

}

void display(void)
{
	// white background
	glClearColor(1.0, 1.0, 1.0, 1.0); 

	// clear buffer 
	glClear(GL_COLOR_BUFFER_BIT);

	// color of triangle
	glColor3f(0.0f, 0.0f, 1.0f);
	
	// calculations
	GLfloat radius = 0.5f;
	GLfloat Angle;
	GLfloat x, y;
	GLint Pointnumber = 5000;
	
	// start to draw line
	glBegin(GL_POLYGON);

	for (float i = 0; i < Pointnumber; i++)
	{
		Angle = i * 2.0f * PI / Pointnumber;
		x = radius * cos(Angle);
		y = radius * sin(Angle);
		glVertex3f(x, y ,-5.0f);
	}

	// finish drawing
	glEnd();

	// flush the buffer
	glFlush();

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