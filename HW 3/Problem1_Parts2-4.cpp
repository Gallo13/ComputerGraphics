/*
Created by: Jessica Gallo
Date Created: 4/10/2021
Last Modified: 4/12/2021
Team: Dihn, Fremgen, Gallo
CSC706 Computer Graphics
HW 3 Problem 1 Parts 2-4
*/

#include <windows.h>
#include <GL/glew.h>
#include <math.h>
//#include <iostream>
//#include <fstream>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//#include <stdlib.h>
//#include <cstdio>
//#include <stdio.h>

// MARK: - draw

void setMaterial(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
    GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
    GLfloat specularR, GLfloat specularG, GLfloat specularB,
    GLfloat shininess) {

    GLfloat ambient[] = { ambientR, ambientG, ambientB };
    GLfloat diffuse[] = { diffuseR, diffuseG, diffuseB };
    GLfloat specular[] = { specularR, specularG, specularB };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void display() {


    // clear window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set the projection matrix
    glMatrixMode(GL_MODELVIEW);



    // draw scene
    // TODO: - house
     glPushMatrix();

    /******** house body *********/

    // push a matrix onto the stack
    glPushMatrix();
    // draw a 3d solid cube
    glutSolidCube(2);
    // pop the matrix off the stack
    glPopMatrix();

    /***** roof *******/

    // push a matrix onto the stack
    glPushMatrix();
    // apply transformations
    glTranslatef(0, 2, 0);
    glRotatef(-90, 0, 0, 0);
    // draw 3d solid cone
    glutSolidCone(1.5, 1, 16, 8);
    // pop the matrix off the stack
    glPopMatrix();

    /******* chimney *******/

    // push a matrix onto the stack
    glPushMatrix();
    // apply transformations
    glTranslatef(.75, 1.70, -.50);
    glScalef(1, 3, 1);
    // draw 3d solid cube
    glutSolidCube(.25);
    // pop matrix off stack
    glPopMatrix();

    /* Sun */

    glPushMatrix();
    glTranslatef(1, 1.90, -2.5);
    glScalef(1, 1, 1);
    glutSolidSphere(0.5, 70, 70);
    glPopMatrix();


    //TODO: -  car

    /******* car  body *********/
    setMaterial(1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 50);
    // push a matrix onto the stack
    glPushMatrix();
    // apply transformations
    glTranslatef(-3, -4, .50);
    glScalef(2.50, 1, 1);
    // draw 3d solid cube
    glutSolidCube(.5);
    // pop matrix off stack
    glPopMatrix();

    /******* wheels *********/

    // push a matrix onto the stack
    glPushMatrix();
    // apply transformations
    glTranslatef(-4, -6, 0);
    glScalef(1.5, 1.5, 1);
    // draw a solid torus
    glutSolidTorus(.05, .1, 8, 8);
    // pop matrix off stack
    glPopMatrix();

    // push a matrix onto the stack
    glPushMatrix();
    glTranslatef(-5, -6, 0);
    glScalef(1.5, 1.5, 1);
    glutSolidTorus(.05, .1, 8, 8);
    // pop matrix off stack
    glPopMatrix();

    // push a matrix onto the stack
    glPushMatrix();
    glTranslatef(-2.50, -4.25, .25);
    glScalef(1.5, 1.5, 1);
    glutSolidTorus(.05, .1, 8, 8);
    // pop matrix off stack
    glPopMatrix();

    glPopMatrix();

    // Display the frame buffer
    glFlush();
}

// MARK: - reshape

void reshape(int width, int height) {
    // Reshape the viewport, where we will actually draw
    // Set it to the entire window
    glViewport(0, 0, width, height);
}

// MARK: - main
int main(int argc, char* argv[]) {
    // initialize GLUT
    glutInit(&argc, argv);
    // setup the size, position, and display mode for new windows
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

    // create and set up a window
    glutCreateWindow("hello, house!");
    // called when ever window needs to be drawn
    glutDisplayFunc(display);
    // called when ever window is reshaped
    glutReshapeFunc(reshape);
    // set up depth-buffering
    glEnable(GL_DEPTH_TEST);
    // turn on default lighting
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0); //default diffuse and specular light
    // glShadeModel(GL_SMOOTH);
    //glEnable(GL_NORMALIZE);

    /* LIGHT ONE =======================================================*/
    // Different Lighting
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT1);

    //GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; /* bright white */
    //GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };

    //glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    //glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

    //GLfloat light1_ambient[] = { 0.8, 0.8, 0.8, 1.0 }; /* soft white */
    //glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);

    // Turn light 1 into a positional light
    //GLfloat light1_position[] = { 0.0, 0.0, 1.0, 1.0 };
    //glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

    // Specify Material Color and Shineness
    //GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; /* bright white */
    //GLfloat mat_diffuse[] = { 1.0, 0.5, 0.0, 1.0 }; /* orange color */
    //GLfloat mat_ambient[] = { 1.0, 0.5, 0.0, 1.0 }; /* same as diffuse */
    //GLfloat mat_shininess = 5.0;
    //glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    //glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    //glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

    /* LIGHT TWO =======================================================*/
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
     // Brass color
    GLfloat mat_specular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
    GLfloat mat_diffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
    GLfloat mat_ambient[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };
    GLfloat mat_shininess[] = { 27.8974f };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHT1);

    GLfloat light1_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_position[] = { -2.0, 2.0, 1.0, 1.0 };
    GLfloat spot_direction[] = { -1.0, -1.0, 0.0 };

    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40, 1, 4, 20);
    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    // tell GLUT to wait for events
    glutMainLoop();
    return 0;

}