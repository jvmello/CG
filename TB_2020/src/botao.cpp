//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas em botões usados na tela principal
*/
#include "botao.h"
#include "gl_canvas2d.h"

Botao::Botao(int x1, int y1, int x2, int y2, char* t)
{

	p1 = new Ponto(x1, y1);
	p2 = new Ponto(x2, y2);
	texto = t;
	ativado = 0;
}

void Botao::desenha()
{
	if(ativado) color(1, 1, 1);
	else color(0.8, 0.8, 0.8);
	rectFill(p1->x, p1->y, p2->x, p2->y);
	color(0, 0, 0);
	rect(p1->x, p1->y, p2->x, p2->y);
	text(p1->x, (int)(p1->y + (p2->y-p1->y)/2), texto);
}

int Botao::colisao(int mX, int mY)
{
	if((mX >= p1->x && mX <= p2->x) && (mY > p1->y && mY < p2->y)) return 1;

	return 0;
}
