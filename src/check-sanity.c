/**
 * Mostra um quadrado vermelho na janela. Testa então se a freeglut está
 * devidamente configurada.
 */

#include <stdio.h>
#include <stdlib.h>
#include "GL/glew.h"
#include "GL/freeglut.h"

void display()
{
  glClearColor(.0, .0, .0, 1.);
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-.8, -.8);
    glVertex2f( .8, -.8);
    glVertex2f( .8,  .8);
    glVertex2f(-.8,  .8);
  glEnd();

  glFlush();
}

void configOpenGL(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutCreateWindow("Learning OpenGL");
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100,100);
  glutDisplayFunc(display);
}

int main(int argc, char **argv)
{
  configOpenGL(argc, argv);
  glutMainLoop();

  return 0;
}