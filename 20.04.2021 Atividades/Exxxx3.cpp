#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>


using namespace std;




int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	ifstream arq;
	arq.open("lista.txt");

	if (arq.is_open())
	{
		string linha;
		while (getline(arq, linha))
		{

			string ultimo_nome;
			ultimo_nome = linha;


			int pos1;
			int pos2;
			pos1 = linha.find(" "); //Posição do primeiro ESPAÇO da string.
			pos2 = linha.rfind(" "); // Posição do primeiro ESPAÇO da string buscando de trás para frente.


			ultimo_nome.erase(0, pos2); //Apaga toda a string, mantendo apenas o último nome.
			ultimo_nome.erase(0, 1); //Apaga o espaço gerado pelo código acima no inicio da string.
			linha.erase(pos2, linha.size()); //Apaga o último nome da string.

			ultimo_nome.append(", " + linha);//Concatena o último nome mais uma vírgula ao restante do nome.

			cout << ultimo_nome << endl;
			

			
			
			

		}
		arq.close();

	}
	else {
		cout << "Não foi possível abrir o arquivo.";
	}



	return 0;
}
