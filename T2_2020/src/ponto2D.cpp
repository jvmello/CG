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

void Ponto2D::rotaciona(int px, int py, double angulo)
{
    double ang_rotacao = (double) angulo / 180.0 * (PI_2/2);
    //printf("\n%f\n", ang_rotacao);
    double s = sin(ang_rotacao);
    double c = cos(ang_rotacao);

    x -= px;
    y -= py;

    double xnew, ynew;
    xnew = x * c - y * s;
    ynew = x * s + y * c;

   	x = round(xnew + px);
    y = round(ynew + py);
}
