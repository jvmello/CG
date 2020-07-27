#include "pistao.h"

Pistao::Pistao(float x, float y, float z, float tam)
{
	this->centro = new Ponto(x, y, z);

	float m = tam/4;

	this->pontos.push_back(new Ponto(x - m, y - m, 0));
    this->pontos.push_back(new Ponto(x - m, y + m, 0));
    this->pontos.push_back(new Ponto(x + m, y + m, 0));
    this->pontos.push_back(new Ponto(x + m, y - m, 0));

    this->camera_fixa = 0;
}

void Pistao::translada(float x, float y, float z)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++){
        this->pontos[i]->x += x;
        this->pontos[i]->y += y;
        this->pontos[i]->z += z;
    }
}

void Pistao::rotaciona(float ang_x, float ang_y, float ang_z)
{

}

void Pistao::encaixe(Ponto* p)
{
	this->translada(-this->centro->x, -this->centro->y, -this->centro->z);
	this->translada(p->x, p->y, p->z);
	this->centro = p;
}

void Pistao::KeyInput(int key)
{
}

void Pistao::desenha()
{
    line(this->pontos[0]->x, this->pontos[0]->y, this->pontos[1]->x, this->pontos[1]->y);
    line(this->pontos[1]->x, this->pontos[1]->y, this->pontos[2]->x, this->pontos[2]->y);
    line(this->pontos[2]->x, this->pontos[2]->y, this->pontos[3]->x, this->pontos[3]->y);
    line(this->pontos[3]->x, this->pontos[3]->y, this->pontos[0]->x, this->pontos[0]->y);
}
