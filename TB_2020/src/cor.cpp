//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas em botões para cores
*/

#include "cor.h"
#include "gl_canvas2d.h"

Cor::Cor(int x1_, int y1_, int x2_, int y2_, float r_, float g_, float b_)
{
	x1 = x1_;
	y1 = y1_;
	x2 = x2_;
	y2 = y2_;
	R = r_;
	G = g_;
	B = b_;
	colide = 0;
}

int Cor::getx1(void)
{
	return x1;
}

int Cor::gety1(void)
{
	return y1;
}

int Cor::getx2(void)
{
	return x2;
}

int Cor::gety2(void)
{
	return y2;
}

float Cor::getR(void)
{
	return R;
}

float Cor::getG(void)
{
	return G;
}

float Cor::getB(void)
{
	return B;
}

void Cor::draw()
{
	color(R, G, B);
	rectFill(x1, y1, x2, y2);
}

int Cor::colisao(int mX, int mY)
{
	if((mX >= x1 && mX <= x2) && (mY > y1 && mY < y2)) return 1;

	return 0;
}
