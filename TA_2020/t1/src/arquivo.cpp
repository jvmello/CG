/**
    Trabalho 1 - Computação Gráfica
    João Vitor Machado de Mello
    201511255
    jvmello@inf.ufsm.br
**/

#include "arquivo.h"

//Funções para carregar e salvar arquivos provenientes da classe "arquivo", a função para gerar arquivos do professor também
//foi utilizada

using namespace std;

//Gera um arquivo com inteiros de -128 a 127
void Arquivo::generateFile()
{
    int elems =  NUM;
    char vet[NUM]; //vetor com as amostras

    srand(time(NULL));
    for(int i = 0; i < NUM; i++) vet[i] = (rand() % 255) - 128;

    FILE *fp;
    fp = fopen("samples.dct", "wb");

    //grava o numero de elementos
    fwrite(&elems, sizeof(int), 1, fp);

    //grava os elementos
    for(int i = 0; i < NUM; i++)
    {
       fwrite(&vet[i], sizeof(char), 1, fp);
    }

    fclose(fp);
}

//carrega o arquivo
//retorna o tamanho do arquivo lido, se algo der errado, retorna 0
int Arquivo::readFile(char* vet)
{
    int elems =  NUM;

    FILE *fp;

    //reabre o arquivo para leitura
    fp = fopen("input.dct", "rb");

    if(fp == NULL) return 0;

    //le o numero de elementos
    fread(&elems, sizeof(int), 1, fp);

    //le os elementos
    for(int i=0; i < NUM; i++)
    {
       fread(&vet[i], sizeof(char), 1, fp);
    }

    fclose(fp);

    return 1;
}

//salva o dado vetor em um arquivo
//retorna o resultado do fwrite
//caso algo dê errado, retorna 0
int Arquivo::saveFile(vector<int> vet)
{
    FILE *fp = fopen("output.dct", "wb");
    if(fp == NULL) return 0;

    //grava o numero de elementos (int)
    int val = vet.size();
    fwrite(&val, sizeof(int), 1, fp);

    //grava os elementos (char = int de 8 bits com sinal)
    for(int i=0; i < vet.size(); i++)
    {
       fwrite(&vet[i], sizeof(char), 1, fp);
    }

    fclose(fp);

    return 1;
}
