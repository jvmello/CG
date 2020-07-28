#include "pistao.h"

Pistao::Pistao(float x, float y, float z, float tam)
{
	this->centro = new Ponto(x, y, z);

	float m = tam/4;

	this->pontos.push_back(new Ponto(x - 1.5*m, y - m, z + m));
    this->pontos.push_back(new Ponto(x - 1.5*m, y + m, z + m));
    this->pontos.push_back(new Ponto(x + 1.5*m, y + m, z + m));
    this->pontos.push_back(new Ponto(x + 1.5*m, y - m, z + m));
    this->pontos.push_back(new Ponto(x - 1.5*m, y - m, z - m));
    this->pontos.push_back(new Ponto(x - 1.5*m, y + m, z - m));
    this->pontos.push_back(new Ponto(x + 1.5*m, y + m, z - m));
    this->pontos.push_back(new Ponto(x + 1.5*m, y - m, z - m));
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

void Pistao::desenha2D()
{
    line(this->pontos[0]->x, this->pontos[0]->y, this->pontos[1]->x, this->pontos[1]->y);
    line(this->pontos[1]->x, this->pontos[1]->y, this->pontos[2]->x, this->pontos[2]->y);
    line(this->pontos[2]->x, this->pontos[2]->y, this->pontos[3]->x, this->pontos[3]->y);
    line(this->pontos[3]->x, this->pontos[3]->y, this->pontos[0]->x, this->pontos[0]->y);
}

void Pistao::desenha3D(float d)
{
    std::vector<Ponto*> Pontos2d;
    for(int i = 0; i<8; i++){
        //printf("\nCONTA = %f * %f / %f", this->pontos[i]->x, d, this->pontos[i]->z);
        Pontos2d.push_back(new Ponto(this->pontos[i]->x*d/this->pontos[i]->z, this->pontos[i]->y*d/this->pontos[i]->z, 0));
        //printf("\nRESULT %f", Pontos2d[i]->x);
    }

    for(int i = 0; i<8; i++){
        //printf("\nANTES %f %f", Pontos2d[i]->x, Pontos2d[i]->y);
        Pontos2d[i]->x += this->centro->x;
        Pontos2d[i]->y += this->centro->y;
        //printf("\nDEPOS %f %f", Pontos2d[i]->x, Pontos2d[i]->y);
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
