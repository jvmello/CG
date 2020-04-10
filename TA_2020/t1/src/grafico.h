/**
    Trabalho 1 - Computação Gráfica
    João Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "gl_canvas2d.h"
#include "cor.h"

//Cabeçalho para a classe que define um gráfico

using namespace std;

class Grafico
{
    public:
        int x1, x2, y1, y2, points, grid;
        vector<float> vec;
        const char* titulo;

        Grafico();
        Grafico(int, int, int, int, const char*);

        void draw(Cor*, Cor*);
        void setVec(vector<float>);
        void setPoints();
        void setGrid();
        void newsize(int, int, int, int);
};
