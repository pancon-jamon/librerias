/*para calcular indice de masa corporal*/
#include <stdio.h>
int main()
{
    float altura=0, peso=0, imc=0;
    
    printf("Ingrese su altura(m): \n");
    scanf("%f",&altura);

    printf("Ingrese su peso(kg): \n");
    scanf("%f",&peso);

    imc= peso / (altura*altura);

    if (imc<18.5)
    {
        printf ("El peso esta por debajo de lo normal.");
    }
    else if((imc>=18.5)&&(imc<25));
    {
        printf ("El peso es saludables");
    }
     if((imc>=25)&&(imc<30)); 
    //cambiar a else if//
    {
        printf ("Tiene sobrepeso");
    }
    printf ("\n Su indice de masa corporal es de: %2.f",imc);
    return (0);
}