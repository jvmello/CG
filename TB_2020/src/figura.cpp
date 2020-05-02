//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas nas figuras
*/

#include "figura.h"
#include "gl_canvas2d.h"

//Classe que monta a figura
Figura::Figura(int x, int y, float r_, float g_, float b_, int t, int tam, int r)
{
    R = r_;
    G = g_;
    B = b_;

    px = x;
    py = y;

    tamanho = tam;

    //tudo pré-definido
    ativada = 0;
    tipo = t;
    preenchida = 0;
    rotacao = 0;

    if(tipo == 1) //linha
    {
        p[0] = new Ponto(x - tamanho, y);
        p[1] = new Ponto(x + tamanho, y);

        pontos = 2;

        rotaciona_horario(r);
    }

    if(tipo == 3) //quadrado
    {
        p[0] = new Ponto(x - tamanho, y - tamanho);
        p[1] = new Ponto(x - tamanho, y + tamanho);
        p[2] = new Ponto(x + tamanho, y + tamanho);
        p[3] = new Ponto(x + tamanho, y - tamanho);

        pontos = 4;

        rotaciona_horario(r);
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

//Faz o preenchimento
void Figura::preenche()
{
    color(Rp, Gp, Bp); //cores de preenchimento
    if(tipo == 2) //Círculo
    {
        for(int x = px-tamanho; x < px+tamanho; x++)
        {
            for(int y = py-tamanho; y < py+tamanho; y++)
            {
                if(colisao(x, y)) point(x, y);
            }
        }
    }
    if(tipo == 3) //Quadrado
    {
        for(int x = px-tamanho; x < px+tamanho; x++)
        {
            for(int y = py-tamanho; y < py+tamanho; y++)
            {
                if(colisao(x, y)) point(x, y);
            }
        }
    }
}

//Aplica a rotação em um PONTO
Ponto* Figura::rotaciona_ponto(Ponto* p, int px, int py, int angulo, int op)
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

//Aplicam a rotação anti-horária e horária em todos os pontos da linha/quadrado
void Figura::rotaciona_anti_horario(int angulo)
{
    for(int i = 0; i < pontos; i++)
    {
        p[i] = rotaciona_ponto(p[i], px, py, angulo, 0);
    }
    rotacao -= angulo;
}

void Figura::rotaciona_horario(int angulo)
{
    for(int i = 0; i < pontos; i++)
    {
        p[i] = rotaciona_ponto(p[i], px, py, angulo, 1);
    }

    rotacao += angulo;
}

void Figura::desenha()
{
    color(R, G, B);

    if(tipo == 1) //linha
    {
        line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
        if(ativada) //se estiver selecionada
        {
            color(0, 0, 0);
            for(int i = 0; i < 2; i++)
            {
                circleFill(p[i]->x, p[i]->y, 2, 30);
            }
        }
    }
    if(tipo == 2) //Círculo
    {
        circle(px, py, tamanho, 40);

        if(preenchida) //Buga caso movimente
        {
            preenche();
        }
        
        if(ativada) //se estiver selecionado
        {
            color(0, 0, 0);
            circleFill(px, py, 2, 30);
        }
    }
    if(tipo == 3) //Quadrado
    {   
        line(p[0]->x, p[0]->y, p[1]->x, p[1]->y);
        line(p[1]->x, p[1]->y, p[2]->x, p[2]->y);
        line(p[2]->x, p[2]->y, p[3]->x, p[3]->y);
        line(p[3]->x, p[3]->y, p[0]->x, p[0]->y);

        if(ativada) //se estiver selecionada
        {
            color(0, 0, 0);
            for(int i = 0; i < 4; i++)
            {
                circleFill(p[i]->x, p[i]->y, 2, 30);
            }
        }
    }
}

int Figura::maiorX(int l)
{
    int m = 0;

    for(int i = 0; i < l; i++)
    {
        if(p[i]->x > m) m = p[i]->x;
    }

    return m;
}

int Figura::maiorY(int l)
{
    int m = 0;

    for(int i = 0; i < l; i++)
    {
        if(p[i]->y > m) m = p[i]->y;
    }

    return m;
}

int Figura::menorX(int l)
{
    int m = 20000;

    for(int i = 0; i < l; i++)
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

//Configura a colisão em cada tipo de figura
int Figura::colisao(int mX, int mY)
{
    if(tipo == 1) //Utiliza uma espécie de bounding box
    {
        if(mX >= menorX(pontos) && mX <= maiorX(pontos) && mY >= menorY(pontos) && mY <= maiorY(pontos)){
            return 1;
        }
    }
    if(tipo == 2) //Utiliza pitágoras para colisão
    {
        float dx = abs(mX-px);
        float dy = abs(mY-py);
        float R = tamanho;

        if(pow(dx, 2) + pow(dy, 2) <= pow(R, 2)) return 1;
    }
    if(tipo == 3) //Utiliza uma espécie de bounding box com as rotações
    {
        int ang = rotacao;
        rotaciona_anti_horario(ang);

        Ponto* p = new Ponto(mX, mY);
        p = rotaciona_ponto(p, mX, mY, ang, 0);

        int meX = menorX(pontos);
        int maX = maiorX(pontos);
        int meY = menorY(pontos);
        int maY = maiorY(pontos);

        rotaciona_horario(ang);
        
        if(p->x >= meX && p->x <= maX && p->y >= meY && p->y <= maY){
            return 1;
        }
    }

    return 0;
}