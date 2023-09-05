/**
 * Copyright ©2023. 
 * All rights reserved, pat_mic
 * libreria de utilitarios para fines académicos
 **/
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>
// #include <string.h>
#include <vector>
#include <conio.h>
#include <string>
#include <conio.h>
#include "windows.h"

using namespace std;

const string WHITESPACE = " \n\r\t\f\v";
//===Color font ===/
#define COLOR_BLACK   "\x1B[30m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_WHITE   "\x1B[37m"
#define COLOR_ORANGE  "\x1B[38;2;255;128;0m"
#define COLOR_ROSE    "\x1B[38;2;255;151;203m"
#define COLOR_LBLUE   "\x1B[38;2;53;149;240m"
#define COLOR_LGREEN  "\x1B[38;2;17;245;120m"
#define COLOR_GRAY    "\x1B[38;2;176;174;174m"
#define COLOR_RESET   "\x1b[0m"

//===Color background ===/
#define BG_BLACK   "\x1B[40m"
#define BG_RED     "\x1B[41m"
#define BG_GREEN   "\x1B[42m"
#define BG_YELLOW  "\x1B[43m"
#define BG_BLUE    "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_CYAN    "\x1B[46m"
#define BG_WHITE   "\x1B[47m"
#define BG_ORANGE  "\x1B[48;2;255;128;0m"
#define BG_LBLUE   "\x1B[48;2;53;149;240m"
#define BG_LGREEN  "\x1B[48;2;17;245;120m"
#define BG_GRAY    "\x1B[48;2;176;174;174m"
#define BG_ROSE    "\x1B[48;2;255;151;203m"

//Colores de texto
#define textColorBlack 30
#define textColorRed 31
#define textColorGreen 32
#define textColorYellow 33
#define textColorBlue 34
#define textColorMagenta 35
#define textColorCyan 36
#define textColorWhite 37

//colores de fondo
#define fnBgBlack 40
#define fnBgRed 41
#define fnBgGreen 42
#define fnBgYellow 43
#define fnBgBlue 44
#define fnBgMagenta 45
#define fnBgCyan 46
#define fnBgWhite 47

/**
 * El primer valor es del color de texto y el segundo del color del fondo
*/
void setColor(int color, int BG_color)
{
        printf("%c[%d;%d;%dm", 0x1B, 1,color,BG_color);
}

/**
 * setTextColor, permite definir el color de texto
 * ejemplo: setTextColor(textColorBlue);
*/
void setTextColor(int color)
{
        printf("%c[%d;%dm", 0x1B, 1,color);
}
#define TIEMPO 100000
enum escapes 
{ 
	BELL 		= '\a', 
	RETROCESO 	= '\b',
	TAB 		= '\t',
	ENTER 		= '\n', 
	TAB_V 		= '\v', 
	RETORNO 	= '\r'
};

enum months { ENE = 1, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC };

void clearTerminal()
{
    system("cls||clear"); 
    fflush(stdout); 
    //cout << "\033[H\033[2J\033[3J" ;
    //cn.clear();
}

int getNumeroPositivo(char *label) //
{
    int numero;
    char str[3];  //999 abc
    do
    {
        printf("\n %s", label);
        gets(str);
        sscanf(str,"%d", &numero);   
    } while (numero <= 0 );
    fflush(stdin);
    return numero;  
}

char menuGeneral( char *showOpc)
{
    char opc='-';
    do{
        printf("\n %s", showOpc);
        scanf("%c",&opc);
    }while ( !((opc =='1') || (opc =='2') || (opc =='3')) ) ;
    return opc;
}

void getLinea(char *str)    // line[lim = 10] -->   {h|o|l|a| |c|o|m|o|\n|\0|~|~|~|}
{      
    char c;
     int i =0;  
    do{
        c = getchar();
        str[i++] = c;
    }while(c != '\n');
    str[i]  == '\0';
}



void loading()
{
    int contadorC=0;
    char c[5] ="\\|/- ";

    for (int i = 0; i <= 100; i++)
    {
        if(contadorC==5)
            contadorC =0;
        printf("%c%c%c %d %% ", RETORNO,TAB, c[contadorC++],i);
        usleep(TIEMPO);
    }
}

