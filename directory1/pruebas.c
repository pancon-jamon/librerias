
#include<stdio.h>
#include <iostream>

/*void serieCaracterAbecedarioDoble(char impresion, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c",impresion[i%n],i);
    }
    

}
void serieCaracterAbecedario(int num)
{
    char alfabeto[]="abcdefghijklmnopqrstuvwxyz";
    int contador=26;
    char resultado;
    for (int i=0; i<num; i++)
    {
        printf("%c ",alfabeto[i%contador],i);
        scanf ("%c", resultado);
    } 
    printf ("\n");
    serieCaracterAbecedarioDoble(resultado, num);
}*/

//int coelloSerieCaracteresAnagrama(int n)
/*void ananagrama()
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
    printf ("\n");*/
//}
/*void coelloCaracteresMasFibonacci(int n)
{

    int a=0, b=1, c=1;
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < c; x++)
        {
            printf ("+\t");
            c=a+b;
            a=b;
            b=c;

        }
        
    }
    
}*/



void Matriz UnoCero(int size) {
    // Definir las dimensiones de la matriz
    int filas = size;
    int columnas = size;

    // Declarar la matriz
    int matriz[filas][columnas];

    // Inicializar la matriz con valores
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i + j;
        }
    }

    // Acceder y mostrar los valores de la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



int main()
{
    int numero=0, i;
    printf ("Elija un numero: ");
    scanf ("%i",&numero);
    coelloCaracteresMasFibonacci(numero);
}