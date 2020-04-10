/**
    Trabalho 1 - Computação Gráfica
    João Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#include "figure.h"
#include "gl_canvas2d.h"

//Implementação das funções para a classe "figure"

//classe pré-definida
figure::figure(int a, int b, int c, int d, const char* t)
{
    x1 = a;
    y1 = b;
    x2 = c;
    y2 = d;
    titulo = t;
}

//instancia classe Button
Button::Button(int x1_, int y1_, int x2_, int y2_, const char* t) : figure(x1_, x2_, y1_, y2_, t)
{
    x1 = x1_;
    x2 = x2_;
    y1 = y1_;
    y2 = y2_;
    titulo = t;
}

//colisão do botão
int Button::colisao(int mouse_x, int mouse_y)
{
    if((mouse_x > x1 && mouse_x < x2) && ((mouse_y > y1) && (mouse_y < y2))) //botão 3(salvar)
    {
        return 1;
    }
    else return 0;
}

//desenha um botão juntamente com o texto inserido nele
void Button::draw()
{
    color(0.80, 0.80, 0.80);
    rectFill(x1, y1, x2, y2);

    color(0, 0, 0);
    text(x1, y1 + ((y2-y1)/2), titulo);
}

//redesenha o botão
void Button::newsize(int x1_, int y1_, int x2_, int y2_)
{
    x1 = x1_;
    y1 = y1_;
    x2 = x2_;
    y2 = y2_;
}

//instancia a classe CheckBox
CheckBox::CheckBox(int x1_, int y1_, int x2_, int y2_, const char* t) : figure(x1_, x2_, y1_, y2_, t)
{
    x1 = x1_;
    x2 = x2_;
    y1 = y1_;
    y2 = y2_;
    titulo = t;
    check = false;
}


//desenha um CheckBox de acordo com as coordenadas dadas
void CheckBox::draw()
{
    color(0, 0, 0);
    rect(x1, y1, x2, y2);
    text(x2 + 10, y1 + round((y2-y1)/2), titulo);

    if(check == true)
    {
        color(0, 0, 0);
        rectFill(x1 + 2, y1 + 3, x2 - 3, y2 - 3);
    }
    else
    {
        color(1, 1, 1);
        rectFill(x1 + 2, y1 + 3, x2 - 3, y2 - 3);
    }
}

//redesenha o CheckBox
void CheckBox::newsize(int x1_, int y1_, int x2_, int y2_)
{
    x1 = x1_;
    y1 = y1_;
    x2 = x2_;
    y2 = y2_;
}

//colisão do CheckBox
int CheckBox::colisao(int mouse_x, int mouse_y)
{
    if((mouse_x > x1 && mouse_x < x2) && ((mouse_y > y1) && (mouse_y < y2))) //botão 3(salvar)
    {
        if(check == true) check = false;
        else if(check == false) check = true;

        return 1;
    }

    return 0;
}

//instancia a classe Slider
Slider::Slider(int x1_, int y1_, int x2_, int y2_, const char* t) : figure(x1_, x2_, y1_, y2_, t)
{
    x1 = x1_;
    x2 = x2_;
    y1 = y1_;
    y2 = y2_;
    titulo = t;
    dist = 0;
    //acha a metade para desenhar a 'caixa' no meio da linha
    Xmid = round((x2 - x1)/2);
    Ymid = round((y2 - y1)/2);
}

//desenha um Slider de acordo com as coordenadas dadas
void Slider::draw()
{
    line(x1, Ymid+y1, x2, Ymid+y1);
    rect(x1 + Xmid - 10 + dist, Ymid + y1 - 10, x1 + Xmid + 10 + dist, Ymid + y1 + 10);

    color(1, 1, 1);
    rectFill(x1 + Xmid - 10 + dist, Ymid + y1 - 9, x1 + Xmid + 9 + dist, Ymid + y1 + 9);
}

int Slider::colisao(){}
