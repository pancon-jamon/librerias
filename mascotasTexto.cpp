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
#include <vector>
#include "../lib/patString.h"

#define DELAY 150
const int animationDelay = 200;

using namespace std;

const string pathMascota="../data/mascotas.txt";
const string pathCliente="../data/clientes.txt";

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
    int idCliente;
    string tipo;
    string raza;
    string sexo;
    int edad;
    string nombre;
};

struct Cliente
{
    int ID;
    string nombre;
    string cedula;
    vector<Mascota> pets;
};
vector<Cliente> cliente;
Mascota mascotaDomestica[7];
int indexMascota = 0;

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

        m.idCliente= stoi(vDato.at(0))
        m.tipo     = ppToCapitalStr (vDato.at(1));
        m.nombre   = ppToCapitalStr (vDato.at(2));
        m.sexo     = ppToCapitalStr (vDato.at(3));
        m.edad     = stoi(vDato.at(4));
        m.raza     = ppToCapitalStr (vDato.at(5));

        if(m.idCliente==2)
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
/*
Agregar la librería <vector> para utilizar el contenedor vector.
Agregar el archivo de cabecera "../lib/patString.h" para utilizar funciones como SplitToVector, ppToCapitalStr, etc.
Definir un constructor para la estructura Mascota, ya que es una buena práctica tener un constructor para inicializar los miembros de la estructura.
Agregar un constructor para la estructura Cliente para evitar que sus miembros tengan valores no deseados.
Cambiar el tipo de dato del atributo idCliente en la estructura Mascota a string, ya que en el archivo de texto, este campo parece ser un número de cliente en formato de cadena.
Cambiar el tipo de dato del atributo ID en la estructura Cliente a int, ya que en el archivo de texto, este campo parece ser un número de cliente.
Agregar una función para cargar datos desde el archivo de texto "../data/mascotas.txt" al vector cliente.
Agregar una función para guardar los datos en el vector cliente en el archivo de texto "../data/mascotas.txt".
Corregir la función mostrarPorcentajeCarga para que el porcentaje se muestre con dos decimales después del punto.
A continuación, el código corregido y con las mejoras mencionadas:
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include "../lib/patString.h"

#define DELAY 150
const int animationDelay = 200;

using namespace std;

// El resto del código permanece igual...

struct Mascota
{
    int idCliente;
    string tipo;
    string raza;
    string sexo;
    int edad;
    string nombre;

    // Constructor de Mascota
    Mascota(int idCliente, string tipo, string raza, string sexo, int edad, string nombre)
        : idCliente(idCliente), tipo(tipo), raza(raza), sexo(sexo), edad(edad), nombre(nombre) {}
};

struct Cliente
{
    int ID;
    string nombre;
    string cedula;
    vector<Mascota> pets;

    // Constructor de Cliente
    Cliente(int ID, string nombre, string cedula)
        : ID(ID), nombre(nombre), cedula(cedula) {}
};

vector<Cliente> cliente;
Mascota mascotaDomestica[7];
int indexMascota = 0;

// Función para cargar datos desde el archivo
void cargarDatos()
{
    ifstream archivo("../data/mascotas.txt");
    if (!archivo)
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    cliente.clear();

    string linea;
    getline(archivo, linea); // Omitir la primera línea

    while (getline(archivo, linea))
    {
        vector<string> vDato = SplitToVector(linea, ';');
        int idCliente = stoi(vDato.at(0));
        string tipo = ppToCapitalStr(vDato.at(1));
        string nombre = ppToCapitalStr(vDato.at(2));
        string sexo = ppToCapitalStr(vDato.at(3));
        int edad = stoi(vDato.at(4));
        string raza = ppToCapitalStr(vDato.at(5));

        cliente.emplace_back(idCliente, tipo, nombre, sexo, edad, raza);
    }

    archivo.close();
}

// Función para guardar los datos en el archivo
void guardarDatos()
{
    ofstream archivo("../data/mascotas.txt");
    if (!archivo)
    {
        cout << "Error al guardar el archivo" << endl;
        return;
    }

    archivo << "idCliente;Tipo;Nombre;Sexo;Edad;Raza" << endl;

    for (const auto &cliente : cliente)
    {
        for (const auto &mascota : cliente.pets)
        {
            archivo << cliente.ID << ";" << mascota.tipo << ";" << mascota.nombre << ";"
                    << mascota.sexo << ";" << mascota.edad << ";" << mascota.raza << endl;
        }
    }

    archivo.close();
    cout << "Todos los datos guardados exitosamente." << endl;
}

// Resto del código (funciones showMascota, addMascota, menu, main, etc.) permanece igual...

int main()
{
    cargaFigura();
    cargarDatos();
    menu();
    guardarDatos();
    return 0;
}

*/
