#include <stdio.h>
#include <string.h>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "text-drawer.h"

GLfloat x = .0
	,			y = .0
  ,     z = .0;

char * text = "dahora";
TDRAWER_Text * text1;

int refreshMillis = 16;

void onDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT);

  TDRAWER_draw(text1);

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

int main(int argc, char **argv)
{
	glutInitWindowSize(500, 250);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutCreateWindow("TextRenderer!");

	text1 = TDRAWER_new(text);

	glutDisplayFunc(onDisplay);
	glutReshapeFunc(onWindowResize);
	glutTimerFunc(0, Timer, 0);

	glutMainLoop();

	return 0;
}
