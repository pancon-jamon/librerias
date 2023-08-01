/*
1:34:24
ARCHIVOS DE TEXTO, 1/AG/2023
CLAUDIA COELLO
PROGRAMACION I SEGUNDO BIMESTRE

modificadores:
v.front()
v.back()
push_back/front <-pone al ultimo o al inicio
pop_back/front<-saca el ultimo o el primer elemento
assign()
insert(posicion)
erase(posicion)
swap(cambio de posicion)
clear()<-borrar toda la lista

iteradores:permite ingresar , punteros
begin()
end()

capacidad:definir capacidad de almacenamiento
size(tamaño)
capacity()
resize(redimencionar)
empty(vaciar)
*/
#include "iostream"
#include "vector"

using namespace std;

void defVectorInt()
{
    int numero[]={2,3,4,9};//es lo mismo que vector
    vector<int> enteros={2,3,4,9};//vector+el tipo de dato+nombre(inicializando vacio)+valores(opc); puedo agregar datos y cambiarlo, con un array no puedo cambiarlo

    enteros.push_back(12);//agrega el 12 al vector
    cout<<endl<<"enteros: "<<endl;
    for (int n : enteros)//for para presentar los datos
        cout<<n<<" ";
    
    cout<<endl<<"numero"<<endl;
    numero[12]=4;
    for (int n : numero)//for para presentar los datos
        cout<<n<<" ";

}

void defVectorString()
{
     string str;
    vector <string> vNombresAlum;//={"pepe","juan","ana","lucia"}

    for (int i = 0; i < 5; i++)//agregar 5 nombres
    {
        cout<<endl<<"Ingrese un nombre: "<<endl;
        cin>>str;
        vNombresAlum.push_back(str);
    }
    
    for (string s : vNombresAlum)
    cout<<s<<", ";

    cout<<endl<<"Elimine un nombre: "<<endl;
    vNombresAlum.pop_back();//pop_back sacar valor
    vNombresAlum.pop_back();

    for (string s : vNombresAlum)
    cout<<s<<", ";
}

int main()
{
    defVectorInt();
    defVectorString();

    vector <int> vRepetido(5,30);//un vetor que empieza con 5 ceros

    for (int i : vRepetido)//si queremos que no cambien agregar un constant
    cout<<++i<<" ";//presenta 31,31,31,31,31
    
    for (int i : vRepetido)
    cout<<i++<<" ";//presenta 30,31,32,33,34

    for (const i : vRepetido)//si queremos que no cambien agregar un constant
    cout<<i<<" ";//presenta 30,30,30,30,30

    cout<<endl;
    return 0;   
}