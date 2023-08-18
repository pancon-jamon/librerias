#include <iostream>
#include <unistd.h>
#include <string>
#include <windows.h>
#include <thread> // Para std::this_thread::sleep_for
using namespace std;

int n[] = {3, 2, 1, 8, 5, 6, 9, 7};
char str[] = {'j', 'a', 'h', '5', 'f', 'z', 'w', 'b'}; 
int tmp;
enum color { blue = 1, green, turqueza, red, rosa, naranja, negro, gris };
#define SLEEP 1000//500000

string setColor(color c)
{
    HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col, c);
    return "";
}

void showArray(int i, int j)
{
    system("cls"); 
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

//Podemos ordenar letras de manera similar a como ordenamos numeros, para el computador una letra y un numero son indistinguibles,
//este orden sigue la posicion de la letra en el abecedario siendo la a la mas pequeña y z la mas grande, si quisieramos ordenar letra y numeros
//primero tomaria en cuenta los numeros y luego las letras
void stringSort( int len)
{   
    for (int i = 0; i < len ; i++)
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
            system("cls");
            cout << setColor(red)<< "Cadena ordenada: " << endl ;//
            for (int k = 0; k < len; k++)
            {
                if (k == i) cout << setColor(naranja);
                cout << str[k] << " ";
                cout << setColor(blue);
            }
            cout << endl;
            this_thread::sleep_for(chrono::milliseconds(SLEEP));
            //usleep(SLEEP);
        }
    }

    char str[] = {'j', 'a', 'h', '5', 'f', 'z', 'w', 'b'}; 
    cout << setColor(turqueza) << "Cadena original: "<<endl;
    for (int i = 0; i < len; i++)
    {
        cout << setColor(negro) << str[i] << " ";
    }
}

int main()
{
    int len = sizeof(str) / sizeof(str[0]);
    cout << endl;

    stringSort(len);
    return 0;
}
