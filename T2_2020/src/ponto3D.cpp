//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma curva
*/

#include "ponto3D.h"

Ponto3D::Ponto3D(int x_, int y_, int z_, int d_)
{
    x = x_;
    y = y_;
    z = z_;
    d = d_;

    ativado = 0;
    ang = 0;
}

Ponto3D::Ponto3D()
{
    x = 0;
    y = 0;
    z = 0;

    ativado = 0;
    ang = 0;
}

void Ponto3D::recalcula()
{
    x = round((x*d)/z);
    y = round((y*d)/z);

}

void Ponto3D::rotacionaX()
{
  ang += 0.000000001;

  x = x;
  y = cos(ang)*y - sin(ang)*z;
  z = sin(ang)*y + cos(ang)*z;
}

void Ponto3D::rotacionaY()
{
  ang += 0.000000001;

  x = cos(ang)*x + cos(ang)*z;
  y = y;
  z = -sin(ang)*x + cos(ang)*z;
}

void Ponto3D::rotacionaZ()
{
  ang += 0.000000001;

  x = cos(ang)*x - sin(ang)*y;
  y = sin(ang)*x + cos(ang)*y;
  z = z;
}

int Ponto3D::getx(void)
{
    return x;
}

int Ponto3D::gety(void)
{
    return y;
}

void Ponto3D::desenha()
{
	if(ativado)
	{
		color(0, 0, 0);
		circle(x, y, 6, 20);
	}
	color(0, 0, 0);
	circleFill(x, y, 5, 20);
}
