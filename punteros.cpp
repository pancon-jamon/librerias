/*
1:34:24
ARCHIVOS DE TEXTO, 2/AG/2023
CLAUDIA COELLO
PROGRAMACION I SEGUNDO BIMESTRE
PUNTEROS: controlar la posicion de memoria, ayuda a que el computador sepa exactamente donde puso un valor basada en una referencia de memoria
El computador suele guardaar los datos donde sea dependiendo donde este el puntero y esto toma tiempo
Los punteros estan destnados a moverse en un espacio o segmento de memoria, cuando hacemos punteros de un tipo de dato este tiene que ser ese tipo de dato(char, int, double)
los punteros estan destinados a este tipo de datos y no puedo leerlo si no lo es, puede entrar en el espacio siempre que sean del mismo tipo, los del tipo null no apunta a nada
para que pueda acordarse donde dejo el dato tiene que tener una referencia(la libreta de apuntes de la cpu) de la direccion, a menudo solo deja los datos desperdigados
los punteos no guardan datos, solo busca las posciciones*/
// #include <iostream>
// #include <vector>
// using namespace std;

// void defPuntero()//esta entrendo a la posicion de memoria y le cambia el valor
// {
//     int a = 10;
//     int b=20;
//     int *pi=NULL;//POR DEFECTO EL NULL PERO PARA ESTAR SEGUROS

//     pi=&a;

//     cout<<endl<<endl
//         <<"Valor de a: "<< a <<endl
//         <<"referencia a: "<< &a <<endl
//         <<"----------------------"
//         <<"refer *pi_a"<< pi <<endl
//         <<"valor *pi_a"<< *pi <<endl;

//     *pi=0;
//         cout<<"cambio a:"<<*pi +20<<endl;

//     pi=&b;
//     cout<<"Valor de b: "<<b<<endl 
//         <<"referencia b: "<< &b <<endl  
//         <<"----------------------"
//         <<"refer pi_b"<< pi <<endl
//         <<"valor *pi_b"<<*pi<<endl;
//     *pi=0;
//     cout<<"cambio b: "<<b<<endl;
//     cout<<"puntero *pi_b"<< *pi <<endl;
// }

// int funcionPorValor(int valor)
// {
//     valor= valor + 18;//suma 18
//     return valor;
// }

// int funcionPuntero(int *valor)
// {
//     *valor= *valor + 18;//suma 18 a la posicion
//     return *valor;
// }

// void tipoParametrosPunteros()
// {
//     int numero=10;
//     int *pi= NULL;

//     cout<<"----------------------"<<endl<<endl;
//     cout<<"Antes de funcionPorValor, numero = "<<numero<<endl;
//     funcionPorValor(numero);
//     cout<<"despues de funcionPorValor, numero = "<<numero<<endl;

//     pi=&numero;
//     cout<<"----------------------"<<endl<<endl;
//     cout<<"Antes de funcionPuntero, numero = "<<numero<<endl;
//     funcionPuntero(pi);
//     cout<<"despues de funcionPuntero, numero = "<<numero<<endl;

//     cout<<"----------------------"<<endl<<endl;
//     cout<<"Antes de funcionPuntero, numero = "<<numero<<endl;
//     funcionPuntero(&numero);
//     cout<<"despues de funcionPuntero, numero = "<<numero<<endl;
// }

// void arrayPunteros()
// {
//     string* titulos= NULL;//inicia en nulo
//     string* autores = NULL;
//     int size;
//     string entrada;

//     //punteros doble
//     string** libros;
//     int colums = 2;

//     cout<<"Cuantos libros deseas ingresar?";
//     getline(cin, entrada);
//     size= stoi(entrada);

//     //dimensionar arrays
//     titulo = new string[size];
//     autores = new string[size];

//     //dimensionar arrays dobles
//     titulo = new string*[size];//asignar numero de filas

//     cout<<endl<<"Ingrese la sig informacion"<<endl;
//     for (int i = 0; i < size; i++)
//     {
//         string titulo,autor;
//         cout<<"\n ********Libro"<<i+1<<"******\n";
//         cout<<"Titulo:";
//         getline(cin,autor);
//         autores[i]=autor;

//         //en array doble
//         libros[i]= new string[colums];//cada fila tendra 2 columnas
//         libros[i][0]= titulo;
//         libros[i][1]= autor;
//     }
//     cout<<"Titulo \t Autor"<<endl;
//     for (int i = 0; i < size; i++)
//         cout<<libros[i][0]<<"\t"<<libros[i][1]<<endl;
    
//     //liberar espacion de los punteros
//     delete [] titulos;
//     delete [] autores;
//     titulos= NULL;
//     autores = NULL;

//     //punteros dobles(debe recorrer fila por fila)
//     for (int i = 0; i < size; i++)
//         delete [] libros[i];//cada  fila de libros es otro array de punteros
    
//     //luego de limpiar las columnas, quitar la fila unica que quedo
//     delete [] libros;
    
// }

// int main()
// {
//     defPuntero();
//     int numero=10;
//     int *pi=NULL;//un puntero no puede recibir valores

