//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
	Funções adicionais utilizadas para manipulação do arquivo
*/
#include <iostream>
using std::cerr;
using std::endl;
#include <fstream>
#include <sstream>
using std::ofstream;
#include <cstdlib>
using namespace std;

#include <vector>
#include "figura.h"

vector<Figura*> carrega_arquivo();

void salva_arquivo(vector<Figura*>);
