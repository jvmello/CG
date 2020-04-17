//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br

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
#include "checkbox.h"
#include "painel.h"
#include "uteis.h"
#include "cor.h"
#include "figura.h"

Botao *b2, *b3, *b4, *b5, *b6, *b7, *b8;
Botao *bdeletar, *brotmenos, *brotmais, *bsalvar, *bcarregar, *bselecionar, *bpreencher, *binserir;
Painel *p1, *p2;
Cor *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8;

int screenWidth = 1200, screenHeight = 600;
int mouseX, mouseY;
int op = 5;

vector<Figura*> figuras;

//Rotacionar -> mudar as coordenadas de cada parte
//Fazer um preenchimento pika
//Desenhar as figuras de acordo com o que o usuário quer
//Fazer o negócio pra diminuir talvez
//Ver sobre arrastar mouse

void desativa_tudo(char* tipo)
{
    if(tipo == "Menu")
    {
        b2->ativado = 0;
        b3->ativado = 0;
        b4->ativado = 0;
        b5->ativado = 0;
        b6->ativado = 0;
        b7->ativado = 0;
        b8->ativado = 0;
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
        for(size_t i = 0; i < figuras.size(); ++i)
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

    b2 = new Botao(865, 520, 1185, 540, "Linha");
    b3 = new Botao(865, 495, 1020, 515, "3 lados");
    b4 = new Botao(1030, 495, 1185, 515, "4 lados");
    b5 = new Botao(865, 470, 1020, 490, "5 lados");
    b6 = new Botao(1030, 470, 1185, 490, "6 lados");
    b7 = new Botao(865, 445, 1020, 465, "7 lados");
    b8 = new Botao(1030, 445, 1185, 465, "8 lados");

    c1 = new Cor(865, 360, 942, 390, 1, 0, 0);
    c2 = new Cor(946, 360, 1023, 390, 0, 1, 0);
    c3 = new Cor(1027, 360, 1104, 390, 0, 0, 1);
    c4 = new Cor(1108, 360, 1185, 390, 1, 0, 1);
    c5 = new Cor(865, 325, 942, 355, 1, 1, 0);
    c6 = new Cor(946, 325, 1023, 355, 0, 1, 1);
    c7 = new Cor(1027, 325, 1104, 355, 1, 1, 1);
    c8 = new Cor(1108, 325, 1185, 355, 0, 0, 0);

    brotmenos = new Botao(865, 260, 1020, 280, "-");
    brotmais = new Botao(1030, 260, 1185, 280, "+");

    bdeletar = new Botao(865, 200, 1020, 240, "Deletar");
    bselecionar = new Botao(1030, 200, 1185, 240, "Selecionar");
    bpreencher = new Botao(865, 160, 1020, 200, "Preencher");
    binserir = new Botao(1030, 160, 1185, 200, "Inserir");

    bsalvar = new Botao(865, 120, 1185, 140, "Salvar arquivo");
    bcarregar = new Botao(865, 100, 1185, 120, "Carregar arquivo");
}

//Função a ser chamada na render para organizar o código, basicamente desenha cada elemento
void desenha()
{
    color(0.9, 0.9, 0.9);
    rectFill(0, 0, 1210, 600);

    p1->draw();
    p2->draw();

    color(0, 0, 0);
    text(985, 570, "Figuras:");

    b2->draw();
    b3->draw();
    b4->draw();
    b5->draw();
    b6->draw();
    b7->draw();
    b8->draw();

    color(0, 0, 0);
    text(985, 420, "Cores:");

    c1->draw();
    c2->draw();
    c3->draw();
    c4->draw();
    c5->draw();
    c6->draw();
    c7->draw();
    c8->draw();

    text(985, 305, "Rotacionar:");
    brotmenos->draw();
    brotmais->draw();

    //text(985, 220, "Funcoes adicionais:");
    bdeletar->draw();
    bselecionar->draw();
    bpreencher->draw();
    binserir->draw();

    //text(985, 180, "Arquivo:");
    bsalvar->draw();
    bcarregar->draw();

    for(size_t i = 0; i < figuras.size(); ++i)
    {
        figuras[i]->draw();
    }
}

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

//Funções de teclado não usadas nesse trabalho
//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
    //printf("\nTecla: %d" , key);
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
        if(b4->colisao(mouseX, mouseY))
        {
            desativa_tudo("Menu");
            b4->ativado = 1;
        }
        if(b5->colisao(mouseX, mouseY))
        {
            desativa_tudo("Menu");
            b5->ativado = 1;
        }
        if(b6->colisao(mouseX, mouseY))
        {
            desativa_tudo("Menu");
            b6->ativado = 1;
        }
        if(b7->colisao(mouseX, mouseY))
        {
            desativa_tudo("Menu");
            b7->ativado = 1;
        }
        if(b8->colisao(mouseX, mouseY))
        {
            desativa_tudo("Menu");
            b8->ativado = 1;
        }

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

        if(p1->colisao(mouseX, mouseY))
        {
            printf("%d\n\n", op);
            if(op == 0) //selecionar
            {
                desativa_tudo("Figura");
                for(size_t i = 0; i < figuras.size(); ++i)
                {
                    if(figuras[i]->colisao(mouseX, mouseY))
                    {
                        figuras[i]->ativada = 1;
                    }
                }
            }
            else if(op == 1) //inserir
            {
                int l = 0;
                if(b2->ativado) l = 2;
                if(b3->ativado) l = 3;
                if(b4->ativado) l = 4;
                if(b5->ativado) l = 5;
                if(b6->ativado) l = 6;
                if(b7->ativado) l = 7;
                if(b8->ativado) l = 8;

                Figura *f = new Figura(mouseX, mouseY, cor->R, cor->G, cor->B, l);
                figuras.push_back(f);
            }
            else if(op == 2) //deletar
            {
                for(size_t i = 0; i < figuras.size(); ++i)
                {
                    if(figuras[i]->colisao(mouseX, mouseY))
                    {
                        figuras.erase(figuras.begin()+i);
                    }
                }
            }
            else if(op == 3) //preencher
            {
                for(size_t i = 0; i < figuras.size(); ++i)
                {
                    if(figuras[i]->colisao(mouseX, mouseY))
                    {
                        //figuras[i]->Rp = cor->R;
                        //figuras[i]->Gp = cor->G;
                        //figuras[i]->Bp = cor->B;

                        //figuras[i]->preenchida = 1;
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
