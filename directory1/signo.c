/* 
30 mayo 2023
Secuencia signos +-+-
Imprime signos segun si es par o impar
*/

#include <stdio.h>
void secuenciaSignos (int numeroSigno, char character){
    for (int  i = 0; i < numeroSigno; i++)
    printf ("&c", character);
    printf ("\n");
}


void secuenciaSignosAlternados (int numeroSigno, char character)
{
    for (int  i = 0; i < numeroSigno; i++)
    {
        if (i%2==0)
           printf ("+ ");
        else
        printf ("- ");
    }
    printf ("\n");
}

int main ()
{
    int numeroSigno=0;
    char character=´+´;

    printf ("Ingrese un numero: ");
    scanf ("%i", &numeroSigno);

    secuenciaSignos (numeroSigno, character);
    secuenciaSignosAlternados (numeroSigno);
    
    return 0;
}