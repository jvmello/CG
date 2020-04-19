#include "uteis.h"

vector<Figura*> carrega_arquivo()
{
	ifstream file("arquivo.txt");
	string str;
	cout << "\n";
	if(getline(file, str)) cout << str;

	vector<Figura*> figuras;

	while (getline(file, str))
    {
        istringstream ss(str);

        int tipo, px, py, tamanho, rotacao;
        float R, G, B;

        ss >> tipo >> px >> py >> tamanho >> rotacao >> R >> G >> B;
        Figura* f = new Figura(px, py, R, G, B, tipo, tamanho);
        figuras.push_back(f);
    }

	return figuras;
}

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
		arquivo_saida << figuras[i]->tipo << " " << figuras[i]->px << " " << figuras[i]->py << " " << figuras[i]->tamanho << " " << figuras[i]->rotacao << " " << figuras[i]->R << " " << figuras[i]->G << " " << figuras[i]->B << endl;
	}
   	arquivo_saida.close();
}

