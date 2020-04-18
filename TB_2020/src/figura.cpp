//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas em botões para cores
*/

#include "figura.h"
#include "gl_canvas2d.h"

Figura::Figura(int x, int y, float r_, float g_, float b_, int l)
{
    R = r_;
    G = g_;
    B = b_;

    px = x;
    py = y;

    ativada = 0;
    lados = l;
    preenchida = 0;

    if(lados == 2) //linha
    {
        p[0] = new Ponto(x - 50, y);
        p[1] = new Ponto(x + 50, y);
    }
    if(lados == 3) //triângulo
    {
        p[0] = new Ponto(x - 50, y);
        p[1] = new Ponto(x, y + 50);
        p[2] = new Ponto(x + 50, y - 10);
    }
    if(lados == 4)
    {
        p[0] = new Ponto(x - 50, y - 50);
        p[1] = new Ponto(x - 50, y + 50);
        p[2] = new Ponto(x + 50, y + 50);
        p[3] = new Ponto(x + 50, y - 50);
    }
    if(lados == 5)
    {
        /*pX[0] = x - 50;
        pY[0] = y - 50;
        pX[1] = x - 50;
        pY[1] = y + 50;
        pX[2] = x + 50;
        pY[2] = y + 50;
        pX[3] = x + 50;
        pY[3] = y - 50;
        pX[4] = x + 50;
        pY[4] = y - 50;*/
    }
    if(lados == 6)
    {

    }
    if(lados == 7)
    {

    }
    if(lados == 8)
    {

    }
}

float Figura::getR(void)
{
    return R;
}

float Figura::getG(void)
{
    return G;
}

float Figura::getB(void)
{
    return B;
}

/*void Figura::preenche()
{
    color(Rp, Gp, Bp);
    if(lados == 3)
    {
        line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
        line(p[1]->x, p[1]->y, p[2]->x, p[2]->y);
        line(p[2]->x, p[2]->y, p[0]->x, p[0]->y);
    }
    if(lados == 4)
    {
        line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
        line(p[1]->x, p[1]->y, p[2]->x, p[2]->y);
        line(p[2]->x, p[2]->y, p[3]->x, p[3]->y);
        line(p[3]->x, p[3]->y, p[0]->x, p[0]->y);
    }
    if(lados == 5)
    {

    }
    if(lados == 6)
    {

    }
    if(lados == 7)
    {

    }
    if(lados == 8)
    {

    }
}*/

Ponto* rotaciona_ponto(Ponto* p, int px, int py, int angulo, int op)
{
    double ang_rotacao = (double) angulo / 180.0 * (PI_2/2);
    float s = sin(ang_rotacao);
    float c = cos(ang_rotacao);

    p->x -= px;
    p->y -= py;

    float xnew, ynew;

    if(!op) //antihorario
    {
        xnew = p->x * c - p->y * s;
        ynew = p->x * s + p->y * c;    
    }
    else
    {
        xnew = p->x * c - p->y * s;
        ynew = p->x * s + p->y * c;
    }    

    p->x = xnew + px;
    p->y = ynew + py;

    return p;
}

void Figura::rotaciona_anti_horario()
{
    for(int i = 0; i < lados; i++)
    {
        p[i] = rotaciona_ponto(p[i], px, py, 30, 0);
    }
}

void Figura::rotaciona_horario()
{
    for(int i = 0; i < lados; i++)
    {
        p[i] = rotaciona_ponto(p[i], px, py, 30, 1);
    }
}

void Figura::draw()
{
    color(0, 0, 0);
    if(ativada)
    {
        for(int i = 0; i < lados; i++)
        {
            circleFill(p[i]->x, p[i]->y, 2, 30);
        }
    }

    color(R, G, B);
    if(lados == 2) //linha
    {
        line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
    }
    if(lados == 3)
    {
        line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
        line(p[1]->x, p[1]->y, p[2]->x, p[2]->y);
        line(p[2]->x, p[2]->y, p[0]->x, p[0]->y);
    }
    if(lados == 4)
    {
        line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
        line(p[1]->x, p[1]->y, p[2]->x, p[2]->y);
        line(p[2]->x, p[2]->y, p[3]->x, p[3]->y);
        line(p[3]->x, p[3]->y, p[0]->x, p[0]->y);
    }
    if(lados == 5)
    {

    }
    if(lados == 6)
    {

    }
    if(lados == 7)
    {

    }
    if(lados == 8)
    {

    }
}

int Figura::maiorX(int l)
{
    int m = 0;

    for(size_t i = 0; i < l; i++)
    {
        if(p[i]->x > m) m = p[i]->x;
    }

    return m;
}

int Figura::maiorY(int l)
{
    int m = 0;

    for(size_t i = 0; i < l; i++)
    {
        if(p[i]->y > m) m = p[i]->y;
    }

    return m;
}

int Figura::menorX(int l)
{
    int m = 20000;

    for(size_t i = 0; i < l; i++)
    {
        if(p[i]->x < m && p[i]->x != 0) m = p[i]->x;
    }

    return m;
}

int Figura::menorY(int l)
{
    int m = 20000;

    for(size_t i = 0; i < l; i++)
    {
        if(p[i]->y < m && p[i]->y != 0) m = p[i]->y;
    }

    return m;
}

int Figura::colisao(int mX, int mY)
{
    if(mX >= menorX(lados) && mX <= maiorX(lados) && mY >= menorY(lados) && mY <= maiorY(lados)){
        return 1;
    }


    if(lados == 2)
    {

    }
    if(lados == 3)
    {

    }
    if(lados == 4)
    {

    }

    return 0;
}
