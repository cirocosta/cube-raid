#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>


struct termios KEYBOARD_initial_settings,
			   KEYBOARD_new_settings;

/**
 * Inicializa configuracao especial para o teclado de modo que possamos,
 * sem utilizar de multithreading, obter aproximadamente em cada
 * timestep o estado do teclado, isto é, saber se houve ou nao um
 * determinado input naquele momento.
 */
void KEYBOARD_init();

/**
 * Verifica efetivamente o input no instante.
 * @return o keycode da tecla
 */
int KEYBOARD_check_input();

/**
 * Finaliza o estado que haviamos colocado com o init. Volta ao estado
 * original de input do teclado para o terminal.
 */
void KEYBOARD_close();

#endif
