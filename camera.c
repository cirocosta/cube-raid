#include "camera.h"

Camera CAM_create(GLfloat position[], bool *keysPressed, GLfloat *mouseDelta){
  Camera *cam = malloc(sizeof(*cam));

  if (cam == NULL) {
    exit(EXIT_FAILURE);
  }

  cam->camX = position[0];
  cam->camY = position[1];
  cam->camZ = position[2];
  cam->camYaw = .0;
  cam->camPitch = .0;

  /* sensibility */
  cam->mouseVel = .1;
  cam->moveVel = .1;

  cam->keysPressed = keysPressed;
  cam->mouseDelta = mouseDelta;

  return *cam;
}

void CAM_setSensibility(Camera *cam, GLfloat mouse, GLfloat move)
{
  cam->mouseVel = 1.;
  cam->moveVel = 1.;
}

void CAM_destroy(Camera *cam)
{
  free(cam);
  cam = NULL;
}

void CAM_lockCamera(Camera *cam)
{
  if (cam->camPitch > 90) cam->camPitch = 90;
  if (cam->camPitch < -90) cam->camPitch = -90;
  if (cam->camYaw < .0) cam->camYaw += 360.;
  if (cam->camYaw > 360.) cam->camYaw -= 360.;
}

void CAM_moveCamera(Camera *cam, GLfloat dir)
{
  GLfloat rad= (cam->camYaw + dir) * (M_PI/180.0);

  cam->camX -= sin(rad) * cam->moveVel;
  cam->camZ -= cos(rad) * cam->moveVel;
}

void CAM_moveCameraUp(Camera *cam, GLfloat dir)
{
  GLfloat rad= (cam->camPitch + dir) * (M_PI/180.0);

  cam->camY += sin(rad) * cam->moveVel;
}

void CAM_control(Camera *cam)
{
  cam->camYaw += cam->mouseVel * cam->mouseDelta[0];
  cam->camPitch += cam->mouseVel * cam->mouseDelta[1];
  CAM_lockCamera(cam);

  if (cam->keysPressed[KB_A]) {
    CAM_moveCamera(cam, 90.);
  } else if (cam->keysPressed[KB_D]) {
    CAM_moveCamera(cam, 270.);
  }

  if (cam->keysPressed[KB_W]) {
    CAM_moveCamera(cam, .0);
    CAM_moveCameraUp(cam, .0);
  } else if (cam->keysPressed[KB_S]) {
    CAM_moveCamera(cam, 180.);
    CAM_moveCameraUp(cam, 180.);
  }

  glRotatef(-cam->camPitch, 1., .0, .0);
  glRotatef(-cam->camYaw, .0, 1., .0);

  cam->mouseDelta[0] = .0;
  cam->mouseDelta[1] = .0;

  /* DEBUG */
  printf("%s\n", CAM_toString(cam));
}


void CAM_updateCamera(Camera *cam)
{
  CAM_control(cam);
  glTranslatef(-(cam->camX),-(cam->camY),-(cam->camZ));
}

char * CAM_toString(Camera *cam)
{
  char result[100];
  sprintf (result, "cam(x,y,z): (%.2f,%.2f,%.2f)", cam->camX, cam->camY, cam->camZ);

  return result;
}
