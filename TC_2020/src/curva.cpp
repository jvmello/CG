//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma figura
*/

#include "curva.h"

Curva::Curva(vector<Ponto*> p)
{
    ativada = 0;
    for (int i=0; i<p.size(); i++){
        pontos.push_back(p[i]);
    }
    x = p[0]->x;
    y = p[0]->y;

    espessura = 2;
}

void Curva::desenha_grafo()
{
    color(0.5, 0.5, 0.5);
    for(int i = 0; i < 3; i++)
    {
        line(pontos[i]->x, pontos[i]->y, pontos[i+1]->x, pontos[i+1]->y);
    }
}

void Curva::desenha_reta_r(float t)
{
    color(0, 0, 1);

    int q1x, q1y, q2x, q2y, q3x, q3y;
    int r1x, r1y, r2x, r2y;

    q1x = round((1-t) * pontos[0]->x + t * pontos[1]->x);
    q1y = round((1-t) * pontos[0]->y + t * pontos[1]->y);
    q2x = round((1-t) * pontos[1]->x + t * pontos[2]->x);
    q2y = round((1-t) * pontos[1]->y + t * pontos[2]->y);
    q3x = round((1-t) * pontos[2]->x + t * pontos[3]->x);
    q3y = round((1-t) * pontos[2]->y + t * pontos[3]->y);

    r1x = (1-t)*q1x + t*q2x;
    r1y = (1-t)*q1y + t*q2y;

    r2x = (1-t)*q2x + t*q3x;
    r2y = (1-t)*q2y + t*q3y;

    line(r1x, r1y, r2x, r2y);

    circleFill(r1x, r1y, espessura, 100);
    circleFill(r2x, r2y, espessura, 100);
}

void Curva::desenha_reta_q(float t)
{
    color(0, 1, 0);

    int q1x, q1y, q2x, q2y, q3x, q3y;

    q1x = round((1-t) * pontos[0]->x + t * pontos[1]->x);
    q1y = round((1-t) * pontos[0]->y + t * pontos[1]->y);
    q2x = round((1-t) * pontos[1]->x + t * pontos[2]->x);
    q2y = round((1-t) * pontos[1]->y + t * pontos[2]->y);
    q3x = round((1-t) * pontos[2]->x + t * pontos[3]->x);
    q3y = round((1-t) * pontos[2]->y + t * pontos[3]->y);

    line(q1x, q1y, q2x, q2y);
    line(q2x, q2y, q3x, q3y);

    circleFill(q1x, q1y, espessura, 100);
    circleFill(q2x, q2y, espessura, 100);
    circleFill(q3x, q3y, espessura, 100);
}

void Curva::desenha_fecho()
{
    color(0.3, 0.3, 0.3);
    rect(menorX(), menorY(), maiorX(), maiorY());
}

void Curva::desenha_func(float t)
{
    int x_ = round(pow(1-t, 3) * pontos[0]->x + (3*t * pow((1-t), 2)) * pontos[1]->x + (3 * pow(t, 2) * (1-t)) * pontos[2]->x + pow(t, 3) * pontos[3]->x);
    int y_ = round(pow(1-t, 3) * pontos[0]->y + (3*t * pow((1-t), 2)) * pontos[1]->y + (3 * pow(t, 2) * (1-t)) * pontos[2]->y + pow(t, 3) * pontos[3]->y);
    circleFill(x_, y_, 3, 100);
}

void Curva::desenha_blending_functions()
{
    color(0, 0, 0);

    for(float t = 0; t <= 1; t += 0.001)
    {
        int x_ = round(pow(1-t, 3));
        int y_ = round(pow(1-t, 3));
        circleFill(100*x_, 100*y_, espessura, 100);
    }

    for(float t = 0; t <= 1; t += 0.001)
    {
        int x_ = round((3*t * pow((1-t), 2)));
        int y_ = round((3*t * pow((1-t), 2)));
        circleFill(100*x_, 100*y_, espessura, 100);
    }

    for(float t = 0; t <= 1; t += 0.001)
    {
        int x_ = round((3 * pow(t, 2) * (1-t)));
        int y_ = round((3 * pow(t, 2) * (1-t)));
        circleFill(100*x_, 100*y_, espessura, 100);
    }

    for(float t = 0; t <= 1; t += 0.001)
    {
        int x_ = round(pow(t, 3));
        int y_ = round(pow(t, 3));
        circleFill(100*x_, 100*y_, espessura, 100);
    }
}

int Curva::menorX()
{
    int menor = 10000;

    for(int i = 0; i < pontos.size(); i++)
    {
        if(pontos[i]->x < menor) menor = pontos[i]->x;
    }

    return menor;
}

int Curva::menorY()
{
    int menor = 10000;

    for(int i = 0; i < pontos.size(); i++)
    {
        if(pontos[i]->y < menor) menor = pontos[i]->y;
    }

    return menor;
}

int Curva::maiorX()
{
    int maior = -1;

    for(int i = 0; i < pontos.size(); i++)
    {
        if(pontos[i]->x > maior) maior = pontos[i]->x;
    }

    return maior;
}

int Curva::maiorY()
{
    int maior = -1;

    for(int i = 0; i < pontos.size(); i++)
    {
        if(pontos[i]->y > maior) maior = pontos[i]->y;
    }

    return maior;
}

void Curva::desenha()
{
    color(1, 0, 0);
    for(float t = 0; t <= 1; t += 0.001)
    {
        int x_ = round(pow(1-t, 3) * pontos[0]->x + (3*t * pow((1-t), 2)) * pontos[1]->x + (3 * pow(t, 2) * (1-t)) * pontos[2]->x + pow(t, 3) * pontos[3]->x);
        int y_ = round(pow(1-t, 3) * pontos[0]->y + (3*t * pow((1-t), 2)) * pontos[1]->y + (3 * pow(t, 2) * (1-t)) * pontos[2]->y + pow(t, 3) * pontos[3]->y);
        circleFill(x_, y_, espessura, 100);
    }
}
