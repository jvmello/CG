#include "virabrequim.h"

Virabrequim::Virabrequim(float x, float y, float z, float tam)
{
    this->centro = new Ponto(x, y, z);
    this->tam = tam;
    float m = tam/4;

    this->pontos.push_back(new Ponto(x - 0.5*m, y - 2*m, z - m));
    this->pontos.push_back(new Ponto(x - 0.5*m, y + 2*m, z - m));
    this->pontos.push_back(new Ponto(x + 0.5*m, y + 2*m, z - m));
    this->pontos.push_back(new Ponto(x + 0.5*m, y - 2*m, z - m));

    this->pontos.push_back(new Ponto(x - 0.5*m, y - 2*m, z + m));
    this->pontos.push_back(new Ponto(x - 0.5*m, y + 2*m, z + m));
    this->pontos.push_back(new Ponto(x + 0.5*m, y + 2*m, z + m));
    this->pontos.push_back(new Ponto(x + 0.5*m, y - 2*m, z + m));

    this->p_biela = new Ponto(x, y + 1.5*m, z);
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

void Virabrequim::rotacionaX(float angulo)
{
    float ang = angulo * 3.1415/180;
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

void Virabrequim::rotacionaY(float angulo)
{
    float ang = angulo * 3.1415/180;
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

void Virabrequim::rotacionaZ(float ang_x, float ang_y, float ang_z)
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

void Virabrequim::desenha2D()
{
    line(this->pontos[0]->x, this->pontos[0]->y, this->pontos[1]->x, this->pontos[1]->y);
    line(this->pontos[1]->x, this->pontos[1]->y, this->pontos[2]->x, this->pontos[2]->y);
    line(this->pontos[2]->x, this->pontos[2]->y, this->pontos[3]->x, this->pontos[3]->y);
    line(this->pontos[3]->x, this->pontos[3]->y, this->pontos[0]->x, this->pontos[0]->y);

    circleFill(this->p_biela->x, this->p_biela->y, tam/20, 20);
}

void Virabrequim::desenha3D(float d)
{
    std::vector<Ponto*> pontos2d;
    Ponto* p_biela2d = new Ponto(0, 0, 0);

    for(int i = 0; i<8; i++)
    {
    	Ponto* aux = new Ponto(this->pontos[i]->x*d/this->pontos[i]->z, this->pontos[i]->y*d/this->pontos[i]->z, 0);
        pontos2d.push_back(new Ponto(aux->x, aux->y, aux->z));
    }

    //p_biela2d->x = p_biela->x*d/p_biela->z;
    //p_biela2d->y = p_biela->y*d/p_biela->z;

    for(int i = 0; i<8; i++){
        pontos2d[i]->x += this->centro->x;
        pontos2d[i]->y += this->centro->y;
    }

    //p_biela2d->x += centro->x;
    //p_biela2d->y += centro->y;

    line(pontos2d[0]->x, pontos2d[0]->y, pontos2d[1]->x, pontos2d[1]->y);
    line(pontos2d[1]->x, pontos2d[1]->y, pontos2d[2]->x, pontos2d[2]->y);
    line(pontos2d[2]->x, pontos2d[2]->y, pontos2d[3]->x, pontos2d[3]->y);
    line(pontos2d[0]->x, pontos2d[0]->y, pontos2d[3]->x, pontos2d[3]->y);

    line(pontos2d[4]->x, pontos2d[4]->y, pontos2d[5]->x, pontos2d[5]->y);
    line(pontos2d[5]->x, pontos2d[5]->y, pontos2d[6]->x, pontos2d[6]->y);
    line(pontos2d[6]->x, pontos2d[6]->y, pontos2d[7]->x, pontos2d[7]->y);
    line(pontos2d[4]->x, pontos2d[4]->y, pontos2d[7]->x, pontos2d[7]->y);

    line(pontos2d[1]->x, pontos2d[1]->y, pontos2d[5]->x, pontos2d[5]->y);
    line(pontos2d[2]->x, pontos2d[2]->y, pontos2d[6]->x, pontos2d[6]->y);
    line(pontos2d[3]->x, pontos2d[3]->y, pontos2d[7]->x, pontos2d[7]->y);
    line(pontos2d[4]->x, pontos2d[4]->y, pontos2d[0]->x, pontos2d[0]->y);
}
