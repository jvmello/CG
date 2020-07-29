#include "biela.h"

Biela::Biela(float x, float y, float z, float tam)
{
    this->centro = new Ponto(x, y, z);
    this->tam = tam;

    float m = tam/4;
    this->pontos.push_back(new Ponto(x - m, y - m, z - m));
    this->pontos.push_back(new Ponto(x - m, y + 8*m, z - m));
    this->pontos.push_back(new Ponto(x + m, y + 8*m, z - m));
    this->pontos.push_back(new Ponto(x + m, y - m, z - m));
    this->pontos.push_back(new Ponto(x - m, y - m, z + m));
    this->pontos.push_back(new Ponto(x - m, y + 8*m, z + m));
    this->pontos.push_back(new Ponto(x + m, y + 8*m, z + m));
    this->pontos.push_back(new Ponto(x + m, y - m, z + m));

    this->p_pistao = new Ponto(x, y + 7.5*m, z);
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
    this->pontos.push_back(new Ponto(p->x - m, p->y - m, p->z - m));
    this->pontos.push_back(new Ponto(p->x - m, p->y + 8*m, p->z - m));
    this->pontos.push_back(new Ponto(p->x + m, p->y + 8*m, p->z - m));
    this->pontos.push_back(new Ponto(p->x + m, p->y - m, p->z - m));
    this->pontos.push_back(new Ponto(p->x - m, p->y - m, p->z + m));
    this->pontos.push_back(new Ponto(p->x - m, p->y + 8*m, p->z + m));
    this->pontos.push_back(new Ponto(p->x + m, p->y + 8*m, p->z + m));
    this->pontos.push_back(new Ponto(p->x + m, p->y - m, p->z + m));

    this->p_pistao = new Ponto(p->x, p->y + 7.5*m, p->z);

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

void Biela::desenha3D(float d)
{
    std::vector<Ponto*> Pontos2d;
    Ponto* p_pistao2d = new Ponto(0, 0, 0);

    for(int i = 0; i<8; i++)
    {
        Pontos2d.push_back(new Ponto(this->pontos[i]->x*d/this->pontos[i]->z, this->pontos[i]->y*d/this->pontos[i]->z, 0));
    }

    for(int i = 0; i<8; i++)
    {
        Pontos2d[i]->x += this->centro->x;
        Pontos2d[i]->y += this->centro->y;
    }

    line(Pontos2d[0]->x, Pontos2d[0]->y, Pontos2d[1]->x, Pontos2d[1]->y);
    line(Pontos2d[1]->x, Pontos2d[1]->y, Pontos2d[2]->x, Pontos2d[2]->y);
    line(Pontos2d[2]->x, Pontos2d[2]->y, Pontos2d[3]->x, Pontos2d[3]->y);
    line(Pontos2d[0]->x, Pontos2d[0]->y, Pontos2d[3]->x, Pontos2d[3]->y);

    line(Pontos2d[4]->x, Pontos2d[4]->y, Pontos2d[5]->x, Pontos2d[5]->y);
    line(Pontos2d[5]->x, Pontos2d[5]->y, Pontos2d[6]->x, Pontos2d[6]->y);
    line(Pontos2d[6]->x, Pontos2d[6]->y, Pontos2d[7]->x, Pontos2d[7]->y);
    line(Pontos2d[4]->x, Pontos2d[4]->y, Pontos2d[7]->x, Pontos2d[7]->y);

    line(Pontos2d[1]->x, Pontos2d[1]->y, Pontos2d[5]->x, Pontos2d[5]->y);
    line(Pontos2d[2]->x, Pontos2d[2]->y, Pontos2d[6]->x, Pontos2d[6]->y);
    line(Pontos2d[3]->x, Pontos2d[3]->y, Pontos2d[7]->x, Pontos2d[7]->y);
    line(Pontos2d[4]->x, Pontos2d[4]->y, Pontos2d[0]->x, Pontos2d[0]->y);
}
