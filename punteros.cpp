/*
1:40
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
#include <iostream>
#include <vector>

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
void defVectorIntOpc()
{
    vector <int> vRepetido(5,30);//un vetor que empieza con 5 ceros
    cout<<"Suma antes de presentar";
    for (int i : vRepetido)//si queremos que no cambien agregar un constant
    cout<<++i<<" ";//presenta 31,31,31,31,31

    cout<<"Suma despues de presentar";
    for (int i : vRepetido)
    cout<<i++<<" ";//presenta 30,31,32,33,34

    cout<<"Sin sumar:";
    for (const int& i : vRepetido)//si queremos que no cambien agregar un constant
    cout<<i<<" ";//presenta 30,30,30,30,30

}
void defVectorString()
{
    string str;
    vector <string> vNombresAlum={"pepe","juan","ana","lucia"};//

    for (int i = 0; i < 5; i++)//agregar 5 nombres
    {
        cout<<endl<<"AGREGAR un nombre: "<<endl;
        cin>>str;
        vNombresAlum.push_back(str);
    }
    
    for (string s : vNombresAlum)
        cout<< s <<", ";

    cout<<endl<<"ELIMINAR : "<<endl;
    vNombresAlum.pop_back();//pop_back sacar valor
    vNombresAlum.pop_back();

    for (string s : vNombresAlum)
        cout<< s <<", ";

    cout<<endl<<"ACCEDER ";
    cout<<endl<<vNombresAlum[12];//funcionan iguales
    cout<<endl<<vNombresAlum.at(12);//valida el tamaño de la lista, puede traer alguna basura, puede ver cuando hay problemas

    vNombresAlum.at(2)="ANA";
    vNombresAlum[1]="juana";
    cout<<endl<<vNombresAlum.at(1);
    cout<<endl<<vNombresAlum.at(2);
}

void iterarVector()
{
    vector <int> num={1,2,3,4};
    vector <int> ::iterator iter;
    iter=num.begin();

    cout<<"num[0]"<<*iter;
    iter++;
    cout<<"num[1]"<<*iter;

    iter=num.begin()+2;
    cout<<"num[2]"<<*iter;
    iter=num.end()-1;
    cout<<"num[3]"<<*iter;

    cout<<"use iterator for loop"<<endl;
    for (iter = num.begin(), iter != num.end(), ++iter)
        cout<<*iter<<" ";

    cout<<"\n Size"<<num.size();
    cout<<"\n Capacidad"<<num.capacity();
    cout<<"\n Tamaño maximo"<<num.max_size();

    if(num.empty())
        cout<<"Vector vacio";
    else    
        cout<<"Vector no vacio";

    num.shrink_to_fit();
    cout<<"\n num elementos estan con shrink_to_fit";
    for (auto it = num.begin(); it != num.end(); it++)
        cout<<*it<<" ";

    //Insertar al inicio
    cout<<"inserte algo"<<endl;
    num.emplace(num.begin(),5);
    num.emplace(num.begin()+3,5);
    num.emplace(num.end(),5);
    for (auto it = num.begin(); it!=num.end(); it++)
        cout<<*it<<" ";

    num.clear();
    cout<<"\n num.clear"<<endl;
    for (auto it = num.begin(); it!=num.end(); it++)
    cout<<*it<<endl;
   
}

int main()
{
    // defVectorInt();

    //-[ok] Agregar elemento
    //-[ok] Elementos de acceso
    //-[] Cambiar elementos
    //-[ok] Quitar elementos

    defVectorString();

    // defVectorIntOpc();

    cout<<endl;
    return 0;   
}

