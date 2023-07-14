    /*10,11/17/2023
        Claudia Coello
        Coreccion prueba: detalles de login con vetores
        Introduccion a vectores
        Recursividad
    */
#include <iostream>
#include <vector>
#define NIVEL 4
#define DELAY 100000
using namespace std;
// #define PPCEDULA;
// #define PPCORREO;
//                                                     //EXAMEN
// bool pplogin{
//     int ppIntento = 2;
//     vector<string> usuarioClaves= [PPCORREO+PPCEDULA,"PROFE"+"1234"+"pepe12345"];//ME PERMITE AGRAGAR USUARIOS SIN DEFiNIR UN TAMAÑO, puedo empezarr con o sin valores
//     do
//     {
//         cout<<"\t\t ..............."<<endl;
//         string u=getText("\t\t + Usuario: ");
//         string u=getPass("\t\t + Clave: ");
//         cout<< "\t\t .................."<<endl;
//         for (auto &&uc : usuariosClaves)//sirve para trabajar de manera secuencial y recorre todo el vector, auto me permite trabajar sin definir el tipo de dato
//         {
//             if (u+c=uc)//usuario + password
//                 {
//                     cout<<endl<<" ::Bienvenido"<<u;
//                     return true;
//                 }
//             cout<<"\t\t *Nro intentos: "<<--ppIntento<<endl<<endl;
//         }
//     } while (ppIntentos>0);
//     cout<<endl<<endl<<"\t :( Los sentimos tu usuario o contraseña son incorrectos"<<endl;
//     return false;
    

// }
                            //RECURSIVIDAD: LLAMARSE A SI MISMO VARIAS VECES, O MENCIONANDOSE, como funciones
/*La recursividad es un patron de un  escenario que se repite varias veces, puede quedarse infinitamente, como en un espejo frente a otro, 
para deterlo necesito un condicional
Recursion:  Es un tecnica de programcion que busca resolver un problema sustituyendolo con otros problemas de la misma categoria, mas simple y un algoritmo recursivo
Solo una funcion puede ser recursiva(un procedimiento es void),  lo que esta dentro de un bucle puede ser una funcion recursiva
Se llama si se busca ejecutarse de forma continua de manera mas estructuradas

CONDICIONES: comportamineto continuo
-Al menos un caso base de parada o salida; un paso para que deje de llamarse a si misma
-Induccion: Paso recursivo que provoca una llamada recursiva, genera una secuencia, es
-Convergencia: dar tantas vueltas hasta que llegue a un valor, el resultado o problema debe ser mas pequeño cada vez

USOS
Se usa para problemas mas cercanos a la matematica
Lectura facil de analizar
Busqueda binaria, listas recursivas, particiones, arboles, series de fibonacci

--OJO VA DE LO MAS GRANDE A LO MAS PEQUEÑO--

EJEMPLOS
Eliminar directorios, con todos sus archivos y subdirectorios
*/
//PATRON MATEMATICO DE LAS FACTORIALES
//^ 0!=1                          <---base
//| 1!=1
//| 2!=2+1! -> 2*1 -> 2...

int factorial( int n)
{
    cout << n << endl;
    if(n==1 || n=0)             //condicion de parada, deja de repetir al llegar a 1
        return 1;
    return n*factorial(n-1);    //lamada recursiva a la funcion que lleva a la condicion de parada, n es el valor que me dara, se esta haciendo mas pequeño
    //[factorial(5)->5*factorial(4)->4*fatorial(3)...->1*factorial(0)]<--pilas,  va uno sobre otro
}//Aqui debo esperar a que me pase el valor de resultado

/*Se busca una forma de memorizar y que sea recursivo, 
mejora el rendimiento a medida que n crece, cada pila usa memoria, este codigo evita esto(memoria retenida)
*/

//la primera vez es recusiva, el resto es memoria, voy bajando pero no necesita tener que esperar a que termine la operacion anterior se multiplica por una constante
//sale el valor directamente a quien lo invoco
int factorialMemRetenida( int n, int r)//n<--base//
{
    if(n=0)             //condicion de parada, deja de repetir al llegar a 1
        return r;
    else
        return factorialMemRetenida (n-1, n*r);//menora en 1 y se multiplica
    //factorial(5<-n inicial-1, 1<-n*r desde 1)->factorial (4,5*1), ->factorial (3, 4*5), ->factorial (2, 3*20),
}

