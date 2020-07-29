//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Funções utilizadas no pistão do motor
*/

#include "pistao.h"

Pistao::Pistao(float x, float y, float z, float tam)
{
	this->centro = new Ponto(x, y, z);

	float uni = tam/5;

	this->pontos.push_back(new Ponto(x - 2.5*uni, y - uni, z + uni));
    this->pontos.push_back(new Ponto(x - 2.5*uni, y + uni, z + uni));
    this->pontos.push_back(new Ponto(x + 2.5*uni, y + uni, z + uni));
    this->pontos.push_back(new Ponto(x + 2.5*uni, y - uni, z + uni));
    this->pontos.push_back(new Ponto(x - 2.5*uni, y - uni, z - uni));
    this->pontos.push_back(new Ponto(x - 2.5*uni, y + uni, z - uni));
    this->pontos.push_back(new Ponto(x + 2.5*uni, y + uni, z - uni));
    this->pontos.push_back(new Ponto(x + 2.5*uni, y - uni, z - uni));
}

void Pistao::translada(float x, float y, float z)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->translada(x, y, z);
    }
}

void Pistao::encaixe(Ponto* p)
{
	this->translada(-this->centro->x, -this->centro->y, -this->centro->z);
	this->translada(p->x, p->y, p->z);
	this->centro = p;
}

void Pistao::rotacionaX(float angulo)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->rotacionaX(angulo, this->centro);
    }
}

void Pistao::rotacionaY(float angulo)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->rotacionaY(angulo, this->centro);
    }
}

void Pistao::rotacionaZ(float angulo)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->rotacionaZ(angulo, this->centro);
    }
}

void Pistao::desenha2D()
{
    line(this->pontos[0]->x, this->pontos[0]->y, this->pontos[1]->x, this->pontos[1]->y);
    line(this->pontos[1]->x, this->pontos[1]->y, this->pontos[2]->x, this->pontos[2]->y);
    line(this->pontos[2]->x, this->pontos[2]->y, this->pontos[3]->x, this->pontos[3]->y);
    line(this->pontos[3]->x, this->pontos[3]->y, this->pontos[0]->x, this->pontos[0]->y);
}

void Pistao::desenha3D(float d)
{
    std::vector<Ponto*> pontos3d; //pontos convertidos

    for(int i = 0; i < 8; i++)
    {
        pontos3d.push_back(new Ponto(this->pontos[i]->x*d/this->pontos[i]->z, this->pontos[i]->y*d/this->pontos[i]->z, 0));
    }

    for(int i = 0; i<8; i++)
    {
        pontos3d[i]->x += this->centro->x;
        pontos3d[i]->y += this->centro->y;
    }

    line(pontos3d[0]->x, pontos3d[0]->y, pontos3d[1]->x, pontos3d[1]->y);
    line(pontos3d[1]->x, pontos3d[1]->y, pontos3d[2]->x, pontos3d[2]->y);
    line(pontos3d[2]->x, pontos3d[2]->y, pontos3d[3]->x, pontos3d[3]->y);
    line(pontos3d[0]->x, pontos3d[0]->y, pontos3d[3]->x, pontos3d[3]->y);

    line(pontos3d[4]->x, pontos3d[4]->y, pontos3d[5]->x, pontos3d[5]->y);
    line(pontos3d[5]->x, pontos3d[5]->y, pontos3d[6]->x, pontos3d[6]->y);
    line(pontos3d[6]->x, pontos3d[6]->y, pontos3d[7]->x, pontos3d[7]->y);
    line(pontos3d[4]->x, pontos3d[4]->y, pontos3d[7]->x, pontos3d[7]->y);

    line(pontos3d[1]->x, pontos3d[1]->y, pontos3d[5]->x, pontos3d[5]->y);
    line(pontos3d[2]->x, pontos3d[2]->y, pontos3d[6]->x, pontos3d[6]->y);
    line(pontos3d[3]->x, pontos3d[3]->y, pontos3d[7]->x, pontos3d[7]->y);
    line(pontos3d[4]->x, pontos3d[4]->y, pontos3d[0]->x, pontos3d[0]->y);
}
