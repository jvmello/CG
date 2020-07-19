//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma curva
*/

#include "ponto2D.h"

Ponto2D::Ponto2D(int x_, int y_)
{
    x = x_;
    y = y_;
}

Ponto2D::Ponto2D()
{
    x = 0;
    y = 0;
}

int Ponto2D::getx(void)
{
    return x;
}

int Ponto2D::gety(void)
{
    return y;
}

void Ponto2D::desenha()
{
    color(0, 0, 0);
    circleFill(x, y, 5, 20);
}
