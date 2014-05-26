#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>


struct termios KEYBOARD_initial_settings,
			   KEYBOARD_new_settings;

void KEYBOARD_init();
int KEYBOARD_check_input();
void KEYBOARD_close();

#endif
