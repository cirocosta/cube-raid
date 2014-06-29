#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "GL/glew.h"
#include "GL/freeglut.h"

#include "lib/glutils.h"
#include "lib/position.h"
#include "models/nave.h"

#ifndef TWO_PI
	#define TWO_PI	(2*M_PI)
#endif


typedef enum
{
  KB_A = 97,
  KB_W = 119,
  KB_D = 100,
  KB_S = 115
} KBKey;


Nave nave;

/**
 * Config
 */

Position posCube;

static bool 	fullScreenMode  = false
  	, 				keysPressed[255];

static int 	refreshMillis   = 16
		,		    iWindowWidth    = 640
		,		    iWindowHeight   = 480
		,		     windowPosX     = 50
		,		     windowPosY     = 50;

static GLfloat z 						= 1.
		,			cubeSize[3] 			= {1., 1., 1.}
		,			colorText[4] 			=	{1., 1., 1., 1.}
		,			posText[3]				= {.3, 1.7, .0}
		,			posLeftPlane[3] 	= {-20., .0, 0.}
		,			posBottonPlane[3] = {.0, .0, 0.}
		,			posRightPlane[3] 	= {20., .0, 0.};

static Light spots[] =
{
  /* LUZ BRANCA! */
  {
    {0.2, 0.2, 0.2, 1.0},  /* ambient */
    {0.8, 0.8, 0.8, 1.0},  /* diffuse */
    {0.4, 0.0, 0.0, 1.0},  /* specular */
    {1.0, 0.0, 0.0, 1.0},  /* position */
    {0.0, 0.0, -1.0},   /* direction */
     20.0,						 /* exponent */
     90.0,             /* cutoff */
    {.5, 0.0, 0.0},    /* attenuation */
    {0.0, 0.0, 0.0},   /* translation */
    {0.0, 0.0, 0.0},    /* rotation */
    {20.0, 0.0, 40.0},  /* swing */
    {0.0, 0.0, 0.0},    /* arc */
    {TWO_PI / 70.0, 0.0, TWO_PI / 140.0}  /* arc increment */
  }
};

static float modelAmb[4] = {0.2, 0.2, 0.2, 1.0}
      ,      matAmb[4] = {0.2, 0.2, 0.2, 1.0}
      ,      matDiff[4] = {0.8, 0.8, 0.8, 1.0}
      ,      matSpec[4] = {0.4, 0.4, 0.4, 1.0}
      ,      matEmission[4] = {0.0, 0.0, 0.0, 1.0};

Light *light = &spots[0];

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
	nave.pos.z = -z - 5;
	posText[2] = -z - 5;
	light->trans[2] = -z + 10;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (keysPressed[KB_A])
		nave.pos.x -= .1;
	else if (keysPressed[KB_D])
		nave.pos.x += .1;


	if (keysPressed[KB_W])
		nave.pos.y += .1;
	else if (keysPressed[KB_S])
		nave.pos.y -= .1;

	LIGHT_set(light, GL_LIGHT0);
	TEXT_draw("DAHORA A VIDA", 2., posText, colorText);
	CUBE_build(cubeSize, posCube, .0);
	NAVE_draw(&nave);
	LIGHT_draw(light);

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
	glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);

  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, modelAmb);
  glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

  glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
  glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
  glMaterialfv(GL_FRONT, GL_EMISSION, matEmission);
  glMaterialf(GL_FRONT, GL_SHININESS, 10.0);

	LIGHT_init(light, GL_LIGHT0);

	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

/**
 * Função principal
 */

int main(int argc, char** argv)
{
	posCube = POS_create(1., .0, -30.);

	nave = NAVE_create(
    		POS_create(0., -.8, 0.), 	/* Position */
    		1,							/* Velocity */
				POS_create(10., 10., 10.),	/* Orientation */
				10);

	configOpenGL(argc, argv);
	glutMainLoop();

	return 0;
}
