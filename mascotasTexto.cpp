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

#define DELAY 10000
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

string cargaFigura()
{
    const int totalFrames = 10;
    string figura = "0oo";
    string figura2 = "o0o";

    for (int frame = 0; frame <= totalFrames; ++frame)
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
    return ""; // El tipo de retorno de la función debe ser string, se devuelve una cadena vacía
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
    int fileSize = 0;
    f.open(pathArchivo);

    const int barraCarga = 1024;
    char barra[barraCarga];
    int porcentaje = 0;  

    if (!f.is_open())
    {
        cout <<setColor(red)<< "Error al abrir el archivo " << pathArchivo << endl;
        return;
    }

    f.seekg(0, ios::end); // busca el fin del archivo
    fileSize = f.tellg();      // obtiene el tamaño del archivo en bytes
    f.seekg(0, ios::beg); // busca el inicio del archivo

    
    cout << endl << setw(10) << "TIPO" << "\t RAZA" << "\t SEXO" << "\t EDAD" << "\t NOMBRE \n";
    while (!f.eof()) // siempre que no esté al final
    {
        f.read(barra, barraCarga);
        int bytesLeidos = f.gcount();

        porcentaje += bytesLeidos;
        mostrarPorcentajeCarga(porcentaje, fileSize);

        for (int i = 0; i < bytesLeidos; i++)
        {
            cout << barra[i];
        }
    }

    f.close();
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
            cout << "Valor inválido. Por favor, ingresa un número entero." << endl;
        }
    } while (!edadValida);

    cout << "Ingresa el nombre de la mascota: ";
    getline(cin, m.nombre);

    mascotaDomestica[indexMascota++] = m;
}


bool saveMascota(string pathFileName)
{
    ofstream f;
    f.open(pathFileName);
    if (!f.is_open())
    {
        cout << "Error al guardar el archivo " << pathFileName << endl;
        return false;
    }

    for (int i = 0; i < indexMascota; i++)
    {
        f << mascotaDomestica[i].tipo << ";" << mascotaDomestica[i].raza << ";" << mascotaDomestica[i].sexo << ";" << mascotaDomestica[i].edad << ";" << mascotaDomestica[i].nombre << endl;
    }

    f.close();
    cout << endl << "Todos los datos guardados exitosamente." << endl;
    return true;
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
        cout <<setColor(blue)<<"1.- Recuperar mascota" << endl <<setColor(rosa)<<"2.- Agregar mascota" << endl << setColor(green)<<"3.- Presentar Mascota" <<setColor(naranja)<<endl <<setColor(turqueza)<< "4.- Guardar mascota" << endl <<setColor(red)<<"5.- Salir" << endl;
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
                cout << "Opción inválida, por favor intentelo nuevamente." << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "Opción inválida, por favor inténtelo nuevamente." << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}
