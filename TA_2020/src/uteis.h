//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Funções utilizadas na main, mas separadas para evitar bagunça de código

    Este arquivo contém as funções que desenham a imagem, desenham a imagem em vários canais,
    calculam histogramas e aplicam escala
*/

#include "Bmp.h"

void formata_vetor(int (&vet)[256]);
void desenha_histograma(int (&vet)[256], int x, int y);
void calcula_histograma(Bmp *img, int op, int (&vet)[256]);
void desenha_imagem(Bmp *img, int x_, int y_, int escala);
void desenha_canal(Bmp *img, int x_, int y_, int op);
void gray_scale(Bmp *img, int x_, int y_);
