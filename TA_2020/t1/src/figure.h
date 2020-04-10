/**
    Trabalho 1 - Computação Gráfica
    João Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//Classe para uma figura, esta pode ser um botão, um checklist ou um slider(não utilizado)

class figure
{
    private:

    public:
        int x1, y1, x2, y2;
        const char *titulo;

        figure(int, int, int, int, const char*);
};

class CheckBox : public figure
{
    public:
        bool check;
        CheckBox(int, int, int, int, const char*);

        void draw();
        void newsize(int, int, int, int);
        int colisao(int, int);
};

class Button : public figure
{
    public:
        Button(int, int, int, int, const char*);

        void draw();
        void newsize(int, int, int, int);
        int colisao(int, int);
};



class Slider : public figure
{
   public:
      int dist;
      int Xmid, Ymid;

      Slider(int, int, int, int, const char*);

      void draw();
      int colisao();
};
