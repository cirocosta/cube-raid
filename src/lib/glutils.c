#include "glutils.h"

void PLANE_build(GLfloat xyz[3], GLfloat position[3], PLANE_type tipo)
{
  GLfloat shininess[] = {90}
    ,     qaBlack[4] = {.0, .0, .0, 1.}
    ,     qaWhite[4] = {1., 1., 1., 1.}
    ,     qaRed[4]  = {1., 1., .0, 1.}
    ,     qaGreen[4] = {.0, 1., .0, 1.}
    ,     qaBlue[4]   = {.0, .0, 1., 1.};

  glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(position[0], position[1], position[2]);
    switch (tipo) {
      case PLANE_SIDE_RIGHT:
      case PLANE_SIDE_LEFT:
        glRotatef(90, .0, .0, 1.);
        break;
      case PLANE_BOTTOM:
      case PLANE_TOP:
        glRotatef(0, .0, .0, 1.);
        break;
      case PLANE_FRONT:
        glRotatef(90, 1., .0, .0);
        break;
    }

    glBegin(GL_QUADS);/*
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGreen);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);*/

      glNormal3f(.0, 0., 1.0);
      glVertex3f(xyz[0]* 10.0, xyz[1]*-1.0, xyz[2]* 100.0);
      glVertex3f(xyz[0]*-10.0, xyz[1]*-1.0, xyz[2]* 100.0);
      glVertex3f(xyz[0]*-10.0, xyz[1]*-1.0, xyz[2]*-100.0);
      glVertex3f(xyz[0]* 10.0, xyz[1]*-1.0, xyz[2]*-100.0);
    glEnd();
  glPopMatrix();
}

void CUBE_build(GLfloat xyz[3], GLfloat position[3], GLfloat angle)
{
  GLfloat shininess[] = {30}
    ,     qaBlack[4] = {.0, .0, .0, 1.}
    ,     qaWhite[4] = {1., 1., 1., 1.}
    ,     qaRed[4]  = {1., 1., .0, 1.}
    ,     qaGreen[4] = {.0, 1., .0, 1.}
    ,     qaBlue[4]   = {.0, .0, 1., 1.};

  glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(position[0], position[1], position[2]);
    glRotatef(angle, 1., 1.0, .0);

    glBegin(GL_QUADS);

      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, qaRed);
      glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
      glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

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
  glPopMatrix();
}


void TEXT_draw(char * message, float size, GLfloat pos[3], GLfloat color[3])
{
  glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(size * 0.001, size * 0.001, size * 0.001);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

    while (*message)
      glutStrokeCharacter(GLUT_STROKE_ROMAN, *message++);
  glPopMatrix();
}
