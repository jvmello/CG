/**
    Trabalho 1 - Computa��o Gr�fica
    Jo�o Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#define NUM 4

using namespace std;

//Classe para manipula��o de arquivos, contendo fun��es para carregar e salvar os mesmos

class Arquivo
{
    public:
        int n = NUM;

        void generateFile();
        int readFile(char*);
        int saveFile(vector<int>);
};
