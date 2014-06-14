#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "../libs/camera.h"
#include "../libs/builder.h"
#include "../libs/text-drawer.h"

/**
 * Config
 */
bool paused         = false
  , fullScreenMode  = false
  , warped          = false
  , keysPressed[255];

TDRAWER_Text *textCounter;
int counter;

GLfloat mouseDelta[2] = {.0, .0}
  ,   firstPosition[3] = {.0, .0, -9.}

  ,   cubeSize[3] = {1., 1., 1.}

  ,   bulbPosition[3] = {.0, 7.0, -9.}
  ,   bulbSize[3] = {.2, 1.3, .2}

  ,   planeSize[3] = {10., 1., 100.};

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


  printf("%f %f %f\n", textCounter->position[0], textCounter->position[1], textCounter->position[2]);
  printf("%f %f %f %f\n", textCounter->color[0], textCounter->color[1], textCounter->color[2], textCounter->color[3]);


  PLANE_build(planeSize, firstPosition);
  CUBE_build(cubeSize, firstPosition, .0);
  CUBE_build(bulbSize, bulbPosition, 90.);

  glutSolidSphere (1.0, 20, 16);

  glLoadIdentity();
  CAM_updateCamera(&cam);

  textCounter->text = "dahora";
  TDRAWER_draw(textCounter);

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

void onKeyDown(unsigned char key, int x, int y)
{
  keysPressed[key] = true;

  switch (key) {
    case 99:
      counter++;
      break;
    case 27:   /* ESC */
    case 113:  /* Q */
       exit(0);
       break;
  }
}

void onKeyUp(unsigned char key, int x, int y)
{
  keysPressed[key] = false;
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

void Timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(refreshMillis, Timer, 0);
}

void onMouseMove(int x, int y)
{
  if (warped) {
    warped = false;
    return;
  }

  mouseDelta[0] = glutGet(GLUT_WINDOW_WIDTH)/2 - x;
  mouseDelta[1] = glutGet(GLUT_WINDOW_HEIGHT)/2 - y;
  centerPointer();
}

void enableFog(GLfloat start, GLfloat end, GLfloat dens, GLfloat fogColor[])
{
  glEnable(GL_FOG);
  /**
   * Habilitando nevoa
   */
  glFogi(GL_FOG_MODE, GL_EXP);
  glFogf(GL_FOG_START, 1.0);
  glFogf(GL_FOG_END, 10.0);
  glFogfv(GL_FOG_COLOR, fogColor);
  glFogf(GL_FOG_DENSITY, .2);
}

/**
 * Prepara OpenGL para que possamos iniciar nosso desenho.
 */
void configOpenGL(int argc, char** argv)
{
  GLfloat dif[] = {.2, .2, .2, .0}
    ,     amb[] = {0.2, 0.2, 0.2, 1.0}
    ,     spec[] = {.0, .0, .0, .0}
    ,     lpos[] = {1., 1., 1., 1}
    ,     fogColor[] = {.5, .5, .5, 1.};

  /* Inicializando janela */
  glutInit(&argc, argv);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Second!");

  /* Funcoes com chamada por callback */
  glutDisplayFunc(renderScene);
  glutReshapeFunc(onWindowResize);
  glutTimerFunc(0, Timer, 0);
  glutSpecialFunc(onSpecialKeyEnter);
  glutKeyboardFunc(onKeyDown);
  glutKeyboardUpFunc(onKeyUp);
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


  /*enableFog(1., 10., .2, fogColor);*/

  /**
   * Ambient: luz a iluminar todo e qualquer ponto na cena
   * Diffuse: luz a iluminar objetos em torno
   * Specular: iluminar determinadas áreas
   */
  /*glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);*/
  glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
  /*glLightfv(GL_LIGHT0, GL_SPECULAR, spec);*/
  /*glLightfv(GL_LIGHT0, GL_POSITION, lpos);*/

  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

int main(int argc, char** argv)
{
  configOpenGL(argc, argv);
  cam = CAM_create(firstPosition, keysPressed, mouseDelta);
  textCounter = TDRAWER_new("");
  glutMainLoop();

  return 0;
}
