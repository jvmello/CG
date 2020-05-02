//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe que define uma figura a ser mostrada na tela
*/

#ifndef __FIGURA__H__
#define __FIGURA__H__

#include <math.h>
#include "ponto.h"

class Figura
{
   public:
        Ponto *p[4]; //uma figura pode ter até quadro pontos
        
        float R, G, B;
        float Rp, Gp, Bp;
        
        int tamanho;
        int px, py; //posições iniciais(usa-se para rotação)
        int ativada;
        int preenchida;
        int tipo, pontos; //tipo define se é linha, quadrado... pontos definem o número dessa figura
        int rotacao;
        
        Figura(int, int, float, float, float, int, int, int);
        
        int maiorX(int);
        int maiorY(int);
        int menorX(int);
        int menorY(int);

        Ponto* rotaciona_ponto(Ponto*, int, int, int, int);
        void rotaciona_horario(int);
        void rotaciona_anti_horario(int);

        float  getR(void);
        float  getG(void);
        float  getB(void);

        void   preenche();
        void   desenha();
        int    colisao(int, int);
};

#endif