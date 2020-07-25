#ifndef VIRABREQUIM_H_INCLUDED
#define VIRABREQUIM_H_INCLUDED

#include <vector>
#include "ponto.h"

class Virabrequim{
public:
    std::vector<Ponto*> pontos;
    Ponto* p_biela;
    int rotacao_fixa;
    float tamanho;

    Virabrequim(Ponto*, float);
    Ponto* get_biela();
    Ponto* get_centro();
    
    void translada(Ponto*);
    void rotaciona(float, float, float);
    void KeyInput(int);
    void desenha();
};

#endif // VIRABREQUIM_H_INCLUDED
