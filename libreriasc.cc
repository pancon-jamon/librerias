#include <stdio.h>

int sumaValor(int a , int b)
{
    int suma = a+b;
    a =0;
    b =0;
    printf("\n sumaValor: a=%i b=%i",a,b);
    return suma;
}


void sumaRef(int *aa , int b, int *c)
{
    *c = *aa + b;
    *aa = 100;
    b =0;
    printf("\n sumaRef: aa=%i b=%i",*aa,b);
}

int main()
{
    int a=10, b=20, suma=0;
    printf("Parametros por valor");

    printf("\n main: a=%i",a);
    suma = sumaValor(a,b);
    printf("\n main: Suma por valor = %i",suma);
    printf("\n main: a=%i",a);
    
    printf("\n\nParametros por referencia");
    printf("\n main: a=%i",a);
    sumaRef(&a,b,&suma);   // & *
    printf("\n main: Suma por referencia = %i",suma);
    printf("\n main: a=%i",a);

    printf("\n");
    return 0;
}

#include <stdio.h>

void swap(int *a , int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void swapValor(int a , int b)
{
    int c = a;
    a = b;
    b = c;
}


int main()
{
    int a = 10 , b= 20;
    // int c=a;
    // a = b;
    // b = c;
    swapValor(a,b);
    swap(&a, &b);
    printf("\n a=%i b=%i",a,b);

    printf("\n");
    return 0;
}
#include <stdio.h>

void swap(int *a , int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void swapValor(int a , int b)
{
    int c = a;
    a = b;
    b = c;
}


int main()
{
    int a = 10 , b= 20;
    // int c=a;
    // a = b;
    // b = c;
    swapValor(a,b);
    swap(&a, &b);
    printf("\n a=%i b=%i",a,b);

    printf("\n");
    return 0;
}

void array(  )
{
    //            0     1   2
    // arr ->  { [10] [20] [30] ... }
    int lenCar = 4;
    int edad[3];
    int notas[]= {1,2,3,4,5};
    char caracteres[] ={'h','o','l','a'};
    char saludo[] ="hola";
    char palabras[] = "coco babana como estas pepe";

    edad[0]=10;
    edad[1]=20;
    edad[2]=30;
    edad[30]=300;

    printf("La edad del 1er alumno es: %d\n", edad[0]);
    printf("La edad del 2do alumno es: %d\n", edad[1]);
    printf("La edad del 3er alumno es: %d\n", edad[2]);
    printf("La edad del error alumno es: %d\n", edad[30]);

    printf("\n---------------\n");
    printf("Nota 1er: %d\n", edad[0]);
    printf("Nota 2do: %d\n", edad[1]);
    printf("Nota 3er: %d\n", edad[2]);
    printf("Nota err: %d\n", edad[10]);

    printf("\n---------------\n");
    printf("Caracteres : ");
    for (int i = 0; i < lenCar; i++)
        printf("%c\t", caracteres[i]);
    
     printf("\n---------------\n");
    printf("saludo : ");
    for (int i = 0; i < lenCar; i++)
        printf("%c\t", saludo[i]);
}
void arrarDeArrays()
{
    //char palabrasInicializadas[] = {"hola","como","estas"};
	char caracterVector[3];  // vector, array,    ['h']['o']['l'] =	"hol"	....
	char *palabrasVector[3];  // vector, array,    ["hola"]["como"]["estas hoy"]  		....
							//						  0	      1	      2 			3 ......
	palabrasVector[0] = "hola";
	palabrasVector[1] = "como";
	palabrasVector[2] = "estas";

	palabrasVector[12] = "20"; 	// *warning

	printf("\npalabrasVector[0]: %s", palabrasVector[0]);
	printf("\npalabrasVector[1]: %s", palabrasVector[1]);
	printf("\npalabrasVector[2]: %s", palabrasVector[2]);

	printf("\npalabrasVector[12]: %s", palabrasVector[12]);
}
printf("Caracteres : ");
    for (int i = 0; i < lenCar; i++)
        printf("%c\t", caracteres[i]);
    
     printf("\n---------------\n");
    printf("saludo : ");
    for (int i = 0; i < lenCar; i++)
        printf("%c\t", saludo[i]);
}
void arrarDeArrays()
{
    //char palabrasInicializadas[] = {"hola","como","estas"};
	char caracterVector[3];  // vector, array,    ['h']['o']['l'] =	"hol"	....
	char *palabrasVector[3];  // vector, array,    ["hola"]["como"]["estas hoy"]  		....
							//						  0	      1	      2 			3 ......
	palabrasVector[0] = "hola";
	palabrasVector[1] = "como";
	palabrasVector[2] = "estas";

	palabrasVector[12] = "20"; 	// *warning

	printf("\npalabrasVector[0]: %s", palabrasVector[0]);
	printf("\npalabrasVector[1]: %s", palabrasVector[1]);
	printf("\npalabrasVector[2]: %s", palabrasVector[2]);

	printf("\npalabrasVector[12]: %s", palabrasVector[12]);
}
return str;
}

