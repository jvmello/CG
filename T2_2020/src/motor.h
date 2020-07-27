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

    Motor(float, float, float, float tamanho, int);

    void translada(Ponto*);
    void rotaciona(float, float, float);
    void KeyInput(int);

    float calcula_angulo_pistao();
    void movimento();
    void desenha();
};

#endif // MOTOR_H_INCLUDED
