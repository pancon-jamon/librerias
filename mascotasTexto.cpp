/*
ARCHIVOS DE TEXTO, 24,25/JUL/2024
CLAUDIA COELLO
PROGRAMACION I SEGUNDO BIMESTRE
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <iostream>
#include <vector>
#include "../lib/ccString.h"

#define DELAY 150
const int animationDelay = 200;

using namespace std;

const string pathMascota="../data/mascotas.txt";
const string pathCliente="../data/clientes.txt";

enum color { blue = 1, green, turqueza, red, rosa, naranja, negro, gris };

string setColor(color c)
{
    HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col, c);
    return "";
}

void cargaFigura()
{
    const int vecesPresentado = 5;
    string figura = "0oo";
    string figura2 = "o0o";

    for (int frame = 0; frame <= vecesPresentado; ++frame)
    {
        cout << "\r" << figura << flush; 
        Sleep(DELAY);

        if (figura2 == "o0o")
            figura2 = "oo0";
        else if (figura2 == "oo0")
            figura2 = "0oo";
        else if (figura2 == "0oo")
            figura2 = "o0o";

        figura = figura2; 
    }

    cout << endl; 
}

struct Mascota
{
    int idCliente;
    string tipo;
    string raza;
    string sexo;
    int edad;
    string nombre;
};

struct Cliente
{
    int ID;
    string nombre;
    string cedula;
    vector<Mascota> pets;
};
vector<Cliente> cliente;

Mascota mascotaDomestica[7];
Cliente clienteConMascota[7];

int indexMascota = 0;
int indexCliente=0;

void showMascota()
{
    ifstream f;
    string line;
    f.open(pathMascota);

    if (!f.is_open())
    {
        cout << setColor(red) << "Error al abrir el archivo " << pathMascota << endl;
        return;
    }

    cout << endl;
    cout << setw(10) << "TIPO" << "\t\t" << "RAZA" << "\t\t" << "SEXO" << "\t\t\t" << "EDAD" << "\t\t" << "NOMBRE" << endl;

    bool firstLine = true; // Variable para verificar si es la primera línea

    while (getline(f, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue; // Omitir la primera línea
        }

        struct Mascota m;
        vector<string> vDato;
        // getMascota(line, ';');

        vDato = SplitToVector(line, ';');

        m.idCliente= stoi(vDato.at(0));
        m.tipo     = ppToCapitalStr (vDato.at(1));
        m.nombre   = ppToCapitalStr (vDato.at(2));
        m.sexo     = ppToCapitalStr (vDato.at(3));
        m.edad     = stoi(vDato.at(4));
        m.raza     = ppToCapitalStr (vDato.at(5));

        if(m.idCliente==2)
            cout << endl<<"     "  << m.tipo<<"           "  << m.nombre<<"           "  << m.sexo <<"              "  << m.edad <<"                  "  << m.raza;
        // cout << endl << "Tipo:   " << m.tipo << "\t Nombre:" << m.nombre << "\t Sexo:" << m.sexo << "\t Edad:" << m.edad << "\t Raza:" << m.raza;
    }

    f.close();
    cout << endl << "Lectura exitosa." << endl;
}

void showCliente()
{
    ifstream f;
    string line;
    f.open(pathCliente);

    if (!f.is_open())
    {
        cout << setColor(red) << "Error al abrir el archivo " << pathCliente << endl;
        return;
    }

    cout << endl;
    cout << setw(10) << "ID" << "\t\t" << "CEDULA" << "\t\t" << "NOMBRE" << endl;

    bool firstLine = true;

    while (getline(f, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }

        struct Cliente c;
        vector<string> vDatoCliente;

        vDatoCliente = SplitToVector(line, ';');

        c.ID = stoi(vDatoCliente.at(0));
        c.nombre = ppToCapitalStr(vDatoCliente.at(1));
        c.cedula = vDatoCliente.at(2);

        if (c.ID == 2)
            cout << endl << "     " << c.ID << "           " << c.cedula << "           " << c.nombre;
    }

    f.close();
    cout << endl << "Lectura exitosa." << endl;
}

void addMascota()
{
    Mascota m;
    bool edadValida = false;

    cout << endl << "Ingresa el tipo de la mascota: ";
    getline(cin, m.tipo);

    cout << "Ingresa la raza de la mascota: ";
    getline(cin, m.raza);

    cout << "Ingresa el sexo de la mascota: ";
    getline(cin, m.sexo);

    do
    {
        cout << "Ingresa la edad de la mascota: ";
        string edadStr;
        getline(cin, edadStr);
        try
        {
            m.edad = stoi(edadStr);
            edadValida = true;
        }
        catch (const exception &e)
        {
            cout << "Porfavor ingrese un numero entero" << endl;
        }
    } while (!edadValida);

    cout << "Ingresa el nombre de la mascota: ";
    getline(cin, m.nombre);

    mascotaDomestica[indexMascota++] = m;
}

void saveMascota()
{
    ofstream f;
    f.open(pathMascota, ios::app);

    if (!f.is_open())
    {
        cout << "Error al guardar el archivo " << pathMascota << endl;
        return;
    }

    for (int i = 0; i < indexMascota; i++)
    {
        f << mascotaDomestica[i].idCliente << ";" << mascotaDomestica[i].tipo << ";" << mascotaDomestica[i].raza << ";" << mascotaDomestica[i].sexo << ";" << mascotaDomestica[i].edad << ";" << mascotaDomestica[i].nombre << endl;
    }

    f.close();
    cout << endl << "Todos los datos guardados exitosamente." << endl;
}

void saveCliente()
{
    ofstream f;
    f.open(pathCliente, ios::app);

    if (!f.is_open())
    {
        cout << "Error al guardar el archivo " << pathCliente << endl;
        return;
    }

    for (int i = 0; i < indexCliente; i++)
    {
        f << clienteConMascota[i].ID << ";" << clienteConMascota[i].nombre << ";" << clienteConMascota[i].cedula << endl;
    }

    f.close();
    cout << endl << "Todos los datos guardados exitosamente." << endl;
}

bool readMascota(string pathFileName)
{
    ifstream f;
    string line;
    // int fileSize = 0;
    // int bytesRead = 0;

    f.open(pathFileName);
    if (!f.is_open())
    {
        cout << "Error al abrir el archivo " << pathFileName << endl;
        return false;
    }

    // Obtener el tamaño total del archivo
    // f.seekg(0, ios::end);
    // fileSize = f.tellg();
    // f.seekg(0, ios::beg);

    while (!f.eof())

    {
        struct Mascota m;
        vector<string> vDato;
        getline(f, line);
        //bytesRead += line.size() + 1; // Sumar el tamaño de la línea y un caracter de nueva línea
        
        vDato = SplitToVector(line, ';');

        m.idCliente= stoi(vDato.at(0));
        m.tipo     = ppToCapitalStr (vDato.at(1));
        m.nombre   = ppToCapitalStr (vDato.at(2));
        m.sexo     = ppToCapitalStr (vDato.at(3));
        m.edad     = stoi(vDato.at(4));
        m.raza     = ppToCapitalStr (vDato.at(5));

    }

    f.close();
    cout << endl << "Lectura exitosa." << endl;
    return true;
}

bool readCliente()
{
    ifstream f;
    string line;

    f.open(pathCliente);
    if (!f.is_open())
    {
        cout << "Error al abrir el archivo " << pathCliente << endl;
        return false;
    }

    while (getline(f, line))
    {
        struct Cliente c;
        vector<string> vDato;
        vDato = SplitToVector(line, ';');

        c.ID = stoi(vDato.at(0));
        c.nombre = ppToCapitalStr(vDato.at(1));
        c.cedula = vDato.at(2);
    }

    f.close();
    cout << endl << "Lectura exitosa." << endl;
    return true;
}

void menuMascota()
{
    int opc = 0;
    
    while (true)
    {
        string ingreso;
        cout << "\t\t---clientes viejos---" << endl;
        cout << setColor(blue) << "1.- Recuperar mascota" << endl << setColor(rosa) << "2.- Agregar mascota" << endl << setColor(green) << "3.- Presentar Mascota" << setColor(naranja) << endl << setColor(turqueza) << "4.- Guardar mascota" << endl << setColor(red) << "5.- Salir" << endl;
        cout <<setColor(naranja) <<"Ingrese una opcion: ";

        getline(cin, ingreso);
        try
        {
            opc = stoi(ingreso);

            if (opc >= 1 && opc <= 5)
            {
                switch (opc)
                {
                    case 1:
                        readMascota(pathMascota);
                        break;
                    case 2:
                        addMascota();
                        break;
                    case 3:
                        showMascota();
                        break;
                    case 4:
                        saveMascota(/*pathMascota*/);
                        break;
                    case 5:
                        cargaFigura();
                        return;
                }
            }
            else
            {
                cout << "Por favor, intente nuevamente." << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "Por favor, intente nuevamente." << endl;
        }
    }
            
}