void showEscaleraDoble(int nivel)
{
    for (int i = 0; i < nivel; i++)
    {
        if(i==0)
            cout<< getEspacio( nivel ) << "  __" << endl;

        cout    << getEspacio( nivel-i ) << "_|"    // genera grada izq
                << "  "                             // esp del centro
                << getEspacio( i*2 ) << "|_"        // genera grada der
                << endl;
    }
}

int main()
{
    int nivel =10;
    showEscaleraDoble(nivel);
    cout << endl;
    return 0;
}

return str;
}

void showEscaleraDoble(int nivel)
{
    for (int i = 0; i < nivel; i++)
    {
        if(i==0)
            cout<< getEspacio( nivel ) << "  __" << endl;

        cout    << getEspacio( nivel-i ) << "_|"    // genera grada izq
                << "  "                             // esp del centro
                << getEspacio( i*2 ) << "|_"        // genera grada der
                << endl;
    }
}

int main()
{
    int nivel =10;
    showEscaleraDoble(nivel);
    cout << endl;
    return 0;
}


    fillArrayPares(pares, size);
    fillArrayImpares(impares, size);
    cout << endl << "Pares: " ;
    showArray(pares, size);

    cout << endl << "Impares: " ;
    showArray(impares, size);

    cout << endl << "alfabeto: " ;
    showArray(alfabeto, size);

    cout << endl;
    return 0;
}
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define FIL 3
#define COL 3
#define COLD 6

void showMatriz(int m[][COL])
{
    for (int f = 0; f < FIL; f++)
    {
        for (int c = 0; c < COL; c++)
            cout << " " << m[f][c];
        cout << endl;
    }
}

void showMatrizP(int tam)
{
    char mc[tam][tam];

    for (int f = 0; f < tam; f++)
    {
        for (int c = 0; c < tam; c++)
            if ((f==0) || (c==0) || (tam/2==f) || ((tam -1 == c) && (f <= tam/2  ) ) )
                mc[f][c] = '*';
            elsemc[f][c] = ' ';
    }
     
    for (int f = 0; f < tam; f++)
    {
        for (int c = 0; c < tam; c++)
             cout << mc[f][c];
        cout <<"   ";
        for (int c = 0; c < tam; c++)
             cout << mc[f][c];
        cout <<endl;
    }

}

void showMatrizInt()
{
    int edades[3][2] = {{1,2},{9,8},{14,21}};
    int filas = (sizeof(edades)/sizeof(edades[0]));
    int colum = (sizeof(edades[0])/sizeof(edades[0][0]));

    cout <<"filas: " <<  filas <<endl;
    cout <<"colum: " <<  colum <<endl;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < colum; j++)
            cout << edades[i][j] << "  ";cout << endl;
    }
}

