#include "biela.h"

Biela::Biela(float x, float y, float z, float tam)
{
    this->centro = new Ponto(x, y, z);
    this->tam = tam;

    float m = tam/4;
    this->pontos.push_back(new Ponto(x - m, y - m, 0));
    this->pontos.push_back(new Ponto(x - m, y + 6*m, 0));
    this->pontos.push_back(new Ponto(x + m, y + 6*m, 0));
    this->pontos.push_back(new Ponto(x + m, y - m, 0));

    this->p_pistao = new Ponto(x, y + 5.5*m, 0);
}

void Biela::translada(float x, float y, float z)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->x += x;
        this->pontos[i]->y += y;
        this->pontos[i]->z += z;
    }
    this->p_pistao->x += x;
    this->p_pistao->y += y;
    this->p_pistao->z += z;
}

void Biela::rotaciona(float ang_x, float ang_y, float ang_z)
{
    float ang = ang_z*3.1415/180;
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
        this->pontos[i]->x = px;
        this->pontos[i]->y = py;
    }

    px = this->p_pistao->x*m_rotacao[0][0] + this->p_pistao->y*m_rotacao[0][1];
    py = this->p_pistao->x*m_rotacao[1][0] + this->p_pistao->y*m_rotacao[1][1];
    this->p_pistao->x = px;
    this->p_pistao->y = py;

    this->translada(this->centro->x, this->centro->y, this->centro->z);
}

void Biela::encaixe(Ponto* p, float ang)
{
    this->centro = p;

    this->pontos.clear();

    float m = this->tam/4;
    this->pontos.push_back(new Ponto(p->x - m, p->y - m, 0));
    this->pontos.push_back(new Ponto(p->x - m, p->y + 6*m, 0));
    this->pontos.push_back(new Ponto(p->x + m, p->y + 6*m, 0));
    this->pontos.push_back(new Ponto(p->x + m, p->y - m, 0));

    this->p_pistao = new Ponto(p->x, p->y + 5.5*m, 0);

    this->rotaciona(0, 0, ang);
}

Ponto* Biela::get_pistao()
{
	return this->p_pistao;
}

void Biela::desenha2D()
{
    line(this->pontos[0]->x, this->pontos[0]->y, this->pontos[1]->x, this->pontos[1]->y);
    line(this->pontos[1]->x, this->pontos[1]->y, this->pontos[2]->x, this->pontos[2]->y);
    line(this->pontos[2]->x, this->pontos[2]->y, this->pontos[3]->x, this->pontos[3]->y);
    line(this->pontos[3]->x, this->pontos[3]->y, this->pontos[0]->x, this->pontos[0]->y);

    circleFill(this->p_pistao->x, this->p_pistao->y, tam/20, 20);
}

void Biela::desenha3D()
{
    line(this->pontos[0]->x, this->pontos[0]->y, this->pontos[1]->x, this->pontos[1]->y);
    line(this->pontos[1]->x, this->pontos[1]->y, this->pontos[2]->x, this->pontos[2]->y);
    line(this->pontos[2]->x, this->pontos[2]->y, this->pontos[3]->x, this->pontos[3]->y);
    line(this->pontos[3]->x, this->pontos[3]->y, this->pontos[0]->x, this->pontos[0]->y);

    circle(this->p_pistao->x, this->p_pistao->y, 15, 20);
}