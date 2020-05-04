//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma figura
*/

#include "curva.h"

Curva::Curva(vector<Ponto*> p, float R_, float G_, float B_)
{
    ativada = 0;
    R = R_;
    G = G_;
    B = B_;
    for (int i=0; i<p.size(); i++){
        pontos.push_back(p[i]);
    }
    x = p[0]->x;
    y = p[0]->y;

    espessura = 2;
}

int Curva::colisao(int mX, int mY)
{
    return 0;
}

void Curva::desenha_grafo()
{
    for(int i = 0; i < 3; i++)
    {
        line(pontos[i]->x, pontos[i]->y, pontos[i+1]->x, pontos[i+1]->y);
    }
}

void Curva::desenha_retas(float t)
{
    int p1x, p1y, p2x, p2y, p3x, p3y;
    int pp1x, pp1y, pp2x, pp2y, pp3x, pp3y;

    p1x = round((1-t) * pontos[0]->x + t * pontos[1]->x);
    p1y = round((1-t) * pontos[0]->y + t * pontos[1]->y);
    p2x = round((1-t) * pontos[1]->x + t * pontos[2]->x);
    p2y = round((1-t) * pontos[1]->y + t * pontos[2]->y);
    p3x = round((1-t) * pontos[2]->x + t * pontos[3]->x);
    p3y = round((1-t) * pontos[2]->y + t * pontos[3]->y);

    pp1x = (1-t)*p1x + t*p2x;
    pp1y = (1-t)*p1y + t*p2y;

    pp2x = (1-t)*p2x + t*p3x;
    pp2y = (1-t)*p2y + t*p3y;

    line(p1x, p1y, p2x, p2y);
    line(p2x, p2y, p3x, p3y);

    int x_ = round(pow(1-t, 3) * pontos[0]->x + (3*t * pow((1-t), 2)) * pontos[1]->x + (3 * pow(t, 2) * (1-t)) * pontos[2]->x + pow(t, 3) * pontos[3]->x);
    int y_ = round(pow(1-t, 3) * pontos[0]->y + (3*t * pow((1-t), 2)) * pontos[1]->y + (3 * pow(t, 2) * (1-t)) * pontos[2]->y + pow(t, 3) * pontos[3]->y);

    color(1, 0, 1);
    line(pp1x, pp1y, pp2x, pp2y);
    //line(pp2x, pp2y, pp3x, pp3y);

    circleFill(p1x, p1y, 3, 100);
    circleFill(p2x, p2y, 3, 100);
    circleFill(p3x, p3y, 3, 100);
    circleFill(pp1x, pp1y, 3, 100);
    circleFill(pp2x, pp2y, 3, 100);
}

void Curva::desenha_fecho()
{
    for(int i = 0; i < 3; i++)
    {
        line(pontos[i]->x, pontos[i]->y, pontos[i+1]->x, pontos[i+1]->y);
    }

    line(pontos[3]->x, pontos[3]->y, pontos[0]->x, pontos[0]->y);
}

void Curva::desenha_func(float t)
{
    int x_ = round(pow(1-t, 3) * pontos[0]->x + (3*t * pow((1-t), 2)) * pontos[1]->x + (3 * pow(t, 2) * (1-t)) * pontos[2]->x + pow(t, 3) * pontos[3]->x);
    int y_ = round(pow(1-t, 3) * pontos[0]->y + (3*t * pow((1-t), 2)) * pontos[1]->y + (3 * pow(t, 2) * (1-t)) * pontos[2]->y + pow(t, 3) * pontos[3]->y);
    circleFill(x_, y_, 3, 100);
        //point(x_, y_);
}

void Curva::desenha()
{
    for(float t = 0; t <= 1; t += 0.001)
    {
        int x_ = round(pow(1-t, 3) * pontos[0]->x + (3*t * pow((1-t), 2)) * pontos[1]->x + (3 * pow(t, 2) * (1-t)) * pontos[2]->x + pow(t, 3) * pontos[3]->x);
        int y_ = round(pow(1-t, 3) * pontos[0]->y + (3*t * pow((1-t), 2)) * pontos[1]->y + (3 * pow(t, 2) * (1-t)) * pontos[2]->y + pow(t, 3) * pontos[3]->y);
        circleFill(x_, y_, espessura, 100);
        //point(x_, y_);
    }

    color(0.2, 0.8, 0.3);
    desenha_fecho();
    color(1, 0, 0);
    desenha_grafo();
    //printf("\nAconteceu: %d %d", x, y);
}
