/*
Autor: Claudia Coello
Descripcion: Series de figuraas
*/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void coelloFiguraCuadrado(int size)
{
    printf ("Serie 3.1: \n");
    for (int v = 1; v <= size; v++)
    {
        for (int h = 1; h <= size; h++)
        {
            if ( (h == 1 || h== size) || (v == 1 || v== size) )
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void coelloFiguraCuadradoAlternado(int size)
{
    printf ("Serie 3.2: \n");
    for (int v = 1; v <= size; v++)
    {
        for (int h = 1; h <= size; h++)
        {
            if ( (h == 1 || h== size) || (v == 1 || v== size) )
                printf("* ");
            if ((h == 1 || h== size) || (v == 1 || v== size)&&(h%2==0)&&(v%2==0))
            printf ("+");
            else
                printf("  ");
        }
        printf("\n");
    }
}


void coelloFiguraTriangulo(int size)
{
    printf ("Serie 3.3: \n");
    for (int f = 1; f <= size; f++)
    {
        for (int c = 1; c <= size; c++)
        {
        if (f >= c)
            printf ("* ");
            else
            printf("  ");
        }
        printf("\n");
    }
    
}

void coelloFiguraTrianguloInvertido(int size)
{
    printf ("Serie 3.3: \n");
    for (int f = 1; f <= size; f++)
    {
        for (int c = 1; c <= size; c++)
        {
        if (f <= c)
            printf ("* ");
            else
            printf("  ");
        }
        printf("\n");
    }
    
}

void coelloFiguraPascal(int n) 
{
    int  primer = 1, space, j;

    for (int i = 1; i <= n; i++) 
    {
        for (space = 1; space <= n - i; space++)
        {
            printf("  ");

            for (j = 0; j <= i; j++) 
            {
                if (j == 0 || i == 0)
                    n = 1;
                else
                    n = n * (i - j + 1) / j;

               printf("%4d", n);
            }
        }

        printf("\n");
    }

}

void coelloFiguraEscalera(int n)
{
    string strSpac="", strGrada="|_";
    for (int i = i; i < n; i++)
    {
        cout<< strSpac << strGrada << endl;
        strSpace+="   ";
    }
    

}

void coelloFiguraEscaleraSignos(int n)
{
    string strSpac="", strGradaP="|_+_", strGradaN="|_-_";
    for (int i = i; i < n; i++)
    {
        cout<< strSpac << ((i%2==0)? strGradaP: strGradaN) << endl;
        strSpace+="   ";
    }
    

}

void coelloFiguraEscaleraDoble(int n)
{
    for (int i = i; i < n; i++)
    {
        if (i=0)
            cout<< getSpace(n)<<"  __"<< endl
        
        cout<< getSpace(n-i)<<"|_"
            << "  "
            <<getSpace(i*2)<<"_|"
            <<endl;
    }
    

}

void MenuFiguras()
{
    coelloFiguraCuadrado;
    coelloFiguraCuadradoAlternado;
    coelloFiguraEscalera;
    coelloFiguraEscaleraDoble;
    coelloFiguraEscaleraSignos;
    coelloFiguraPascal;
    coelloFiguraTriangulo;
    coelloFiguraTrianguloInvertido;

}

