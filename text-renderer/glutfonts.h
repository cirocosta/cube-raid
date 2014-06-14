#ifndef GLUTFONTS_H
	#define GLUTFONTS_H

	#include <stdio.h>
	#include <string.h>
	#include <math.h>

	#ifdef WIN32
		#include <windows.h>
	#endif

	#include <GL/gl.h>
	#include <GL/glut.h>

	typedef enum {
	   MODE_BITMAP,
	   MODE_STROKE
	} mode_type;

	void print_bitmap_string(void* font, char* s);
	void print_stroke_string(void* font, char* s);
	void my_init();
	void my_reshape(int w, int h);
	void my_handle_key(GLubyte key, GLint x, GLint y);
	void draw_stuff();
	void my_display(void);
/*
	void * bitmap_fonts[3] = {
    GLUT_BITMAP_HELVETICA_10,
    GLUT_BITMAP_HELVETICA_12,
    GLUT_BITMAP_HELVETICA_18
	};

	char * bitmap_font_names[3] = {
		"GLUT_BITMAP_HELVETICA_10",
    "GLUT_BITMAP_HELVETICA_12",
    "GLUT_BITMAP_HELVETICA_18"
	};*/

#endif
