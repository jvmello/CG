//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas em botões usados na tela principal
*/
#include "ponto.h"

class Botao
{
   public:
        char*  texto;
        Ponto *p1, *p2;
        int ativado;
        Botao(int, int, int, int, char*);
        int    getx1(void);
        int    getx2(void);
        int    gety1(void);
        int    gety2(void);
        void   desenha();
        int    colisao(int, int);
};