#ifndef CAMERA_H
	#include <stdbool.h>
	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>
	#ifndef M_PI
		#define M_PI 3.1415926535
	#endif

	#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)
	#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / M_PI)

	typedef struct Camera
	{
		float camX;
		float camY;
		float camZ;
		float camYaw;
		float camPitch;
	} Camera;

	Camera CAM_create();
	void CAM_destroy(Camera *cam);
	/**
	 * Faz com que a camera fique sempre :
	 * 	- entre [-90, 90] graus de inclinacao.
	 * 	- com os graus de guinada em [0, 360 graus]
	 */
	void CAM_lockCamera(Camera *cam);
	void CAM_moveCamera(Camera *cam, float dist, float dir);
	void CAM_moveCameraUp(Camera *cam, float dist, float dir);
	/**
	 * [CAM_Control description]
	 * @param moveVel   [description]
	 * @param mouseVel  [description]
	 * @param mouseIn   [description]
	 * @param cam 			camera element
	 * @param positions array of ints: window Width, window Height,
	 *                  mouseX, mouseY
	 */
	void CAM_Control(Camera *cam, float moveVel, float mouseVel,
	                 bool mouseIn, int positions[]);
#endif