void loadingShort()
{
    char c[] ="\\|/- ";
    for (int i = 0; i <= 100; i++)
    {
        //contadorC== (i%5==0) ? i%5 : 0;
        printf("\r%c %3d %% ",c[i%5],i);
        //usleep(TIEMPO);
    }
}

void LoadingBar(int size)
{ 
    char barra[size];
    float porcentaje = (float)100/(float)size;
    for (int i = 0; i <= size; i++)
        barra[i]=' ';
    
    for (int i = 0; i <= size; i++)
    {
        barra[i]='#';
        printf("%c%c [%s]  %.0f %%", RETORNO, TAB, barra, i*porcentaje);
        usleep(TIEMPO*2);
    }
}

/**
 * trimLeft: retorna una cadena eliminando espacios en blanco por la izquierda
 * @param s   : cadena de caracteres
*/
string ppTrimLeft(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE); //     "   pepep   "
    return (start == string::npos) ? "" : s.substr(start);
}
/**
 * trimRight: retorna una cadena eliminando espacios en blanco por la derecha
 * @param s   : cadena de caracteres
*/
string ppTrimRight(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE); //      " pepe 		"
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}
/**
 * trim: retorna una cadena eliminando espacios en blanco por la derecha e izquierda
 * @param s   : cadena de caracteres
*/
string ppTrim(const string &s)
{
    return ppTrimRight(ppTrimLeft(s));		// " loro 	"  -> "loro"
}
/**
 * tolowerStr: retorna una cadena en minusculas
 * @param str   : cadena de caracteres
*/
string ppToLowerStr(string str)
{
    for (int x=0; x < str.length(); x++)
        str[x] = tolower(str[x]);
    return str;
}
/**
 * toupperStr: retorna una cadena en mayusculas
 * @param str   : cadena de caracteres
*/
string ppToUpperStr(string str)
{
    for (int x=0; x < str.length(); x++)
        str[x] = toupper(str[x]);
    return str;
}
/**
 * toCapitalStr: retorna una cadena con la 1ra letra en mayusculas
 * @param str   : cadena de caracteres
*/
string ppToCapitalStr(string str)
{
    for (int x=0; x < str.length(); x++)
         str[x] = (x==0) ? toupper(str[x]) : tolower(str[x]);
    return str;
}
/**
 * getString :divide una cadena de caracteres segun un caracter
 * @param str   : cadena de caracteres
 * @param delim : carater para segmentar
 * @param outlst: lista de cadenas obtenidas de la division
*/
void ppSplitStr( const string  str, const char delim,  vector<string> &outlst )
{
    string strDiv;
    stringstream s(str);
    while ( getline(s, strDiv, delim) )
        outlst.push_back(strDiv);
}
/**
 * getString : Obtiene una cadena desde la consola
 * @param etiqueta  : Nombre de la etiqueta del campo a obtener
 * @param respuesta : int, valor a leer de tipo entero
 */
void ppGetString(string etiqueta, string &respuesta)
{
 	cout << etiqueta;
    //getline(cin, respuesta);
    cin>>respuesta;
    cin.get();
	cin.clear();
    fflush(stdin);
}
/**
 * getNumber : Obtiene un numero entero desde la consola
 * @param etiqueta  : Nombre de la etiqueta del campo a obtener
 * @param respuesta : int, valor a leer de tipo entero
 */
void ppGetNumber(string etiqueta, int &respuesta)
{
	cout<< etiqueta;
	cin >> respuesta ;
	cin.clear();
    fflush(stdin);
}
/**
 * getNumber : Obtiene un numero decimal desde la consola
 * @param etiqueta  : Nombre de la etiqueta del campo a obtener
 * @param respuesta : float,  valor a leer de tipo entero
 */
void ppGetNumber(string etiqueta, float &respuesta)
{
	cout<< etiqueta;
	cin >> respuesta;
	cin.clear();
    fflush(stdin);
}
/**
 * getNumberPosi : Obtiene un numero entero positivo desde la consola
 * @param etiqueta  : Nombre de la etiqueta del campo a obtener
 * @param respuesta : int que referencia a memoria del numero a leer
 */
