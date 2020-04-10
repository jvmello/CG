/**
    Trabalho 1 - Computação Gráfica
    João Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#include "gl_canvas2d.h"
#include "funcoes.h"

//Funções auxiliares de informação ao usuário

//a cada operação feita, chama uma mensagem para ser exibida na "área de avisos"
void systemMessage(int w, int h, int op)
{
    color(1, 0, 0);
    const char *t;
    switch(op)
    {
        case 0:
            t = "";
        break;

        case 1:
            t = "Valores carregados";
        break;

        case 2:
            t = "Erro ao carregar dados";
        break;

        case 3:
            t = "Calculos aplicados";
        break;

        case 4:
            t = "Erro ao aplicar conversão";
        break;

        case 5:
            t = "Dados salvos";
        break;

        case 6:
            t = "Erro ao salvar dados";
        break;

        case 7:
            t = "Valores indisponiveis";
        break;

        default:
            t = "Erro desconhecido";
        break;
    }

    text(w, h, t); //escreve o texto escolhido pela chamada
}

