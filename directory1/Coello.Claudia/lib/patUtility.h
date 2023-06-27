/**
 * Copyright ©2023. All Rights Reserved, pat_mic
 * libreria de utilitarios para fines académicos de programación I - EPN
 * 
 * ©2023 pat_mic, All Rights Reserved.
 * @author: pat_mic
 * @date : 2022.08.24
 **/
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <conio.h>

using namespace std;
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
void setColor(int color, int BG_color){
        printf("%c[%d;%d;%dm", 0x1B, 1,color,BG_color);
}

/**
 * setTextColor, permite definir el color de texto
 * ejemplo: setTextColor(textColorBlue);
*/
void setTextColor(int color){
        printf("%c[%d;%dm", 0x1B, 1,color);
}

const string WHITESPACE = " \n\r\t\f\v";

/**
 * trimLeft: retorna una cadena eliminando espacios en blanco por la izquierda
 * @param s   : cadena de caracteres
*/
string ppTrimLeft(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE); //     "   pepep"
    return (start == string::npos) ? "" : s.substr(start);
}
/**
 * trimRight: retorna una cadena eliminando espacios en blanco por la derecha
 * @param s   : cadena de caracteres
*/
string ppTrimRight(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE); //      "pepe 		"
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

#define TIEMPO 100000
enum escapes { 
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