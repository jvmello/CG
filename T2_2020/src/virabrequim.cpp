//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Funções utilizadas no virabrequim do motor
*/

#include "virabrequim.h"

//inicializacao
Virabrequim::Virabrequim(float x, float y, float z, float tam)
{
    this->centro = new Ponto(x, y, z);
    this->tam = tam;
    float uni = tam/5;

    this->pontos.push_back(new Ponto(x - 0.5*uni, y - 2*uni, z - uni));
    this->pontos.push_back(new Ponto(x - 0.5*uni, y + 2*uni, z - uni));
    this->pontos.push_back(new Ponto(x + 0.5*uni, y + 2*uni, z - uni));
    this->pontos.push_back(new Ponto(x + 0.5*uni, y - 2*uni, z - uni));

    this->pontos.push_back(new Ponto(x - 0.5*uni, y - 2*uni, z + uni));
    this->pontos.push_back(new Ponto(x - 0.5*uni, y + 2*uni, z + uni));
    this->pontos.push_back(new Ponto(x + 0.5*uni, y + 2*uni, z + uni));
    this->pontos.push_back(new Ponto(x + 0.5*uni, y - 2*uni, z + uni));

    this->p_biela = new Ponto(x, y + 1.5*uni, z);
}

Ponto* Virabrequim::get_biela()
{
	return this->p_biela;
}

Ponto* Virabrequim::get_centro()
{
	return this->centro;
}

//Faz a translação dos pontos
void Virabrequim::translada(float x, float y, float z)
{
	for(unsigned int i = 0; i < this->pontos.size(); i++)
	{
        this->pontos[i]->translada(x, y, z);
    }

    this->p_biela->translada(x, y, z);
}

//Rotaciona os pontos no eixo X
void Virabrequim::rotacionaX(float angulo)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->rotacionaX(angulo, this->centro);
    }

    this->p_biela->rotacionaX(angulo, this->centro);
}

//Rotaciona os pontos no eixo Y
void Virabrequim::rotacionaY(float angulo)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->rotacionaY(angulo, this->centro);
    }

    this->p_biela->rotacionaY(angulo, this->centro);
}

//Rotaciona os pontos no eixo Z
void Virabrequim::rotacionaZ(float angulo)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->rotacionaZ(angulo, this->centro);
    }

    this->p_biela->rotacionaZ(angulo, this->centro);
}

//Desenha um virabrequim comum em 2D
void Virabrequim::desenha2D()
{
    line(this->pontos[0]->x, this->pontos[0]->y, this->pontos[1]->x, this->pontos[1]->y);
    line(this->pontos[1]->x, this->pontos[1]->y, this->pontos[2]->x, this->pontos[2]->y);
    line(this->pontos[2]->x, this->pontos[2]->y, this->pontos[3]->x, this->pontos[3]->y);
    line(this->pontos[3]->x, this->pontos[3]->y, this->pontos[0]->x, this->pontos[0]->y);

    circleFill(this->p_biela->x, this->p_biela->y, tam/20, 20);
}

//Desenha o cubo 3D
void Virabrequim::desenha3D(float d)
{
    std::vector<Ponto*> pontos3d; //pontos convertidos

    for(int i = 0; i<8; i++)
    {
    	Ponto* aux = new Ponto(this->pontos[i]->x*d/this->pontos[i]->z, this->pontos[i]->y*d/this->pontos[i]->z, 0);
        pontos3d.push_back(new Ponto(aux->x, aux->y, aux->z));
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
