//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas em botões usados na tela principal
*/

#include "botao.h"
#include "gl_canvas2d.h"

Botao::Botao(int x1_, int y1_, int x2_, int y2_, char* t)
{
	x1 = x1_;
	y1 = y1_;
	x2 = x2_;
	y2 = y2_;
	texto = t;
	ativado = 0;
}

int Botao::getx1(void)
{
	return x1;
}

int Botao::gety1(void)
{
	return y1;
}

int Botao::getx2(void)
{
	return x2;
}

int Botao::gety2(void)
{
	return y2;
}

void Botao::draw()
{
	if(ativado) color(1, 1, 1);
	else color(0.8, 0.8, 0.8);
	rectFill(x1, y1, x2, y2);
	color(0, 0, 0);
	rect(x1, y1, x2, y2);
	text(x1, (int)(y1 + (y2-y1)/2), texto);
}

int Botao::colisao(int mX, int mY)
{
	if((mX >= x1 && mX <= x2) && (mY > y1 && mY < y2)) return 1;

	return 0;
}
