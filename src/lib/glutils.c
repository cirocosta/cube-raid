#include "glutils.h"

void PLANE_build(GLfloat xyz[3], GLfloat position[3], PLANE_type tipo)
{
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
        glRotatef(0, .0, .0, 0.);
        break;
      case PLANE_FRONT:
        glRotatef(90, 1., .0, .0);
        break;
    }

    glBegin(GL_QUADS);
      glNormal3f(0.0, 0.0, 1.0);
      glVertex3f(xyz[0]* 10.0, xyz[1]*-1.0, xyz[2]* 100.0);
      glVertex3f(xyz[0]*-10.0, xyz[1]*-1.0, xyz[2]* 100.0);
      glVertex3f(xyz[0]*-10.0, xyz[1]*-1.0, xyz[2]*-100.0);
      glVertex3f(xyz[0]* 10.0, xyz[1]*-1.0, xyz[2]*-100.0);
    glEnd();
  glPopMatrix();
}

void CUBE_build(GLfloat xyz[3], GLfloat position[3], GLfloat angle)
{
  glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(position[0], position[1], position[2]);
    glRotatef(angle, 1., 1.0, .0);

    glBegin(GL_QUADS);
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

void LIGHT_init(Light *light, int lt)
{
  glEnable(lt);
  glLightfv(lt, GL_AMBIENT, light->amb);
  glLightfv(lt, GL_DIFFUSE, light->diff);
  glLightfv(lt, GL_SPECULAR, light->spec);

  glLightf(lt, GL_SPOT_EXPONENT, light->spotExp);
  glLightf(lt, GL_SPOT_CUTOFF, light->spotCutoff);
  glLightf(lt, GL_CONSTANT_ATTENUATION, light->atten[0]);
  glLightf(lt, GL_LINEAR_ATTENUATION, light->atten[1]);
  glLightf(lt, GL_QUADRATIC_ATTENUATION, light->atten[2]);
}


void LIGHT_set(Light *light, int lt)
{
  glPushMatrix();
    glTranslatef(light->trans[0], light->trans[1], light->trans[2]);
    glRotatef(light->rot[0], 1, 0, 0);
    glRotatef(light->rot[1], 0, 1, 0);
    glRotatef(light->rot[2], 0, 0, 1);
    glLightfv(lt, GL_POSITION, light->pos);
    glLightfv(lt, GL_SPOT_DIRECTION, light->spotDir);
  glPopMatrix();
}

void LIGHT_draw(Light *light)
{
  glDisable(GL_LIGHTING);

  glColor4fv(light->diff);
  glPushMatrix();
    glTranslatef(light->trans[0], light->trans[1], light->trans[2]);
    glRotatef(light->rot[0], 1, 0, 0);
    glRotatef(light->rot[1], 0, 1, 0);
    glRotatef(light->rot[2], 0, 0, 1);

    glBegin(GL_LINES);
      glVertex3f(light->pos[0], light->pos[1], light->pos[2]);
      glVertex3f(light->spotDir[0], light->spotDir[1], light->spotDir[2]);
    glEnd();

  glPopMatrix();

  glEnable(GL_LIGHTING);
}
