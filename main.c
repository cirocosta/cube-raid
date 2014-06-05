#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "camera.h"
#include "builder.h"

/**
 * Config
 */
bool paused         = false
  , fullScreenMode  = false
  , warped          = false
  , IS_KEY_PRESSED[255];

float angle         = .0;

int refreshMillis   = 16
  , iWindowWidth    = 640
  , cWindowWidth    = 640
  , iWindowHeight   = 480
  , cWindowHeight   = 480
  ,  windowPosX     = 50
  ,  windowPosY     = 50;

Camera cam;

/**
 * Auxiliary Funcs
 */

void centerPointer()
{
  glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH)/2,
                  glutGet(GLUT_WINDOW_HEIGHT)/2);
  warped = true;
}


void renderScene()
{
  /* clears both color and depth buffers with the clearing color and depth */
  /* before rendering the grahics. */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  PLANE_build(1., 1.);
  CUBE_build(1., 1., 1., angle += .5);

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

  centerPointer();
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
  printf("(%d %d)\n", glutGet(GLUT_WINDOW_WIDTH)/2 - x,
                      glutGet(GLUT_WINDOW_HEIGHT)/2 - y);

  if (warped) {
    warped = false;
    return;
  }
  centerPointer();
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
  glutReshapeFunc(onWindowResize);
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
