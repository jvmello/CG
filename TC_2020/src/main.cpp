//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
	- Para utilizar, é preciso escolher um tipo de figura e um tipo de ação, também é possível escolher um tipo de cor (se não escolher, vai ser preta a imagem)
	- É possível aumentar/diminuir o tamanho, modificar a posição, preencher os círculos e rotacionar as linhas/quadrados (sentido horário e anti-horário)
	- Comandos de teclado
		- WASD para movimentar uma imagem (precisa estar selecionada)
		- Q e E para rotacionar a imagem em sentido anti-horário ou horário
		- Z e C para diminuir/aumentar o tamanho da imagem
		- Delete para resetar uma imagem selecionada
		- P para sobrepor uma figura a outra
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

#include "botao.h"
#include "checkbox.h"
#include "curva.h"
#include "painel.h"
#include "ponto.h"

Botao *bespmais, *bespmenos, *bselecionar, *binserir, *bresetar;
Checkbox *cb1, *cb2, *cb3, *cb4, *cb5, *cb6, *cb7;
Curva *c;
Painel *p1, *p2;

int screenWidth = 1200, screenHeight = 600;
int mouseX, mouseY;
int op = 0;
vector <Ponto*> pontos;
int curva = 0;
int mostra_curva = 0;
int animacao = 0;
int reta_r = 0;
int reta_q = 0;
int grafo_de_controle = 0;
int fecho_convexo = 0;
int blending_functions = 0;
int continua = 0;
int arrastando = 0;
float t = 0;

//função para desabilitar algumas funções (auxilia no controle da interface)
void desativa_tudo(char* tipo)
{
    if(tipo == "Adicional")
    {
        bresetar->ativado = 0;
        bselecionar->ativado = 0;
        binserir->ativado = 0;
    }

    if(tipo == "Ponto")
    {
        for(int i = 0; i < pontos.size(); ++i)
        {
            pontos[i]->ativado = 0;
        }
    }
}

void DrawMouseScreenCoords()
{
    char str[100];
    //sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
    //sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
}

//Inicialização de elementos
void init()
{
    p1 = new Painel(10, 10, 840, 590);
    p2 = new Painel(860, 10, 1190, 590);

    bresetar = new Botao(865, 510, 1185, 550, "Resetar");
    bselecionar = new Botao(865, 470, 1185, 510, "Selecionar");
    binserir = new Botao(865, 430, 1185, 470, "Inserir");

    bespmenos = new Botao(865, 350, 1020, 370, "-");
    bespmais = new Botao(1030, 350, 1185, 370, "+");

    cb1 = new Checkbox(865, 260, 895, 290);
    cb2 = new Checkbox(865, 220, 895, 250);
    cb3 = new Checkbox(865, 180, 895, 210);
    cb4 = new Checkbox(865, 140, 895, 170);
    cb5 = new Checkbox(865, 100, 895, 130);
    cb6 = new Checkbox(865, 60, 895, 90);
    cb7 = new Checkbox(865, 20, 895, 50);
}

//Função a ser chamada na render para organizar o código, basicamente desenha cada elemento
void desenha()
{
    color(0.9, 0.9, 0.9);
    rectFill(0, 0, 1210, 600);

    p1->desenha();
    p2->desenha();

    color(0, 0, 0);

    text(985, 570, "Menu");
    bresetar->desenha();
    bselecionar->desenha();
    binserir->desenha();

    color(0, 0, 0);
    line(860, 410, 1190, 410);

    text(980, 390, "Espessura");
    bespmais->desenha();
    bespmenos->desenha();

    color(0, 0, 0);
    line(860, 330, 1190, 330);
    text(980, 310, "Funcoes");

    cb1->desenha();
    cb2->desenha();
    cb3->desenha();
    cb4->desenha();
    cb5->desenha();
    cb6->desenha();
    cb7->desenha();

    text(905, 275, "Mostrar curva");
    text(905, 235, "Animacoes");
    text(905, 195, "Reta R");
    text(905, 155, "Reta Q");
    text(905, 115, "Grafo de controle");
    text(905, 75, "Fecho convexo");
    text(905, 35, "Blending functions");

    color(1, 0, 0);
    rectFill(1155, 260, 1185, 290);
    color(1, 1, 1);
    rectFill(1155, 220, 1185, 250);
    color(0, 0, 1);
    rectFill(1155, 180, 1185, 210);
    color(0, 1, 0);
    rectFill(1155, 140, 1185, 170);
    color(0.3, 0.3, 0.3);
    rectFill(1155, 100, 1185, 130);
    color(0.3, 0.3, 0.3);
    rectFill(1155, 60, 1185, 90);
    color(0, 0, 0);
    rectFill(1155, 20, 1185, 50);

    for(int i = 0; i < pontos.size(); i++)
    {
        pontos[i]->desenha();

        if(i == 0) text(pontos[0]->x - 20, pontos[0]->y + 20, "P1");
        if(i == 1) text(pontos[1]->x - 20, pontos[1]->y + 20, "P2");
        if(i == 2) text(pontos[2]->x - 20, pontos[2]->y + 20, "P3");
        if(i == 3) text(pontos[3]->x - 20, pontos[3]->y + 20, "P4");
    }

    if(pontos.size() == 4)
    {
        
    }

    if(curva)
    {
        if(mostra_curva) c->desenha();

        if(animacao)
        {
            if(continua) t += 0.005;
            color(1, 1, 1);
            c->desenha_func(t);

            if(reta_q) c->desenha_reta_q(t);
            if(reta_r) c->desenha_reta_r(t);

            if(t >= 1) t = 0;
        }

        if(grafo_de_controle) c->desenha_grafo();
        if(fecho_convexo) c->desenha_fecho();
        if(blending_functions) c->desenha_blending_functions();
    }

    color(0, 0, 0);
    text(15, 15, "t = ");
    stringstream str;
    str << t;
    string temp_str = str.str();
    char* char_type = (char*) temp_str.c_str();
    text(60, 15, char_type);
}

