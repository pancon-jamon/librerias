/*para calcular indice de masa corporal*/
#include <stdio.h>
int main()
{
    int altura=0, peso=0, imc=0;
    
    printf("Ingrese su altura(m): \n");
    scanf("%i",&altura);

    printf("Ingrese su peso(kg): \n");
    scanf("%i",&peso);

    imc= peso / (altura*altura);
    if (imc<18.5)
    {
        printf ("El peso esta por debajo de lo normal.");
    }else if((imc>=18.5)&&(imc<25));
    {
        printf ("El peso es saludables");
    }else if((imc>=25)&&(imc<30));{
        printf ("Tiene sobrepeso");
    }
    return (0);
}