#include <stdio.h>


//serie 1
void  coelloSerieNumericaFibonacci(int cantidad)
{
    printf ("Serie 1.1:\t ");
    int a =0, b=1, c=1;
    for (int i = 0; i < cantidad; i++)
    {
        printf("%i",c);
        printf("\t");
        c = a + b;
        a = b;
        b = c;
    }
    printf("\t");
    cantidad =0;
    printf("\n");
}

//serie 2
void  coelloCaracterFibonacciMas(int cantidad)
{
    printf ("Serie 2.2: ");
    int a =0, b=1, c=1;
    for (int i = 0; i < cantidad; i++)
    {
        printf(" +");
        for (int s = 0; s < c; s++)
            printf ("+");
        printf("\t");
        c = a + b;
        a = b;
        b = c;
    }
    cantidad =0;
    printf("\ncoelloCaracterFibonacciMas.cantida %i",cantidad); 
    printf("\n");
}

//serie 3

void  coelloCaracterFibonacciMasDesde2(int cantidad)
{
    printf ("Serie 2.3: ");
    int a =0, b=1, c=1;
    for (int i = 1; i < cantidad; i++)
    {
        printf(" +");
        for (int s = 0; s < c; s++)
            printf ("+");
        printf("\t");
        c = a + b;
        a = b;
        b = c;
    }
    cantidad =0;
    printf("\n coelloCaracterFibonacciMas.cantida %i",cantidad); 
    printf("\n");
}

void coelloCaracterAlternado(int n)// + - + - ...//
{
    for (int i=0; i<n; i++)
        {
            if (i%2==0) 
            printf (" + ");
            else
            printf (" - ");
        }
        printf (" \n ");

}

void coelloSerieNumericaParImparConCeros(int n)
{
    for (int i=0; i<=n; i++)
        {
            if (i%2==0) 
                printf (" 0 ");
            else
                printf (" %i ",i);
        }
    printf (" \n ");

}

void coelloSeriePotencias(int n)
{
    printf("Serie 1.6: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s=0;
            s=i*j;
            printf ("%i\t",s);
        }
        
    }
    printf ("\n");

}

void coelloSerieMasTres(int n){
    printf ("Serie numerica 1.7 \t");
    for (int i = 1; i < n; i+3)
    {
        printf ("%i\t",i);
    }
     printf ("\n");
}

void coelloSerieMasCinco(int n){
    printf ("Serie numerica 1.8 \t");
    for (int i = 3; i < n; i+5)
    {
        printf ("%i\t",i);
    }
     printf ("\n");
}

void coelloSeriePorDos(int n){
    printf ("Serie numerica 1.9 \t");
    for (int i = 1; i < n; i*2)
    {
        printf ("%i\t",i);
    }
     printf ("\n");
}

void coelloSeriePorTres(int n){
    printf ("Serie numerica 1.10 \t");
    for (int i = 1; i < n; i*3)
    {
        printf ("%i\t",i);
    }
     printf ("\n");
}



int main()
{
    int numero=0, i;
    printf ("Elija un numero: ");
    scanf ("%i",&numero);
    
    coelloSerieNumericaFibonacci(numero);
    coelloCaracterAlternado(numero);
    coelloSerieNumericaParImparConCeros(numero);
    coelloSerieMasTres(numero);
    coelloSerieMasCinco(numero);
    coelloSeriePorDos(numero);
    coelloSeriePotencias(numero);
    coelloCaracterFibonacciMasDesde2(numero);
    coelloCaracterFibonacciMas(numero);

}

