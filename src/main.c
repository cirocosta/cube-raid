#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "lib/glutils.h"

/**
 * Config
 */

bool fullScreenMode  = false
  , keysPressed[255];

int refreshMillis   = 16
	, iWindowWidth    = 640
	, cWindowWidth    = 640
	, iWindowHeight   = 480
	, cWindowHeight   = 480
	,  windowPosX     = 50
	,  windowPosY     = 50;

GLfloat z 								= 1.
	,   	posCube[3] 				= {3., .0, -30.}
	,			planeSize[3] 			= {10., 1., 100.}
	,			cubeSize[3] 			= {1., 1., 1.}
	,			posLeftPlane[3] 	= {-20., .0, -9.}
	,			posBottonPlane[3] = {.0, .0, -9.}
	,			posRightPlane[3] 	= {20., .0, -9.};

/**
 * Aux Functions
 */

void renderScene()
{
	z += .1;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* CENARIO CONSTRUCTION */

	CUBE_build(cubeSize, posCube, .0);

	PLANE_build(planeSize, posLeftPlane, PLANE_SIDE_LEFT);
	PLANE_build(planeSize, posBottonPlane, PLANE_TOP);
	PLANE_build(planeSize, posRightPlane, PLANE_SIDE_RIGHT);

	/* CENARIO CONSTRUCTION */

	printf("%f\n", z);

	glLoadIdentity();
	glTranslatef(.0, .0, z);
	glutSwapBuffers();
}

void resizeWindow(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;

	if (!h) h = 1;

	aspectRatio = (GLfloat) w / (GLfloat) h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45., aspectRatio, .1, 100.);
}

void tickTimer(int value) {
	 glutPostRedisplay();
	 glutTimerFunc(refreshMillis, tickTimer, 0);
}

void onKeyDown(unsigned char key, int x, int y)
{
  keysPressed[key] = true;

  switch (key) {
    case 27:   /* ESC */
    case 113:  /* Q */
       exit(0);
       break;
  }
}

void onKeyUp(unsigned char key, int x, int y)
{
  keysPressed[key] = false;
}

/**
 * Callback for special input, like arrow and etc. (x,y) are the
 * position of the mouse at the moment of the fire of the event.
 */
void onSpecialKeyEnter(int key, int x, int y)
{
  switch (key) {
    case GLUT_KEY_F1:
      fullScreenMode = !fullScreenMode;
      if (fullScreenMode) {
        windowPosX = glutGet(GLUT_WINDOW_X);
        windowPosY = glutGet(GLUT_WINDOW_Y);
        iWindowWidth = glutGet(GLUT_WINDOW_WIDTH);
        iWindowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        glutFullScreen();
      } else {
        glutReshapeWindow(iWindowWidth, iWindowHeight);
        glutPositionWindow(windowPosX, windowPosY);
      }
    break;
  }
}

void configOpenGL(int argc, char** argv)
{
	GLfloat amb[] = {0.2, 0.2, 0.2, 1.0};

	/* Inicializando janela */
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Second!");

	/* Funcoes com chamada por callback */
	glutDisplayFunc(renderScene);
	glutReshapeFunc(resizeWindow);
	glutTimerFunc(0, tickTimer, 0);
  glutSpecialFunc(onSpecialKeyEnter);
  glutKeyboardFunc(onKeyDown);
  glutKeyboardUpFunc(onKeyUp);
	glDepthFunc(GL_LEQUAL);
	glutSetKeyRepeat(0);

	/* Settando cores iniciais */
	glClearColor(.0, .0, .0, 1.);
	glClearDepth(1.); /* sets the background depth to farthest (0 - 1]) */

	/* Habilitando funcionalidades */
	glEnable(GL_DEPTH_TEST); /* enabling depth testing for z-culling */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);

	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

int main(int argc, char** argv)
{
	configOpenGL(argc, argv);
	glutMainLoop();

	return 0;
}
