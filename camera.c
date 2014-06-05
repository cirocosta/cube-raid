#include "camera.h"

Camera CAM_create(){
    Camera *cam = malloc(sizeof(*cam));

    if (cam == NULL) {
      exit(EXIT_FAILURE);
    }

    cam->camX = .0;
    cam->camY = .0;
    cam->camZ = 5.;
    cam->camYaw = .0;
    cam->camPitch = .0;

    return *cam;
}

void CAM_destroy(Camera *cam)
{
  free(cam);
  cam = NULL;
}

void  CAM_lockCamera(Camera *cam)
{
  if (cam->camPitch > 90) cam->camPitch = 90;
  if (cam->camPitch < -90) cam->camPitch = -90;
  if (cam->camYaw < .0) cam->camYaw += 360.;
  if (cam->camYaw > 360.) cam->camYaw -= 360.;
}

void CAM_moveCamera(Camera *cam, float dist, float dir)
{
  float rad = degreesToRadians(cam->camYaw + dir);

  cam->camX -= sin(rad) * dist;
  cam->camZ -= cos(rad) * dist;
}

void CAM_moveCameraUp(Camera *cam, float dist, float dir)
{
  float rad = degreesToRadians(cam->camPitch + dir);

  cam->camY += sin(rad) * dist;
}

void CAM_Control(Camera *cam, float moveVel, float mouseVel,
                 bool mouseIn, int positions[])
{
  if (mouseIn) {
    printf("%s\n", "mouse in!");
    /*glutSetCursor(GLUT_CURSOR_NONE);*/
/*    int midX = positions[0] / 2;
    int midY = positions[1] / 2;

    int mX = positions[2];
    int mY = positions[3];

    cam->camYaw += mouseVel * (midX - mX);
    cam->camPitch += mouseVel * (midY - mY);

    CAM_lockCamera(cam);

    glutWarpPointer(midX, midY);*/
  } else {
    /*glutSetCursor(GLUT_CURSOR_LEFT_ARROW);*/
  }
}

void CAM_move(Camera *cam)
{
  glTranslatef(-(cam->camX),-(cam->camY),-(cam->camZ));
}
