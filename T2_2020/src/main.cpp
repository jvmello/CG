//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
*/

#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

#include "gl_canvas2d.h"

#include "ponto2D.h"
#include "ponto3D.h"

#include "figura2D.h"

int screenWidth = 1200, screenHeight = 600;
int mouseX, mouseY;
int op = 0;
int ang = 0;

int d = 30;

Ponto2D* p1 = new Ponto2D(600, 180);
Ponto2D* p2 = new Ponto2D(650, 180);
Ponto2D* p3 = new Ponto2D(550, 400);
Ponto2D* p4 = new Ponto2D(700, 400);
Ponto2D* p5 = new Ponto2D(625, 220);

Ponto2D* p6 = new Ponto2D(625, 360);

Ponto2D* p7 = new Ponto2D(200, 200);
Ponto2D* p8 = new Ponto2D(200, 100);
Ponto2D* p9 = new Ponto2D(200, 100);
Ponto2D* p10 = new Ponto2D(200, 100);

Ponto2D* p11 = new Ponto2D(200, 100);
Ponto2D* p12 = new Ponto2D(200, 100);
Ponto2D* p13 = new Ponto2D(200, 100);
Ponto2D* p14 = new Ponto2D(200, 200);

Figura2D* f1 = new Figura2D(300, 300);
Figura2D* f2 = new Figura2D(300, 300);

void DrawMouseScreenCoords()
{
    //char str[100];
    //sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
    //sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
}

//Inicialização de elementos
void init()
{
    /*p1->recalcula();
    p2->recalcula();
    p3->recalcula();
    p4->recalcula();
    p5->recalcula();
    p6->recalcula();
    p7->recalcula();
    p8->recalcula();*/


    p7->x = p6->x-50;
    p7->y = p6->y-50;

    p8->x = p6->x+50;
    p8->y = p6->y-50;

    p9->x = p6->x-50;
    p9->y = p6->y+250;

    p10->x = p6->x+50;
    p10->y = p6->y+250;

    p11->x = p9->x-50;
    p11->y = p9->y-30;

    p12->x = p10->x+50;
    p12->y = p10->y-30;

    p13->x = p9->x-50;
    p13->y = p9->y+50;

    p14->x = p10->x+50;
    p14->y = p10->y+50;
}

void desenha_cubo()
{
    p1->desenha();
    p2->desenha();
    p3->desenha();
    p4->desenha();
    p5->desenha();
    p6->desenha();
    p7->desenha();
    p8->desenha();

    line(p1->x, p1->y, p2->x, p2->y);
    line(p1->x, p1->y, p4->x, p4->y);
    line(p1->x, p1->y, p5->x, p5->y);

    line(p2->x, p2->y, p6->x, p6->y);
    line(p2->x, p2->y, p3->x, p3->y);

    line(p3->x, p3->y, p4->x, p4->y);
    line(p3->x, p3->y, p7->x, p7->y);

    line(p4->x, p4->y, p8->x, p8->y);

    line(p5->x, p5->y, p6->x, p6->y);
    line(p5->x, p5->y, p8->x, p8->y);

    line(p6->x, p6->y, p7->x, p7->y);

    line(p7->x, p7->y, p8->x, p8->y);

    //Sleep(100);

    /*p1->d+=0.01;
    p2->d+=0.01;
    p3->d+=0.01;
    p4->d+=0.01;
    p5->d+=0.01;
    p6->d+=0.01;
    p7->d+=0.01;
    p8->d+=0.01;*/

    // p1->rotacionaX();
    // p2->rotacionaX();
    // p3->rotacionaX();
    // p4->rotacionaX();
    // p5->rotacionaX();
    // p6->rotacionaX();
    // p7->rotacionaX();
    // p8->rotacionaX();

    // p1->rotacionaZ();
    // p2->rotacionaZ();
    // p3->rotacionaZ();
    // p4->rotacionaZ();
    // p5->rotacionaZ();
    // p6->rotacionaZ();
    // p7->rotacionaZ();
    // p8->rotacionaZ();
}

//Função a ser chamada na render para organizar o código, basicamente desenha cada elemento
void desenha()
{
    color(0, 0, 0);

    //p1->desenha();
    //p2->desenha();
    //p3->desenha();
    //p4->desenha();
    p5->desenha();

    Sleep(15);

    p1->rotaciona(p5->x, p5->y, 5);
    p2->rotaciona(p5->x, p5->y, 5);
    p3->rotaciona(p5->x, p5->y, 5);
    p4->rotaciona(p5->x, p5->y, 5);
    p6->rotaciona(p5->x, p5->y, 5);

    line(p1->x, p1->y, p2->x, p2->y);
    line(p1->x, p1->y, p3->x, p3->y);
    line(p2->x, p2->y, p4->x, p4->y);
    line(p3->x, p3->y, p4->x, p4->y);

    //p7->translada(p6->x+30, p6->y+30);
    float ang = 0.0;
    float p1 = (p7->x - p6->x);
    float p2 = (p7->x - p6->x);

    if(p2 == 0) p2 = 1;

    ang = atan(p1 / p2);
    //printf("");
    p7->rotaciona(p6->x, p6->y, ang);
    p8->rotaciona(p6->x, p6->y, ang);
    p9->rotaciona(p6->x, p6->y, ang);
    p10->rotaciona(p6->x, p6->y, ang);
    p11->rotaciona(p6->x, p6->y, ang);
    p12->rotaciona(p6->x, p6->y, ang);
    p13->rotaciona(p6->x, p6->y, ang);
    p14->rotaciona(p6->x, p6->y, ang);

    line(p7->x, p7->y, p8->x, p8->y);
    line(p7->x, p7->y, p9->x, p9->y);
    line(p8->x, p8->y, p10->x, p10->y);
    line(p9->x, p9->y, p10->x, p10->y);

    line(p11->x, p11->y, p12->x, p12->y);
    line(p11->x, p11->y, p13->x, p13->y);
    line(p12->x, p12->y, p14->x, p14->y);
    line(p13->x, p13->y, p14->x, p14->y);   

    circle(p5->x, p5->y, 10, 50);
    circle(p6->x, p6->y, 10, 50);
}

void render()
{
    //Sleep(10);
    desenha();
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
    //printf("\nLiberou: %d" , key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
    mouseX = x; //guarda as coordenadas do mouse para exibir dentro da render()
    mouseY = y;

    //printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);

    if( state == 0 ) //clicou
    {
    }

    if(state == -2) //Verifica se o mouse está em estado de "arrastar", ativado pelo selecionar
    {
    }

    if(state == 1){}
}

int main(void)
{
    initCanvas(&screenWidth, &screenHeight, "Trabalho 2 - jvmello");

    init();

    runCanvas();
}
