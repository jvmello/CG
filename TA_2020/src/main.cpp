//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
 * Instruções:
 * Clicar no botão "Carregar" para carregar qualquer das imagens (img1 e img2);
 * Tá meio invertido pelo Y 'inverso';
 * Clicar em qualquer um dos checkboxes para mostrar a imagem em canais separados;
 * Clicar em qualquer um dos botões + e - para aumentar e diminuir a escala.


 Requisitos implementados:
 * Histograma;
 * Canais de cor;
 * Escala.
*/

#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

#include "bmp.h"
#include "botao.h"
#include "checkbox.h"
#include "uteis.h"

Bmp *img1, *img2;
unsigned char *data;
Botao *b1, *b2;
Botao *s1, *s2, *s3, *s4;
Checkbox *cb1, *cb2, *cb3, *cb4, *cb5, *cb6, *cb7, *cb8;
int R1[256], R2[256], G1[256], G2[256], B1[256], B2[256];
int carrega_imagem1 = 0, carrega_imagem2 = 0;
int escala_img1 = 1, escala_img2 = 1;

int screenWidth = 1200, screenHeight = 600;
int mouseX, mouseY;
char *texto_escala_img1 = "", *texto_escala_img2 = "";

void DrawMouseScreenCoords()
{
    char str[100];
    sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
    sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
}

//Inicialização de elementos
void init()
{
    img1 = new Bmp(".\\gl_1_canvasGlut\\img1.bmp");
    img1->convertBGRtoRGB();

    b1 = new Botao(1080, 50, 1160, 80, "Carregar");
    s1 = new Botao(1085, 130, 1100, 145, "-");
    s2 = new Botao(1130, 130, 1145, 145, "+");

    cb1 = new Checkbox(700, 100, 715, 115);
    cb2 = new Checkbox(700, 80, 715, 95);
    cb3 = new Checkbox(700, 60, 715, 75);
    cb4 = new Checkbox(700, 40, 715, 55);

    img2 = new Bmp(".\\gl_1_canvasGlut\\img2.bmp");
    img2->convertBGRtoRGB();

    b2 = new Botao(1080, 400, 1160, 430, "Carregar");
    s3 = new Botao(1085, 480, 1100, 495, "-");
    s4 = new Botao(1130, 480, 1145, 495, "+");

    cb5 = new Checkbox(700, 380, 715, 395);
    cb6 = new Checkbox(700, 360, 715, 375);
    cb7 = new Checkbox(700, 340, 715, 355);
    cb8 = new Checkbox(700, 320, 715, 335);

    calcula_histograma(img1, 1, R1);
    calcula_histograma(img1, 2, G1);
    calcula_histograma(img1, 3, B1);

    calcula_histograma(img2, 1, R2);
    calcula_histograma(img2, 2, G2);
    calcula_histograma(img2, 3, B2);
}

//Função a ser chamada na render para organizar o código, basicamente desenha cada elemento
void desenha()
{
    b1->draw();
    text(1080, 100, "Imagem 1");

    s1->draw();
    s2->draw();
    text(1082, 160, "Escala:");
    if(escala_img1 == 1) texto_escala_img1 = "100";
    if(escala_img1 == 2) texto_escala_img1 = "50";
    if(escala_img1 == 4) texto_escala_img1 = "25";
    text(1102, 135, texto_escala_img1);

    cb1->draw();
    text(720, 40, "Grayscale");
    cb2->draw();
    text(720, 60, "Canal B");
    cb3->draw();
    text(720, 80, "Canal G");
    cb4->draw();
    text(720, 100, "Canal R");

    b2->draw();
    text(1080, 450, "Imagem 2");

    s3->draw();
    s4->draw();
    text(1082, 510, "Escala:");
    if(escala_img2 == 1) texto_escala_img2 = "100";
    if(escala_img2 == 2) texto_escala_img2 = "50";
    if(escala_img2 == 4) texto_escala_img2 = "25";
    text(1102, 485, texto_escala_img2);

    cb5->draw();
    text(720, 320, "Grayscale");
    cb6->draw();
    text(720, 340, "Canal B");
    cb7->draw();
    text(720, 360, "Canal G");
    cb8->draw();
    text(720, 380, "Canal R");

    if(carrega_imagem1)
    {
        desenha_imagem(img1, 10, 40, escala_img1);
        if(cb1->ativado)
        {
            desenha_canal(img1, 120, 190, 1);
            color(1, 0, 0);
            desenha_histograma(R1, 230, 190);
        }
        if(cb2->ativado)
        {
            desenha_canal(img1, 120, 40, 2);
            color(0, 1, 0);
            desenha_histograma(G1, 230, 40);
        }

        if(cb3->ativado)
        {
            desenha_canal(img1, 500, 190, 3);
            color(0, 0, 1);
            desenha_histograma(B1, 610, 190);
        }
        if(cb4->ativado)
        {
            gray_scale(img1, 500, 40);
        }
    }

    if(carrega_imagem2)
    {
        desenha_imagem(img2, 10, 320, escala_img2);
        if(cb5->ativado)
        {
            desenha_canal(img2, 120, 470, 1);
            color(1, 0, 0);
            desenha_histograma(R2, 230, 470);
        }
        if(cb6->ativado)
        {
            desenha_canal(img2, 120, 320, 2);
            color(0, 1, 0);
            desenha_histograma(G2, 230, 320);
        }

        if(cb7->ativado)
        {
            desenha_canal(img2, 500, 470, 3);
            color(0, 0, 1);
            desenha_histograma(B2, 610, 470);
        }
        if(cb8->ativado)
        {
            gray_scale(img2, 500, 320);
        }
    }
}

void render()
{
    int bytes = img1->getBytesPerLine();
    color(0, 0, 0);

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
        if(b1->colisao(mouseX, mouseY))  carrega_imagem1 = 1;
        if(cb1->colisao(mouseX, mouseY)) cb1->ativado = !cb1->ativado;
        if(cb2->colisao(mouseX, mouseY)) cb2->ativado = !cb2->ativado;
        if(cb3->colisao(mouseX, mouseY)) cb3->ativado = !cb3->ativado;
        if(cb4->colisao(mouseX, mouseY)) cb4->ativado = !cb4->ativado;

        if(s1->colisao(mouseX, mouseY)) //Botão -
        {
            if(escala_img1 < 4) escala_img1*=2;
        }

        if(s2->colisao(mouseX, mouseY)) //Botão +
        {
            if(escala_img1 > 1) escala_img1/=2;
        }

        if(b2->colisao(mouseX, mouseY))  carrega_imagem2 = 1;
        if(cb5->colisao(mouseX, mouseY)) cb5->ativado = !cb5->ativado;
        if(cb6->colisao(mouseX, mouseY)) cb6->ativado = !cb6->ativado;
        if(cb7->colisao(mouseX, mouseY)) cb7->ativado = !cb7->ativado;
        if(cb8->colisao(mouseX, mouseY)) cb8->ativado = !cb8->ativado;

        if(s3->colisao(mouseX, mouseY)) //Botão -
        {
            if(escala_img2 < 4) escala_img2*=2;
        }

        if(s4->colisao(mouseX, mouseY)) //Botão +
        {
            if(escala_img2 > 1) escala_img2/=2;
        }
    }
}

int main(void)
{
    initCanvas(&screenWidth, &screenHeight, "Trabalho A - jvmello");

    init();

    runCanvas();
}
