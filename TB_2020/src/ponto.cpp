//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma figura
*/

#include "ponto.h"

Ponto::Ponto(int x_, int y_)
{
    x = x_;
    y = y_;
}

int Ponto::getx(void)
{
    return x;
}

int Ponto::gety(void)
{
    return y;
}