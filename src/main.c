#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#ifndef M_PI
	#define M_PI 3.14159265
#endif
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "lib/glutils.h"

#define TWO_PI	(2*M_PI)

/**
 * Config
 */

bool 	fullScreenMode  = false
  , 	keysPressed[255];

int refreshMillis   = 16
	, iWindowWidth    = 640
	, cWindowWidth    = 640
	, iWindowHeight   = 480
	, cWindowHeight   = 480
	,  windowPosX     = 50
	,  windowPosY     = 50;

GLfloat z 								= 1.
	,			planeSizel[3] 		= {10., 1., 100.}
	,			planeSizet[3] 		= {10., 1., 100.}
	,			planeSizer[3] 		= {10., 1., 100.}
	,			cubeSize[3] 			= {1., 1., 1.}

	,			colorText[4] 			=	{1., 1., 1., 1.}

	,			lAmbient[4] 			=	{.0, .0, .0, 1.}
	,			lDiffuse[4] 			=	{1., 1., 1., 1.}
	,			lSpecular[4] 			=	{1., 1., 1., 1.}

	,			posLight[3]				=	{-10.0, 10., 0.}
	,   	posCube[3] 				= {3., .0, -30.}
	,			posText[3]				= {.3, 1.7, .0}
	,			posLeftPlane[3] 	= {-20., .0, -9.}
	,			posBottonPlane[3] = {.0, .0, -9.}
	,			posRightPlane[3] 	= {20., .0, -9.};

/**
 * Aux Functions
 */

void printFloat(float f[3])
{
	printf("%f %f %f\n", f[0],f[1],f[2]);
}

void renderScene()
{
	z += .1;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	posText[2] = posLight[2] = -z - 5;

	glLightfv(GL_LIGHT0, GL_POSITION, posLight);
	TEXT_draw("DAHORA A VIDA", 2., posText, colorText);

	/* CENARIO CONSTRUCTION */

	CUBE_build(cubeSize, posCube, .0);

	PLANE_build(planeSizel, posLeftPlane, PLANE_SIDE_LEFT);
	PLANE_build(planeSizet, posBottonPlane, PLANE_TOP);
	PLANE_build(planeSizer, posRightPlane, PLANE_SIDE_RIGHT);

	/* CENARIO CONSTRUCTION */

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
	glClearDepth(1.);

	/* Habilitando funcionalidades */
	glEnable(GL_DEPTH_TEST);
	/*glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);*/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	/* Configurando luz ambiente */
	glLightfv(GL_LIGHT0, GL_AMBIENT, lAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posLight);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

/**
 * Função principal
 */

int main(int argc, char** argv)
{
	configOpenGL(argc, argv);
	glutMainLoop();

	return 0;
}
