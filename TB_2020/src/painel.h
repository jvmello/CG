//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas nos paineis da tela principal
*/

class Painel
{
   public:
        int x1, x2, y1, y2;
        Painel(int, int, int, int);
        int    getx1(void);
        int    getx2(void);
        int    gety1(void);
        int    gety2(void);
        void   draw();
        int    colisao(int, int);
};