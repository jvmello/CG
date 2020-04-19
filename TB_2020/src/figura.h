//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    
*/

#ifndef __FIGURA__H__
#define __FIGURA__H__

#include <math.h>
#include "ponto.h"

class Figura
{
   public:
        Ponto *p[8];
        float R, G, B;
        float Rp, Gp, Bp;
        int tamanho;
        int px, py;
        int ativada;
        int preenchida;
        int tipo, pontos;
        int rotacao;
        Figura(int, int, float, float, float, int, int);
        int maiorX(int);
        int maiorY(int);
        int menorX(int);
        int menorY(int);
        void rotaciona_horario();
        void rotaciona_anti_horario();
        float  getR(void);
        float  getG(void);
        float  getB(void);
        void preenche();
        void   desenha();
        int    colisao(int, int);
};

#endif