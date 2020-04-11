//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    
*/

class Figura
{
   public:
        int posX[8], posY[8];
        float R, G, B;
        int colide;
        Figura(float, float, float);
        float  getR(void);
        float  getG(void);
        float  getB(void);
        void   draw();
        int    colisao(int, int);
};