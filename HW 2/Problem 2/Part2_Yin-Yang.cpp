/*
Created by: Jessica Gallo
Date Created: 3/19/2021
Last Modified: 3/23/2021
Team: Dihn, Fremgen, Gallo
CSC706 Computer Graphics
HW 2 Part 2 Draw Yin Yang Symbol
*/
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void init()
{
	//glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
	glClearColor(0.0, 0.0, 1.0, 0.0); // background color = white
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	//glMatrixMode(GL_MODELVIEW);

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// White arc circle
	float theta;
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i<360; i++)
	{
		theta = i * 3.14 / 180;
		glVertex2f(250+150*cos(theta), 250+150*sin(theta)); // circle origin 0,0
	}
	glEnd();
	// Black arc circle
	float theta6;
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 180; i++)
	{
		theta6 = i * 3.14 / 180;
		glVertex2f(250 + 150 * cos(theta6), 250 + 150 * sin(theta6)); // circle origin 0,0
	}
	glEnd();
	// Black medium circle
	float theta2;
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<360; i++)
	{
		theta2 = i * 3.14 / 180;
		glVertex2f(175+75*cos(theta2), 250+75*sin(theta2)); // circle origin 0,0
	}
	glEnd();
	// White small circle
	float theta3;
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta3 = i * 3.14 / 180;
		glVertex2f(175 + 15 * cos(theta3), 250 + 15 * sin(theta3)); // circle origin 0,0
	}
	glEnd();
	// White medium circle
	float theta4;
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta4 = i * 3.14 / 180;
		glVertex2f(325 + 75 * cos(theta4), 250 + 75 * sin(theta4)); // circle origin 0,0
	}
	glEnd();
	// Black small circle
	float theta5;
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta5 = i * 3.14 / 180;
		glVertex2f(330 + 15 * cos(theta5), 250 + 15 * sin(theta5)); // circle origin 0,0
	}
	glEnd();
	
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Yin-Yang Symbol");
	init();
	glutDisplayFunc(display); // send graphics to display window
	glutMainLoop(); //Display everything and wait
}
