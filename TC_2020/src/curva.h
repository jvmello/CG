//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma figura
*/

#include "gl_canvas2d.h"
#include "ponto.h"
using namespace std;
#include <vector>

#ifndef CURVA_H
#define CURVA_H

class Curva
{
   public:
        int x, y;
        int ativada;
        float R, G, B;
        vector<Ponto*> pontos;
        Curva(vector<Ponto*>, float, float, float);
        void   desenha_fecho();
        void   desenha();
        int    colisao(int, int);
};

#endif