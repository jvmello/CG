#ifndef BIELA_H_INCLUDED
#define BIELA_H_INCLUDED

class Biela{
public:
    std::vector<Ponto*> pontos;
    float tamanho;
    Ponto* pt_pistao;
    bool fix_r;
    bool fix_d;

    Biela(Ponto*, float);

    void translada(Ponto*);
    void conexao(Ponto*, float);
    void rotaciona(float, float, float);
    Ponto* get_pistao();
    void KeyInput(int key);
    void desenha();
};