/*
 Autor: Claudia Coello
 Descripcion: menu principal
*/
#include <stdio.h>
#include "../lib/patUtility.h"
#include "../lib/serieNumericas.h"
#include "../lib/serieCaracteres.h"
#include "../lib/serieFiguras.h"
#include "serieCadena.h"
#include <unistd.h>
#define DELAYE 100000;

char menu()
{
    int opc=0;
    char c[] ="\\|/- ";
    for (int i = 0; i <= 100; i++)
    {
        printf("\r%c %3d %% ",c[i%5],i);
    }
    
    do{
        setTextColor(textColorBlue);
        printf("\n\t Claudia Coello 1726416892");
        setTextColor(textColorCyan);

        printf("\n1. Series numericas");
        printf("\n2. Series de carateres");
        printf("\n3. Series de figuras");
        printf("\n4. Serie cadena");
        printf("\n99.Salir");
        opc =  getNumeroPositivo("Ingresa opc: ");
        int numero=0;
            printf ("Elija un numero: ");
            scanf ("%i",&numero);
            if (opc==1)
            {
                Menu;
            }
            if (opc==2)
            {
                imprimirCaracteres;
            }
            if (opc==3)
            {
                MenuFiguras;
            }
            if (opc==4)
            {
                imprimir;
            }
            serieCaracteres(numero);
            serieCadena(numero);
            serieFiguras(numero);
            serieNumericas(numero);
            
    }while ( opc < 0 ) ;
    return opc;
}