void menuCliente()
{
    int opc = 0;
    string ingreso;

    cout << setColor(blue) << "1.- Agregar nuevo cliente" << endl;
    cout << setColor(rosa) << "2.- Agregar cedula" << endl;
    cout << setColor(green) << "3.- Generar ID" << endl;

    getline(cin, ingreso);
    opc = stoi(ingreso);

    Cliente c;

    switch (opc)
    {
        case 1:
            cout << "Ingrese el nombre del cliente: ";
            getline(cin, c.nombre);
            break;
        case 2:
            cout << "Ingrese la cedula del cliente: ";
            getline(cin, c.cedula);
            break;
        case 3:
            cout << "Ingrese el ID del cliente: ";
            getline(cin, ingreso);
            c.ID = stoi(ingreso);
            break;
        default:
            cout << "Opcion invalida" << endl;
            return;
    }

    clienteConMascota[indexCliente++] = c;

    int respuesta = 0;
    cout << "Ahora que desea hacer?" << endl;
    cout <<setColor(blue)<< "1 .- Volver (sin guardar)" << endl;
    cout <<setColor(rosa)<< "2 .- Guardar datos" << endl;
    cout <<setColor(turqueza)<< "3 .- Salir" << endl;
    cout << "Ingrese una opcion: ";

    getline(cin, ingreso);
    respuesta = stoi(ingreso);

    try
    {
        if (respuesta == 1)
        {
            int opc=0;
    
            try
            {
                string eleccion;
                cout<<"Que desea hacer?"<<endl
                    <<setColor(red)<<"1.-Ingresar un nuevo usuario"<<endl
                    <<setColor(naranja)<<"2.- Ingresar con un usuario existente"<<endl
                    <<setColor(gris)<<"3.-Salir";
                getline(cin, eleccion);
                opc = stoi(eleccion);

                if (opc>0 && opc<=3)
                {
                    switch (opc)
                    {
                        case 1:
                            menuCliente();
                            break;
                        case 2:
                            menuMascota();
                            return;
                            
                        case 3:
                            cargaFigura();
                            return;
                    }
                }
                
            }
            catch(const exception& e)
            {
                cout<<"Vuelve a intentarlo";
            }
            
        }
        else if (respuesta == 2)
        {
            saveCliente();
        }
        else if (respuesta == 3)
        {
            cargaFigura();
            return;
        }
        else
        {
            cout << "Opcion invalida" << endl;
        }
    }
    catch (const exception &e)
    {
        cout << "Opcion invalida" << endl;
    }
}

void menu()
{
    int opc=0;
    
    try
    {
        string eleccion;
        cout<<"Que desea hacer?"<<endl
        <<setColor(gris)<<"1.- Ingresar un nuevo usuario"
        <<endl<<setColor(rosa)<<"2.- Ingresar con un usuario existente"
        <<endl<<setColor(green)<<"3.-Salir"<<endl;
        getline(cin, eleccion);
        opc = stoi(eleccion);

        do
        {
            if (opc>0 && opc<=3)
            {
                switch (opc)
                {
                    case 1:
                        menuCliente();
                        break;
                    case 2:
                        menuMascota();
                        break;
                    case 3:
                        cargaFigura();
                        return;
                }
            }
        } while (opc=true);
        
    }
    catch(const exception& e)
    {
        cout<<"Vuelve a intentarlo";
    }
    
}

int main()
{
    cargaFigura();
    menu();
    return 0;
}
