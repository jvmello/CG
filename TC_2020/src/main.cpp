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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#include "gl_canvas2d.h"

#include "ponto.h"
#include "botao.h"
#include "painel.h"
#include "uteis.h"
#include "cor.h"
#include "curva.h"

Botao *bresetar, *bespmais, *bespmenos, *bsalvar, *bcarregar, *bselecionar, *bpreencher, *binserir;
Painel *p1, *p2; //paineis de desenho e menu
Cor *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8; //cores selecionaveis
Curva *c;

int screenWidth = 1200, screenHeight = 600;
int mouseX, mouseY;
int op = 0;
vector <Ponto*> pontos;
int curva = 0;
int arrastando = 0;
float t = 0;

//função para desabilitar algumas funções (auxilia no controle da interface)
void desativa_tudo(char* tipo)
{
    if(tipo == "Cor")
    {
        c1->ativado = 0;
        c2->ativado = 0;
        c3->ativado = 0;
        c4->ativado = 0;
        c5->ativado = 0;
        c6->ativado = 0;
        c7->ativado = 0;
        c8->ativado = 0;
    }
    if(tipo == "Adicional")
    {
        bresetar->ativado = 0;
        bselecionar->ativado = 0;
        bpreencher->ativado = 0;
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
    sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
    sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
}

//Inicialização de elementos
void init()
{
    p1 = new Painel(10, 10, 840, 590);
    p2 = new Painel(860, 10, 1190, 590);

    c1 = new Cor(865, 380, 942, 410, 1, 0, 0);
    c2 = new Cor(946, 380, 1023, 410, 0, 1, 0);
    c3 = new Cor(1027, 380, 1104, 410, 0, 0, 1);
    c4 = new Cor(1108, 380, 1185, 410, 1, 0, 1);
    c5 = new Cor(865, 345, 942, 375, 1, 1, 0);
    c6 = new Cor(946, 345, 1023, 375, 0, 1, 1);
    c7 = new Cor(1027, 345, 1104, 375, 1, 1, 1);
    c8 = new Cor(1108, 345, 1185, 375, 0, 0, 0);

    bespmenos = new Botao(865, 260, 1020, 280, "-");
    bespmais = new Botao(1030, 260, 1185, 280, "+");

    bresetar = new Botao(865, 150, 1020, 190, "Resetar");
    bselecionar = new Botao(1030, 150, 1185, 190, "Selecionar");
    bpreencher = new Botao(865, 110, 1020, 150, "Preencher");
    binserir = new Botao(1030, 110, 1185, 150, "Inserir");

    bsalvar = new Botao(865, 20, 1020, 40, "Salvar");
    bcarregar = new Botao(1030, 20, 1185, 40, "Carregar");
}

//Função a ser chamada na render para organizar o código, basicamente desenha cada elemento
void desenha()
{
    color(0.9, 0.9, 0.9);
    rectFill(0, 0, 1210, 600);

    p1->desenha();
    p2->desenha();

    color(0, 0, 0);
    line(860, 460, 1190, 460);

    color(0, 0, 0);
    text(1000, 430, "Cores:");

    c1->desenha();
    c2->desenha();
    c3->desenha();
    c4->desenha();
    c5->desenha();
    c6->desenha();
    c7->desenha();
    c8->desenha();

    color(0, 0, 0);
    line(860, 325, 1190, 325);

    text(970, 295, "Espessura:");
    bespmais->desenha();
    bespmenos->desenha();

    color(0, 0, 0);
    line(860, 240, 1190, 240);

    text(925, 210, "Funcoes adicionais:");
    bresetar->desenha();
    bselecionar->desenha();
    bpreencher->desenha();
    binserir->desenha();

    color(0, 0, 0);
    line(860, 90, 1190, 90);

    text(985, 60, "Arquivo:");
    bsalvar->desenha();
    bcarregar->desenha();

    for(int i = 0; i < pontos.size(); ++i)
    {
        pontos[i]->desenha();
    }

        if(curva){
        c->desenha();

        t += 0.005;
        color(0, 0, 1);
        c->desenha_func(t);
        c->desenha_retas(t);

        if(t > 1) t = 0;

        //Sleep(100);
    }
}

//Pega a cor ativada
Cor* getCor()
{
    if(c1->ativado) return c1;
    if(c2->ativado) return c2;
    if(c3->ativado) return c3;
    if(c4->ativado) return c4;
    if(c5->ativado) return c5;
    if(c6->ativado) return c6;
    if(c7->ativado) return c7;
    if(c8->ativado) return c8;

    return new Cor(0, 0, 0, 0, 0, 0, 0);
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
        Cor *cor = getCor();

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
            bresetar->ativado = 1;
            curva = 0;
            pontos.clear();
            op = 3;
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

        //Clicando em qualquer uma das cores
        if(c1->colisao(mouseX, mouseY))
        {
            desativa_tudo("Cor");
            c1->ativado = 1;
        }
        if(c2->colisao(mouseX, mouseY))
        {
            desativa_tudo("Cor");
            c2->ativado = 1;
        }
        if(c3->colisao(mouseX, mouseY))
        {
            desativa_tudo("Cor");
            c3->ativado = 1;
        }
        if(c4->colisao(mouseX, mouseY))
        {
            desativa_tudo("Cor");
            c4->ativado = 1;
        }
        if(c5->colisao(mouseX, mouseY))
        {
            desativa_tudo("Cor");
            c5->ativado = 1;
        }
        if(c6->colisao(mouseX, mouseY))
        {
            desativa_tudo("Cor");
            c6->ativado = 1;
        }
        if(c7->colisao(mouseX, mouseY))
        {
            desativa_tudo("Cor");
            c7->ativado = 1;
        }
        if(c8->colisao(mouseX, mouseY))
        {
            desativa_tudo("Cor");
            c8->ativado = 1;
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
                    Ponto *p = new Ponto(mouseX, mouseY, cor->R, cor->G, cor->B);
                    pontos.push_back(p);
                }

                if(pontos.size() == 4)
                {
                    c = new Curva(pontos, 0, 0, 0);
                    curva = 1;
                }
            }
            if(op == 3) //resetar
            {
                curva = 0;
            }
            if(op == 4) //Colorir
            {

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
    initCanvas(&screenWidth, &screenHeight, "Trabalho B - jvmello");

    init();

    runCanvas();
}
