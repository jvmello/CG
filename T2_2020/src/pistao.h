#include <vector>
#include "ponto.h"

#ifndef PISTAO_H_INCLUDED
#define PISTAO_H_INCLUDED

class Pistao
{
	public:
		std::vector<Ponto*> pontos;
	    int camera_fixa;
	    Ponto* centro;
	    float tam;

	    Pistao(float, float, float, float);

	    void translada(float, float, float);
	    void rotaciona(float, float, float);
	    void encaixe(Ponto*);
	    void desenha2D();
	    void desenha3D();
};

#endif // PISTAO_H_INCLUDED