/*
ARCHIVOS DE TEXTO, 24/JUL/2024
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
MINUTO 27:07
*/

#include <iostream>
#include<fstream>//f de files, stream flujo de datos, permite leer archivos de 
#include <iomanip>

using namespace std;


struct Mascota//<--estructura
{
    string tipo;
    string nombre;
};
Mascota mascotaDomestica[7];
int indexMascota=0;

void getMascota(string lineArchivo, char del)
{
    struct Mascota m;
    stringstream ss(lineArchivo);
    string word;
    int i=1;
    while (!ss.eof())
    {    
        getline(ss, word, del);
        if(i==1)
            m.tipo=word;
        if(i==2)
            m.tipo=word;
        i++;
    }
    mascotaDomestica[indexMascota++]=m;

}

void showMascota()
{
    cout<<endl<<setw(10)<<"TIPO"<<"\t Nombre \n";
    for (auto &&m:mascotaDomestica)
        cout<<setw(10)<<m.tipo<<" \t "<<m.nombre<<endl;//setw formateador de datos
}

void addMascota()
{
    struct Mascota m;
    cout<<endl<<"Ingresa el tipo de mascota";
    getline(cin, m.tipo);
    cout<<"Ingresa el nombre de mascota: ";
    getline(cin, m.nombre);
    mascotaDomestica[indexMascota++]=m;
}

bool readArchivo(string pathFileName)//path ruta del archivo
{
    fstream f;
    string line;


    cout << "readArchivo:" << endl;
    f.open(pathFile, ios_base::in);
    if(!f.is_open())
        cout<<"error al abrir el archivo"<<pathFile<<endl;
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

bool saveMascota(string pathFileName)//path ruta del archivo
{
    fstream f;
    string line;

    cout << "saveMascota:" <<pathFileName<< endl;
    f.open(pathFileName, ios_base::out);
    if(!f.is_open())
    {    
        cout<<"error al guardar el archivo"<<pathFileName<< endl;
        return false;
    }
    
    for (int i = 0; i < indexMascota; i++)
    {
        auto &&m =mascotaDomestica[i];
       f<< m.tipo<< " ; "<< m.nomre<< endl; //<-guarda en el archivo
    }
    
        
      
    f.close();
    cout<<endl<<"mascota guardada"<<endl;
    return false;
}

bool readMascota(string pathFileName)
{
    fstream f;
    string line;


    cout << "readArchivo:" <<pathFileName<< endl;
    f.open(pathFileName, ios_base::in);
    if(!f.is_open())
    {    
        cout<<"error al abrir el archivo"<<pathFileName<<endl;
        return false;
    }
    
    while(!f.eof() )//mientras no este al final de la linea
    {
        getline(f, line);
        getMascota(line, ';');
    }
      
    f.close();
    cout<<endl<<"lectura exitosa";
    return false;
}

int main()
{
    // cout<<"---alumnos---"
    // readArchivo("../../data//alumnos.txt");

    string pathArchivo="../../data//mascotas.txt";
    cout<< "---mascotas---"<< endl;

    readMascota(pathArchivo);
    addMascota();
    showMascota();
    saveMascota(pathArchivo);

    cout<< endl;
    return 0;

}


/*estructura de datos*/