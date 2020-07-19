//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe que define uma figura a ser mostrada na tela
*/

#ifndef __FIGURA2D__H__
#define __FIGURA2D__H__

#include <math.h>
#include "ponto2D.h"

class Figura2D
{
   public:
        Ponto2D *p[4]; //uma figura pode ter até quadro pontos

        float R, G, B;
        float Rp, Gp, Bp;

        int tamanho;
        int px, py; //posições iniciais(usa-se para rotação)
        int ativada;
        int preenchida;
        int tipo, pontos; //tipo define se é linha, quadrado... pontos definem o número dessa figura
        int rotacao;

        Figura2D(int, int);

        Ponto2D* rotaciona_ponto(Ponto2D*, int, int, int, int);
        void rotaciona_horario(float);
        void rotaciona_anti_horario(float);

        void   desenha();
};

#endif
