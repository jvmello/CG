/**
    Trabalho 1 - Computação Gráfica
    João Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#include "cor.h"

//Implementa métodos da classe Cor

//instanciadores
Cor::Cor()
{
    R = 0;
    G = 0;
    B = 0;
}

Cor::Cor(float R_, float G_, float B_)
{
    R = R_;
    G = G_;
    B = B_;
}

//setters

void Cor::setR(float R_)
{
    R = R_;
}

void Cor::setG(float G_)
{
    G = G_;
}

void Cor::setB(float B_)
{
    B = B_;
}
