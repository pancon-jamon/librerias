#include <stdio.h>
char menu()
{
    char Opciones=`-`;
    do{
        printf ("\n\t MENU");
        printf ("\n 1.-Generar Pares");
        printf ("\n 2.-Generar Impare");
        printf ("\n 3.-Generar Fibonacci");
        printf ("\n Ingresa tu opcion: ");
        scanf ("%c",&Opciones);

    }while (!(Opcion=`1`)||(Opcion=`2`)||(Opcion=`3`))
return Opciones;
}
