#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <conio.h>
#include "windows.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int Q = 6; // Estados del autómata
const int L = 256; // Tamaño del alfabeto (ASCII)
const int ER = -1; // Estado de error
#define TIEMPO 100000
#define DELAY 150
const int animationDelay = 200;

string nombreArchivo = "armadas.txt"; // Reemplaza con el nombre de tu archivo
enum color { blue = 1, green, turqueza, red, rosa, naranja, negro, gris };

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

enum escapes 
{ 
	BELL 		= '\a', 
	RETROCESO 	= '\b',
	TAB 		= '\t',
	ENTER 		= '\n', 
	TAB_V 		= '\v', 
	RETORNO 	= '\r'
};

void LoadingBar(int size)
{ 
    char barra[size];
    float porcentaje = (float)100/(float)size;
    for (int i = 0; i <= size; i++)
        barra[i]=' ';
    
    for (int i = 0; i <= size; i++)
    {
        barra[i]='#';
        printf("%c%c [%s]  %.0f %%", RETORNO, TAB, barra, i*porcentaje);
        usleep(TIEMPO*2);
    }
}

int const mt[Q][L] =
{
    //   a    v    i    ó    n    b    o    m    b    a    r    d    e    r    o   c   o   m   b   o   y   s   \n  otros
    {   1,   ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER, ER, ER, ER, ER, ER, ER, ER, ER }, // q0 - Estado inicial
    {   ER,  2,   ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER, ER, ER, ER, ER, ER, ER, ER, ER }, // q1 - Encontrado 'a'
    {   ER,  ER,  3,   ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER, ER, ER, ER, ER, ER, ER, ER, ER }, // q2 - Encontrado 'v'
    {   ER,  ER,  ER,  4,   ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER, ER, ER, ER, ER, ER, ER, ER, ER }, // q3 - Encontrado 'i'
    {   ER,  ER,  ER,  ER,  5,   ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER, ER, ER, ER, ER, ER, ER, ER, ER }, // q4 - Encontrado 'ó'
    {   ER,  ER,  ER,  ER,  ER,  6,   ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER, ER, ER, ER, ER, ER, ER, ER, ER }, // q5 - Encontrado 'n'
    // Estados finales
    {   ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER,  ER, ER, ER, ER, ER, ER, ER, ER, ER }, // q6 - Estado final para "avión bombardero"
};

// Función para identificar el tipo de armada en el texto
string IdentificarTipoArmada(const string& texto) 
{
    int estadoActual = 0;
    int inicioTipoArmada = -1;

    for (int i = 0; i < texto.length(); i++) {
        char caracter = texto[i];
        int columna = 0;

        // Determina la columna en la matriz de transición
        if (caracter == ' ') columna = 1;
        else if (caracter == ':') columna = 2;

        estadoActual = mt[estadoActual][columna];

        // Si se llega al estado 5, se reconoce "aviones bombarderos"
        if (estadoActual == 5) inicioTipoArmada = i - 18; // Retrocede para encontrar el inicio de "aviones bombarderos"

        // Si se llega al estado 9, se reconoce "convoyes"
        if (estadoActual == 9) inicioTipoArmada = i - 6; // Retrocede para encontrar el inicio de "convoyes"
    }

    if (estadoActual == 5) return "aviones bombarderos";
    else if (estadoActual == 9) return "convoyes";
    else return "No se reconoció ninguna armada";
}

// Función para leer un archivo de texto y almacenar las líneas en un vector
// vector<string> LeerArchivoDeTexto(const string& nombreArchivo) 
// {
//     vector<string> lineas;
//     ifstream archivo(nombreArchivo);

//     if (archivo.is_open()) {
//         string linea;
//         while (getline(archivo, linea)) {
//             lineas.push_back(linea);
//         }
//         archivo.close();
//     } else {
//         cout << "Error al abrir el archivo: " << nombreArchivo << endl;
//     }

//     return lineas;
// }
bool readArchivo(string pathFileName)//path ruta del archivo
{
    fstream f;
    string line;


    cout << "readArchivo:" << pathFileName<< endl;
    f.open(pathFileName, ios_base::in);//in indica que sera solo de lectur
    if(!f.is_open())
        cout<<"error al abrir el archivo"<<pathFileName<<endl;
    else
    {
        while(!f.eof() )
        {
            getline(f, line);
            cout<<line<<endl;
        }
        return true;
    }    
    f.close();
    return false;
}
// tener cuidado de cuadrar el archivo y que no esté en edición o si este leyendo 2 archivos al mismo 
int main() 
{
    string texto = "Hoy se detectaron aviones bombarderos : en la zona este.";

    string tipoArmada = IdentificarTipoArmada(texto);

    cout << "Tipo de armada detectada: " << tipoArmada << endl;

    vector<string> lineasDelArchivo = readArchivo(nombreArchivo);// LeerArchivoDeTexto

    // Ahora, lineasDelArchivo contiene todas las líneas del archivo de texto

    // Puedes iterar a través de las líneas e imprimir su contenido para verificar
    for (const string& linea : lineasDelArchivo) {
        cout << linea << endl;
    }

    return 0;
}
