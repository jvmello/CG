/**
    Trabalho 1 - Computação Gráfica
    João Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"
#include "figure.h"
#include "calculos.h"

//Funções para calcular DCT e IDCT

using namespace std;

//calcula a DCT
//retorna o vetor já convertido
//caso haja algum erro, retorna um vetor vazio
vector<float> DCT(char* vet, int tam)
{
    int x, u;
    float c;

    vector<float> valoresDCT;

    if(vet == NULL || tam == 0)
    {
        return valoresDCT;
    }

    //se o vetor pode seguir, aloca-se o número de posições pra ele e inicia-se o cálculo
    valoresDCT.resize(tam);

    for (x = 0; x < tam; x++)
    {
        if(x == 0)
            c = 1;
        else
            c = CONSTANTE_DCT;

        for(u = 0; u < tam; u++)
        {
            valoresDCT[x] += ((int)vet[u]) * cos(((2 * u) + 1) * x * (PI_2 / 2) / (2*tam));
        }

        valoresDCT[x] = valoresDCT[x] * 1/2 * c;
    }

    return valoresDCT;
}

//calcula a IDCT
//retorna o vetor já convertido(em números inteiros)
//caso haja algum erro, retorna um vetor vazio
vector<float> IDCT(vector<float> valoresDCT, int tam)
{
    int x, u;
    float c;

    vector<float> valoresIDCT;
    vector<float> valores;

    if(valoresDCT.empty() || tam == 0)
    {
        return valores;
    }

    //se o vetor pode seguir, aloca-se o número de posições pra ele e inicia-se o cálculo
    valoresIDCT.resize(tam);
    valores.resize(tam);

    for(x = 0; x < tam; x++)
    {
        for(u = 0; u < tam; u++)
        {
            if(u == 0) c = 1;

            else c = CONSTANTE_DCT;

            valoresIDCT[x] += valoresDCT[u] * cos(((2 * x) + 1) * u * (PI_2 / 2) / (2*tam)) * c;
        }

        valores[x] = round(valoresIDCT[x] * 1/2); //realiza a conversão e manda um inteiro arredondado como retorno
    }

    return valores;
}

vector<float> calcDiff(vector<float> v1, vector<float> v2)
{
    vector<float> diff;

    if(v1.size() != v2.size()) return diff;

    diff.resize(v1.size());

    for(int i = 0; i < v1.size(); i++) diff[i] = v2[i] - v1[i];

    return diff;
}
