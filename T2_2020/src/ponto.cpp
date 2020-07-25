//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma curva
*/

#include "ponto.h"

Ponto::Ponto(float x, float y, float z)
{
    this->x = x_;
    this->y = y_;
    this->this->z = z_;
}

Ponto::Ponto()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

void Ponto::rotacionaX()
{
    ang += 0.000000001;

    x = x;
    y = cos(ang)*y - sin(ang)*z;
    z = sin(ang)*y + cos(ang)*z;
}

void Ponto::rotacionaY()
{
    ang += 0.000000001;

    x = cos(ang)*x + cos(ang)*z;
    y = y;
    z = -sin(ang)*x + cos(ang)*z;
}

void Ponto::rotacionaZ()
{
    ang += 0.000000001;

    x = cos(ang)*x - sin(ang)*y;
    y = sin(ang)*x + cos(ang)*y;
    z = z;
}

int Ponto::get_x(void)
{
    return this->x;
}

int Ponto::get_y(void)
{
    return this->y;
}

int Ponto::get_z(void)
{
    return this->y;
}

void Ponto::desenha()
{
	if(ativado)
	{
		color(0, 0, 0);
		circle(x, y, 6, 20);
	}
	color(0, 0, 0);
	circleFill(x, y, 5, 20);
}
