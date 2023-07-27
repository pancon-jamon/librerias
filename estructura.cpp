/*
ARCHIVOS DE TEXTO, 24,25/JUL/2024
CLAUDIA COELLO
PROGRAMACION I SEGUNDO BIMESTRE
rubber duck debugging: tecnica de programacion. Se le explica el codigo a " un patito de hule"

FUNCIONES PARA MENEJAR CARACTERES:
    -isalnum: verdadero(cualquier numero entero distinto de 0) si es una letra o un digito
    -isalpha: verdadero si es una letra
    -isblank: verdadero si es un espacio en blanco o tabulado
    -isdigit: verdadero si es un digito
    -isspace: verdadero si es un espacio en blanco, salto de linea, retorno de carro, tabulador, etc
    -islower: verdadero si es una letra minuscula
    -issupper: verdadero si es una mayuscula

    *incluyendo <ctype.h> (Sirve para convertir mayusculas a minuculas y vicivera)*
    
    toupper(caracter): devuelve la mayuscula asociada al caracter, si la tiene, de lo contrario devuelve el mismo carater
    tolower(caracter): devuelve la minuscula asociada al caracter, si la tiene, de lo contrario devuelve el mismo carater

LIBRERIAS
    -math.h(operaciones matematicas basicas)
        Define estas operaciones:
            acos:arcoseno
            asin:arcoseno
            atan:arcotangente
            Floor: menor entero no menor que el parametro
            Cosh: coseno hiperbolico
            log:logaritmo natural
            Pow(x,y);eleva un valor dado a un exponente

    stdio.h(operaciones entandar de salida y entrada) 
        printf:imprimir salida de datos
        scanf: introducir entradas
        puts:imprime una cadena de caractere
        getc: devuelve un caracter desde un fichero
        ferror: comprueba el indicador de errores

    stdlib.h(prototipos de funciones de c para gestion de memoria dinamica, control de procesos, etc.
    podemos dividirlos en: conversion, memoria, control de procesos, ordenacion y busqueda, matematicas)
        atof: cadena de caracteres a coma flotante
        rand: genera un numero pseudo aleatorio
        free: liberar memoria devolviendola al heap
        system: ejecutar un comando externo
        exit: terminar ejecucion
    string.h(contiene la definicion de macros, constantes, funciones, tipos y algunas operaciones de manipulacion de memoria)
        null: constante puntero nulo
        strcpy:copiar cadena en otra
        strcat:añadir cadena al final de otra
        strrev: invertir cadena
        strstr:buscar cadena dentro de otra
*/

#include <iostream>
#include<fstream>//f de files, stream flujo de datos, permite leer archivos de texto, binarios
#include <iomanip>

using namespace std;


struct Mascota//<--estructura(asocia informacion) ayuda a facilitar el codigo
{
    string tipo;
    string raza;
    char sexo;
    int edad;
    string nombre;
    
};

// struct Persona//cada persona tiene una mascota
// {
//     string tipo;
//     string nombre;
//     Mascota mascotaDomestica[5];
// };

// string Mascotatipo[9];
// string Mascotanombre[9];

// string Personatipo[9];
// string Personanombre[9];


#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

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
    while (!ss.eof())
    {
        getline(ss, word, del);
        if (i == 1)
            m.tipo = word;
        if (i == 2)
            m.raza = word;
        if (i == 3)
            m.sexo = word; 
        if (i == 4)
            m.edad = stoi(word); 
        if (i == 5)
            m.nombre = word;
        i++;
    }
    mascotaDomestica[indexMascota++] = m;
}

void showMascota()//mostrar las mascotas guardadas en el archivo
{
    string pathArchivo = "../../data/mascotas.txt";
    ifstream f;
    string line;

    f.open(pathArchivo);
    if (!f.is_open())
    {
        cout << "Error al abrir el archivo " << pathArchivo << endl;
        return;
    }

    cout << endl << setw(10) << "TIPO" << "\t RAZA" << "\t SEXO" << "\t EDAD" << "\t Nombre \n";
    while (getline(f, line))
    {
        getMascota(line, ';');
        cout << setw(10) << mascotaDomestica[indexMascota - 1].tipo << " \t " << mascotaDomestica[indexMascota - 1].raza << " \t " << mascotaDomestica[indexMascota - 1].sexo << " \t " << mascotaDomestica[indexMascota - 1].edad << " \t " << mascotaDomestica[indexMascota - 1].nombre << endl;
    }

    f.close();
}


void addMascota()
{
    Mascota m;
    cout << endl << "Ingresa el tipo de la mascota: ";
    getline(cin, m.tipo);

    cout << "Ingresa la raza de la mascota: ";
    getline(cin, m.raza);

    cout << "Ingresa el sexo de la mascota (M/F): ";
    cin >> m.sexo; // Leer un solo carácter para el sexo

    cout << "Ingresa la edad de la mascota: ";
    cin >> m.edad; // Leer un número entero para la edad

    cin.ignore(); // Ignorar el salto de línea después de leer el entero

    cout << "Ingresa el nombre de la mascota: ";
    getline(cin, m.nombre);

    mascotaDomestica[indexMascota++] = m;
}

bool saveMascota(string pathFileName)
{
    ofstream f;
    f.open(pathFileName, ios::app); // Modo "app" para agregar al final del archivo
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
        cout << "1.- Recuperar mascota" << endl << "2.- Agregar mascota" << endl << "3.- Presentar Mascota" << endl << "4.- Guardar mascota" << endl << "5.- Salir" << endl;
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
                        cout << "Saliendo del programa..." << endl;
                        return;
                }
            }
            else
            {
                cout << "Error. Opción inválida. Intentelo nuevamente." << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "Error. Opción inválida. Intentelo nuevamente." << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}




/*estructura de datos*/
//AGREGAR MENU con try catch y waiting, AGREAGR HASTA 5 REGISTROS Y SIN ENTER AL FINAL SALTANDO EL ENCABEZADO
