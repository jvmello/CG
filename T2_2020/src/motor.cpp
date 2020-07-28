#include "motor.h"

Motor::Motor(float x, float y, float z, float tam, int num_pistao)
{
    this->centro = new Ponto(x, y, z);
    this->tam = tam;
    this->num_pistao = num_pistao;

    float tam_v = tam * 0.4;
    this->virabrequim = new Virabrequim(this->centro->x, this->centro->y, this->centro->z, tam_v);

    Ponto* p_b = this->virabrequim->get_biela();
    float tam_b = tam * 0.3;
    this->biela = new Biela(p_b->x, p_b->y, p_b->z, tam_b);

    Ponto* p_t = this->biela->get_pistao();
    float tam_p = tam * 0.3;
    this->pistao = new Pistao(p_t->x, p_t->y, p_t->z, tam_p);
}

void Motor::translada(Ponto* p)
{

}

void Motor::rotaciona(float angle_x, float angle_y, float angle_z)
{

}

float Motor::calcula_angulo_pistao()
{
    return 0;
}

void Motor::movimento()
{
    this->virabrequim->rotaciona(0,0,this->rpm);
    
    float ang;
    ang = this->calcula_angulo_pistao();
    
    this->biela->encaixe(this->virabrequim->get_biela(), ang);
    this->pistao->encaixe(this->biela->get_pistao());
}

void Motor::desenha2D()
{
    this->virabrequim->desenha2D();
    this->biela->desenha2D();
    this->pistao->desenha2D();
}

void Motor::desenha3D()
{
    this->virabrequim->desenha3D();
    this->biela->desenha3D();
    this->pistao->desenha3D();
}