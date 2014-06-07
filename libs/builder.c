#include "builder.h"

void PLANE_build(GLfloat xyz[3], GLfloat position[3])
{
  GLfloat difamb[] = {0.3,1.0,0.6,1.0};

  glMatrixMode(GL_MODELVIEW);
  glTranslatef(position[0], position[1], position[2]);

  glBegin(GL_QUADS);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, difamb);
    glNormal3f(.0, 1.0, .0);
    glVertex3f(xyz[0]* 10.0, xyz[1]*-1.0, xyz[2]* 100.0);
    glVertex3f(xyz[0]*-10.0, xyz[1]*-1.0, xyz[2]* 100.0);
    glVertex3f(xyz[0]*-10.0, xyz[1]*-1.0, xyz[2]*-100.0);
    glVertex3f(xyz[0]* 10.0, xyz[1]*-1.0, xyz[2]*-100.0);
  glEnd();
}

void CUBE_build(GLfloat xyz[3], GLfloat position[3], GLfloat angle)
{
  GLfloat difamb[] = {1.0, 0.5, 0.3, 1.0};
  glMatrixMode(GL_MODELVIEW);
  glTranslatef(position[0], position[1], position[2]);
  glRotatef(angle, 1., 1.0, .0);

  glBegin(GL_QUADS);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, difamb);

    /* Top face */
    glNormal3f(.0, 1.0, .0);
    glVertex3f(xyz[0]* 1.0, xyz[1]*1.0, xyz[2]*-1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]*1.0, xyz[2]*-1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]*1.0, xyz[2]* 1.0);
    glVertex3f(xyz[0]* 1.0, xyz[1]*1.0, xyz[2]* 1.0);

    /* Bottom face */
    glNormal3f(.0, -1.0, .0);
    glVertex3f(xyz[0]* 1.0, xyz[1]*-1.0, xyz[2]* 1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]*-1.0, xyz[2]* 1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]*-1.0, xyz[2]*-1.0);
    glVertex3f(xyz[0]* 1.0, xyz[1]*-1.0, xyz[2]*-1.0);

    /* Front face */
    glNormal3f(.0, .0, 1.0);
    glVertex3f(xyz[0]* 1.0, xyz[1]* 1.0, xyz[2]*1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]* 1.0, xyz[2]*1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]*-1.0, xyz[2]*1.0);
    glVertex3f(xyz[0]* 1.0, xyz[1]*-1.0, xyz[2]*1.0);

    /* Back face */
    glNormal3f(.0, .0, -1.0);
    glVertex3f(xyz[0]* 1.0, xyz[1]*-1.0, xyz[2]*-1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]*-1.0, xyz[2]*-1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]* 1.0, xyz[2]*-1.0);
    glVertex3f(xyz[0]* 1.0, xyz[1]* 1.0, xyz[2]*-1.0);

    /* Left face */
    glNormal3f(-1.0, .0, .0);
    glVertex3f(xyz[0]*-1.0, xyz[1]* 1.0, xyz[2]* 1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]* 1.0, xyz[2]*-1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]*-1.0, xyz[2]*-1.0);
    glVertex3f(xyz[0]*-1.0, xyz[1]*-1.0, xyz[2]* 1.0);

    /* Right face */
    glNormal3f(1.0, .0, .0);
    glVertex3f(xyz[0]*1.0, xyz[1]* 1.0, xyz[2]*-1.0);
    glVertex3f(xyz[0]*1.0, xyz[1]* 1.0, xyz[2]* 1.0);
    glVertex3f(xyz[0]*1.0, xyz[1]*-1.0, xyz[2]* 1.0);
    glVertex3f(xyz[0]*1.0, xyz[1]*-1.0, xyz[2]*-1.0);
  glEnd();
}