void ppGetNumberPosi(string etiqueta, int &respuesta)
{
    string str;
    do {
        cout<<etiqueta;
        getline (cin,str);
        
        cin.clear();
        fflush(stdin);
        try
        {
            respuesta = stoi(str);
        }
        catch(const exception& e)
        {
            respuesta =-1;
            //cout << " :( Valor no valido... " << endl;
        }
    } while (respuesta<0);
}
/**
 * ppGetNumberBetween : Obtiene un numero entero entre min y max desde la consola
 * @param etiqueta  : Nombre de la etiqueta del campo a obtener
 * @param respuesta : int que referencia a memoria del numero a leer
 */
int ppGetNumberBetween(string etiqueta, int min, int max)
{
    int num;
    string str;
    bool numValido = false;
    do {
        cout<<etiqueta;
        getline (cin,str);

        numValido = false;
        cin.clear();
        fflush(stdin);
        try
        {
            num = stoi(str);
            if ((num >= min) && (num <= max))
                numValido = true;
        }
        catch(const exception& e)
        {
            num =min-1;
        }
    } while (!numValido);
    return num;
}
/**
 * procedimiento obtiene dato char
 **/
void ppGetCharArray(string etiqueta, char* dato )
{
    string str;
    cout << etiqueta;
    getline(cin, str);    //      pepe

    //cleaning data : space, tab, ret,....
    str = ppTrim(str);
    strcpy(dato ,str.c_str());

    cin.clear();
    fflush(stdin);
}

vector<string> SplitToVector (const string str, const char delim)
{
    string strDiv;
    vector <string> v;
    stringstream s(str);
    while (getline(s, strDiv, delim))
        v.push_back(strDiv);
    return v;

}

string ppGetPassword(string etiqueta)
{
    int i=0;
    char s[10] = { 0 };
    cout<<etiqueta;
	while ((s[i] = _getch()) && int(s[i++])!= 13)
		_putch('*');
	s[--i] ='\0';
	cin.clear();
    fflush(stdin);
	cout<<"\n";
	return s;
}

string ppGetStringTrim(string etiqueta)
{
    string str;
    do {
        cout<<etiqueta;
        getline (cin,str);
        cin.clear();
        fflush(stdin);
        try
        {
            str = ppTrim(str);
            if (str == "")
                throw 100;
        }
        catch(const exception& e)
        {
            cout << " :( Valor no valido... " << endl;
        }
    } while (str.length()<=0);
    return str;
}

void ppClearTerminal()
{
    // system ("cls");
    // system ("clear");
    cout << "\033[H\033[2J\033[3J" ;
    cin.clear();
    fflush(stdin);
}

string us1 = "claudia", us2 = "profe", psw1 = "1726416892", psw2 = "1234";

string getUser()
{
    string usI, pswI;
    cout << "Ingrese su usuario: ";
    cin >> usI;
    cout << "Ingrese su contraseña: ";
    cin >> pswI;

    for (int i = 0; i <= 2; i++)
    {
        if ((us1 == usI && psw1 == pswI) || (us2 == usI && psw2 == pswI))
        {
            cout << "Bienvenido " << usI << endl;
            break;
        }
        else
        {
            cout << "Vuelva a intentarlo" << endl;
            cout << "Ingrese su usuario: ";
            cin >> usI;
            cout << "Ingrese su contraseña: ";
            cin >> pswI;
        }
    }

    return usI;
}


#include <iostream>
#include<fstream>//f de files, stream flujo de datos, permite leer archivos de texto, binarios
#include <iomanip>

using namespace std;


struct Mascota//<--estructura
{
    string tipo;
    string nombre;
};
Mascota mascotaDomestica[7];
int indexMascota=0;

void strtSplit()
{
    
}

void getMascota(string lineArchivo, char del)
{
    struct Mascota m;
    stringstream ss(lineArchivo);
    string word;
    int i=1;
    while (!ss.eof())
    {    
        getline(ss, word, del);
        if(i==1)
            m.tipo=word;
        if(i==2)
            m.tipo=word;
        i++;
    }
    mascotaDomestica[indexMascota++]=m;

}

void showMascota()
{
    cout<<endl<<setw(10)<<"TIPO"<<"\t Nombre \n";
    for (auto &&m:mascotaDomestica)
        cout<<setw(10)<<m.tipo<<" \t "<<m.nombre<<endl;//setw formateador de datos
}

