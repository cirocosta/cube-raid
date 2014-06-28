#ifndef BUILDER_H
	#define BUILDER_H
	#include "GL/glew.h"
	#include "GL/freeglut.h"

	typedef enum __PLANE_type
	{
	  PLANE_FRONT,
	  PLANE_SIDE,
	  PLANE_TOP
	} PLANE_type;

	void CUBE_build(GLfloat xyz[3], GLfloat position[3], GLfloat angle);
	void PLANE_build(GLfloat xyz[3], GLfloat position[3], PLANE_type tipo);

#endif
