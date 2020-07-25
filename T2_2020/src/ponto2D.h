//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma figura
*/

#include "gl_canvas2d.h"
#include <math.h>

#ifndef PONTO2D_H
#define PONTO2D_H

class Ponto2D
{
   public:
        int x, y;
        Ponto2D(int, int);
        Ponto2D();
        int    getx(void);
        int    gety(void);
        void   desenha();
        void   rotaciona(int, int, double);
        void   translada(int, int);
};

#endif