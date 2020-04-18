//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    
*/
#include <math.h>
#include "ponto.h"

class Figura
{
   public:
        Ponto *p[8];
        float R, G, B;
        float Rp, Gp, Bp;
        int px, py;
        int ativada;
        int preenchida;
        int lados;
        Figura(int, int, float, float, float, int);
        int maiorX(int);
        int maiorY(int);
        int menorX(int);
        int menorY(int);
        void rotaciona_horario();
        void rotaciona_anti_horario();
        float  getR(void);
        float  getG(void);
        float  getB(void);
        void   draw();
        int    colisao(int, int);
};