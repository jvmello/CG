//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas em botões usados na tela principal
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