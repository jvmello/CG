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
}

int Curva::colisao(int mX, int mY)
{
    return 0;
}

void Curva::desenha_fecho()
{
    for(int i = 0; i < 3; i++)
    {
        line(pontos[i]->x, pontos[i]->y, pontos[i+1]->x, pontos[i+1]->y);
    }
}

void Curva::desenha()
{
    desenha_fecho();
    for(float t = 0; t <= 1; t += 0.0001)
    {
        int x_ = round(pow(1-t, 3) * pontos[0]->x + (3*t * pow((1-t), 2)) * pontos[1]->x + (3 * pow(t, 2) * (1-t)) * pontos[2]->x + pow(t, 3) * pontos[3]->x);
        int y_ = round(pow(1-t, 3) * pontos[0]->y + (3*t * pow((1-t), 2)) * pontos[1]->y + (3 * pow(t, 2) * (1-t)) * pontos[2]->y + pow(t, 3) * pontos[3]->y);
        circleFill(x_, y_, 3, 100);
        //point(x_, y_);
    }
    //printf("\nAconteceu: %d %d", x, y);
}
