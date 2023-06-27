#include <stdio.h>

void cuadrados(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s=0;
            s=i*j;
            pritnf ("%i",&s);
        }
        
    }
    printf ("\n");

}


   /*\|||/
     (> <)
  ooO-(_)-Ooo*/

int main()
{
    int numero=0;
    printf ("Elija un numero: ");
    scanf ("%i",&numero);
    cuandrados(numero);
    fibonacci(numero);
}

void fibonacci(int n){

    for (int i = 0; i < n; i++)
    {
        printf ("%i",&i);
    }
    
}


#include <stdio.h>

int main() {
    int numTerminos, i;
    long long int terminoAnterior = 0, terminoActual = 1, siguienteTermino;

    printf("Ingrese el número de términos que desea en la serie de Fibonacci: ");
    scanf("%d", &numTerminos);

    printf("Serie de Fibonacci de %d términos:\n", numTerminos);

    // Mostrar los primeros dos términos de la serie
    printf("%lld, %lld, ", terminoAnterior, terminoActual);

    // Calcular y mostrar los siguientes términos de la serie
    for (i = 3; i <= numTerminos; i++) {
        siguienteTermino = terminoAnterior + terminoActual;
        printf("%lld, ", siguienteTermino);
        terminoAnterior = terminoActual;
        terminoActual = siguienteTermino;
    }

    printf("\n");
    return 0;
}
