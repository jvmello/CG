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

#include "ponto.h"
#include "virabrequim.h"
#include "biela.h"
#include "pistao.h"
#include "motor.h"
#include "auxiliares.h"

int screenWidth = 1200, screenHeight = 600;
int mouseX, mouseY;
int op = 0;
int ang = 0;

int d = 200;

Motor* motor2D;
Motor* motor3D;

void DrawMouseScreenCoords()
{
    //char str[100];
    //sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
    //sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
}

//Inicialização de elementos
void init()
{
    motor2D = new Motor(1150, 50, 0, 100, 1);
    motor3D = new Motor(150, 50, 100, 100, 1);
}

//Função a ser chamada na render para organizar o código, basicamente desenha cada elemento
void desenha()
{
    color(0, 0, 0);

    motor2D->movimento();
    motor2D->desenha2D();

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

    if(key == 45) //+
    {
        motor2D->rpm -= 0.05;
        motor3D->rpm -= 0.05;
    }

    if(key == 119) d+=10; //W
    if(key == 115) d-=10; //S
    
    if(key == 97) //A
    {
        motor3D->translada(new Ponto(0, 1, 0));
    }

    if(key == 100) //D
    {
        //motor3D->translada(new Ponto(1, 0, 0));
    }

    if(key == 100) //Z
    {
        //motor3D->translada(new Ponto(0, 0, 1));
        motor3D->rotaciona(1, 1, 0);
    }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
    printf("\nLiberou: %d" , key);
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

    if(state == 1)
    {
    }
}

int main(void)
{
    initCanvas(&screenWidth, &screenHeight, "Trabalho 2 - jvmello");

    init();

    runCanvas();
}
