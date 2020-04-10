/**
    Trabalho 1 - Computação Gráfica
    João Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"
#include "figure.h"
#include "calculos.h"
#include "funcoes.h"
#include "grafico.h"
#include "gl_canvas2d.h"
#include "global.h"
#include "cor.h"

using namespace std;

Arquivo* a = new Arquivo();

//variaveis globais
int op; //operações de mensagens do sistema
int func = 0, cor1 = 0, cor2 = 0;
vector<int> valoresOriginais;
char v[4];

int w = 1280, h = 720;

//Declaração dos objetos utilizados

Cor* c1 = new Cor();
Cor* c2 = new Cor();

Grafico* g1 = new Grafico(round(w*0.01), round(h*0.7), round(w*0.36), round(h*0.97), "Origem");
Grafico* g2 = new Grafico(round(w*0.01), round(h*0.41), round(w*0.36), round(h*0.68), "DCT");
Grafico* g3 = new Grafico(round(w*0.38), round(h*0.7), round(w*0.73), round(h*0.97), "IDCT");
Grafico* g4 = new Grafico(round(w*0.38), round(h*0.41), round(w*0.73), round(h*0.68), "Diferencas");

Button* b1 = new Button(round(w*0.01), round(h*0.34), round(w*0.1), round(h*0.39), "Carregar");
Button* b2 = new Button(round(w*0.12), round(h*0.34), round(w*0.21), round(h*0.39), "Aplicar");
Button* b3 = new Button(round(w*0.23), round(h*0.34), round(w*0.32), round(h*0.39), "Salvar");
Button* b4 = new Button(round(w*0.34), round(h*0.34), round(w*0.43), round(h*0.39), "Funcoes");
Button* b5 = new Button(round(w*0.01), round(h*0.2), round(w*0.02), round(h*0.26), "<");
Button* b6 = new Button(round(w*0.07), round(h*0.2), round(w*0.08), round(h*0.26), ">");
Button* b7 = new Button(round(w*0.28), round(h*0.2), round(w*0.29), round(h*0.26), "<");
Button* b8 = new Button(round(w*0.34), round(h*0.2), round(w*0.35), round(h*0.26), ">");

CheckBox* cb1 = new CheckBox(round(w*0.01), round(h*0.27), round(w*0.1), round(h*0.32), "Pontos");
CheckBox* cb2 = new CheckBox(round(w*0.23), round(h*0.27), round(w*0.32), round(h*0.32), "Grid");

vector<float> valoresDCT(a->n);
vector<float> valoresIDCT(a->n);

//modifica valor das cores
void cores()
{
    switch(cor1)
    {
        case 0:
            c1->setR(0);
            c1->setG(0);
            c1->setB(0);
        break;

        case 1:
            c1->setR(1);
            c1->setG(0);
            c1->setB(0);
        break;

        case 2:
            c1->setR(0);
            c1->setG(1);
            c1->setB(0);
        break;

        case 3:
            c1->setR(0);
            c1->setG(0);
            c1->setB(1);
        break;

        case 4:
            c1->setR(0);
            c1->setG(1);
            c1->setB(1);
        break;

        case 5:
            c1->setR(1);
            c1->setG(0);
            c1->setB(1);
        break;

        case 6:
            c1->setR(1);
            c1->setG(1);
            c1->setB(0);
        break;
    }

    switch(cor2)
    {
        case 0:
            c2->setR(0);
            c2->setG(0);
            c2->setB(0);
        break;

        case 1:
            c2->setR(1);
            c2->setG(0);
            c2->setB(0);
        break;

        case 2:
            c2->setR(0);
            c2->setG(1);
            c2->setB(0);
        break;

        case 3:
            c2->setR(0);
            c2->setG(0);
            c2->setB(1);
        break;

        case 4:
            c2->setR(0);
            c2->setG(1);
            c2->setB(1);
        break;

        case 5:
            c2->setR(1);
            c2->setG(0);
            c2->setB(1);
        break;

        case 6:
            c2->setR(1);
            c2->setG(1);
            c2->setB(0);
        break;
    }
}

//desenha funções base da DCT
void funcoes()
{
    for(int u = 0; u < 8; u++)
    {
        for(float x = 0; x < 8; x+=0.01)
        {
            color(0, 0, 0);
            float soma = 0;
            soma = cos((((2*x) + 1) * u * (3.14))/16);
            circleFill((w*0.75) + (x*35), (h*0.13 * u + (soma*h*0.05)), 1, 40);
        }
    }
}

//desenha a interface
void draw()
{
    //interface inicial, chamando a mensagem, as cores e os objetos envolvidos

    systemMessage(round(w * 0.48), round(h * 0.34), op);

    cores();
    b1->draw();
    b2->draw();
    b3->draw();
    b4->draw();
    b5->draw();
    b6->draw();
    b7->draw();
    b8->draw();

    g1->draw(c1, c2);
    g2->draw(c1, c2);
    g3->draw(c1, c2);
    g4->draw(c1, c2);

    cb1->draw();
    cb2->draw();

    color(0, 0, 0);
    text(round(w*0.01), round(h*0.18), "Cor das linhas");
    text(round(w*0.28), round(h*0.18), "Cor dos pontos");
    color(c1->R, c1->G, c1->B);
    rectFill(round(w*0.03), round(h*0.2), round(w*0.06), round(h*0.26));
    color(c2->R, c2->G, c2->B);
    rectFill(round(w*0.3), round(h*0.2), round(w*0.33), round(h*0.26));
    color(1, 1, 1);

    //redimensiona tudo de acordo com o tamanho da tela
    g1->newsize(round(w*0.01), round(h*0.7), round(w*0.36), round(h*0.97));
    g2->newsize(round(w*0.01), round(h*0.41), round(w*0.36), round(h*0.68));
    g3->newsize(round(w*0.38), round(h*0.7), round(w*0.73), round(h*0.97));
    g4->newsize(round(w*0.38), round(h*0.41), round(w*0.73), round(h*0.68));

    b1->newsize(round(w*0.01), round(h*0.34), round(w*0.1), round(h*0.39));
    b2->newsize(round(w*0.12), round(h*0.34), round(w*0.21), round(h*0.39));
    b3->newsize(round(w*0.23), round(h*0.34), round(w*0.32), round(h*0.39));
    b4->newsize(round(w*0.34), round(h*0.34), round(w*0.43), round(h*0.39));
    b5->newsize(round(w*0.01), round(h*0.2), round(w*0.02), round(h*0.26));
    b6->newsize(round(w*0.07), round(h*0.2), round(w*0.08), round(h*0.26));
    b7->newsize(round(w*0.28), round(h*0.2), round(w*0.29), round(h*0.26));
    b8->newsize(round(w*0.34), round(h*0.2), round(w*0.35), round(h*0.26));

    cb1->newsize(round(w*0.01), round(h*0.27), round(w*0.04), round(h*0.32));
    cb2->newsize(round(w*0.23), round(h*0.27), round(w*0.26), round(h*0.32));

    if(func == 1) funcoes();
}

void render()
{
    draw();
}

//callback para receber a largura e altura atuais do sistema
void display_size(int largura, int altura)
{
    w = largura;
    h = altura;
}

//recebe e trata o movimento do wheel do mouse
void mw(int direction)
{
    //if(slider1->colisao()){}
}

void keyboard(int key){}
void keyboardUp(int key){}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int b, int state, int x, int y)
{
    y = (h - y); //inverte o valor de y recebido

    //Trata colisão com botões e checkboxes
    if(b == 0 && state == 0)
    {
        if(b1->colisao(x, y)) //carregar
        {
            valoresOriginais.resize(a->n);

            if(a->readFile(v)) op = 1; //sucesso
            else{
                op = 2; //erro
                return;
            }

            for(int i = 0; i < a->n; i++) valoresOriginais[i] = v[i];
        }

        if(b2->colisao(x, y)) //aplicar
        {
            valoresDCT = DCT(v, a->n);
            valoresIDCT = IDCT(valoresDCT, a->n);

            if(valoresDCT.empty() || valoresIDCT.empty() || a->n == 0)
            {
                op = 4; //erro
                return;
            }
            else
            {
                op = 3; //sucesso
            }

            std::vector<float> doubleVec(valoresOriginais.begin(), valoresOriginais.end()); //facilita a conversão
            g1->setVec(doubleVec);
            g2->setVec(valoresDCT);
            g3->setVec(valoresIDCT);
            g4->setVec(calcDiff(doubleVec, valoresIDCT));
        }

        if(b3->colisao(x, y)) //salvar
        {
            std::vector<int> doubleVec(valoresIDCT.begin(), valoresIDCT.end());

            if(a->saveFile(doubleVec)) op = 5; //sucesso
            else op = 6; //erro
        }

        if(b4->colisao(x, y)) //funções
        {
            if(func == 0) func = 1;
            else if(func == 1) func = 0;
        }

        //alternadores de cores
        if(b5->colisao(x, y))
        {
            if(cor1 > 0) cor1--;
            else if(cor1 == 0) cor1 = 6;
        }

        if(b6->colisao(x, y))
        {
            if(cor1 < 6) cor1++;
            else if(cor1 == 6) cor1 = 0;
        }

        if(b7->colisao(x, y))
        {
            if(cor2 > 0) cor2--;
            else if(cor2 == 0) cor2 = 6;
        }

        if(b8->colisao(x, y))
        {
            if(cor2 < 6) cor2++;
            else if(cor2 == 6) cor2 = 0;
        }

        //pontos(sim ou não)
        if(cb1->colisao(x, y))
        {
            g1->setPoints();
            g2->setPoints();
            g3->setPoints();
            g4->setPoints();
        }

        //grid(sim ou não)
        if(cb2->colisao(x, y))
        {
            g1->setGrid();
            g2->setGrid();
            g3->setGrid();
            g4->setGrid();
        }
    }
}

int main(void)
{
    //a->generateFile();
    initCanvas(1280, 720, "Calculo da DCT - jvmello");
    runCanvas();
}
