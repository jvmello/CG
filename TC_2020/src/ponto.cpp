//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma figura
*/

#include "ponto.h"

Ponto::Ponto(int x_, int y_)
{
    x = x_;
    y = y_;
    ativado = 0;
}

Ponto::Ponto(int x_, int y_, float R_, float G_, float B_)
{
    x = x_;
    y = y_;
    R = R_;
    G = G_;
    B = B_;
    ativado = 0;
}

int Ponto::getx(void)
{
    return x;
}

int Ponto::gety(void)
{
    return y;
}

int Ponto::colisao(int mX, int mY)
{
    float dx = abs(mX-x);
    float dy = abs(mY-y);
    float R = 5;

    if(pow(dx, 2) + pow(dy, 2) <= pow(R, 2)) return 1;

    return 0;
}

void Ponto::desenha()
{
	if(ativado)
	{
		color(0, 0, 0);
		circle(x, y, 6, 20);
	}
	color(R, G, B);
	circleFill(x, y, 5, 20);
}