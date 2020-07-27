#include "virabrequim.h"

Virabrequim::Virabrequim(float x, float y, float z, float tam)
{
    this->centro = new Ponto(x, y, z);
    this->tam = tam;
    float m = tam/4;

    this->pontos.push_back(new Ponto(x - m, y - m, 0));
    this->pontos.push_back(new Ponto(x - 0.5*m, y + 3*m, 0));
    this->pontos.push_back(new Ponto(x + 0.5*m, y + 3*m, 0));
    this->pontos.push_back(new Ponto(x + m, y - m, 0));

    this->p_biela = new Ponto(x, y + 2.5*m, 0);
}

Ponto* Virabrequim::get_biela()
{
	return this->p_biela;
}

Ponto* Virabrequim::get_centro()
{
	return this->centro;
}

void Virabrequim::translada(float x, float y, float z)
{
	for(unsigned int i = 0; i < this->pontos.size(); i++)
	{
        this->pontos[i]->x += x;
        this->pontos[i]->y += y;
        this->pontos[i]->z += z;
    }

    this->p_biela->x += x;
    this->p_biela->y += y;
    this->p_biela->z += z;
}

void Virabrequim::rotaciona(float ang_x, float ang_y, float ang_z)
{
	float ang = ang_z * 3.1415/180;
	float px, py;

	this->translada(-this->centro->x, -this->centro->y, -this->centro->z);

	double m_rotacao[3][3] =
	{
		cos(ang), -sin(ang), 0,
		sin(ang), cos(ang),  0,
		0,        0,         1
	};

	for(unsigned int i = 0; i < this->pontos.size(); i++)
	{
		px = pontos[i]->x*m_rotacao[0][0] + pontos[i]->y*m_rotacao[0][1];
		py = pontos[i]->x*m_rotacao[1][0] + pontos[i]->y*m_rotacao[1][1];

		pontos[i]->x = px;
		pontos[i]->y = py;
	}

	px = this->p_biela->x*m_rotacao[0][0] + this->p_biela->y*m_rotacao[0][1];
	py = this->p_biela->x*m_rotacao[1][0] + this->p_biela->y*m_rotacao[1][1];

	this->p_biela->x = px;
	this->p_biela->y = py;

	this->translada(this->centro->x, this->centro->y, this->centro->z);
}

void Virabrequim::KeyInput(int key)
{
}

void Virabrequim::desenha()
{
    line(this->pontos[0]->x, this->pontos[0]->y, this->pontos[1]->x, this->pontos[1]->y);
    line(this->pontos[1]->x, this->pontos[1]->y, this->pontos[2]->x, this->pontos[2]->y);
    line(this->pontos[2]->x, this->pontos[2]->y, this->pontos[3]->x, this->pontos[3]->y);
    line(this->pontos[3]->x, this->pontos[3]->y, this->pontos[0]->x, this->pontos[0]->y);

    circle(this->p_biela->x, this->p_biela->y, 20, 20);

    line(this->centro->x, this->centro->y, this->centro->x, this->centro->y+1000);
}
