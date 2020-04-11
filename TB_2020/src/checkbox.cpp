//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas em checkboxes usados na tela principal
*/

#include "checkbox.h"
#include "gl_canvas2d.h"

Checkbox::Checkbox(int x1_, int y1_, int x2_, int y2_)
{
	x1 = x1_;
	y1 = y1_;
	x2 = x2_;
	y2 = y2_;
	ativado = 0;
}

int Checkbox::getx1(void)
{
	return x1;
}

int Checkbox::gety1(void)
{
	return y1;
}

int Checkbox::getx2(void)
{
	return x2;
}

int Checkbox::gety2(void)
{
	return y2;
}

void Checkbox::draw()
{
	color(0, 0, 0);
	if(ativado)
	{
		rectFill(x1+1, y1+2, x2-2, y2-1);
	}
	rect(x1, y1, x2, y2);
}

int Checkbox::colisao(int mX, int mY)
{
	if((mX >= x1 && mX <= x2) && (mY > y1 && mY < y2)) return 1;

	return 0;
}
