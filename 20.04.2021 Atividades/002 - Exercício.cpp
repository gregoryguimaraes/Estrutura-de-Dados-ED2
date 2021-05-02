#include <iostream>
#include <locale.h>
#include <string>
using namespace std;



void verifica(string s) {
   

        if (s == string(s.rbegin(), s.rend())) {
            cout << "A palavra digitada e um palindromo." << endl;
        }
        else {
            cout << "A palavra digitada nao e um palindromo.";
        }
    }
   





int main(int argc, char** argv) {
	setlocale(LC_ALL, "");

    string str;
    int pos;
    string msg;
   
    cout << "Digite uma palavra para verificacao de palindromo" << endl;


    getline(cin, str);

    //verificação de espaços
    pos = str.find(" "); 

    if (pos == -1) {
        msg = str;
    }
    else {
        cout << "Nao e permitido frases com espaco.";
    }

    cout << msg << endl;


    //resultado final
    verifica(msg);

   


}
