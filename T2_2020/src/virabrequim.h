#ifndef VIRABREQUIM_H_INCLUDED
#define VIRABREQUIM_H_INCLUDED

#include <vector>
#include "ponto.h"

class Virabrequim{
public:
    std::vector<Ponto*> pontos;
    float tamanho;
    float tam;
    Ponto* centro;
    Ponto* p_biela;

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
