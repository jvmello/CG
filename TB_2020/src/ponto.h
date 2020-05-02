//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma figura
*/

#ifndef PONTO_H
#define PONTO_H

class Ponto
{
   public:
        int x, y;
        Ponto(int, int);
        int    getx(void);
        int    gety(void);
};

#endif