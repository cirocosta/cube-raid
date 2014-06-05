#ifndef CAMERA_H
  #include <stdbool.h>
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include "GL/glew.h"
  #ifndef M_PI
    #define M_PI 3.1415926535
  #endif

  #define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)
  #define radiansToDegrees(angleRadians) (angleRadians * 180.0 / M_PI)

  typedef enum
  {
    KB_A = 97,
    KB_W = 119,
    KB_D = 100,
    KB_S = 115
  } KBKey;

  typedef struct Camera
  {
    float camX
      ,   camY
      ,   camZ
      ,   camYaw
      ,   camPitch
      ,   mouseVel
      ,   moveVel
      ,   *mouseDelta;

    bool *keysPressed;
  } Camera;

  Camera CAM_create(float position[], bool *keysPressed, float *mouseDelta);
  void CAM_destroy(Camera *cam);
  void CAM_setSensibility(Camera *cam, float mouse, float move);
  /**
   * Faz com que a camera fique sempre :
   *  - entre [-90, 90] graus de inclinacao.
   *  - com os graus de guinada em [0, 360 graus]
   */
  void CAM_lockCamera(Camera *cam);
  void CAM_moveCamera(Camera *cam, float dir);
  void CAM_moveCameraUp(Camera *cam, float dir);
  void CAM_Control(Camera *cam);
  void CAM_updateCamera(Camera *cam);
  char * CAM_toString(Camera *cam);
#endif
