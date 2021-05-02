#include <iostream>
#include <windows.h> 
#include <locale.h>
using namespace std;

void gotoxy(short x, short y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    string msg = "PALMEIRAS CAMPEAO!";
    int col;
    int lin;

    col = 26;

    gotoxy(col, 5);
    cout << msg;

    for (char c : msg)
    {
        for (lin = 6; lin <= 20; lin++)
        {
            gotoxy(col, lin);
            cout << c;
            gotoxy(col, lin - 1);
            cout << " ";
            Sleep(50);
        }
        col++;
    }
    gotoxy(0, 22);
    return 0;
}

