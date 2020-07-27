#include "motor.h"

Motor::Motor(float x, float y, float z, float tam, int num_pistao)
{
    this->centro = new Ponto(x, y, z);
    this->tam = tam;
    this->num_pistao = num_pistao;

    float t_v = tam * 0.4;
    this->virabrequim = new Virabrequim(this->centro->x, this->centro->y, this->centro->z, t_v);

    Ponto* p_b = this->virabrequim->get_biela();
    float t_b = tam * 0.4;
    this->biela = new Biela(p_b->x, p_b->y, p_b->z, t_b);

    Ponto* p_t = this->biela->get_pistao();
    float t_p = tam *0.4;
    this->pistao = new Pistao(p_t->x, p_t->y, p_t->z, t_p);
}

void Motor::translada(Ponto* p)
{

}

void Motor::rotaciona(float angle_x, float angle_y, float angle_z)
{

}

void Motor::KeyInput(int key)
{
    this->virabrequim->KeyInput(key);
    this->biela->KeyInput(key);
    this->pistao->KeyInput(key);
}

float Motor::calcula_angulo_pistao()
{
    return 0;
}

void Motor::movimento()
{
    this->virabrequim->rotaciona(0,0,1);
    
    float ang;
    ang = this->calcula_angulo_pistao();
    
    this->biela->encaixe(this->virabrequim->get_biela(), ang);
    this->pistao->encaixe(this->biela->get_pistao());
}

void Motor::desenha()
{
    this->virabrequim->desenha();
    this->biela->desenha();
    this->pistao->desenha();
}
