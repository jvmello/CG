//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas em botões usados na tela principal
*/

#include "painel.h"
#include "gl_canvas2d.h"

Painel::Painel(int x1_, int y1_, int x2_, int y2_)
{
	x1 = x1_;
	y1 = y1_;
	x2 = x2_;
	y2 = y2_;
}

int Painel::getx1(void)
{
	return x1;
}

int Painel::gety1(void)
{
	return y1;
}

int Painel::getx2(void)
{
	return x2;
}

int Painel::gety2(void)
{
	return y2;
}

void Painel::draw()
{
	color(0, 0, 0);
	rect(x1, y1, x2, y2);
	color(0.8, 0.8, 0.8);
	rectFill(x1+1, y1+1, x2-1, y2-1);
	
}

int Painel::colisao(int mX, int mY)
{
	if((mX >= x1 && mX <= x2) && (mY > y1 && mY < y2)) return 1;

	return 0;
}
