#include <iostream>
#include <unistd.h>
#include <string>
#include <windows.h>
using namespace std;

int n[] = {3, 2, 1, 8, 5, 6, 9, 7};
char str[] = {'j', 'a', 'h', 'n', 'f'};  // Cambiado de string a char
int tmp;
enum color { blue = 1, green, turqueza, red, rosa, naranja, negro, gris };
#define SLEEP 90000000

string setColor(color c)
{
    HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col, c);
    return "";
}

void showArray(int i, int j)
{
    system("cls"); // Limpia la pantalla en Windows
    cout << endl << endl
         << setColor(green) << " " << string(i * 3, ' ') << "i"
         << setColor(blue) << endl << "[";
    for (int k = 0; k < 8; k++)
    {
        if (k == i) cout << setColor(green);
        if (k == j) cout << setColor(naranja);
        cout << n[k] << " " << setColor(blue);
    }
    cout << "]" << endl
         << setColor(naranja) << " " << string(j * 3, ' ') << "j" << endl;
    usleep(SLEEP);
}

void bubbleSort()
{
    showArray(0, 0);
    for (int i = 0; i < 8; i++)
    {
        for (int j = i; j < 8; j++)
        {
            showArray(i, j);
            if (n[i] > n[j])
            {
                cout << endl << string(i * 3, ' ') << setColor(naranja)
                     << "SWAP(" << n[i] << ">" << n[j] << ")" << endl;
                cin.get();
                tmp = n[i];
                n[i] = n[j];
                n[j] = tmp;
            }
        }
    }
}

void stringSort(char str[], int len)  // Agregado len para la longitud de la cadena
{
    cout << setColor(red) << "Cadena original: ";
    for (int i = 0; i < len; i++)
    {
        cout << str[i];
    }
    
    for (int i = 0; i < len - 1; i++)
    {
        int menorElemento = i;
        for (int j = i + 1; j < len; j++)
        {
            if (str[j] < str[menorElemento])
            {
                menorElemento = j;
            }
        }
        if (menorElemento != i)
        {
            swap(str[i], str[menorElemento]);
        }
    }
    cout << setColor(green) << "Cadena ordenada: ";
    for (int i = 0; i < len; i++)
    {
        cout << str[i];
    }
    cout << endl;
}

void selectSort()
{
    for (int i = 0; i < 8; i++)
    {
        int min = i;
        for (int j = i + 1; j < 8; j++)
        {
            showArray(i, j);
            if (n[min] > n[j])
            {
                min = j;
                cout << endl << setColor(red) << "min = " << n[min] << endl;
                usleep(SLEEP);
            }
        }
        cout << endl << setColor(red) << "min = " << n[min] << endl;
        cout << "SWAP(" << n[i] << " > " << n[min] << ")" << endl;
        cin.get();

        tmp = n[i];
        n[i] = n[min];
        n[min] = tmp;
    }
    showArray(0, 0);
}

int main()
{
    // selectSort();
    // bubbleSort();
    int len = sizeof(str) / sizeof(str[0]);  // Calcula la longitud de la cadena
    stringSort(str, len);

    return 0;
}

