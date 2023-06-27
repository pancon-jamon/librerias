/*
Autor: Claudia Coello
Descripcion: Series de strings
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
using namespace std;

void coelloContadorVocales() 
{
    char frase[100];
    int contador = 0;

    printf("Ingresa una frase: ");
    fgets(frase, sizeof(frase), stdin);

    for (int i = 0; frase[i] != '\0'; i++) {
        char caracter = tolower(frase[i]);

        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') 
        {
            contador++;
        }
    }

    printf("El número de vocales en la frase es: %d\n", contador);

    return 0;
}

void coelloContadorConsonantes() 
{
    char frase[100];
    int contador = 0;

    printf("Ingresa una frase: ");
    fgets(frase, sizeof(frase), stdin);

    for (int i = 0; frase[i] != '\0'; i++) {
        char caracter = tolower(frase[i]);

        if (caracter >= 'a' && caracter <= 'z') {
            if (caracter != 'a' && caracter != 'e' && caracter != 'i' && caracter != 'o' && caracter != 'u') {
                contador++;
            }
        }
    }

    printf("El número de consonantes en la frase es: %d\n", contador);
}

bool esVocal(char c) 
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void coelloEliminarVocal(char *frase, char vocal) {
    int longitud = strlen(frase);

    for (int i = 0; i < longitud; i++) {
        if (frase[i] == vocal) {
            for (int j = i; j < longitud; j++) {
                frase[j] = frase[j + 1];
            }
            longitud--;
            i--;
        }
    }
}

void serieCaracterAbecedario(int num)
{
    char alfabeto[]="abcdefghijklmnopqrstuvwxyz";
    int contador=26;
    
    for (int i=0; i<num; i++)
    {
        printf("%c ",alfabeto[i%contador],i);
    } 
    printf ("\n");
}

void coelloserieCaracterAbecedarioDoble(int num)
{
    char alfabeto[]="abcdefghijklmnopqrstuvwxyz";
    int contador=26;
    
    for (int i=0; i<num; i++)
    {
        printf("%c ",alfabeto[i%contador],i);
    } 
    printf ("\n");
}

void coelloserieCaracterAbecedarioAlternado(int num)
{
    char alfabeto[]="abcdefghijklmnopqrstuvwxyz";
    int contador=26;
    
    for (int i=0; i<num; i++)
    {
        if (i%2==0)
        printf("%c ",alfabeto[i%contador],i);
        else 
        printf ((i%4==1)?"+ ":"- ");
    } 
    printf("\n");
}

void coelloCadenaAnagrama()
{
    char palabra[10]=" ", palabraResultado[10]=" ",palabraSegundoResultado[10]=" ", palabraTercerResultado[10]=" ";
    printf ("Selescciona una de las siguientes palabras: delira, ballena, alondra, españa, Enrique\n");
    fgets(palabra, sizeof(palabra), stdin);
    printf ("Ahora intenta formar una palabra con la que ingresaste cambiando el orden de las letras y escribela aqui: ");
    fgets(palabraResultado, sizeof(palabraResultado), stdin);
    do
    {
        if (palabraResultado!="lidera"  || palabraResultado!="llenaba" || palabraResultado!="ladrona" ||  palabraResultado!="apañes" || palabraResultado!="quieren")
        {
        printf ("Intentalo nuevamente: ");
        fgets(palabraSegundoResultado, sizeof(palabraSegundoResultado), stdin);
        if (palabraSegundoResultado!="lidera"  || palabraSegundoResultado!="llenaba" || palabraSegundoResultado!="ladrona" ||  palabraSegundoResultado!="apañes" || palabraSegundoResultado!="quieren")
            {
            printf ("Intentalo nuevamente: ");
            fgets(palabraTercerResultado, sizeof(palabraTercerResultado), stdin);
            if ( palabraTercerResultado!="lidera") printf ("La palabra que puedes formar es:lidera ");
            if (palabraTercerResultado!="llenaba") printf ("La palabra que puedes formar es:llenaba ");
            if (palabraTercerResultado!="ladrona") printf ("La palabra que puedes formar es:ladrona ");
            if (palabraTercerResultado!="apañes") printf ("La palabra que puedes formar es:apañes ");
            if (palabraTercerResultado!="quieren") printf ("La palabra que puedes formar es:quieren ");
            }
        }
            else 
                printf ("¡Felicidades lo lograste!");
    
    } while (palabraResultado=="delira" || palabraResultado=="ballena" ||  palabraResultado=="alondra" || palabraResultado== "españa" || palabraResultado== "Enrique");
    printf ("\n");
}


void imprimir()
{
    char frase[100];
    char vocal;

    printf("Ingresa una frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Ingresa la vocal que deseas eliminar: ");
    scanf("%c", &vocal);

    eliminarVocal(frase, vocal);

    printf("La frase resultante es: %s\n", frase);

    coelloCadenaAnagrama;
    coelloserieCaracterAbecedarioAlternado(int numero);
    coelloserieCaracterAbecedarioDoble(int numero);
    coelloserieCaracterAbecedario(int numero);
    coelloContadorConsonantes;
    coelloContadorVocales;
    coelloEliminarVocal;


}