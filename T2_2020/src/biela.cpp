//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Funções utilizadas na biela
*/


#include "biela.h"

Biela::Biela(float x, float y, float z, float tam)
{
    this->centro = new Ponto(x, y, z);
    this->tam = tam;

    //Pontos (3D)
    float uni = tam/5;
    this->pontos.push_back(new Ponto(x - uni, y - uni, z - uni));
    this->pontos.push_back(new Ponto(x - uni, y + 8*uni, z - uni));
    this->pontos.push_back(new Ponto(x + uni, y + 8*uni, z - uni));
    this->pontos.push_back(new Ponto(x + uni, y - uni, z - uni));
    this->pontos.push_back(new Ponto(x - uni, y - uni, z + uni));
    this->pontos.push_back(new Ponto(x - uni, y + 8*uni, z + uni));
    this->pontos.push_back(new Ponto(x + uni, y + 8*uni, z + uni));
    this->pontos.push_back(new Ponto(x + uni, y - uni, z + uni));

    this->p_pistao = new Ponto(x, y + 7.5*uni, z);
}

//Translada/rotaciona todos os pontos
void Biela::translada(float x, float y, float z)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->translada(x, y, z);
    }

    this->p_pistao->translada(x, y, z);
}

void Biela::rotacionaX(float angulo)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->rotacionaX(angulo, this->centro);
    }

    this->p_pistao->rotacionaX(angulo, this->centro);
}

void Biela::rotacionaY(float angulo)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->rotacionaY(angulo, this->centro);
    }

    this->p_pistao->rotacionaY(angulo, this->centro);
}

void Biela::rotacionaZ(float angulo)
{
    for(unsigned int i = 0; i < this->pontos.size(); i++)
    {
        this->pontos[i]->rotacionaZ(angulo, this->centro);
    }

    this->p_pistao->rotacionaZ(angulo, this->centro);
}

//Encaixe envolvido entre biela e virabrequim
void Biela::encaixe(Ponto* p, float ang)
{
    this->centro = p;

    this->pontos.clear();

    float uni = this->tam/5;
    this->pontos.push_back(new Ponto(p->x - uni, p->y - uni, p->z - uni));
    this->pontos.push_back(new Ponto(p->x - uni, p->y + 8*uni, p->z - uni));
    this->pontos.push_back(new Ponto(p->x + uni, p->y + 8*uni, p->z - uni));
    this->pontos.push_back(new Ponto(p->x + uni, p->y - uni, p->z - uni));
    this->pontos.push_back(new Ponto(p->x - uni, p->y - uni, p->z + uni));
    this->pontos.push_back(new Ponto(p->x - uni, p->y + 8*uni, p->z + uni));
    this->pontos.push_back(new Ponto(p->x + uni, p->y + 8*uni, p->z + uni));
    this->pontos.push_back(new Ponto(p->x + uni, p->y - uni, p->z + uni));

    this->p_pistao = new Ponto(p->x, p->y + 7.5*uni, p->z);

    this->rotacionaZ(ang);
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
