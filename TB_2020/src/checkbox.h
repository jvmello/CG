//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
    Classes e funções utilizadas em checkboxes usados na tela principal
*/

class Checkbox
{
   public:
	    int x1, x2, y1, y2, ativado;
	    Checkbox(int, int, int, int);
	    int    getx1(void);
	    int    getx2(void);
	    int    gety1(void);
	    int    gety2(void);
	    void   desenha();
	    int    colisao(int, int);
};