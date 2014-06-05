#include "mouse.h"

Mouse MOUSE_create()
{
  Mouse *mouse = malloc(sizeof(*mouse));

  if (mouse == NULL) {
    exit(EXIT_FAILURE);
  }

  mouse->posX = 0;
  mouse->posY = 0;

  return *mouse;
}

void MOUSE_destroy(Mouse *mouse)
{
  free(mouse);
}
