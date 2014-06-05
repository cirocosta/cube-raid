#ifndef MOUSE_H
  #define MOUSE_H
  #include <stdlib.h>

  typedef struct Mouse
  {
    int posX;
    int posY;
  } Mouse;

  Mouse MOUSE_create();
  void MOUSE_destroy(Mouse *mouse);

#endif
