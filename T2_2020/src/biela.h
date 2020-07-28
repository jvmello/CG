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
    void rotaciona(float, float, float);
    Ponto* get_pistao();
    void KeyInput(int key);
    void desenha2D();
    void desenha3D(float);
};

#endif // BIELA_H_INCLUDED