void addMascota()
{
    struct Mascota m;
    cout<<endl<<"Ingresa el tipo de mascota";
    getline(cin, m.tipo);
    cout<<"Ingresa el nombre de mascota: ";
    getline(cin, m.nombre);
    mascotaDomestica[indexMascota++]=m;
}

bool readArchivo(string pathFileName)//path ruta del archivo
{
    fstream f;
    string line;


    cout << "readArchivo:" << pathFileName<< endl;
    f.open(pathFileName, ios_base::in);//in indica que sera solo de lectur
    if(!f.is_open())
        cout<<"error al abrir el archivo"<<pathFileName<<endl;
    else
    {
        while(!f.eof() )
        {
            getline(f, line);
            cout<<line<<endl;
        }
        return true;
    }    
    f.close();
    return false;
}
// tener cuidado de cuadrar el archivo y que no esté en edición o si este leyendo 2 archivos al mismo 

bool saveMascota(string pathFileName)//path ruta del archivo
{
    fstream f;
    string line;

    cout << "saveMascota:" <<pathFileName<< endl;
    f.open(pathFileName, ios_base::out);
    if(!f.is_open())
    {    
        cout<<"error al guardar el archivo"<<pathFileName<< endl;
        return false;
    }
    
    for (int i = 0; i < indexMascota; i++)
    {
        auto &&m==mascotaDomestica[i];
       f<< m.tipo<< " ; "<< m.nomre<< endl; //<-guarda en el archivo
    }
    
        
      
    f.close();
    cout<<endl<<"mascota guardada"<<endl;
    return false;
}

bool readMascota(string pathFileName)
{
    fstream f;
    string line;


    cout << "readArchivo:" <<pathFileName<< endl;
    f.open(pathFileName, ios_base::in);
    if(!f.is_open())
    {    
        cout<<"error al abrir el archivo"<<pathFileName<<endl;
        return false;
    }
    
    while(!f.eof() )//mientras no este al final de la linea
    {
        getline(f, line);
        getMascota(line, ';');
    }
      
    f.close();
    cout<<endl<<"lectura exitosa";
    return false;
}

void showArray(int i, int j)
{
    system("cls"); // Limpia la pantalla en Windows
    cout << endl << endl
         << setColor(green) << " " << string(i * 3, ' ') << "i"
         << setColor(blue) << endl << "[";
    for (int k = 0; k < 8; k++)
    {
        if (k == i) cout << setColor(green);
        if (k == j) cout << setColor(naranja);
        cout << n[k] << " " << setColor(blue);
    }
    cout << "]" << endl
         << setColor(naranja) << " " << string(j * 3, ' ') << "j" << endl;
    usleep(SLEEP);
}

void bubbleSort()
{
    showArray(0, 0);
    for (int i = 0; i < 8; i++)
    {
        for (int j = i; j < 8; j++)
        {
            showArray(i, j);
            if (n[i] > n[j])
            {
                cout << endl << string(i * 3, ' ') << setColor(naranja)
                     << "SWAP(" << n[i] << ">" << n[j] << ")" << endl;
                cin.get();
                tmp = n[i];
                n[i] = n[j];
                n[j] = tmp;
            }
        }
    }
}

void stringSort(char str[], int len)  // Agregado len para la longitud de la cadena
{
    cout << setColor(red) << "Cadena original: "<<endl;
    for (int i = 0; i < len; i++)
    {
        cout << str[i];
    }
    
    for (int i = 0; i < len - 1; i++)
    {
        int menorElemento = i;
        for (int j = i + 1; j < len; j++)
        {
            if (str[j] < str[menorElemento])
            {
                menorElemento = j;
            }
        }
        if (menorElemento != i)
        {
            swap(str[i], str[menorElemento]);
        }
    }
    cout << setColor(green) << "Cadena ordenada: ";
    for (int i = 0; i < len; i++)
    {
        cout << str[i];
    }
    cout << endl;
}

void selectSort()
{
    for (int i = 0; i < 8; i++)
    {
        int min = i;
        for (int j = i + 1; j < 8; j++)
        {
            showArray(i, j);
            if (n[min] > n[j])
            {
                min = j;
                cout << endl << setColor(red) << "min = " << n[min] << endl;
                usleep(SLEEP);
            }
        }
        cout << endl << setColor(red) << "min = " << n[min] << endl;
        cout << "SWAP(" << n[i] << " > " << n[min] << ")" << endl;
        cin.get();

        tmp = n[i];
        n[i] = n[min];
        n[min] = tmp;
    }
    showArray(0, 0);
}

