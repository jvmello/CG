//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma figura
*/

#include "gl_canvas2d.h"

#ifndef PONTO_H
#define PONTO_H

class Ponto
{
   public:
        int x, y;
        int ativado;
        float R, G, B;
        Ponto(int, int);
        Ponto(int, int, float, float, float);
        int    getx(void);
        int    gety(void);
        void   desenha();
        int    colisao(int, int);
};

#endif