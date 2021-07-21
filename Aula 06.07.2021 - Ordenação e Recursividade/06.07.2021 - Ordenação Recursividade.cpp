#include <iostream>
using namespace std;

void insertion_sort(int n, int *a)
{
	int atual, valor, prox;
	for (atual = 1; atual < n; atual++)
	{
		valor = a[atual];
		prox = atual - 1;

		while (prox >= 0 && a[prox] > valor)
		{
			a[prox + 1] = a[prox];
			prox--;
		}
		a[prox + 1] = valor;
	}
}

void insertion_sort_recurs(int n, int *a)
{
	if (n <= 1)
		return;

	int atual, valor, prox;

	atual = n - 1;
	valor = a[atual];
	prox = atual - 1;

	insertion_sort_recurs(atual, a);

	while (prox >= 0 && a[prox] > valor)
	{
		a[prox + 1] = a[prox];
		prox--;
	}
	a[prox + 1] = valor;
}

void print(int n, int *a)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "Elemento: " << i << " = " << a[i] << endl;
	}
	cout << "------------------" << endl;
}

int main(int argc, char **argv)
{
	int v[8] = {26, 49, 38, 13, 58, 87, 34, 93};
	print(8, v);

	insertion_sort_recurs(8, v);
	print(8, v);
}