int main()
{
    // selectSort();
    // bubbleSort();
    int len = sizeof(str) / sizeof(str[0]);  // Calcula la longitud de la cadena
    stringSort(str, len);

    return 0;
}

enum ERRORES { E_DIV = 500, W_NUM_PAR, W_DEN_PAR};

int main()
{
    int a , b;

    cout << " -- division solo de pares -- "<<endl<<endl;
    cout << " ingresa numero par a: "; cin>>a;
    cout << " ingresa numero par b : "; cin>>b;

    try
    {
        if (b == 0)
            throw 500;  
        if (a%2 !=0)
            throw 501;  
        if (b%2 !=0)
            throw 502;
            
        cout << " division a/b : "<< a/b<<endl<<endl;
    }
    catch (const int e) 
    {
        switch (e)
        {
            case E_DIV :        cout<<"Error: Division por cero"<<endl<<endl;  
                                b=1;
                                cout << " Division arreglada a/b : "<< a/b<<endl<<endl;
                                b=0;
                                break;
            case W_NUM_PAR :    cout<<"Warning: Numerador no es par"<<endl<<endl;   break;
            case W_DEN_PAR :    cout<<"Warning: Denominador no es par"<<endl<<endl;   break;
        }
    }
    

    cout << " sumar a+b : "<< a+b<<endl<<endl;
    cout << " -- FIN -- ";
    /* do code */
}
// Unir 2 listas circulares simples:  lista L1 con L2 y muestra la L1 que es la final;

struct nodo
{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};

typedef struct nodo *TlistaC;

TlistaC lista1, lista2,  fin1, fin2;

void mostrarListas()
{
     TlistaC aux;
     aux = lista1;
     
     if(lista1!=NULL)
     {
          cout<<"\n\n Lista 1 :\n\n";           
          do
          {
               cout<<"  "<<aux->nro;
               aux = aux->sgte;
          }while(aux!=lista1);          
     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;
     
     aux = lista2;    
     if(lista2!=NULL)
     {
          cout<<"\n\n Lista 2 :\n\n";           
          do
          {
               cout<<"  "<<aux->nro;
               aux = aux->sgte;
          }while(aux!=lista2);          
     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;     
}

void insertar(TlistaC &lista, TlistaC &fin, int valor)
{
     TlistaC q;
     q = new(struct nodo);
     q->nro = valor;
     
     
     if(lista==NULL)
     {
          lista = q;
          lista->sgte = lista;
          fin = q ;          
     }
     else
     {
          fin->sgte = q;
          q->sgte = lista;
          fin = q;
     }
}

void ingresarListas()
{
     int tam1, tam2, dato;
     
     cout<<"\n Tamanio de lista 1 : "; cin>> tam1;
     cout<<endl;
     
     for(int i=0; i<tam1; i++)
     {
          cout<<"\tElemento "<<i+1<<": ";   cin>> dato;
          insertar(lista1, fin1, dato);  
     }
     
     cout<<"\n Tamanio de lista 2 : "; cin>> tam2;
     cout<<endl;
     
     for(int i=0; i<tam2; i++)
     {
          cout<<"\tElemento "<<i+1<<": ";   cin>> dato;
          insertar(lista2, fin2, dato);  
     }
}

void unirListas()
{
     fin1->sgte = lista2;
     fin2->sgte = lista1;
     
     cout<<"\n\n\tListas circulares L1 y L2 unidas..."<<endl;
}
void mostrarLista1()
{
     TlistaC aux;
     aux = lista1;
     
     if(lista1!=NULL)
     {
          cout<<"\n\n Lista 1 :\n\n";           
          do
          {
               cout<<"  "<<aux->nro;
               aux = aux->sgte;
          }while(aux!=lista1);          
     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;
}
void menu()
{
    cout<<"\n\t\tUNIR LISTAS CIRCULARES\n\n";
    cout<<" 1. INGRESAR LISTAS                  "<<endl;
    cout<<" 2. MOSTRAR LISTAS                   "<<endl;
    cout<<" 3. UNIR LISTAS                      "<<endl;
    cout<<" 4. MOSTRAR LISTA 1                  "<<endl;
    cout<<" 5. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

/*                        Funcion Principal
---------------------------------------------------------------------*/
int main()
{
    TlistaC lista = NULL;
    int op;     // opcion del menu
    
    TlistaC lista1 = lista2 = NULL;
    do
    {
        menu();  cin>> op;
        switch(op)
        {
            case 1:
                 ingresarListas( );
            break;
            
            case 2:
                 mostrarListas();
            break;
            
            case 3:
                 unirListas();
            break;
            
            case 4:
                 mostrarLista1();
            break;
                 
        }
        cout<<endl<<endl;
    }while(op!=5);
   return 0;
}
// Listas Enlazadas simples : Inserta, elimina, busca, muestra
 
struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};
 
typedef struct nodo *Tlista;
 
void insertarInicio(Tlista &lista, int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}
 
void insertarFinal(Tlista &lista, int valor)
{
    Tlista t, q = new(struct nodo);
    q->nro  = valor;
    q->sgte = NULL;
    if(lista==NULL)
        lista = q;
    else
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }
}

int insertarAntesDespues()
{
    int _op, band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;
 
    cout<<"\n\t Opcion : "; cin>> _op;
 
    if(_op==1)
        band = -1;
    else
        band = 0;
 
    return band;
}
 
void insertarElemento(Tlista &lista, int valor, int pos)
{ 
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->nro = valor;
 
    if(pos==1)
    {
        q->sgte = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesDespues();
        t = lista;
        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                q->sgte = t->sgte;
                t->sgte = q;
                return;
            }
            t = t->sgte;
        }
    }
    cout<<"   Error...Posicion no encontrada..!"<<endl;
}
 
