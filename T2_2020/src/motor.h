//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções do motor
*/


#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED

#include <vector>
#include <math.h>
#include "virabrequim.h"
#include "biela.h"
#include "pistao.h"

class Motor{
public:
    Virabrequim* virabrequim;
    Biela* biela;
    Pistao* pistao;
    float tam;
    Ponto* centro;
    float rpm = 0.6; //rpm pré-definido

    Motor(float, float, float, float);

    void translada(float, float, float);
    void rotacionaX(float);
    void rotacionaY(float);
    void rotacionaZ(float);

    float calcula_angulo_pistao(Ponto*, Ponto*);
    void movimento();
    void desenha2D();
    void desenha3D(float);
};

#endif
