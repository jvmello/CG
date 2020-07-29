//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas no virabrequim do motor
*/

#ifndef VIRABREQUIM_H_INCLUDED
#define VIRABREQUIM_H_INCLUDED

#include <vector>
#include "ponto.h"

class Virabrequim{
public:
    std::vector<Ponto*> pontos;
    float tam;
    Ponto* centro; //centro para transformações
    Ponto* p_biela; //ponto da biela

    Virabrequim(float, float, float, float);

    Ponto* get_biela();
    Ponto* get_centro();
    
    void translada(float, float, float);

    void rotacionaX(float);
    void rotacionaY(float);
    void rotacionaZ(float);

    void desenha2D();
    void desenha3D(float);
};

#endif
