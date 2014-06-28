#include <stdio.h>
#include <stdlib.h>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "lib/queue.h"
#include "models/cenario.h"

int refreshMillis   = 16
	, iWindowWidth    = 640
	, cWindowWidth    = 640
	, iWindowHeight   = 480
	, cWindowHeight   = 480
	,  windowPosX     = 50
	,  windowPosY     = 50;

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere (1.0, 20, 16);
	glLoadIdentity();
	glutSwapBuffers();
}

void onWindowResize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;

	if (!h) h = 1;

	aspectRatio = (GLfloat) w / (GLfloat) h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45., aspectRatio, .1, 100.);
}

void Timer(int value) {
	 glutPostRedisplay();
	 glutTimerFunc(refreshMillis, Timer, 0);
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
	glutReshapeFunc(onWindowResize);
	glutTimerFunc(0, Timer, 0);
	glDepthFunc(GL_LEQUAL);
	glutSetKeyRepeat(0);

	/* Settando cores iniciais */
	glClearColor(.0, .0, .0, 1.);
	glClearDepth(1.); /* sets the background depth to farthest (0 - 1]) */

	/* Habilitando funcionalidades */
	glEnable(GL_DEPTH_TEST); /* enabling depth testing for z-culling */

	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

int main(int argc, char** argv)
{
	configOpenGL(argc, argv);
	glutMainLoop();

	return 0;
}
