//João Vitor Machado de Mello, matrícula 201511255, jvmello@inf.ufsm.br
/*
	Funções adicionais utilizadas para manipulação do arquivo
*/

#include "uteis.h"

//Carrega
/*vector<Figura*> carrega_arquivo()
{
	ifstream arquivo("arquivo.txt");
	string str;
	cout << "\n";
	if(getline(arquivo, str)) cout << str;

	vector<Figura*> figuras;

	while (getline(arquivo, str))
    {
        istringstream ss(str);
    }

	return figuras;
}

//Salva os dados
void salva_arquivo(vector<Figura*> figuras)
{
	ofstream arquivo_saida;

	arquivo_saida.open("arquivo.txt");
   	if(!arquivo_saida)
   	{
    	cerr << "Nao foi possivel abrir o arquivo" << endl;
      	exit(1);
   	}

   	arquivo_saida << figuras.size() << endl;
	for (int i = 0; i < figuras.size(); i++)
	{
		//String formatada
//		arquivo_saida << figuras[i]->tipo << " " << figuras[i]->px << " " << figuras[i]->py << " " << figuras[i]->tamanho << " " << figuras[i]->rotacao << " " << figuras[i]->R << " " << figuras[i]->G << " " << figuras[i]->B << endl;
	}
   	arquivo_saida.close();
}*/

