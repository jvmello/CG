//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Funções utilizadas no motor
*/

#include "motor.h"

Motor::Motor(float x, float y, float z, float tam)
{
    this->centro = new Ponto(x, y, z);
    this->tam = tam;

    //Inicia virabrequim, biela e pistão com valores definidos

    float tam_virabrequim = tam * 0.4;
    this->virabrequim = new Virabrequim(this->centro->x, this->centro->y, this->centro->z, tam_virabrequim);

    Ponto* p_biela = this->virabrequim->get_biela();
    float tam_biela = tam * 0.3;
    this->biela = new Biela(p_biela->x, p_biela->y, p_biela->z, tam_biela);

    Ponto* p_pistao = this->biela->get_pistao();
    float tam_pistao = tam * 0.3;
    this->pistao = new Pistao(p_pistao->x, p_pistao->y, p_pistao->z, tam_pistao);
}

//Translada e rotaciona tudo
void Motor::translada(float x, float y, float z)
{
    this->virabrequim->translada(x, y, z);
    this->biela->translada(x, y, z);
    this->pistao->translada(x, y, z);
}

void Motor::rotacionaX(float ang)
{
    this->virabrequim->rotacionaX(ang);
    this->biela->rotacionaX(ang);
    this->pistao->rotacionaX(ang);
}

void Motor::rotacionaY(float ang)
{
    this->virabrequim->rotacionaY(ang);
    this->biela->rotacionaY(ang);
    this->pistao->rotacionaY(ang);
}

void Motor::rotacionaZ(float ang)
{
    this->virabrequim->rotacionaZ(ang);
    this->biela->rotacionaZ(ang);
    this->pistao->rotacionaZ(ang);
}

//Ângulo de encaixe
float Motor::calcula_angulo_pistao(Ponto* p1, Ponto* p2)
{
    float produto_interno, norma_p1, norma_p2, ang;

    produto_interno = (p1->x * p2->x) + (p1->y * p2->y);
    norma_p1 = sqrt(pow(p1->x, 2) + pow(p1->y, 2));
    norma_p2 = sqrt(pow(p2->x, 2) + pow(p2->y, 2));

    ang = produto_interno/(norma_p1*norma_p2);
    ang = acosf(ang)*180/3.1415;

    return ang;
}

//Motor se movendo
void Motor::movimento()
{
    this->virabrequim->rotacionaZ(this->rpm);

    float ang;
    ang = this->calcula_angulo_pistao(this->pistao->centro, this->virabrequim->centro);
    
    this->biela->encaixe(this->virabrequim->get_biela(), ang);
    this->pistao->encaixe(this->biela->get_pistao());
}

//Desenha o motor usando as funções das outras partes
void Motor::desenha2D()
{
    this->virabrequim->desenha2D();
    this->biela->desenha2D();
    this->pistao->desenha2D();
}

void Motor::desenha3D(float d)
{
    this->virabrequim->desenha3D(d);
    this->biela->desenha3D(d);
    this->pistao->desenha3D(d);
}
