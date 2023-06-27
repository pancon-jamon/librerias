#include <stdio.h>
void main ()
{
    int size=0;
    char signo[2];
    printf ("Ingresa un numero:");
    scanf ("%i",& size);
    for (int i=0; i<size+(size/3); i++)
    {
        for(int c=0; c<size; c++)
        {
            if ((i==0 || i== (size+(size/3))-1 || i==size/2) || ((c==size-1)&&(i>size/2))|| ((c==0)&&(1<size/2)))
            printf ("* ",i , c);
            else 
            printf (" ");
        }
        printf ("\n");
    }
}
/*              + + +
                +
                +
                + + +
*/
