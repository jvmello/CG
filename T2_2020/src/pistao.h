#include <vector>
#include "ponto.h"

#ifndef PISTAO_H_INCLUDED
#define PISTAO_H_INCLUDED

class Pistao
{
	public:
		std::vector<Ponto*> pontos;
	    int camera_fixa;

	    Pistao(Ponto*, float);

	    void translada(Ponto*);
	    void rotaciona(float, float, float);
	    void encaixe(Ponto*);
	    void KeyInput(int);
	    void desenha();
};

#endif // PISTAO_H_INCLUDED