//     cout<<"Numero antes= "<<numero<<endl;
//     funcionPorValor(numero);//el numero nunca cambio, entro y salio de la funcion
//     cout<<"numero despues="<<numero<<endl;

//     pi=&numero;
//     cout<<"\t -----------"<<endl<<"Numero antes= "<<numero<<endl;
//     funcionPuntero(pi);//no cambia pero lo encuentra con el puntero
//     cout<<"numero despues="<<numero<<endl;

//     cout<<"\t -----------"<<endl<<"Numero antes= "<<numero<<endl;
//     funcionPuntero(&numero);//le envio la referencia de memoria
//     cout<<"numero despues="<<numero<<endl;
//     tipoParametrosPunteros();
//     cout<<endl;
//     return 0;
// }


// //punteros dobles es como matriz cuadratica
#include <iostream>
#include <vector>
using namespace std;

void defPuntero()
{
    int a = 10;
    int b = 20;
    int *pi = NULL; // POR DEFECTO EL NULL PERO PARA ESTAR SEGUROS

    pi = &a;

    cout << endl
         << endl
         << "Valor de a: " << a << endl
         << "referencia a: " << &a << endl
         << "----------------------"
         << "refer *pi_a" << pi << endl
         << "valor *pi_a" << *pi << endl;

    *pi = 0;
    cout << "cambio a: " << *pi + 20 << endl;

    pi = &b;
    cout << "Valor de b: " << b << endl
         << "referencia b: " << &b << endl
         << "----------------------"
         << "refer pi_b" << pi << endl
         << "valor *pi_b" << *pi << endl;
    *pi = 0;
    cout << "cambio b: " << b << endl;
    cout << "puntero *pi_b" << *pi << endl;
}

int funcionPorValor(int valor)
{
    valor = valor + 18;
    return valor;
}

int funcionPuntero(int *valor)
{
    *valor = *valor + 18;
    return *valor;
}

void tipoParametrosPunteros()
{
    int numero = 10;
    int *pi = NULL;

    cout << "----------------------" << endl
         << endl;
    cout << "Antes de funcionPorValor, numero = " << numero << endl;
    numero = funcionPorValor(numero); // Asignar el valor devuelto por la función a 'numero'
    cout << "después de funcionPorValor, numero = " << numero << endl;

    pi = &numero;
    cout << "----------------------" << endl
         << endl;
    cout << "Antes de funcionPuntero, numero = " << numero << endl;
    funcionPuntero(pi);
    cout << "después de funcionPuntero, numero = " << numero << endl;

    cout << "----------------------" << endl
         << endl;
    cout << "Antes de funcionPuntero, numero = " << numero << endl;
    funcionPuntero(&numero);
    cout << "después de funcionPuntero, numero = " << numero << endl;
}

void arrayPunteros()
{
    string *titulos = NULL;
    string *autores = NULL;
    int size;
    string entrada;

    // Punteros dobles
    string **libros;
    int colums = 2;

    cout << "Cuantos libros deseas ingresar?";
    getline(cin, entrada);
    size = stoi(entrada);

    // Dimensionar arrays
    titulos = new string[size];
    autores = new string[size];

    // Dimensionar arrays dobles
    libros = new string *[size]; // Asignar numero de filas

    cout << endl
         << "Ingrese la sig informacion" << endl;
    for (int i = 0; i < size; i++)
    {
        string titulo, autor;
        cout << "\n ********Libro" << i + 1 << "******\n";
        cout << "Titulo:";
        getline(cin, titulo);
        titulos[i] = titulo;

        // En array doble
        libros[i] = new string[colums]; // Cada fila tendrá 2 columnas
        libros[i][0] = titulo;
        libros[i][1] = autor;
    }

    cout << "Titulo \t Autor" << endl;
    for (int i = 0; i < size; i++)
        cout << libros[i][0] << "\t" << libros[i][1] << endl;

    // Liberar espacio de los punteros
    delete[] titulos;
    delete[] autores;
    titulos = NULL;
    autores = NULL;

    // Punteros dobles (debe recorrer fila por fila)
    for (int i = 0; i < size; i++)
        delete[] libros[i]; // Cada fila de libros es otro array de punteros

    // Luego de limpiar las columnas, quitar la fila única que quedó
    delete[] libros;
}

void cambioDePunteros()
{
    int numero = 10;
    int *pi = NULL;

    cout << "Numero antes= " << numero << endl;
    numero = funcionPorValor(numero); // Asignar el valor devuelto por la función a 'numero'
    cout << "numero después= " << numero << endl;

    pi = &numero;
    cout << "\t -----------" << endl
         << "Numero antes= " << numero << endl;
    funcionPuntero(pi);
    cout << "numero después= " << numero << endl;

    cout << "\t -----------" << endl
         << "Numero antes= " << numero << endl;
    funcionPuntero(&numero);
    cout << "numero después= " << numero << endl;
    tipoParametrosPunteros();
    cout << endl;
}

int main()
{
    defPuntero();
    arrayPunteros();
    return 0;
}

