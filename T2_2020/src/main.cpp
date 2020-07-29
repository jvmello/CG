//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    * Implementei o motor com cubos;
    * O RPM pode ser setado utilizando + e -;
    * A câmera pode ter a distância aumentada ou diminuída usando W ou S, respectivamente;
    * Também deixei os botões X (para rotacionar no eixo X) e Y (para o eixo Y), mas a rotação bugou.
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

#include "ponto.h"
#include "virabrequim.h"
#include "biela.h"
#include "pistao.h"
#include "motor.h"

int screenWidth = 1200, screenHeight = 600;
int mouseX, mouseY;
int ang = 0;

int d = 200;

Motor* motor2D;
Motor* motor3D;

//Inicialização de elementos
void init()
{
    motor2D = new Motor(1150, 50, 0, 100);
    motor3D = new Motor(150, 50, 100, 100);
}

//Função a ser chamada na render para organizar o código, basicamente desenha cada elemento
void desenha()
{
    color(0, 0, 0);

    //Motor do canto da tela
    motor2D->movimento();
    motor2D->desenha2D();

    //Motor em 3D
    motor3D->movimento();
    motor3D->desenha3D(d);
}

void render()
{
    desenha();
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
    if(key == 43) //+
    {
        motor2D->rpm += 0.05;
        motor3D->rpm += 0.05;
    }

    if(key == 45) //-
    {
        motor2D->rpm -= 0.05;
        motor3D->rpm -= 0.05;
    }

    if(key == 119) d+=10; //W
    if(key == 115) d-=10; //S


    if(key == 120) motor3D->rotacionaX(1);

    if(key == 121) motor3D->rotacionaY(1);
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
}

int main(void)
{
    initCanvas(&screenWidth, &screenHeight, "Trabalho 2 - jvmello");

    init();

    runCanvas();
}
