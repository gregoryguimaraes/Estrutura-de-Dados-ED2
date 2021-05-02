#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <ctype.h>



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
			//cout << linha << endl;
			string ultimo_nome;
			ultimo_nome = linha;

			string ultimo_nomeU = "";


			int pos;
			pos = ultimo_nome.rfind(" ");



			ultimo_nome.erase(0, pos);


			linha.erase(pos, linha.size() - 1);

			linha.insert(0, ultimo_nome + ", ");
			linha.erase(0, 1);

			//cout  << linha << endl;

			string nome;
			nome = linha;

			int i;
			int pos2;
			pos2 = nome.rfind(" ");

			
			for (char c: nome) {

				for(i = nome.size(); i>= pos2; i--)
				{

					pos2 = nome.rfind(" ");
					nome.erase(pos2, nome.size());
					nome += linha[pos2 + 1];
					nome.append(".");

				}


			}

			cout << nome << endl;






			

			/*
			for (char c : ultimo_nome) {
				ultimo_nomeU += toupper(c);
			}
			



			linha.insert(0, ultimo_nomeU + ", ");
			linha.erase(0,1);
			*/







			





		}
		arq.close();
	}
	else {
		cout << "Não foi possível abrir o arquivo.";
	}



	return 0;
}
