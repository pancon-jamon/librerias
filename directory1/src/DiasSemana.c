#include "stdio.h"
int main()
{
    int mes=0; 
    printf ("ingrese el numero del mes: ");
    scanf("%i",&mes);
    switch (mes)
    {
        case 1:printf("enero");
        break;
        case 2:printf("febrero");
        break;
        case 3:printf("marzo");
        break;
        case 4:printf("abril");
        break;
        case 5:printf("mayo");
        break;
        case 6:printf("julio");
        break;
        case 7:printf("junio");
        break;
        case 8:printf("agosto");
        break;
        case 9:printf("septiembre");
        break;
        case 10:printf("octubre");
        break;
        case 11:printf("noviembre"); 
        break;
        case 12:printf("diciembre"); 
        break;
        default: printf ("error");
    }

}