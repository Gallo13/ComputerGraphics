/*
Created by: Jessica Gallo
Team: Peter Dihn, Kevin Fremgen, Jessica Gallo
Date Created: 2/19/2021
Last Modified: 2/24/2021
Description: CSC706 Computer Graphics
				HW1
				Problem2: Basic Drawing
				Draw a village of houses utilizing at least the following GL primities (triangles, triangle
				fans, line strip, masks). Incorporate stippling and masks as a way to model the facade of 
				the houses and/or chimneys, wintdows, etc. Use colors and, in general, be creative as far
				as shapes, colors (backgrounds, foreground, filling) and utilize relative drawing (line-to, 
				move-to). 
*/

#include <windows.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <math.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // Sets display window color to white
	glMatrixMode(GL_PROJECTION);  // Sets projection parameters
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegments(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear display window

	/* GROUND  ============================================================================================================*/
	// Grass to the left of road
	glColor3f(0.196, 0.804, 0.196); // Green
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(0, 150);
	glVertex2i(55, 150);
	glVertex2i(145, 0);
	glEnd();
	// Sidewalk to the left of road
	glColor3f(1.000, 0.973, 0.863); // Beige
	glBegin(GL_POLYGON);
	glVertex2i(55, 150);
	glVertex2i(60, 150);
	glVertex2i(150, 0);
	glVertex2i(145, 0);
	glEnd();
	// Road
	glColor3f(0.753, 0.753, 0.753); // Grey
	glBegin(GL_POLYGON);
	glVertex2i(60, 150);
	glVertex2i(90, 150);
	glVertex2i(208, 0);
	glVertex2i(150, 0);
	glEnd();
	// Sidewalk to the right of road
	glColor3f(1.000, 0.973, 0.863); // Beige
	glBegin(GL_POLYGON);
	glVertex2i(90, 150);
	glVertex2i(95, 150);
	glVertex2i(213, 0);
	glVertex2i(208, 0);
	glEnd();
	// Grass to the right of road
	glColor3f(0.196, 0.804, 0.196); // Green
	glBegin(GL_POLYGON);
	glVertex2i(95, 150);
	glVertex2i(200, 150);
	glVertex2i(200, 15);
	glVertex2i(213, 10);
	glEnd();
	
	/* STREET LINES =======================================================================================================*/
	//glColor3f(1.0, 1.0, 0.0); // yellow
	glColor3f(0.0, 0.0, 0.0); // yellow
	// Right Street Line
	glBegin(GL_LINES);
	glVertex2i(50, 200);
	glVertex2i(200, 10);
	// Left Street Line
	glVertex2i(60, 150);
	glVertex2i(150, 0);
	glEnd();
	// Dotted Line
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(5, 0x00FF);
	glBegin(GL_LINE_STRIP);
	glVertex2i(55, 175);
	glVertex2i(175, 0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	/* HOUSE 1 (bottom left) ==============================================================================================*/
	// Chimney
	glColor3f(0.0, 0.0, 0.0); // black
	glRecti(91, 40, 94, 54);
	// Triangle Rooftop
	glColor3f(0.863, 0.863, 0.863); // light grey
	glBegin(GL_TRIANGLES);
	glVertex2i(90, 40); //L
	glVertex2i(120, 40); // Right
	glVertex2i(103, 60); //Middle
	glEnd();
	// House Rectangle
	glColor3f(0.275, 0.510, 0.70); // steel blue
	glRecti(120, 10, 90, 40);
	// Door
	glColor3f(0.000, 0.000, 0.502); // navy
	glRecti(102, 10, 108, 25);
	// Windows
	glColor3f(0.0, 1.0, 1.0); // blue
	glRecti(93, 36, 99, 30); //L
	glRecti(111, 36, 117, 30); //R
	// Window Lines
	glColor3f(0.0, 0.0, 0.0); // black
	glBegin(GL_LINES);
	glVertex2i(114, 36);
	glVertex2i(114, 30);
	glVertex2i(117, 33);
	glVertex2i(111, 33);
	glVertex2i(99, 33);
	glVertex2i(93, 33);
	glVertex2i(96, 36);
	glVertex2i(96, 30);
	glEnd();
	// Walk Way
	glColor3f(0.0, 0.0, 0.0); // black
	glBegin(GL_LINE_STRIP);
	glVertex2i(102, 10);
	glVertex2i(108, 10);
	glVertex2i(108, 6);
	glVertex2i(141, 6);
	glVertex2i(144, 1);
	glVertex2i(102, 1);
	glVertex2i(102, 10);
	glEnd();

	/* HOUSE 2 (middle left) ==============================================================================================*/
	// Quad Rooftop
	glColor3f(0.804, 0.522, 0.247); // peru brown
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(50, 90); //L
	glVertex2i(60, 100); // M
	glVertex2i(70, 90); //L
	glVertex2i(80, 100); // M
	glVertex2i(90, 90); //L
	glVertex2i(100, 80); // M
	glEnd();
	// House Rectangle
	glColor3f(0.0, 0.0, 0.0); // white
	glRecti(50, 65, 90, 90);
	GLubyte brick[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC
	};
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(brick);
	glColor3f(0.502, 0.000, 0.000); // maroon
	glRecti(50, 65, 90, 90);
	glDisable(GL_POLYGON_STIPPLE);
	// Door
	glColor3f(1.000, 0.894, 0.769); // bisque
	glRecti(67, 78, 73, 65);
	// Windows
	glColor3f(0.0, 1.0, 1.0); // blue
	glRecti(86, 80, 78, 88); //R
	glRecti(61, 80, 53, 88); //L
	// Window Lines
	glColor3f(0.0, 0.0, 0.0); // black
	glBegin(GL_LINES);
	glVertex2i(78, 84);
	glVertex2i(86, 84);
	glVertex2i(82, 80);
	glVertex2i(82, 88);
	glVertex2i(53, 84);
	glVertex2i(61, 84);
	glVertex2i(57, 80);
	glVertex2i(57, 88);

	glEnd();

	/* HOUSE 3 (right) ==============================================================================================*/
	// Quad Rooftop
	glColor3f(0.251, 0.878, 0.816); // turqoise
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(149, 110); //L
	glVertex2i(150, 120); // M
	glVertex2i(160, 110); //L
	glVertex2i(170, 120); // M
	glVertex2i(180, 110); //L
	glVertex2i(190, 100); // M
	glEnd();
	// Triangle Rooftop
	glColor3f(0.282, 0.820, 0.800); // dark turqoise
	glBegin(GL_TRIANGLES);
	glVertex2i(141, 110); //L
	glVertex2i(155, 110); // Right
	glVertex2i(150, 120); //Middle
	glEnd();
	// House Rectangle
	glColor3f(0.878, 1.000, 1.000); // light cyan
	glRecti(141, 110, 155, 90);
	glColor3f(0.686, 0.933, 0.933); // pale turqoise
	glRecti(155, 110, 180, 90);
	// Door
	glColor3f(0.275, 0.510, 0.706); // steel blue
	glRecti(145, 100, 150, 90);
	// Windows
	glColor3f(0.941, 0.973, 1.000); // blue
	glRecti(157, 108, 165, 99); // R1
	glRecti(170, 108, 178, 99); // R2
	// Window Lines
	glColor3f(0.0, 0.0, 0.0); // black
	glBegin(GL_LINES);
	glVertex2i(157, 103);
	glVertex2i(165, 103);
	glVertex2i(174, 108);
	glVertex2i(174, 99);
	glVertex2i(161, 108);
	glVertex2i(161, 99);
	glVertex2i(170, 103);
	glVertex2i(178, 103);
	glEnd();

	/* HOUSE 4 (top left) ==============================================================================================*/
	// Triangle Rooftop
	glColor3f(0.627, 0.322, 0.176); // sienna
	glBegin(GL_TRIANGLES);
	glVertex2i(45, 140); //L
	glVertex2i(55, 150); // M
	glVertex2i(65, 140); //R
	glColor3f(0.0, 0.0, 0.0); // black
	glVertex2i(55, 150); // L
	glVertex2i(45, 140); //M
	glVertex2i(45, 150); // R
	glEnd();
	glColor3f(0.627, 0.322, 0.176); // Color = sienna
	glRecti(20, 140, 45, 150);
	// House Rectangle
	glColor3f(1.000, 0.498, 0.314); // coral
	glRecti(20, 140, 45, 125);
	glColor3f(1.000, 0.627, 0.478); // light salmon
	glRecti(45, 140, 65, 125);
	// Door
	glColor3f(1.0, 1.0, 1.0); // brown
	glRecti(47, 133, 51, 125);
	// Garage
	glColor3f(1.0, 1.0, 1.0); // white
	glRecti(23, 137, 42, 125);
	// Window
	glColor3f(0.0, 1.0, 1.0); // blue
	glRecti(55, 138, 62, 129); 
	// Window Lines
	glColor3f(0.0, 0.0, 0.0); // black
	glBegin(GL_LINES);
	glVertex2i(58, 138);
	glVertex2i(58, 129);
	glVertex2i(55, 133);
	glVertex2i(62, 133);
	glEnd();
	// Car
	// window
	glColor3f(1.0, 0.0, 0.0); // red
	glRecti(25, 122, 32, 120);
	glColor3f(0.0, 1.0, 1.0); // blue
	glRecti(25, 120, 32, 113);
	// window lines
	glColor3f(0.0, 0.0, 0.0); // black
	glBegin(GL_LINES);
	glVertex2i(28, 120);
	glVertex2i(28, 113);
	glEnd();
	// mirrors
	glColor3f(1.0, 0.0, 0.0); // red
	glRecti(24, 117, 25, 114);
	glRecti(32, 117, 33, 114);
	// body
	glRecti(24, 113, 33, 107);
	// headlights
	glColor3f(1.0, 1.0, 0.0); // yellow
	glRecti(25, 111, 27, 109);
	glRecti(30, 111, 32, 109);
	// tires
	glColor3f(0.0, 0.0, 0.0); // black
	glRecti(25, 107, 27, 105);
	glRecti(30, 107, 32, 105);


	/* Trees ==============================================================================================*/
	// Tree 1
	glColor3f(0.5f, 0.35f, 0.05f); // Brown
	glRecti(70, 5, 74, 13);

	glColor3f(0.000, 0.392, 0.000); // Green
	glBegin(GL_TRIANGLES);
	glVertex2i(62, 13);
	glVertex2i(72, 33);
	glVertex2i(82, 13);

	glVertex2i(64, 20);
	glVertex2i(72, 44);
	glVertex2i(80, 20);

	glVertex2i(66, 30);
	glVertex2i(72, 50);
	glVertex2i(78, 30);
	glEnd();

	// Tree 2
	glColor3f(0.5f, 0.35f, 0.05f); // Brown
	glRecti(20, 25, 24, 30);

	glColor3f(0.000, 0.392, 0.000); // Green
	glBegin(GL_TRIANGLES);
	glVertex2i(15, 30);
	glVertex2i(22, 40);
	glVertex2i(29, 30);

	glVertex2i(17, 37);
	glVertex2i(22, 50);
	glVertex2i(27, 37);

	glVertex2i(19, 47);
	glVertex2i(22, 60);
	glVertex2i(25, 47);
	glEnd();

	// Tree 3
	glColor3f(0.5f, 0.35f, 0.05f); // Brown
	glRecti(20, 25, 24, 30);

	glColor3f(0.000, 0.392, 0.000); // Green
	glBegin(GL_TRIANGLES);
	glVertex2i(15, 30);
	glVertex2i(22, 40);
	glVertex2i(29, 30);

	glVertex2i(17, 37);
	glVertex2i(22, 50);
	glVertex2i(27, 37);

	glVertex2i(19, 47);
	glVertex2i(22, 60);
	glVertex2i(25, 47);
	glEnd();

	glFlush(); //Process all OpenGL routines as quickly as possible
}



void main(int argc, char** argv)
{
	glutInit(&argc, argv); // inmitialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Set display mode
	glutInitWindowPosition(50, 50); // Set top-left display window position
	glutInitWindowSize(1300, 700); //Set display window width and height
	glutCreateWindow("HW1 House Project"); //Create display window
	init(); //execute initialization prodecure
	glutDisplayFunc(lineSegments); // send graphics to display window
	glutMainLoop(); //Display everything and wait
}

