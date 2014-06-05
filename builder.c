#include "builder.h"

void PLANE_build(float w, float h)
{
  float difamb[] = {0.3,1.0,0.6,1.0};

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(1.5, .0, -7.);

  glBegin(GL_QUADS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, difamb);
    glVertex3f( 1.0, -1.0,  100.0);
    glVertex3f(-1.0, -1.0,  100.0);
    glVertex3f(-1.0, -1.0, -100.0);
    glVertex3f( 1.0, -1.0, -100.0);
  glEnd();
}

void CUBE_build(GLfloat w, GLfloat h, GLfloat d, float angle)
{
  float difamb[] = {1.0, 0.5, 0.3, 1.0};
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(1.5, .0, -7.);
  glRotatef(angle, 1., 1.0, .0);

  glBegin(GL_QUADS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, difamb);

    /* Top face */
    glNormal3f(.0, 1.0, .0);
    glVertex3f(w* 1.0, h*1.0, d*-1.0);
    glVertex3f(w*-1.0, h*1.0, d*-1.0);
    glVertex3f(w*-1.0, h*1.0, d* 1.0);
    glVertex3f(w* 1.0, h*1.0, d* 1.0);

    /* Bottom face */
    glNormal3f(.0, -1.0, .0);
    glVertex3f(w* 1.0, h*-1.0, d* 1.0);
    glVertex3f(w*-1.0, h*-1.0, d* 1.0);
    glVertex3f(w*-1.0, h*-1.0, d*-1.0);
    glVertex3f(w* 1.0, h*-1.0, d*-1.0);

    /* Front face */
    glNormal3f(.0, .0, 1.0);
    glVertex3f(w* 1.0, h* 1.0, d*1.0);
    glVertex3f(w*-1.0, h* 1.0, d*1.0);
    glVertex3f(w*-1.0, h*-1.0, d*1.0);
    glVertex3f(w* 1.0, h*-1.0, d*1.0);

    /* Back face */
    glNormal3f(.0, .0, -1.0);
    glVertex3f(w* 1.0, h*-1.0, d*-1.0);
    glVertex3f(w*-1.0, h*-1.0, d*-1.0);
    glVertex3f(w*-1.0, h* 1.0, d*-1.0);
    glVertex3f(w* 1.0, h* 1.0, d*-1.0);

    /* Left face */
    glNormal3f(-1.0, .0, .0);
    glVertex3f(w*-1.0, h* 1.0, d* 1.0);
    glVertex3f(w*-1.0, h* 1.0, d*-1.0);
    glVertex3f(w*-1.0, h*-1.0, d*-1.0);
    glVertex3f(w*-1.0, h*-1.0, d* 1.0);

    /* Right face */
    glNormal3f(1.0, .0, .0);
    glVertex3f(w*1.0, h* 1.0, d*-1.0);
    glVertex3f(w*1.0, h* 1.0, d* 1.0);
    glVertex3f(w*1.0, h*-1.0, d* 1.0);
    glVertex3f(w*1.0, h*-1.0, d*-1.0);
  glEnd();
}
