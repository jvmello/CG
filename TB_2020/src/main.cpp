//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
	- Para utilizar, é preciso escolher um tipo de figura e um tipo de ação, também é possível escolher um tipo de cor (se não escolher, vai ser preta a imagem)
	- É possível aumentar/diminuir o tamanho, modificar a posição, preencher os círculos e rotacionar as linhas/quadrados (sentido horário e anti-horário)
	- Comandos de teclado
		- WASD para movimentar uma imagem (precisa estar selecionada)
		- Q e E para rotacionar a imagem em sentido anti-horário ou horário
		- Z e C para diminuir/aumentar o tamanho da imagem
		- Delete para deletar uma imagem selecionada
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
#include "figura.h"

Botao *b1, *b2, *b3;
Botao *bdeletar, *brotant, *brothor, *bsalvar, *bcarregar, *bselecionar, *bpreencher, *binserir;
Painel *p1, *p2; //paineis de desenho e menu
Cor *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8; //cores selecionaveis

int screenWidth = 1200, screenHeight = 600;
int mouseX, mouseY;
int op = 5;

vector<Figura*> figuras; //aqui ficarão as figuras mostradas

//função para desabilitar algumas funções (auxilia no controle da interface)
void desativa_tudo(char* tipo)
{
    if(tipo == "Menu")
    {
        b1->ativado = 0;
        b2->ativado = 0;
        b3->ativado = 0;
    }
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
        bdeletar->ativado = 0;
        bselecionar->ativado = 0;
        bpreencher->ativado = 0;
        binserir->ativado = 0;
    }
    if(tipo == "Figura")
    {
        for(int i = 0; i < figuras.size(); ++i)
        {
            figuras[i]->ativada = 0;
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

    b1 = new Botao(865, 530, 1185, 550, "Linha");
    b2 = new Botao(865, 505, 1185, 525, "Circulo");
    b3 = new Botao(865, 480, 1185, 500, "Quadrado");

    c1 = new Cor(865, 380, 942, 410, 1, 0, 0);
    c2 = new Cor(946, 380, 1023, 410, 0, 1, 0);
    c3 = new Cor(1027, 380, 1104, 410, 0, 0, 1);
    c4 = new Cor(1108, 380, 1185, 410, 1, 0, 1);
    c5 = new Cor(865, 345, 942, 375, 1, 1, 0);
    c6 = new Cor(946, 345, 1023, 375, 0, 1, 1);
    c7 = new Cor(1027, 345, 1104, 375, 1, 1, 1);
    c8 = new Cor(1108, 345, 1185, 375, 0, 0, 0);

    brotant = new Botao(865, 260, 1020, 280, "<-");
    brothor = new Botao(1030, 260, 1185, 280, "->");

    bdeletar = new Botao(865, 150, 1020, 190, "Deletar");
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
    text(985, 570, "Figuras:");

    b1->desenha();
    b2->desenha();
    b3->desenha();

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

    text(970, 295, "Rotacionar:");
    brotant->desenha();
    brothor->desenha();

    color(0, 0, 0);
    line(860, 240, 1190, 240);

    text(925, 210, "Funcoes adicionais:");
    bdeletar->desenha();
    bselecionar->desenha();
    bpreencher->desenha();
    binserir->desenha();

    color(0, 0, 0);
    line(860, 90, 1190, 90);

    text(985, 60, "Arquivo:");
    bsalvar->desenha();
    bcarregar->desenha();

    for(int i = 0; i < figuras.size(); ++i)
    {
        figuras[i]->desenha();
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
    if(key == 119) //W
    {
    	for(int i = 0; i < figuras.size(); i++)
    	{
    		if(figuras[i]->ativada)
    		{
				int novo_y = figuras[i]->py += 5;
    			Figura* f = new Figura(figuras[i]->px, novo_y, figuras[i]->R, figuras[i]->G, figuras[i]->B, figuras[i]->tipo, figuras[i]->tamanho, figuras[i]->rotacao);
    			figuras.erase(figuras.begin()+i);
    			f->ativada = 1;
    			figuras.push_back(f);
    		}
    	}
    }
    if(key == 97) //A
    {
    	for(int i = 0; i < figuras.size(); i++)
    	{
    		if(figuras[i]->ativada)
    		{
				int novo_x = figuras[i]->px -= 5;
	    		Figura* f = new Figura(novo_x, figuras[i]->py, figuras[i]->R, figuras[i]->G, figuras[i]->B, figuras[i]->tipo, figuras[i]->tamanho, figuras[i]->rotacao);
	    		figuras.erase(figuras.begin()+i);
	    		f->ativada = 1;
	    		figuras.push_back(f);
	    	}
    	}
    }
    if(key == 115) //S
    {
    	for(int i = 0; i < figuras.size(); i++)
    	{
    		if(figuras[i]->ativada)
    		{
				int novo_y = figuras[i]->py -= 5;
    			Figura* f = new Figura(figuras[i]->px, novo_y, figuras[i]->R, figuras[i]->G, figuras[i]->B, figuras[i]->tipo, figuras[i]->tamanho, figuras[i]->rotacao);
    			figuras.erase(figuras.begin()+i);
    			f->ativada = 1;
    			figuras.push_back(f);
    		}
    	}
    }
    if(key == 100) //D
    {
    	for(int i = 0; i < figuras.size(); i++)
    	{
    		if(figuras[i]->ativada)
    		{
	    		int novo_x = figuras[i]->px += 5;
	    		Figura* f = new Figura(novo_x, figuras[i]->py, figuras[i]->R, figuras[i]->G, figuras[i]->B, figuras[i]->tipo, figuras[i]->tamanho, figuras[i]->rotacao);
	    		figuras.erase(figuras.begin()+i);
	    		f->ativada = 1;
	    		figuras.push_back(f);
    		}
    	}
    }

    if(key == 113) //Q
    {
    	for(int i = 0; i < figuras.size(); i++)
    	{
    		if(figuras[i]->ativada) figuras[i]->rotaciona_anti_horario(30);
    	}
    }
    if(key == 101) //E
    {
    	for(int i = 0; i < figuras.size(); i++)
    	{
    		if(figuras[i]->ativada) figuras[i]->rotaciona_horario(30);
    	}
    }

    if(key == 122) //Z
    {
    	for(int i = 0; i < figuras.size(); i++)
    	{
    		if(figuras[i]->ativada)
    		{
    			int novo_tamanho = figuras[i]->tamanho -= 5;
    			Figura* f = new Figura(figuras[i]->px, figuras[i]->py, figuras[i]->R, figuras[i]->G, figuras[i]->B, figuras[i]->tipo, novo_tamanho, figuras[i]->rotacao);
    			figuras.erase(figuras.begin()+i);
    			f->ativada = 1;
    			figuras.push_back(f);
    		}
    	}
    }
    if(key == 99) //C
    {
    	for(int i = 0; i < figuras.size(); i++)
    	{
    		if(figuras[i]->ativada)
    		{
    			int novo_tamanho = figuras[i]->tamanho += 5;
    			Figura* f = new Figura(figuras[i]->px, figuras[i]->py, figuras[i]->R, figuras[i]->G, figuras[i]->B, figuras[i]->tipo, novo_tamanho, figuras[i]->rotacao);
    			figuras.erase(figuras.begin()+i);
    			f->ativada = 1;
    			figuras.push_back(f);
    		}
    	}
    }

    if(key == 112) //P
    {
    	for(int i = 0; i < figuras.size(); ++i)
        {
            if(figuras[i]->ativada)
			{
				Figura* f = new Figura(figuras[i]->px, figuras[i]->py, figuras[i]->R, figuras[i]->G, figuras[i]->B, figuras[i]->tipo, figuras[i]->tamanho, figuras[i]->rotacao);
				f->ativada = 1;
				figuras.erase(figuras.begin()+i);
				figuras.push_back(f);
			}
        }
    }

    if(key == 127) //DELETE
    {
    	for(int i = 0; i < figuras.size(); ++i)
        {
            if(figuras[i]->ativada)
			{
				figuras.erase(figuras.begin()+i);
			}
        }
    }
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

        //Clicando em qualquer uma das figuras
        if(b1->colisao(mouseX, mouseY))
        {
            desativa_tudo("Menu");
            b1->ativado = 1;
        }
        if(b2->colisao(mouseX, mouseY))
        {
            desativa_tudo("Menu");
            b2->ativado = 1;
        }
        if(b3->colisao(mouseX, mouseY))
        {
            desativa_tudo("Menu");
            b3->ativado = 1;
        }

        //Clicando em qualquer um dos botões de funções
        if(bdeletar->colisao(mouseX, mouseY))
        {
            desativa_tudo("Adicional");
            bdeletar->ativado = 1;
            op = 2;
        }
        if(bselecionar->colisao(mouseX, mouseY))
        {
            desativa_tudo("Adicional");
            bselecionar->ativado = 1;
            op = 0;
        }
        if(bpreencher->colisao(mouseX, mouseY))
        {
            desativa_tudo("Adicional");
            bpreencher->ativado = 1;
            op = 3;
        }
        if(binserir->colisao(mouseX, mouseY))
        {
            desativa_tudo("Adicional");
            binserir->ativado = 1;
            op = 1;
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

        //Botões de rotação
        if(brotant->colisao(mouseX, mouseY))
        {
            for(int i = 0; i < figuras.size(); ++i)
            {
            	if(figuras[i]->ativada) figuras[i]->rotaciona_anti_horario(30);
            }
        }
        if(brothor->colisao(mouseX, mouseY))
        {
            for(int i = 0; i < figuras.size(); ++i)
            {
            	if(figuras[i]->ativada) figuras[i]->rotaciona_horario(30);
            }
        }

		//Botões do arquivo
        if(bsalvar->colisao(mouseX, mouseY))
        {
       		salva_arquivo(figuras);
        }
		if(bcarregar->colisao(mouseX, mouseY))
        {
       		figuras = carrega_arquivo();
        }

        //Aplica as funções no painel
        if(p1->colisao(mouseX, mouseY))
        {
            if(op == 0) //selecionar
            {
                desativa_tudo("Figura");
                for(int i = 0; i < figuras.size(); ++i)
                {
                    if(figuras[i]->colisao(mouseX, mouseY))
                    {
                        figuras[i]->ativada = 1;
                    }
                }
            }
            else if(op == 1) //inserir
            {
                int t = 0;
                if(b1->ativado) t = 1;
                if(b2->ativado) t = 2;
                if(b3->ativado) t = 3;

                Figura *f = new Figura(mouseX, mouseY, cor->R, cor->G, cor->B, t, 50, 0);
                figuras.push_back(f);
            }
            else if(op == 2) //deletar
            {
                for(int i = 0; i < figuras.size(); ++i)
                {
                    if(figuras[i]->colisao(mouseX, mouseY))
                    {
                        figuras.erase(figuras.begin()+i);
                    }
                }
            }
            else if(op == 3) //preencher
            {
                for(int i = 0; i < figuras.size(); ++i)
                {
                    if(figuras[i]->colisao(mouseX, mouseY))
                    {
                        figuras[i]->Rp = cor->R;
                        figuras[i]->Gp = cor->G;
                        figuras[i]->Bp = cor->B;

                        figuras[i]->preenchida = 1;
                    }
                }
            }
        }
    }
}

int main(void)
{
    initCanvas(&screenWidth, &screenHeight, "Trabalho B - jvmello");

    init();

    runCanvas();
}
