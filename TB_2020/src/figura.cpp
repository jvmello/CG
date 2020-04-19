//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas em botões para cores
*/

#include "figura.h"
#include "gl_canvas2d.h"

Figura::Figura(int x, int y, float r_, float g_, float b_, int t, int tam)
{
    R = r_;
    G = g_;
    B = b_;

    px = x;
    py = y;

    tamanho = tam;

    ativada = 0;
    tipo = t;
    preenchida = 1;

    if(tipo == 1) //linha
    {
        p[0] = new Ponto(x - tamanho, y);
        p[1] = new Ponto(x + tamanho, y);

        pontos = 2;
    }
    if(tipo == 2) //circulo
    {
        //p[0] = new Ponto(x - tamanho, y);
        //p[1] = new Ponto(x, y + tamanho);
        //p[2] = new Ponto(x + tamanho, y - 10);
    }
    if(tipo == 3) //quadrado
    {
        p[0] = new Ponto(x - tamanho, y - tamanho);
        p[1] = new Ponto(x - tamanho, y + tamanho);
        p[2] = new Ponto(x + tamanho, y + tamanho);
        p[3] = new Ponto(x + tamanho, y - tamanho);

        pontos = 4;
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

void Figura::preenche()
{
    color(0, 0, 0);
    if(tipo == 2)
    {
        for(int x = px; x < px+tamanho*3; x++)
        {
            for(int y = py; y < py+tamanho*3; y++)   
            {
                if(colisao(x, y)) point(x, y);
            }
        }
    }
    if(tipo == 3)
    {
        for(int x = 0; x < 1200; x++)
        {
            for(int y = 0; y < 800; y++)   
            {
                if(colisao(x, y)) point(x, y);
            }
        }
        line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
        line(p[1]->x, p[1]->y, p[2]->x, p[2]->y);
        line(p[2]->x, p[2]->y, p[3]->x, p[3]->y);
        line(p[3]->x, p[3]->y, p[0]->x, p[0]->y);
    }
}

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
        xnew = p->x * c + p->y * s;
        ynew = -p->x * s + p->y * c;
    }    

    p->x = xnew + px;
    p->y = ynew + py;

    return p;
}

void Figura::rotaciona_anti_horario()
{
    for(int i = 0; i < pontos; i++)
    {
        p[i] = rotaciona_ponto(p[i], px, py, 30, 0);
    }
}

void Figura::rotaciona_horario()
{
    for(int i = 0; i < pontos; i++)
    {
        p[i] = rotaciona_ponto(p[i], px, py, 30, 1);
    }
}

void Figura::desenha()
{
    color(R, G, B);
    if(tipo == 1) //linha
    {
        line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
        if(ativada)
        {
            color(0, 0, 0);
            for(int i = 0; i < 2; i++)
            {
                circleFill(p[i]->x, p[i]->y, 2, 30);
            }
        }
    }
    if(tipo == 2)
    {
        circle(px, py, tamanho, 40);

        if(ativada)
        {
            color(0, 0, 0);
            circleFill(px, py, 2, 30);
        }
        if(preenchida)
        {
            //circleFill(px, py, tamanho, 40);
            preenche();
        }
    }
    if(tipo == 3)
    {
        if(ativada)
        {
            color(0, 0, 0);
            for(int i = 0; i < 4; i++)
            {
                circleFill(p[i]->x, p[i]->y, 2, 30);
            }
        }

        if(preenchida)
        {
            //color(Rp, Gp, Bp);
            //rectFill(p[0]->x, p[1]->y, p[2]->x, p[3]->y);
            preenche();
        }
        else{
            line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
            line(p[1]->x, p[1]->y, p[2]->x, p[2]->y);
            line(p[2]->x, p[2]->y, p[3]->x, p[3]->y);
            line(p[3]->x, p[3]->y, p[0]->x, p[0]->y);
        }
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

    for(int i = 0; i < l; i++)
    {
        if(p[i]->y < m && p[i]->y != 0) m = p[i]->y;
    }

    return m;
}

int Figura::colisao(int mX, int mY)
{
    if(tipo == 1)
    {
        if(mX >= menorX(pontos) && mX <= maiorX(pontos) && mY >= menorY(pontos) && mY <= maiorY(pontos)){
            return 1;
        }
    }
    if(tipo == 2)
    {
        float dx = abs(mX-px);
        float dy = abs(mY-py);
        float R = tamanho;

        if(pow(dx, 2) + pow(dy, 2) <= pow(R, 2)) return 1;
    }
    if(tipo == 3)
    {

    }

    return 0;
}
