//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Funções utilizadas na main, mas separadas para evitar bagunça de código

    Este arquivo contém as funções que desenham a imagem, desenham a imagem em vários canais,
    calculam histogramas e aplicam escala
*/

#include <stdio.h>
#include <stdlib.h>
#include "uteis.h"
#include "gl_canvas2d.h"

//Gambiarra pra não deixar o histograma muito desbalanceado ou fora da tela mesmo
void formata_vetor(int (&vet)[256]){
    for(int i = 0; i < 256; i++){
        if(vet[i] > 100) vet[i] = 100;
    }
}

//Desenha o histograma para a cor definida pelo vetor
void desenha_histograma(int (&vet)[256], int x, int y){
    int x_ = x;
    formata_vetor(vet);
    for(int i = 0; i < 256; i++){
        circleFill(x_, y+vet[i], 1, 10);
        x_++;
    }
    x_ = x;
    for(int i = 0; i < 255; i++){
        line(x_, y+vet[i], x_+1, y+vet[i+1]);
        x_++;
    }
}

//Calcula o histograma para a cor definida pelo campo op
//1 = R
//2 = G
//3 = B
void calcula_histograma(Bmp *img, int op, int (&vet)[256])
{
    int bytes = img->getBytesPerLine();
    unsigned char *datas = img->getImage();

    for(int i = 0; i < 256; i++) vet[i] = 0;

    for(int y=0; y<img->getHeight(); y++)
        for(int x=0; x<img->getWidth()*3; x+=3)
        {
            int pos = y*bytes + x;

            if(op == 1)
            {
                vet[(int)datas[pos]%255]++;
            }
            else if(op == 2)
            {
                vet[(int)datas[pos+1]%255]++;
            }
            else if(op == 3)
            {
                vet[(int)datas[pos+2]%255]++;
            }
        }
    int teste = 0;

    for(int i = 0; i < 256; i++) teste += vet[i];
}

//Desenha a imagem no programa
//Pega os valores iniciais de posicionamento como parâmetro
//Também pega uma escala
void desenha_imagem(Bmp *img, int x_, int y_, int escala)
{
    int bytes = img->getBytesPerLine();
    unsigned char* data = img->getImage();

    for(int y=0; y<img->getHeight(); y++)
        for(int x=0; x<img->getWidth()*3; x+=3)
        {
            int pos = y*bytes + x;
            color((float)data[pos]/(float)255,(float)data[pos+1]/(float)255,(float)data[pos+2]/(float)255);
            point(x_+((x/3)/escala),y_+(y/escala));
        }
}

//Desenha a imagem no canal desejado
//1 = R
//2 = G
//3 = B
void desenha_canal(Bmp *img, int x_, int y_, int op)
{
    int bytes = img->getBytesPerLine();
    unsigned char* data = img->getImage();
    for(int y=0; y<img->getHeight(); y++)
    for(int x=0; x<img->getWidth()*3; x+=3)
    {
        int pos = y*bytes + x;
        unsigned char tmp = data[pos];
        if(op == 1) color((float)data[pos]/(float)255,0, 0);
        if(op == 2) color(0, (float)data[pos+1]/(float)255, 0);
        if(op == 3) color(0, 0, (float)data[pos+2]/(float)255);
        point(((x/3)+x_),(y+y_));
    }
}

//Desenha a imagem em grayscale
void gray_scale(Bmp *img, int x_, int y_)
{
    int bytes = img->getBytesPerLine();
    unsigned char* data = img->getImage();
    for(int y=0; y<img->getHeight(); y++)
    for(int x=0; x<img->getWidth()*3; x+=3)
    {
        int pos = y*bytes + x;
        unsigned char tmp = data[pos];
        float luz = (0.299 * data[pos]) + (0.587 * data[pos+1]) + (0.114 * data[pos+2]);
        color((float)luz/(float)255, (float)luz/(float)255, (float)luz/(float)255);
        point(((x/3)+x_),(y+y_));
    }
}
