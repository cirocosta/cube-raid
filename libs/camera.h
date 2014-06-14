#ifndef CAMERA_H
  #include <stdbool.h>
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include "GL/glew.h"
  #ifndef M_PI
    #define M_PI 3.1415926535
  #endif

  typedef enum
  {
    KB_A = 97,
    KB_W = 119,
    KB_D = 100,
    KB_S = 115
  } KBKey;

  typedef struct Camera
  {
    GLfloat camX
      ,   camY
      ,   camZ
      ,   camYaw
      ,   camPitch
      ,   mouseVel
      ,   moveVel
      ,   *mouseDelta;

    bool *keysPressed;
  } Camera;

  /**
   * Construtor
   * @param  position    array [3] de GLFloat indicando a posicao do
   *                     mesmo
   * @param  keysPressed array [255] indicando o keydown de cada tecla
   * @param  mouseDelta  array [2] indicando o delta para x e y do
   *                     mouse respectivamente
   * @return             instancia de camera.
   */
  Camera CAM_create(GLfloat position[], bool *keysPressed, GLfloat *mouseDelta);
  /**
   * Destrutor
   * @param cam instancia de camera
   */
  void CAM_destroy(Camera *cam);
  /**
   * Setta a sensibilidade da movimentação/view da camera
   * @param cam   instancia da camera
   * @param mouse sens. do mouse
   * @param move  sens. do movimento
   */
  void CAM_setSensibility(Camera *cam, GLfloat mouse, GLfloat move);
  /**
   * Faz com que a camera fique sempre :
   *  - entre [-90, 90] graus de inclinacao.
   *  - com os graus de guinada em [0, 360 graus]
   */
  void CAM_lockCamera(Camera *cam);
  void CAM_moveCamera(Camera *cam, GLfloat dir);
  void CAM_moveCameraUp(Camera *cam, GLfloat dir);
  void CAM_Control(Camera *cam);
  void CAM_updateCamera(Camera *cam);
  char * CAM_toString(Camera *cam);
#endif
