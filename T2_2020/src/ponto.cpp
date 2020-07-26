//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas nos pontos que formam uma curva
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