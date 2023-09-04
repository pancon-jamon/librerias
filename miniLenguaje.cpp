#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

enum color { blue = 1, green, turqueza, red, rosa, naranja, negro, gris };

const string pathFileName = "C:\\Users\\ccoel\\OneDrive\\Escritorio\\Progra I\\Bim 2\\data\\lenguaje.txt";
#define DELAY 100

string setColor(color c)
{
    HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col, c);
    return "";
}

void ppClearTerminal()
{
    cout << "\033[H\033[2J\033[3J";
    cin.clear();
    fflush(stdin);
}

bool esCaracterAceptable(char caracter)
{
    return (caracter == ' ' || caracter == '(' || caracter == ';' || caracter == '{');
}

bool validarPalabra(const string& palabra)
{
    int estado = 0;
    bool palabraValida = true;

    for (char caracter : palabra)
    {
        switch (estado)
        {
            case 0: // Estado INICIO
                if (caracter == 's')
                    estado = 1;
                else if (caracter == 'a')
                    estado = 4;
                else
                    palabraValida = false;
                break;
            case 1: // Estado S
                if (caracter == 'i')
                    estado = 2;
                else if (caracter == ' ' || caracter == '(')
                    estado = 6;
                else
                    palabraValida = false;
                break;
            case 2: // Estado SI
                if (esCaracterAceptable(caracter))
                    estado = 3;
                else
                    palabraValida = false;
                break;
            case 3: // Estado SI seguido de espacio, ( o ;
                if (!esCaracterAceptable(caracter))
                    palabraValida = false;
                break;
            case 4: // Estado A
                if (caracter == 'l')
                    estado = 5;
                else
                    palabraValida = false;
                break;
            case 5: // Estado AL
                if (caracter == 't')
                    estado = 2; // Transición de SAL a SI
                else
                    palabraValida = false;
                break;
            case 6: // Estado SI seguido de (
                if (caracter == ')')
                    estado = 3;
                else
                    palabraValida = false;
                break;
        }

        if (!palabraValida)
            break;
    }

    return (estado == 3 || estado == 6) && palabraValida; 
}



bool readArchivo()
{
    fstream f;
    string line;
    bool archivoValido = true; // Indica si el archivo es válido

    cout << "readArchivo: " << pathFileName << endl;
    f.open(pathFileName, ios_base::in);
    if (!f.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return false;
    }

    while (getline(f, line))
    {
        if (!validarPalabra(line))
        {
            cout << "Palabra incorrecta en linea: " << line << endl;
            archivoValido = false;
        }
        Sleep(DELAY);
    }

    f.close();

    return archivoValido;
}

int main()
{
    if (readArchivo())
    {
        cout << "Validacion completa." << endl;
    }
    else
    {
        cout << "Validacion fallida." << endl;
    }
    return 0;
}
