#ifndef TEXT_DRAWER_H
  #define TEXT_DRAWER_H

  #include <stdio.h>
  #include <string.h>
  #include "GL/glew.h"
  #include "GL/freeglut.h"

  typedef struct __text
  {
    void * font;
    char * text;
    GLfloat position[3];
    GLfloat color[4];
    int size;

  } TDRAWER_Text;

  TDRAWER_Text * TDRAWER_new(char * initialText);
  void TDRAWER_destroy(TDRAWER_Text * text);
  void TDRAWER_draw(TDRAWER_Text * text);

#endif
