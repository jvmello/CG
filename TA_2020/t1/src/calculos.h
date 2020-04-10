/**
    Trabalho 1 - Computação Gráfica
    João Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

using namespace std;

//Cabeçalho para definir os cálculos de conversão utilizados no programa

#define CONSTANTE_DCT (sqrt(2))
#define PI_2 6.28318530717958

vector<float> DCT(char* vet, int tam);

vector<float> IDCT(vector<float> dataDCT, int tam);

vector<float> calcDiff(vector<float> v1, vector<float> v2);

