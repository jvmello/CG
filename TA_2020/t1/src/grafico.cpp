/**
    Trabalho 1 - Computação Gráfica
    João Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#include "grafico.h"

//Implementação dos métodos da classe gráfico

//instanciadores
Grafico::Grafico()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;

    points = 0;
    grid = 0;
}

Grafico::Grafico(int x, int y, int xx, int yy, const char* t)
{
    x1 = x;
    y1 = y;
    x2 = xx;
    y2 = yy;
    titulo = t;

    points = 0;
    grid = 0;
}

//desenha um gráfico na tela
void Grafico::draw(Cor* c1, Cor* c2)
{
    float Ymid = (y2 - y1) / 2;
    float dist = 0;
    float gridX = (x2-x1)/8;
    float gridY = (y2-y1)/8;
    float x1_, y1_, x2_, y2_, val;

    //fundo
    color(0.95, 0.95, 0.95);
    rectFill(x1, y1, x2, y2);

    color(0, 0, 0);

    //linhas, contorno e título
    rect(x1, y1, x2, y2);
    rectFill(x1, y1+Ymid-1, x2, y1+Ymid+1);
    text(1.1*x1, 0.98 * y2, titulo);

    if(vec.size() != 0)
    {
        //seta distância no eixo x
        dist = round((x2 - x1) / (vec.size()-1));

        for(int i = 0; i < vec.size() - 1; i++)
        {
            //Calcula pontos a cada valor

            x1_ = x1 + ((i)*dist);
            val = vec[i] / 128;

            y1_ = y1 + Ymid + (val*(Ymid));
            x2_= x1 + ((i+1)*dist);
            val = vec[i+1] / 128;
            y2_ = y1 + Ymid + (val*(Ymid));

            //aplica pontos
            if(points == 1)
            {
                color(c2->R, c2->G, c2->B);
                circleFill(x1_, y1_, 5, 40);
                if(i + 1 == vec.size() - 1) circleFill(x2_, y2_, 5, 40);
            }
            else circleFill(0, 0, 5, 40);

            color(0, 0, 0);

            if(grid == 1)
            {
                //desenha linhas de acordo com uma distância(default = 8 linhas horizontais/verticais)
                for(int i = x1; i < x2; i += gridX)
                {
                    line(i, y1, i, y2);
                }

                for(int i = y1; i < y2; i += gridY)
                {
                    line(x1, i, x2, i);
                }
            }

            color(c1->R, c1->G, c1->B);
            for(float t = 0; t <= 1; t+=0.0001)
            {
                //linha paramétrica
                float x = ((1-t) * x1_) + (t * x2_);
                float y = ((1-t) * y1_) + (t * y2_);
                point(x, y);
            }
            color(0, 0, 0);
        }
    }
}

void Grafico::setVec(vector<float> v)
{
    vec.resize(v.size());
    for(int i = 0; i < v.size(); i++) vec[i] = v[i];
}

void Grafico::setPoints()
{
    if(points == 0) points = 1;
    else if(points == 1) points = 0;
}

void Grafico::setGrid()
{
    if(grid == 0) grid = 1;
    else if(grid == 1) grid = 0;
}

//redesenha o objeto de acordo com o tamanho da janela
void Grafico::newsize(int x1_, int y1_, int x2_, int y2_)
{
    x1 = x1_;
    y1 = y1_;
    x2 = x2_;
    y2 = y2_;
}
