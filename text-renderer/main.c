#include <stdio.h>
#include <string.h>
#include "GL/glew.h"
#include "GL/freeglut.h"

GLfloat x = .0
	,			y = .0;

int refreshMillis = 16;

/**
 * Fontes que estou disponibilizando
 */
void * BITMAP_FONTS[3] = {
  GLUT_BITMAP_HELVETICA_10,
  GLUT_BITMAP_HELVETICA_12,
  GLUT_BITMAP_HELVETICA_18
};

void printBitmapString(void * font, char * s)
{
	if (s && strlen(s)) {
		while (*s) {
			glutBitmapCharacter(font, *s);
			s++;
		}
	}
}

void onDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glColor3f(1., 1., 1.);
  glRasterPos2f(x += .01, y += .01);
  printBitmapString(BITMAP_FONTS[2], "Something cool!");

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

   glutDisplayFunc(onDisplay);
   glutReshapeFunc(onWindowResize);
   glutTimerFunc(0, Timer, 0);

   glutMainLoop();

	return 0;
}
