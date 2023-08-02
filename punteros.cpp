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
#include <iostream>
using namespace std;

void defPuntero()//esta entrendo a la posicion de memoria y le cambia el valor
{
    int a = 10;
    int b=20;
    int *pi=NULL;//POR DEFECTO EL NULL PERO PARA ESTAR SEGUROS

    pi=&a;

    cout<<endl<<endl
        <<"Valor de a: "<< a <<endl
        <<"referencia a: "<< &a <<endl
        <<"----------------------"
        <<"refer *pi_a"<< pi <<endl
        <<"valor *pi_a"<< *pi <<endl;

    *pi=0;
        cout<<"cambio a:"<<*pi +20<<endl;

    pi=&b;
    cout<<"Valor de b: "<<b<<endl 
        <<"referencia b: "<< &b <<endl  
        <<"----------------------"
        <<"refer pi_b"<< pi <<endl
        <<"valor *pi_b"<<*pi<<endl;
    *pi=0;
    cout<<"puntero *pi_b"<< *pi <<endl;
}

int funcionPorValor(int valor)
{
    valor= valor + 18;//suma 18
    return valor;
}

int funcionPuntero(int *valor)
{
    *valor= *valor + 18;//suma 18 a la posicion
    return *valor;
}


int main()
{
    //defPuntero();
    int numero=10;
    int *pi=NULL;//un puntero no puede recibir valores

    cout<<"Numero antes= "<<numero<<endl;
    funcionPorValor(numero);//el numero nunca cambio, entro y salio de la funcion
    cout<<"numero despues="<<numero<<endl;

    pi=&numero;
    cout<<"\t -----------"<<endl<<"Numero antes= "<<numero<<endl;
    funcionPuntero(pi);//no cambia pero lo encuentra con el puntero
    cout<<"numero despues="<<numero<<endl;

    cout<<"\t -----------"<<endl<<"Numero antes= "<<numero<<endl;
    funcionPuntero(&numero);//le envio la referencia de memoria
    cout<<"numero despues="<<numero<<endl;

    cout<<endl;
    return 0;
}


