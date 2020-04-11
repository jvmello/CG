//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas nos botões de cores na tela principal
*/

class Cor
{
   public:
        int x1, x2, y1, y2;
        float R, G, B;
        int ativado;
        Cor(int, int, int, int, float, float, float);
        int    getx1(void);
        int    getx2(void);
        int    gety1(void);
        int    gety2(void);
        float  getR(void);
        float  getG(void);
        float  getB(void);
        void   draw();
        int    colisao(int, int);
};