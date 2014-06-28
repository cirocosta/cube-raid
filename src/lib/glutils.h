#ifndef GLUTILS_H
	#define GLUTILS_H
	#include "GL/glew.h"
	#include "GL/freeglut.h"
	#include <stdbool.h>

	typedef enum __PLANE_type
	{
	  PLANE_FRONT,
	  PLANE_SIDE_LEFT,
	  PLANE_SIDE_RIGHT,
	  PLANE_TOP,
	  PLANE_BOTTOM
	} PLANE_type;

	void CUBE_build(GLfloat xyz[3], GLfloat position[3], GLfloat angle);
	void PLANE_build(GLfloat xyz[3], GLfloat position[3], PLANE_type tipo);

#endif
