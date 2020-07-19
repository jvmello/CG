//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma figura
*/

#include "gl_canvas2d.h"
#include <math.h>

#ifndef PONTO3D_H
#define PONTO3D_H

class Ponto3D
{
   public:
        int x, y, z, d;
        int ativado;
        float ang;
        Ponto3D(int, int, int, int);
        Ponto3D();
        void   rotacionaX();
        void   rotacionaY();
        void   rotacionaZ();
        int    getx(void);
        int    gety(void);
        void   desenha();
        int    colisao(int, int, int);
        void   recalcula();
};

#endif