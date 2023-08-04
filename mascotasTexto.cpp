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
#include "../lib/patString.h"

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

struct Persona
{
    int ID;
    string nombre;
    string cedula;
    Mascota mascotaDomestica[5];
}


void mostrarPorcentajeCarga(int bytesLeidos, int fileSize)
{
    float porcentaje = (float)bytesLeidos / fileSize * 100;
    cout << "Progreso: " << fixed << setprecision(2) << porcentaje << "%" << endl;
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

    bool firstLine = true; // Variable para verificar si es la primera línea

    while (getline(f, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue; // Omitir la primera línea
        }

        struct Mascota m;
        vector<string> vDato;
        // getMascota(line, ';');

        vDato = SplitToVector(line, ';');

        m.tipo =ppToCapitalStr (vDato.at(0));
        m.nombre =ppToCapitalStr (vDato.at(1));
        m.sexo =ppToCapitalStr (vDato.at(2));
        m.edad = stoi(vDato.at(3));
        m.raza =ppToCapitalStr (vDato.at(4));
        cout << endl<<"     "  << m.tipo<<"           "  << m.nombre<<"           "  << m.sexo <<"              "  << m.edad <<"                  "  << m.raza;
        // cout << endl << "Tipo:   " << m.tipo << "\t Nombre:" << m.nombre << "\t Sexo:" << m.sexo << "\t Edad:" << m.edad << "\t Raza:" << m.raza;
    }

    f.close();
    cout << endl << "Lectura exitosa." << endl;
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
    int fileSize = 0;
    int bytesRead = 0;

    f.open(pathFileName);
    if (!f.is_open())
    {
        cout << "Error al abrir el archivo " << pathFileName << endl;
        return false;
    }

    // Obtener el tamaño total del archivo
    f.seekg(0, ios::end);
    fileSize = f.tellg();
    f.seekg(0, ios::beg);

    while (!f.eof())
    {
        struct Mascota m;
        vector<string> vDato;
        getline(f, line);
        bytesRead += line.size() + 1; // Sumar el tamaño de la línea y un caracter de nueva línea
        
        vDato = SplitToVector(line, ';');

        m.tipo = vDato.at(0);
        m.nombre = vDato.at(1);
        m.sexo = vDato.at(2);
        m.edad = stoi(vDato.at(3));
        m.raza = vDato.at(4);

        // cout << endl << "Tipo:" << m.tipo << "\t Nombre:" << m.nombre << "\t Sexo:" << m.sexo << "\t Edad:" << m.edad << "\t Raza:" << m.raza;

        mostrarPorcentajeCarga(bytesRead, fileSize); // Mostrar el porcentaje de carga real
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
        cout << "\t\t---mascotas---" << endl;
        cout << setColor(blue) << "1.- Recuperar mascota" << endl << setColor(rosa) << "2.- Agregar mascota" << endl << setColor(green) << "3.- Presentar Mascota" << setColor(naranja) << endl << setColor(turqueza) << "4.- Guardar mascota" << endl << setColor(red) << "5.- Salir" << endl;
        cout <<setColor(naranja) <<"Ingrese una opcion: ";

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
