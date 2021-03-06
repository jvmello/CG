//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas na curva
*/

#include "gl_canvas2d.h"
#include "ponto.h"
using namespace std;
#include <vector>
#include <math.h>
#include <unistd.h>

#ifndef CURVA_H
#define CURVA_H

class Curva
{
   public:
        int x, y;
        int ativada, espessura;
        vector<Ponto*> pontos; //vetor de pontos
        Curva(vector<Ponto*>);
        
        //desenha opções de desenho adicionais
        void   desenha_grafo();
        void   desenha_fecho();
        void   desenha_reta_r(float);
        void   desenha_reta_q(float);
        void   desenha_func(float);

        //para fecho
        int menorX();
        int menorY();
        int maiorX();
        int maiorY();

        void   desenha();
};

#endif