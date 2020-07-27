#ifndef VIRABREQUIM_H_INCLUDED
#define VIRABREQUIM_H_INCLUDED

#include <vector>
#include "ponto.h"

class Virabrequim{
public:
    std::vector<Ponto*> pontos;
    Ponto* p_biela;
    float tamanho;
    Ponto* centro;
    float tam;

    Virabrequim(float, float, float, float);
    Ponto* get_biela();
    Ponto* get_centro();
    
    void translada(float, float, float);
    void rotaciona(float, float, float);
    void KeyInput(int);
    void desenha();
};

#endif // VIRABREQUIM_H_INCLUDED
