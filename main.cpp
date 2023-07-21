// #include <iostream>
// #include "windows.h"
// using namespace std;

// #define NIVEL 4
// #define SLEEP 100000

// int TA[NIVEL];//={4,3,2,1}
// int TB[NIVEL];//={0,0,0,0}
// int TC[NIVEL];//={0,0,0,0}

// enum color{blue=1, green, turqueza, red, rosa, naranja, negro, gris};

// bool validarEntrada(string valor)
// {
//     switch (opc)
//     {
//     case a: return true;
//     case b: return true;
//     case c: return true;
//     }
//     return false;
// }

// void showMenu()
// {
//   string origenDisc="", destinoDisc="";
//   cout<<setColor(rosa)<<"Mover disco: "<<endl
//       <<"a.- Torre A"<<endl
//       <<"b.- Torre B"<<endl
//       <<"c.- Torre C"<<endl
//       <<"x.-Salir";
//     do
//     {
//       cout<<"Mover disco de la torre: ";
//       cin>>origenDisc;
//       cout<<"Hacia la torre: ";
//       cin>>destinoDisc;

//         if (origenDisc==destinoDisc && validarEntrada(origenDisc) && validarEntrada(destinoDisc))
//             cout<<endl<<"Intentelo nuevamente"<<endl;

//     } while (true);

// }

// string setColor(color c)
// {
//   HANDLE col=GetStdHandle(STD_OUTPUT_HANDLE) ;
//   SetConsoleTextAttribute(col, c);
//   return "" ;

// }

// string drawNivelTorre(const int nroDisk)
// {
//     //cout << nroDisk;
//     string space="", disk="";
//     for (int i=0; i <= NIVEL; i++)
//         if(i<nroDisk)
//             disk+="-";
//         else
//             space+=" ";
//     return space + disk +"|"+ disk + space;
// }

// void showTorres()
// {
//   cout<<setColor(red)<<\t  "Torre de Hanoi"<<endl<<endl<<setColor(blue);
//   for (int n = NIVEL - 1; n >= 0; n--)
//     cout<<drawNivelTorre(TA[n])<<drawNivelTorre(TB[n])<<drawNivelTorre(TC[n])<<endl;// TA[3]= 1 -    TA[2] = 2 --     TA[1] = 3 ---

// cout<<stew(5)<<"A"<<stew(9)<<"B"<<stew(9)<<"C"<<endl<<endl;
// }
// //stew(5)<<"A"<- significa:reserva 5 espacios y ponle a

// int getTopDisc(int torre[])
// {
//   int i=0;
//   for (; i=0; i< NIVEL, i++)
//     if (torre[i]==0)
//       break;
//   return i;

// }

// void showMatrizPrueba()
// {
//   cout<<endl<<"TA:  ";
//   for (auto &&n : TA/*<-Este es el array que quiero recorrer*/)//<-forrange sabe en que nivel empieza y en cual acaba, tiene un incremento de 1 automatico
//   {
//     cout<<n<<", ";
//     cout<<" TOP:  "<<getTopDisc(TA);
//   }

//   cout<<endl<<"TB:  ";
//   for (auto &&n : TB)
//   {
//     cout<<n<<", ";
//     cout<<" TOP:  "<<getTopDisc(TB);
//   }
//   cout<<endl<<"TC:  ";

//   for (auto &&n : TC)
//     {cout<<n<<", ";
//     cout<<" TOP:  "<<getTopDisc(TC);}
// }

// void moverDisco(int torreOrigen[], int torreDestino[])
// {

//   int inicio=getTopDisc(torreOrigen), final=getTopDisc(torreDestino);

//   if(inicio>0)
//     inicio--;

//   torreDestino[final]=torreOrigen[inicio];
//   torreOrigen[inicio]=0;
//   cout<<endl<<"";
// }

// int main()
// {
//   int disco=NIVEL;
//   for (int i = 0; i < NIVEL; i++)
//   {
//     TA[i]=TB[i]=TC[i]=0;
//     TA[i]=disco--;
//   }

//   // showMatrizPrueba();
//   showTorres();

//   moverDisco(TA, TB);
//   // showMatrizPrueba();
//   showTorres();
//   getchar();

