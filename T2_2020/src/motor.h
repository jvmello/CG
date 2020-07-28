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
    int num_pistao;
    Ponto* centro;
    float rpm = 0.8;

    Motor(float, float, float, float tamanho, int);

    void translada(Ponto*);
    void rotaciona(float, float, float);

    float calcula_angulo_pistao();
    void movimento();
    void desenha2D();
    void desenha3D();
};

#endif // MOTOR_H_INCLUDED
