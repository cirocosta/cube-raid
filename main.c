#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "camera.h"

/**
 * Config
 */
bool paused         = false;
bool fullScreenMode = false;
bool warped         = false;
int refreshMillis   = 16;
float angle         = .0;
int windowWidth     = 640;
int windowHeight    = 480;
int windowPosX      = 50;
int windowPosY      = 50;

Camera cam;
bool IS_KEY_PRESSED[255];


/**
 * Auxiliary Funcs
 */

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

void CUBE_build(GLfloat w, GLfloat h, GLfloat d)
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

void renderScene()
{
  /* clears both color and depth buffers with the clearing color and depth */
  /* before rendering the grahics. */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  angle += .5;

  PLANE_build(1., 1.);
  CUBE_build(1., 1., 1.);

  glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h)
{
  GLfloat aspectRatio;

  if (!h) h = 1;

  aspectRatio = (GLfloat) w / (GLfloat) h;
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45., aspectRatio, .1, 100.);
}

void onKeyboardEnter(unsigned char key, int x, int y)
{
  IS_KEY_PRESSED[key] = true;

  switch (key) {
    case 27:   /* ESC */
    case 113:  /* Q */
       exit(0);
       break;
  }
}

void onKeyboardUp(unsigned char key, int x, int y)
{
  IS_KEY_PRESSED[key] = false;
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
        windowWidth = glutGet(GLUT_WINDOW_WIDTH);
        windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        glutFullScreen();
      } else {
        glutReshapeWindow(windowWidth, windowHeight);
        glutPositionWindow(windowPosX, windowPosY);
      }
    break;
  }
}

void onMouseClick(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    paused = !paused;
    if (paused) {
      /* TODO[ciro] */
      glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
      printf("%s\n", "The program is not paused");
    } else {
      /* TODO[ciro] */
      glutSetCursor(GLUT_CURSOR_NONE);
      printf("%s\n", "The program has been resumed");
    }
  }
}

void Timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(refreshMillis, Timer, 0);
}

void onMouseMove(int x, int y)
{
  printf("(%d %d)\n", windowWidth/2 - x, windowHeight/2 - y);

  if (warped) {
    warped = false;
    return;
  }
  glutWarpPointer(windowWidth/2, windowHeight/2);
  warped = true;
}

/**
 * Prepara OpenGL para que possamos iniciar nosso desenho.
 */
void configOpenGL(int argc, char** argv)
{
  float dif[] = {.2, .2, .2, .0};
  float amb[] = {0.2, 0.2, 0.2, 1.0};
  float spec[] = {.0, .0, .0, .0};
  float lpos[] = {1., 1., 1., 0};

  /* Inicializando janela */
  glutInit(&argc, argv);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Second!");

  /* Funcoes com chamada por callback */
  glutDisplayFunc(renderScene);
  glutReshapeFunc(reshape);
  glutTimerFunc(0, Timer, 0);
  glutMouseFunc(onMouseClick);
  glutSpecialFunc(onSpecialKeyEnter);
  glutKeyboardFunc(onKeyboardEnter);
  glutKeyboardUpFunc(onKeyboardUp);
  glutPassiveMotionFunc(onMouseMove);
  glDepthFunc(GL_LEQUAL);
  glutSetKeyRepeat(0);

  /* Settando cores iniciais */
  glClearColor(.0, .0, .0, 1.);
  glClearDepth(1.); /* sets the background depth to farthest (0 - 1]) */

  /* Habilitando funcionalidades */
  glEnable(GL_DEPTH_TEST); /* enabling depth testing for z-culling */
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  /**
   * Ambient: luz a iluminar todo e qualquer ponto na cena
   * Diffuse: luz a iluminar objetos em torno
   * Specular: iluminar determinadas áreas
   */
  glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
  glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT0, GL_SPECULAR, spec);
  glLightfv(GL_LIGHT0, GL_POSITION, lpos);

  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

int main(int argc, char** argv)
{
  configOpenGL(argc, argv);
  cam = CAM_create();
  glutMainLoop();

  return 0;
}
