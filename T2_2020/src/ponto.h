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
        int ativado;
        float ang;
        Ponto(int, int, int, int);
        Ponto();
        void   rotacionaX();
        void   rotacionaY();
        void   rotacionaZ();
        int    get_x(void);
        int    get_y(void);
        int    get_z(void);
        void   desenha();
        void   recalcula();
};

#endif