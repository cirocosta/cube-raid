/**
 * Funcoes utilitarias para desenhar com OpenGL: desenho de plano,
 * cubos e posicionamento/drawing de luz de spot.
 */

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
 /**
  * Keys 'especiais' do teclado para a movimentacao
  */
  typedef enum
  {
    KB_A = 97,
    KB_W = 119,
    KB_D = 100,
    KB_S = 115
  } KBKey;

  /**
   * Tipos de planos que podem ser criados
   */
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

  /**
   * Estrutura do tipo LIGH que representa uma luz do tipo spotlight
   */
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
  } Light;

  /**
   * Metodos dos LIGHT
   */

  void LIGHT_init(Light *light, int lt);
  void LIGHT_set(Light *light, int lt);
  void LIGHT_draw(Light *light);

#endif
