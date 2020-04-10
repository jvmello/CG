/**
    Trabalho 1 - Computa��o Gr�fica
    Jo�o Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#ifndef _Enrollment_h_
#define _Enrollment_h_

#include <stdio.h>
#include <stdlib.h>

//Cabe�alho para definir uma classe para cores
//ifndef aplicado para evitar conflitos com outros .h

class Cor
{
    public:
        float R, G, B;

        Cor();
        Cor(float, float, float);

        //setters
        void setR(float);
        void setG(float);
        void setB(float);
};

#endif // _Enronllment_h_