void showArrayString()
{
    string titulos[5];
    string autores[5];
    
    cout<< "Ingrese información de los Libros: \n";
    for(int i = 0; i < 5; i++)
    {
        cout << "\n******* Libro " << i + 1 << "********:\n";
        cout << "Titulo: ";
        //scanf("%s",tixcvx);
        //cin >> titulos[i]; //No funciona con espacios
        getline(cin, titulos[i]);
        cout << "Autor: ";
        //cin >> autores[i]; //No funciona con espacios
        getline(cin, autores[i]);
    }

    cout<< "\n******* Libros Ingresados ********:\n";
    for(int i = 0; i < 5; i++)
    {
        cout<< "  Titulo: " << titulos[i];
        cout<< "  Autor : " << autores[i];
        cout<<endl;
    }

}

void showMatrizString()
{
    string libros[5][2];
    cout << "Por favor ingrese la siguiente información de los Libros: \n";
    string titulo ,autor;
    for(int i = 0; i < 5; i++) {
        cout << "\n******* Libro " << i + 1 << "********:\n";
        cout << "Titulo: ";
        getline(cin,titulo);
        cout << "Autor: ";
        getline(cin,autor);
        libros[i][0] = titulo;
        libros[i][1] = autor;
    }

    cout<< "\n******* Libros Ingresados ********:\n";
    for(int i = 0; i < 5; i++)
    {
        cout<< "  Titulo: " << libros[i][0];
        cout<< "  Autor : " << libros[i][1];
        cout<<endl;
    }

}

void showMatrizDinamica(char matriz[][COLD])
{
    int fila = (sizeof(matriz) / 2);  // sizeof(matriz) = sizeof(matriz[0]) = sizeof(matriz[0][0])
    //int columna = (sizeof(matriz[0])/sizeof(matriz[0][0]));
    for(int f= 0; f < fila; f++){
        for( int c=0; c < COLD; c++){
            cout<<matriz[f][c]<<" ";
        }cout<<endl;
    }
}

void MatrizDinamica(int fila)
{
    char matriz[fila][COLD];
 
    for(int f= 0; f < fila; f++){
        for( int c=0; c < COLD; c++){
            matriz[f][c]='+';
        }
    }
    showMatrizDinamica(matriz);
}

int main()
{
    int a[10][5];
    float b[3][2][4];

    int m[FIL][COL] = { {1, 0, 0},
                        {0, 1, 0},
                        {0, 0, 1} };
     
    // showMatriz(m);
    // showMatrizP(9);
    // showMatrizInt();
    // showArrayString();
    //showMatrizString(); 
    MatrizDinamica(4);
    return 0;
}
 MatrizDinamica(4);
    return 0;
}
 cout << "\r" << c[i%5] << " " <<setw(3) <<i << " % ";
        usleep(SLEEP);
    }
}

void showBarLoading(int size)
{
    for (int i = 0; i <= 100; i++)
    {   
        cout << "\r[" << setBar("=", size).replace(i%size,1,"-") << "] " <<setw(3) <<i << " % ";
        usleep(SLEEP);
    }
}

void showWaitingLoading(int size)
{
    bool avanzar=false;
    for (int i = 0; i <= 100; i++)
    {   
        if(i%size==0)
            avanzar =!avanzar;
        int ix = (avanzar)? i%size: (size - i%size);
        cout << "\r[" << setBar(" ", size).replace(ix,0,"<>") << "] " <<setw(3) <<i << " % ";
        usleep(SLEEP);
    }
}

void showFace()
{
     for (int i = 0; i < 15; i++)
     {
         cout << "\x1B[2J\x1B[H";
        string desplazar = setBar("  ",i);
        cout << "\r" << desplazar << "   \\|||/  " << endl;
        cout << "\r" << desplazar << "   (> <)   " << endl;
        cout << "\r" << desplazar << "ooO-(*)-Ooo" << endl;
        usleep(SLEEP*5);
     }
}

int main()
{
    showFace();
    showWaiting();
    cout<< endl;
    showLoadingSpinner();
    cout<< endl;
    showBarLoading(20);
    cout<< endl;
    showWaitingLoading(20);
    cout<< endl;
    return 0;
}

/*
Guión, 
conceptualizaón
codigo
    - explicar lib
    - main
    - metodos
    - ejecucion
*/