void render()
{
    desenha();
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
    if(key == 112) continua = !continua;
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
        //Clicando em qualquer um dos botões de funções
        if(bselecionar->colisao(mouseX, mouseY))
        {
            desativa_tudo("Adicional");
            bselecionar->ativado = 1;
            op = 1;
        }
        if(binserir->colisao(mouseX, mouseY))
        {
            desativa_tudo("Adicional");
            binserir->ativado = 1;
            op = 2;
        }
        if(bresetar->colisao(mouseX, mouseY))
        {
            desativa_tudo("Adicional");
            pontos.clear();
            curva = 0;
            t = 0;
        }

        if(bespmais->colisao(mouseX, mouseY))
        {
            if(curva)
            {
                if(c->espessura < 10) c->espessura++;
            }
        }
        if(bespmenos->colisao(mouseX, mouseY))
        {
            if(curva)
            {
                if(c->espessura > 1) c->espessura--;
            }
        }

        if(cb1->colisao(mouseX, mouseY))
        {
            cb1->ativado = !cb1->ativado;
            mostra_curva = !mostra_curva;
        }
        if(cb2->colisao(mouseX, mouseY))
        {
            cb2->ativado = !cb2->ativado;
            animacao = !animacao;
        }
        if(cb3->colisao(mouseX, mouseY))
        {
            cb3->ativado = !cb3->ativado;
            reta_r = !reta_r;
        }
        if(cb4->colisao(mouseX, mouseY))
        {
            cb4->ativado = !cb4->ativado;
            reta_q = !reta_q;
        }
        if(cb5->colisao(mouseX, mouseY))
        {
            cb5->ativado = !cb5->ativado;
            grafo_de_controle = !grafo_de_controle;
        }
        if(cb6->colisao(mouseX, mouseY))
        {
            cb6->ativado = !cb6->ativado;
            fecho_convexo = !fecho_convexo;
        }
        if(cb7->colisao(mouseX, mouseY))
        {
            cb7->ativado = !cb7->ativado;
            blending_functions = !blending_functions;
        }

        //Aplica as funções no painel
        if(p1->colisao(mouseX, mouseY))
        {
            if(op == 1) //Selecionar
            {
                desativa_tudo("Ponto");
                for(int i = 0; i < pontos.size(); ++i)
                {
                    if(pontos[i]->colisao(mouseX, mouseY))
                    {
                        pontos[i]->ativado = 1;
                        arrastando = 1;
                    }
                }
            }
            if(op == 2) //Inserir
            {
                if(pontos.size() < 4)
                {
                    Ponto *p = new Ponto(mouseX, mouseY);
                    pontos.push_back(p);
                }

                if(pontos.size() == 4)
                {
                    c = new Curva(pontos);
                    curva = 1;
                }
            }
        }
    }

    if(state == -2)
    {
        if(arrastando)
        {
            for(int i = 0; i < pontos.size(); ++i)
            {
                if(pontos[i]->ativado)
                {
                    pontos[i]->x = mouseX;
                    pontos[i]->y = mouseY;
                }
            }
        }
    }

    if(state == 1)
    {
        arrastando = 0;
    }
}

int main(void)
{
    initCanvas(&screenWidth, &screenHeight, "Trabalho C - jvmello");

    init();

    runCanvas();
}
