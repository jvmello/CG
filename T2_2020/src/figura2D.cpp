//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas nas figuras
*/

#include "figura2D.h"
#include "gl_canvas2d.h"

//Classe que monta a figura
Figura2D::Figura2D(int x, int y)
{
    px = x;
    py = y;

    tamanho = 50;
    p[0] = new Ponto2D(x - tamanho, y - tamanho);
    p[1] = new Ponto2D(x - tamanho, y + tamanho);
    p[2] = new Ponto2D(x + tamanho, y + tamanho);
    p[3] = new Ponto2D(x + tamanho, y - tamanho);

    pontos = 4;
}

//Aplica a rotação em um PONTO
Ponto2D* Figura2D::rotaciona_ponto(Ponto2D* p, int px, int py, int angulo, int op)
{
    double ang_rotacao = (double) angulo / 180.0 * (PI_2/2);
    //printf("\n%f\n", ang_rotacao);
    float s = sin(ang_rotacao);
    float c = cos(ang_rotacao);

    //printf("\nantes %d %d", p->x, p->y);

    p->x -= px;
    p->y -= py;

    //printf("\ndepois %d %d\n", p->x, p->y);

    //return p;

    float xnew = p->x, ynew = p->y;

    xnew = p->x * c - p->y * s;
    ynew = p->x * s + p->y * c;

    p->x = xnew + px;
    p->y = ynew + py;

    //Sleep(50);

    return p;
}

//Aplicam a rotação anti-horária e horária em todos os pontos da linha/quadrado
void Figura2D::rotaciona_anti_horario(int angulo)
{
    for(int i = 0; i < pontos; i++)
    {
        p[i] = rotaciona_ponto(p[i], px, py, angulo, 0);
    }
    rotacao -= angulo;
}

void Figura2D::rotaciona_horario(int angulo)
{
    for(int i = 0; i < pontos; i++)
    {
        p[i] = rotaciona_ponto(p[i], px, py, angulo, 1);
    }

    rotacao += angulo;
}

void Figura2D::desenha()
{
    line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
    line(p[1]->x, p[1]->y, p[2]->x, p[2]->y);
    line(p[2]->x, p[2]->y, p[3]->x, p[3]->y);
    line(p[3]->x, p[3]->y, p[0]->x, p[0]->y);
}
