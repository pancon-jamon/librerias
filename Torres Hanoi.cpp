#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <iomanip>//poder colocar el nombre a la matriz
using namespace std;

#define NIVEL 4
#define DELAY 100000

int TA[NIVEL];//={4,3,2,1}
int TB[NIVEL];//={0,0,0,0}
int TC[NIVEL];//={0,0,0,0}

enum opc{a=1,b,c};
enum color{blue=1, green, turqueza, red, rosa, naranja, negro, gris};

string setColor(color c)
{
    HANDLE col=GetStdHandle(STD_OUTPUT_HANDLE) ;
    SetConsoleTextAttribute(col, c);
    return "" ;
}

string drawNivelTorre(const int nroDisk)
{
    //cout << nroDisk;
    string space=string(NIVEL-nroDisk,' '), disk=string(nroDisk,'-');
    return space + disk +"|"+ disk + space;
}

int getTopDisc(int torre[])
{
    int i=0;
    for (; i=0; i< NIVEL; i++)
    if (torre[i]==0)
        break;
    return i;
}

void moverDisco(int torreIni[], int torreFin[])
{
    
    int ini=getTopDisc(torreIni), fin=getTopDisc(torreFin);

    if(ini>0)
        ini--;
    
    torreFin[fin]=torreIni[ini];
    torreIni[ini]=0;

}

void drawTorres()
{
    cout<<setColor(red)<<"\n\t  Torre de Hanoi"<<endl<<endl<<setColor(blue);
    for (int n = NIVEL - 1; n >= 0; n--)
        cout<<drawNivelTorre(TA[n])<< drawNivelTorre(TB[n])<< drawNivelTorre(TC[n])<< endl;// TA[3]= 1 -    TA[2] = 2 --     TA[1] = 3 ---

    cout<< setw(5)<< "A"<< setw(9)<< "B"<< setw(9)<< "C"<< endl<< endl;
}
//setw(5)<<"A"<- significa:reserva 5 espacios y ponle A's

void showMatrizPrueba()
{
    cout<<endl<<"TA:  ";
    for (auto &&n : TA/*<-Este es el array que quiero recorrer*/)//<-forrange sabe en que nivel empieza y en cual acaba, tiene un incremento de 1 automatico
        cout<<n<<", ";

    cout<<endl<<"TB:  ";
    for (auto &&n : TB)
        cout<<n<<", ";

    cout<<endl<<"TC:  ";
    for (auto &&n : TC)
        cout<<n<<", ";
  
}

bool validarEntrada(string opc)
{
    for (auto &&torre : {"a","b","c"})
        if(opc==torre)
            return true;
    return false;

}

void jugar()
{
    //int TA[NIVEL]-->TA[]-->*TA son equivalentes
    int *TI, *TF;
    string origenDisc="", destinoDisc="";
   
    do
    {
      try
      {
        cout<<setColor(rosa)<<endl<<"(x) para salir"<<endl;
        cout<<"Mover disco de la torre: ";
        getline(cin,origenDisc);
        cout<<"Hacia la torre: ";
        getline(cin,destinoDisc);
        cin.clear();

        if (origenDisc!=destinoDisc && validarEntrada(origenDisc) && validarEntrada(destinoDisc))
            break;
        throw invalid_argument("Opcion no valida");

      }
      catch(...)
      {
        origenDisc=destinoDisc="";
        cout<<setColor(red)<<"\n Opcion no valida";
      }
    } while (true);

    if(origenDisc=="a") TI==TA;
    if(origenDisc=="b") TI==TB;
    if(origenDisc=="c") TI==TC;
            
    if(destinoDisc=="a") TF==TA;
    if(destinoDisc=="b") TF==TB;
    if(destinoDisc=="c") TF==TC;

    moverDisco(TI, TF);
    drawTorres();

}
//0!=stricmp(origenDisc,destinoDisc)<--compara los 2 valores
void validarReglas()
{

}

void automatizacion()
{
    //showMatrizPrueba();

    // // showMatrizPrueba();
    // showTorres();

    moverDisco(TA, TB);
    drawTorres();
    showMatrizPrueba();
    drawTorres();
    getchar();

    moverDisco(TA, TC);
    drawTorres();
    showMatrizPrueba();
    drawTorres();
    getchar();

    moverDisco(TB, TC);
    drawTorres();
    showMatrizPrueba();
    drawTorres();
    getchar();

    moverDisco(TA, TB);
    drawTorres();
    showMatrizPrueba();
    drawTorres();
    getchar();

    moverDisco(TC, TA);
    drawTorres();
    showMatrizPrueba();
    drawTorres();
    getchar();

    moverDisco(TC, TB);
    drawTorres();
    showMatrizPrueba();
    drawTorres();
    getchar();

    moverDisco(TA, TB);
    drawTorres();
    showMatrizPrueba();
    drawTorres();
    getchar();
}

int main()
{
    int disco=NIVEL;
    for (int i = 0; i < NIVEL; i++)
    {
        TA[i]=TB[i]=TC[i]=0;
        TA[i]=disco--;
    }
    drawTorres();
    jugar();


    automatizacion();
    

    cout<<endl;
    return 0;
}

