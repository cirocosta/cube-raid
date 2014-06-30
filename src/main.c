#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "GL/glew.h"
#include "GL/freeglut.h"

#include "lib/glutils.h"
#include "lib/position.h"

#include "models/nave.h"
#include "models/cenario.h"

/* Config */

static bool 	fullScreenMode  = false
  	, 				keysPressed[255];

static int 	refreshMillis   = 16
		,		    iWindowWidth    = 640
		,		    iWindowHeight   = 480
		,		     windowPosX     = 50
		,		     windowPosY     = 50;

static GLfloat z 						= 1.
		,			colorText[4] 			=	{1., 1., 1., 1.}
		,			posText[3]				= {.3, 1.7, .0};

static Light spots[] = {
  {
    {0.2, 0.2, 0.2, 1.0},   /* ambient */
    {0.8, 0.8, 0.8, 1.0},   /* diffuse */
    {0.4, 0.0, 0.0, 1.0},   /* specular */
    {1.0, 0.0, 0.0, 1.0},   /* position */
    {0.0, 0.0, -1.0},       /* direction */
     20.0,						      /* exponent */
     90.0,                  /* cutoff */
    {.5, 0.0, 0.0},         /* attenuation */
    {0.0, 0.0, 0.0},        /* translation */
    {0.0, 0.0, 0.0},        /* rotation */
  }
};

static float modelAmb[4] = {0.2, 0.2, 0.2, 1.0}
      ,      matAmb[4] = {0.2, 0.2, 0.2, 1.0}
      ,      matDiff[4] = {0.8, 0.8, 0.8, 1.0}
      ,      matSpec[4] = {0.4, 0.4, 0.4, 1.0}
      ,      matEmission[4] = {0.0, 0.0, 0.0, 1.0};

Position posCube;
Light *light = &spots[0];
Nave nave;
Queue map;
CircularBuffer *cb;
char txtLife[50];

/**
 * Handler dos ticks - frames chamados
 */
void renderScene()
{
	z += .1;
	posText[2] = -z - 5;
	light->trans[2] = -z + 10;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	LIGHT_set(light, GL_LIGHT0);

  sprintf(txtLife, "VIDA: (%d)", nave.hp);
	TEXT_draw(txtLife, 2., posText, colorText);

	NAVE_update(&nave, keysPressed, z);
	NAVE_draw(&nave);

	CENARIO_draw(cb, nave);
	CENARIO_detect_collision(cb, &nave);

	LIGHT_draw(light);

	glLoadIdentity();
	glTranslatef(.0, .0, z);

	glutSwapBuffers();
}

/**
 * Handler do evento de Resize
 */

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

/**
 * Controle de KEYS do teclado
 */

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

/**
 * Inicializacao da configuracao do OpenGL (glew/glut)
 */
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

  /* Definindo a iluminação do ambiente */
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, modelAmb);
  glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

  /* Materiais a serem usados */
  glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
  glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
  glMaterialfv(GL_FRONT, GL_EMISSION, matEmission);
  glMaterialf(GL_FRONT, GL_SHININESS, 10.0);

  /* Inicializacao da Luz */
	LIGHT_init(light, GL_LIGHT0);

  glutSetCursor(GLUT_CURSOR_NONE);
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
			10 							/* HP */
	);

	map = CENARIO_create("map1");
    CENARIO_init(&cb, map);

	configOpenGL(argc, argv);
	glutMainLoop();

	return 0;
}
