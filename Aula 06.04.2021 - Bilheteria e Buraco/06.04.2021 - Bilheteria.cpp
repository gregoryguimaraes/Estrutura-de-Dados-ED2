#include <iostream>
#include <stdlib.h>
#include <iomanip>

#define LIN 15
#define COL 40

using namespace std;

int main()
{
  // Fazer a bilheria de um teatro com 600 lugares, com 15 fileiras e 40 poltronas

  int i;
  int j;

  // variável que guarda a escolha do usuário
  int escolha;

  int poltrona;
  int fileira;

  int lugares_ocupados = 0;
  float faturamento = 0;

  // matriz de booleanos para poltronasa idéia é que os lugares ocupados
  // serão false, enquanto os disponiveis serão true
  bool poltronas[LIN][COL];

  // definindo valor das posições da matriz
  for (i = 0; i < LIN; ++i)
  {
    for (j = 0; j < COL; ++j)
    {
      poltronas[i][j] = true;
    }
  }

  do
  {
    cout << "0. Finalizar" << endl;
    cout << "1. Reservar poltrona" << endl;
    cout << "2. Mapa de ocupação" << endl;
    cout << "3. Faturamento" << endl;

    cin >> escolha;

    /* --------------------------- Reserva de poltrona -------------------------- */
    if (escolha == 1)
    {
      cout << endl
           << "As poltronas estão dispostas em 15 fileiras com 40 poltronas cada." << endl;

      cout << "Selecione o número da fileira desejada (Até 15): ";
      cin >> fileira;

      cout << "Agora selecione o número da poltrona (Até 40): ";
      cin >> poltrona;

      --poltrona;
      --fileira;

      if (poltronas[fileira][poltrona])
      {
        poltronas[fileira][poltrona] = false;

        if (fileira >= 1 && fileira <= 5)
        {
          faturamento += 50;
        }
        else if (fileira >= 6 && fileira <= 10)
        {
          faturamento += 30;
        }
        else if (fileira >= 11 && fileira <= 15)
        {
          faturamento += 15;
        }

        lugares_ocupados++;

        cout << endl
             << "Reserva da poltrona realizada com sucesso! Faça outra escolha para continuar." << endl;
      }
      else
      {
        cout << endl
             << "Erro! Essa poltrona já estava reservada! Faça outra escolha para continuar." << endl;
      }
    }

    /* ---------------------------- mapa de reservas ---------------------------- */
    else if (escolha == 2)
    {
      for (i = 0; i < LIN; ++i)
      {
        for (j = 0; j < COL; ++j)
        {
          if (poltronas[i][j])
            cout << ".";
          else
            cout << "#";
          cout << " | ";
        }
        cout << endl;
      }
    }

    /* -------------------------- mostrando faturamento ------------------------- */
    else if (escolha == 3)
    {
      cout << endl
           << "Mostrando o faturamento e a quantidade de poltronas ocupadas: " << endl;

      cout << endl
           << "Número de poltronas ocupadas: " << lugares_ocupados;
      cout << endl
           << "Faturamento total: R$ " << setprecision(2) << fixed << faturamento << endl;
    }

  } while (escolha != 0);

  return 0;
}