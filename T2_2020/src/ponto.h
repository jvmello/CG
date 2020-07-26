//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma figura
*/

#include "gl_canvas2d.h"
#include <math.h>

#ifndef PONTO_H
#define PONTO_H

class Ponto
{
   public:
        float x, y, z;
        
        Ponto(float, float, float);
        Ponto();
        
        int    get_x(void);
        int    get_y(void);
        int    get_z(void);
};

#endif