//   moverDisco(TA, TC);
//   // showMatrizPrueba();
//   showTorres();
//   getchar();

//   moverDisco(TB, TC);
//   // showMatrizPrueba();
//   showTorres();
//   getchar();

//   cout<<endl;

//   return 0;

// }
#include <iostream>
#include "windows.h"
#include <iomanip>
using namespace std;

#define NIVEL 4
#define SLEEP 100000

int TA[NIVEL];//={4,3,2,1}
int TB[NIVEL];//={0,0,0,0}
int TC[NIVEL];//={0,0,0,0}

enum color { blue = 1, green, turqueza, red, rosa, naranja, negro, gris };

string setColor(color c)
{
    HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col, c);
    return "";
}

void moverDisco(int torreOrigen[], int torreDestino[])
{
    int inicio = getTopDisc(torreOrigen), final = getTopDisc(torreDestino);

    if (inicio > 0)
        inicio--;

    torreDestino[final] = torreOrigen[inicio];
    torreOrigen[inicio] = 0;
    cout << endl << "";
}

bool validarEntrada(string origenDisc, string destinoDisc)
{
    switch (origenDisc[0]) {
    case 'a':
    case 'b':
    case 'c':
        break;
    default:
        return false;
    }

    switch (destinoDisc[0]) {
    case 'a':
    case 'b':
    case 'c':
        break;
    default:
        return false;
    }

    return true;
}

void showMenu()
{
    string origenDisc = "", destinoDisc = "";
    cout << setColor(rosa) << "x.-Salir " << endl

    do
    {
      cout << "Mover disco de la torre: ";
      getline(cin, torreOrigen);
        cout << "Hacia la torre: ";
      getline(cin, torreDestino);
      try
      {
        if (origenDisc == destinoDisc && !validarEntrada(torreOrigen) && !validarEntrada(torreDestino) )
        throw invalid_argument("Opcion no valida");
      }
      catch(...)
      {
        torreOrigen=torreDestino="";
        cout<<"Opcion invalida";
      }

    } while (true);
  moverDisco(TA, TC);
  showTorres();
}

string drawNivelTorre(const int nroDisk, int tower[])
{
    //cout << nroDisk;
    string space = "", disk = "";

    if (tower[nroDisk - 1] != 0) {
        for (int i = 0; i < NIVEL; i++)
            if (i < nroDisk)
                disk += "-";
            else
                space += " ";
    }
    else {
        space += std::string(NIVEL, ' ');
    }
    return space + disk + "|" + disk + space;
}

void showTorres()
{
    cout << setColor(red) << setw(30) << "Torre de Hanoi" << endl << endl << setColor(blue);
    for (int n = NIVEL - 1; n >= 0; n--)
        cout << drawNivelTorre(TA[n], TA) << drawNivelTorre(TB[n], TB) << drawNivelTorre(TC[n], TC) << endl;

    cout << setw(5) << "A" << setw(9) << "B" << setw(9) << "C" << endl << endl;
}

int getTopDisc(int torre[])
{
    int i = 0;
    for (; i < NIVEL; i++)
        if (torre[i] == 0)
            break;
    return i;

}

void moverDisco(int torreOrigen[], int torreDestino[])
{
    int inicio = getTopDisc(torreOrigen), final = getTopDisc(torreDestino);

    if (inicio > 0)
        inicio--;

    torreDestino[final] = torreOrigen[inicio];
    torreOrigen[inicio] = 0;
    cout << endl << "";
}

int main()
{
  string origen="", 
 cout<< "sacar disco de la torre";
 cin>>origen;

    if (validarEntrada(origen))
      cout<<"invalido";
    getchar();
  getchar();
 
  int disco = NIVEL;
  for (int i = 0; i < NIVEL; i++)
  {
      TA[i] = TB[i] = TC[i] = 0;
      TA[i] = disco--;
  }

    // showMatrizPrueba();
    showTorres();

    moverDisco(TA, TB);
    showTorres();
    getchar();

    moverDisco(TA, TC);
    showTorres();
    getchar();

    moverDisco(TB, TC);
    showTorres();
    getchar();

    cout << endl;

    return 0;
}
