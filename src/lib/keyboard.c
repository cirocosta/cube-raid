#include "keyboard.h"

struct termios KEYBOARD_initial_settings,
			   KEYBOARD_new_settings;

void KEYBOARD_init()
{
	tcgetattr(0,&KEYBOARD_initial_settings);

	KEYBOARD_new_settings = KEYBOARD_initial_settings;
	KEYBOARD_new_settings.c_lflag &= ~ICANON;
	KEYBOARD_new_settings.c_lflag &= ~ECHO;
	KEYBOARD_new_settings.c_lflag &= ~ISIG;
	KEYBOARD_new_settings.c_cc[VMIN] = 0;
	KEYBOARD_new_settings.c_cc[VTIME] = 0;

	tcsetattr(0, TCSANOW, &KEYBOARD_new_settings);
}

int KEYBOARD_check_input()
{
	return getchar();
}

void KEYBOARD_close()
{
	tcsetattr(0, TCSANOW, &KEYBOARD_initial_settings);
}
