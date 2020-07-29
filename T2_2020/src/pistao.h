//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas no pistão do motor
*/

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

	    void encaixe(Ponto*);

	    void rotacionaX(float);
    	void rotacionaY(float);
    	void rotacionaZ(float);

	    void desenha2D();
	    void desenha3D(float);
};

#endif