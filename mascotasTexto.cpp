/*
ARCHIVOS DE TEXTO, 24,25/JUL/2024
CLAUDIA COELLO
PROGRAMACION I SEGUNDO BIMESTRE
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <iostream>

#define DELAY 150
const int animationDelay = 200;

using namespace std;

enum color { blue = 1, green, turqueza, red, rosa, naranja, negro, gris };

void clearConsole()
{
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Linux o macOS
    #endif
}

string setColor(color c)
{
    HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col, c);
    return "";
}

void cargaFigura()
{
    const int vecesPresentado = 5;
    string figura = "0oo";
    string figura2 = "o0o";

    for (int frame = 0; frame <= vecesPresentado; ++frame)
    {
        cout << "\r" << figura << flush; 
        Sleep(DELAY);

        if (figura2 == "o0o")
            figura2 = "oo0";
        else if (figura2 == "oo0")
            figura2 = "0oo";
        else if (figura2 == "0oo")
            figura2 = "o0o";

        figura = figura2; 
    }

    cout << endl; 
}

struct Mascota
{
    string tipo;
    string raza;
    string sexo;
    int edad;
    string nombre;
};

Mascota mascotaDomestica[7];
int indexMascota = 0;

void getMascota(string lineArchivo, char del)
{
    Mascota m;
    stringstream ss(lineArchivo);
    string word;
    int i = 1;
    while (getline(ss, word, del))
    {
        if (i == 1)
            m.tipo = word;
        else if (i == 2)
            m.raza = word;
        else if (i == 3)
            m.sexo = word;
        else if (i == 4)
            m.edad = stoi(word);
        else if (i == 5)
            m.nombre = word;
        i++;
    }
    mascotaDomestica[indexMascota++] = m;
}

void mostrarPorcentajeCarga(int bytesLeidos, int fileSize)
{
    float porcentaje = (float)bytesLeidos / fileSize * 100;
    cout << "Progress: " << fixed << setprecision(2) << porcentaje << "%" << endl;
}

void showMascota()
{
    string pathArchivo = "../../data/mascotas.txt";
    ifstream f;
    string line;
    f.open(pathArchivo);

    if (!f.is_open())
    {
        cout << setColor(red) << "Error al abrir el archivo " << pathArchivo << endl;
        return;
    }

    cout << endl;
    cout << setw(10) << "TIPO" << "\t\t" << "RAZA" << "\t\t" << "SEXO" << "\t\t\t" << "EDAD" << "\t\t" << "NOMBRE" << endl;

    while (getline(f, line))
    {
        getMascota(line, ';');
    }

    for (int i = 0; i < indexMascota; i++)
    {
        cout <<setw(10) << mascotaDomestica[i].tipo << "\t\t"
             << mascotaDomestica[i].raza << "\t\t"
             << mascotaDomestica[i].sexo << "\t\t"
             << mascotaDomestica[i].edad << "\t\t"
             << mascotaDomestica[i].nombre << endl;
    }

    
}


void addMascota()
{
    Mascota m;
    bool edadValida = false;

    cout << endl << "Ingresa el tipo de la mascota: ";
    getline(cin, m.tipo);

    cout << "Ingresa la raza de la mascota: ";
    getline(cin, m.raza);

    cout << "Ingresa el sexo de la mascota: ";
    getline(cin, m.sexo);

    do
    {
        cout << "Ingresa la edad de la mascota: ";
        string edadStr;
        getline(cin, edadStr);
        try
        {
            m.edad = stoi(edadStr);
            edadValida = true;
        }
        catch (const exception &e)
        {
            cout << "Porfavor ingrese un numero entero" << endl;
        }
    } while (!edadValida);

    cout << "Ingresa el nombre de la mascota: ";
    getline(cin, m.nombre);

    mascotaDomestica[indexMascota++] = m;
}

void saveMascota(string pathFileName)
{
    ofstream f;
    f.open(pathFileName, ios::app); 

    if (!f.is_open())
    {
        cout << "Error al guardar el archivo " << pathFileName << endl;
        return;
    }

    int startIndex = indexMascota > 7 ? indexMascota - 7 : 0;
    for (int i = startIndex; i < indexMascota; i++)
    {
        f << mascotaDomestica[i].tipo << ";" << mascotaDomestica[i].raza << ";" << mascotaDomestica[i].sexo << ";" << mascotaDomestica[i].edad << ";" << mascotaDomestica[i].nombre << endl;
    }

    f.close();
    cout << endl << "Todos los datos guardados exitosamente." << endl;
}


bool readMascota(string pathFileName)
{
    ifstream f;
    string line;

    f.open(pathFileName);
    if (!f.is_open())
    {
        cout << "Error al abrir el archivo " << pathFileName << endl;
        return false;
    }

    while (getline(f, line))
    {
        getMascota(line, ';');
    }

    f.close();
    cout << endl << "Lectura exitosa." << endl;
    return true;
}

void menu()
{
    int opc = 0;
    string pathArchivo = "../../data/mascotas.txt";

    while (true)
    {
        string ingreso;
        cout << "---mascotas---" << endl;
        cout << setColor(blue) << "1.- Recuperar mascota" << endl << setColor(rosa) << "2.- Agregar mascota" << endl << setColor(green) << "3.- Presentar Mascota" << setColor(naranja) << endl << setColor(turqueza) << "4.- Guardar mascota" << endl << setColor(red) << "5.- Salir" << endl;
        cout << "Ingrese una opcion: ";

        getline(cin, ingreso);

        try
        {
            opc = stoi(ingreso);

            if (opc >= 1 && opc <= 5)
            {
                switch (opc)
                {
                case 1:
                    readMascota(pathArchivo);
                    break;
                case 2:
                    addMascota();
                    break;
                case 3:
                    showMascota();
                    break;
                case 4:
                    saveMascota(pathArchivo);
                    break;
                case 5:
                    cargaFigura();
                    return;
                }
            }
            else
            {
                cout << "Por favor intentelo nuevamente." << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "Por favor intentelo nuevamente." << endl;
        }
    }
}

int main()
{
    cargaFigura();
    //mostrarPorcentajeCarga();
    menu();
    return 0;
}
