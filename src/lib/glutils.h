#ifndef GLUTILS_H
	#define GLUTILS_H
	#include <stdbool.h>
	#include <math.h>
	#include "GL/glew.h"
	#include "GL/freeglut.h"
	#include "position.h"
  #ifndef M_PI
    #define M_PI 3.14159265
  #endif

	typedef enum __PLANE_type
	{
	  PLANE_FRONT,
	  PLANE_SIDE_LEFT,
	  PLANE_SIDE_RIGHT,
	  PLANE_TOP,
	  PLANE_BOTTOM
	} PLANE_type;

	void CUBE_build(GLfloat xyz[3],
	                Position pos,
	                GLfloat angle);

	void PLANE_build(GLfloat xyz[3],
	                 Position pos,
	                 PLANE_type tipo);

	void TEXT_draw(char * message,
	               float size,
	               GLfloat pos[3],
	               GLfloat color[3]);

  typedef struct lightRec {
    float amb[4];
    float diff[4];
    float spec[4];
    float pos[4];
    float spotDir[3];
    float spotExp;
    float spotCutoff;
    float atten[3];

    float trans[3];
    float rot[3];
    float swing[3];
    float arc[3];
    float arcIncr[3];
  } Light;

  void LIGHT_init(Light *light, int lt);
  void LIGHT_set(Light *light, int lt);
  void LIGHT_draw(Light *light);

#endif
