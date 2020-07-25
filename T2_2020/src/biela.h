#ifndef BIELA_H_INCLUDED
#define BIELA_H_INCLUDED

#include <vector>
#include "ponto.h"

class Biela{
public:
    std::vector<Ponto*> pontos;
    float tamanho;
    Ponto* pt_pistao;
    int rotacao_fixa;
    int camera_fixa;

    Biela(Ponto*, float);

    void translada(Ponto*);
    void encaixe(Ponto*, float);
    void rotaciona(float, float, float);
    Ponto* get_pistao();
    void KeyInput(int key);
    void desenha();
};

#endif // BIELA_H_INCLUDED