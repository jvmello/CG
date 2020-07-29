//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classe e funções utilizadas na biela do motor
*/


#ifndef BIELA_H_INCLUDED
#define BIELA_H_INCLUDED

#include <vector>
#include "ponto.h"

class Biela{
public:
    std::vector<Ponto*> pontos;
    float tam;
    Ponto* p_pistao;
    Ponto* centro;

    Biela(float, float, float, float);

    void translada(float, float, float);
    void encaixe(Ponto*, float);
    
    void rotacionaX(float);
    void rotacionaY(float);
    void rotacionaZ(float);
    
    Ponto* get_pistao();

    void KeyInput(int key);
    void desenha2D();
    void desenha3D(float);
};

#endif