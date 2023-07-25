
//1.- hacer carpeta: data, archivo txt: alumnos(nombres), mascotas(tipo, nombre), en carpeta
//src hacer escalibur(archivo en notas)
    /*rubber duck debugging: tecnica de programacion donde se le explica el codigo a " un patito de hule"
    
    */
#include <iostream>
#include<fstream>//f de files, stream flujo de datos, permite leer archivos de 
/*ARCHIVOS DE TEXTO, 24/JUL/2024*/


using namespace std;

struct mascotas//<--estructura
{
    string tipo;
    string nombre;
}
Mascota mascotaDomestica[5]

bool reafArchivos(string pathFileName)//path ruta del archivo
{
    fstream f;
    string line;
    
    cout << "readArchivo:" << endl;
    f.open(pathFile, ios_base::in);
    if(!f.is_open())
        cout<<"error al abrir el archivo"<<pathFile<<endl;
    else
    {
        while(!f.eof() )
        {
            getLine(f, line);
            cout<<line<<endl;
            
        }
        return true;
    }    
    f.close();
    return false;
}
// tener cuidado de cuadrar el archivo y que no esté en edición o si este leyendo 2 archivos al mismo 
void strtSplit(cons)

bool readMascota(string pathFileName)
{
    fstream f;
    string line;
    
    cout << "readArchivo:" <<pathFile<< endl;
    f.open(pathFile, ios_base::in);
    if(!f.is_open())
        cout<<"error al abrir el archivo"<<pathFile<<endl;
    else
    {
        while(!f.eof() )
        {
            getLine(f, line);
            cout<<line<<endl;
            
        }
        return true;
    }    
    f.close();
    return false;
}


int main()
{
    cout<<"---alumnos---"
    readArchivo("../../data//alumnos.txt");
    
    cout<<"---mascotas---"
    readArchivo("../../data//mascotas.txt");
    cout<< endl;
    return 0;
    
    
}

/*estructura de datos*/