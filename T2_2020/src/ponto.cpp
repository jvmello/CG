//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos (agora com três coordenadas)
*/

#include "ponto.h"

Ponto::Ponto(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Ponto::Ponto()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

int Ponto::get_x(void)
{
    return this->x;
}

int Ponto::get_y(void)
{
    return this->y;
}

int Ponto::get_z(void)
{
    return this->y;
}

void Ponto::translada(float x, float y, float z)
{
    this->x += x;
    this->y += y;
    this->z += z;
}

//Rotaciona o ponto no eixo X
void Ponto::rotacionaX(float angulo, Ponto* centro)
{
    float ang = angulo*3.1415/180;
    float py, pz;

    this->translada(-centro->x, -centro->y, -centro->z);

    //matriz de rotação
    double m_rotacao[4][4] =
    {
        1, 0,        0,         0,
        0, cos(ang), -sin(ang), 0,
        0, sin(ang), cos(ang),  0,
        0, 0,        0,         1
    };

    py = this->y*m_rotacao[1][1] + this->z*m_rotacao[1][2];
    pz = this->y*m_rotacao[2][1] + this->z*m_rotacao[2][2];
    this->x = py;
    this->y = pz;

    this->translada(centro->x, centro->y, centro->z);
}

//Rotaciona o ponto no eixo Y
void Ponto::rotacionaY(float angulo, Ponto* centro)
{
    float ang = angulo*3.1415/180;
    float px, pz;

    this->translada(-centro->x, -centro->y, -centro->z);

    //matriz de rotação
    double m_rotacao[4][4] =
    {
        cos(ang),  0,        sin(ang), 0,
        0,         1,        0,        0,
        -sin(ang), 0,        cos(ang), 0,
        0,         0,        0,        1
    };

    px = this->x*m_rotacao[0][0] + this->z*m_rotacao[0][2];
    pz = this->x*m_rotacao[2][0] + this->z*m_rotacao[2][2];
    this->x = px;
    this->y = pz;

    this->translada(centro->x, centro->y, centro->z);
}

//Rotaciona o ponto no eixo Z
void Ponto::rotacionaZ(float angulo, Ponto* centro)
{
    float ang = angulo*3.1415/180;
    float px, py;

    this->translada(-centro->x, -centro->y, -centro->z);

    //matriz de rotação
    double m_rotacao[4][4] =
    {
        cos(ang), -sin(ang), 0, 0,
        sin(ang), cos(ang),  0, 0,
        0,        0,         1, 0,
        0,        0,         0, 1
    };

    px = this->x*m_rotacao[0][0] + this->y*m_rotacao[0][1];
    py = this->x*m_rotacao[1][0] + this->y*m_rotacao[1][1];
    this->x = px;
    this->y = py;

    this->translada(centro->x, centro->y, centro->z);
}