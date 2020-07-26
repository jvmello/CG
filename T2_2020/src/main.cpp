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

int d = 30;

void DrawMouseScreenCoords()
{
    //char str[100];
    //sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
    //sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
}

//Inicialização de elementos
void init()
{

}

//Função a ser chamada na render para organizar o código, basicamente desenha cada elemento
void desenha()
{
    color(0, 0, 0);


}

void render()
{
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