void buscarElemento(Tlista lista, int valor)
{
    Tlista q = lista;
    int i = 1, band = 0;
 
    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }
 
    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}
 
void reportarLista(Tlista lista)
{
     int i = 0;
     while(lista != NULL)
     {
          cout <<' '<< ++i <<") " << lista->nro << endl;
          lista = lista->sgte;
     }
}
 
void eliminarElemento(Tlista &lista, int valor)
{
    Tlista p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;
                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}
 
void eliminaRepetidos(Tlista &lista, int valor)
{
    Tlista q, ant;
    q = lista;
    ant = lista;
    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            if(q==lista) // primero elemento
            {
                lista = lista->sgte;
                delete(q);
                q = lista;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }
 
    }// fin del while
   
    cout<<"\n\n Valores eliminados..!"<<endl;
}
 
void menu1()
{
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. INSERTAR EN UNA POSICION         "<<endl;
    cout<<" 4. REPORTAR LISTA                   "<<endl;
    cout<<" 5. BUSCAR ELEMENTO                  "<<endl;
    cout<<" 6. ELIMINAR ELEMENTO 'V'            "<<endl;
    cout<<" 7. ELIMINAR ELEMENTOS CON VALOR 'V' "<<endl;
    cout<<" 8. SALIR                            "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}
 
/*                        Funcion Principal
---------------------------------------------------------------------*/
int main()
{
    Tlista lista = NULL;
    int op;     // opcion del menu
    int _dato;  // elemenento a ingresar
    int pos;    // posicion a insertar
 
    do
    {
        menu1();  cin>> op;
        switch(op)
        {
            case 1:
                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 insertarInicio(lista, _dato);
            break;
            case 2:
                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 insertarFinal(lista, _dato );
            break;
            case 3:
                 cout<< "\n NUMERO A INSERTAR: ";cin>> _dato;
                 cout<< " Posicion : ";       cin>> pos;
                 insertarElemento(lista, _dato, pos);
            break;
            case 4:
                 cout << "\n\n MOSTRANDO LISTA\n\n";
                 reportarLista(lista);
            break;
            case 5:
                 cout<<"\n Valor a buscar: "; cin>> _dato;
                 buscarElemento(lista, _dato);
            break;
            case 6:
                cout<<"\n Valor a eliminar: "; cin>> _dato;
                eliminarElemento(lista, _dato);
            break;
            case 7:
                cout<<"\n Valor repetido a eliminar: "; cin>> _dato;
                eliminaRepetidos(lista, _dato);
            break;
        }
        cout<<endl<<endl;
    }while(op!=8);
   return 0;
}