int fibonnacci(int n)
{
    if (n==1 || n==2)
       return n-1;
    else   
        return fibonnacci (n-1)+fibonnacci(n-2);
    
}
//para operaciones numericas muy grandes con mucha memoria o virus

//otro ejemplo de memoria retenida
//a=3, b=4, (3, 4)=>suma (4, 3)=> suma (5, 2)=> suma (6, 1)=> suma(7, 0)
int suma(int a, int b)
{
    if (b=0)//<= cuando b llega a 0 retornara la utima operacion
        return a;
    else
        return suma(++a, --b);//uno va a subir, el otro bajar
}
int multiplicacion(int a, int b)
{
    if (b=0 || a=0)//<= cuando b llega a 0 retornara la utima operacion
        return a;
    else
        return suma(++a, --b);//uno va a subir, el otro bajar
}

int potencia(int a, int b)
{
    if (b=0)//<= cuando b llega a 0 retornara la utima operacion
        return 1;
    else
        return potencia(a, b-1)*a;//uno va a subir, el otro bajar
}
//torres de hanoi<- tarea

//10 9 8 7 6 5 ... 1
string conteoRegresivo(int n)//de  bucle a 
{
   if(n==1)
      return to_string(n);//<- lo convertimos en string, entonces si podemos concatenarlo
   return to_string(n) +"-"+conteoRegresivo(n-1);//<- el else se obvia
}

//5 6 7 8 9 10
string conteoProgresivo(int numero)//de  bucle a 
{
   if(numero==10)
      return to_string(numero);//<- lo convertimos en string, entonces si podemos concatenarlo
   return to_string(numero) +" "+conteoRegresivo(numero+1);//oje, si fuese ++ despues numero aumentara despues
}

//mejoras
string conteoRegresivoMemoria(int n, string memoria)
{
    if(n==1)
        return memoria+ to_string(n);
    memoria+= to_string(n)+"-";
    return conteoRegresivoMemoria(n-1, memoria);
}

int main()
{
    int a, b, n = 15; 
    cout<< "Factorial de  "<< n <<" es " << factorial(n) << endl;
    cout<< "Factorial de  "<< n <<" es " << factorial(n,1) << endl;

    cout << "Operaciones:" <<endl; 
    cout << "Ingrese valor de a : ";    cin >> a;
    cout << "Ingrese valor de b : ";    cin >> b;
    cout << a << " + " << b << " = " << suma(a,b) << endl;
    cout << a << " * " << b << " = " << multiplicacion(a,b) << endl;
    cout << a << " elevado a " << b << " = " << potencia(a,b) << endl;
    cout<<"Conteo regresivo:"<<conteoRegresivo(10)<<endl;
    cout<<"Conteo progresivo:"<<conteoProgresivo(5)<<endl;
    cout<<"Conteo regresivo memoria:"<<conteoRegresivoMemoria(10, "")<<endl;//empieza con nada, el dato de partida se da aqui y no en el procedimiento

    return 0;
}

//JUEGO LAS TORRES DE HINORI

int TA[]={4,3,2,1};
int TB[NIVEL];
int TC[NIVEL];

string drawNivelTorre(const int nroDisk){
    //cout << nroDisk;
    string space="", disk="";
    for (int i=0; i <= NIVEL; i++)
        if(i<nroDisk)
            disk+="-";
        else
            space+=" ";
    return space + disk +"|"+ disk + space;
}

void showTorres(){
    for (int n = NIVEL - 1; n >= 0; n--) {
        cout<<drawNivelTorre(TA[n])    // TA[3]= 1 -    TA[2] = 2 --     TA[1] = 3 --- 
            <<drawNivelTorre(TB[n])
            <<drawNivelTorre(TC[n])
            <<endl ;
    }
}

int main()
{
    cout<<"Torres"<<endl;
    showTorres();
    return 0;
}

