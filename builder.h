#ifndef BUILDER_H
	#define BUILDER_H
	#include "GL/glew.h"
	#include "GL/freeglut.h"

	/* TODO[ciro]
			-	 rever parametros para contrucao de cubo/build
	*/

	void CUBE_build(GLfloat w, GLfloat h, GLfloat d, float angle);
	void PLANE_build(float w, float h);

#endif
