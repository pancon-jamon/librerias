#include <iostream>

#include <string>

#include <stdexcept>



const int precio[] = {25, 50, 75, 100}; // para máquina suiza



#define INICIO 0

#define GALLETA 1

#define COLA 2

#define DORITOS 3

#define HELADO 4

#define ERROR -1



using namespace std;



bool validarOPC(const string &str) 

{

    try 

    {

        int num = stoi(str);

        return true;

    } 

    catch (const invalid_argument &e) 

    {

        return false;

    } 

}



void maquinaGuayaca(int precio, int producto)

{

    int estado = INICIO;



    switch (estado)

    {

        case INICIO:

        {

            if (precio >= 25)

                estado = GALLETA;

            else

                estado = ERROR;

            break;

        }

        case GALLETA:

        {

            if (producto == 1 && precio == 25) 

                cout << "Has comprado una galleta" << endl; 

            else

                estado = COLA;

            break; 

        }

        case COLA:

        {

            if (producto == 2 && precio == 50) 

                cout << "Has comprado una cola" << endl; 

            else

                estado = DORITOS;

            break; 

        }

        case DORITOS:

        {

            if (producto == 3 && precio == 75) 

                cout << "Has comprado un dorito" << endl; 

            else

                estado = HELADO;

            break; 

        }

        case HELADO:

        {

            if (producto == 4 && precio == 100) 

                cout << "Has comprado un helado" << endl; 

            else

                break; 

        }

        case ERROR:

            cout<<"Te falta dinero";

            break;

    }

}


void menuMG()
{
    string opc, moneda;

    int opcInt, monedaInt;

    bool todoBien = true;



    



    while (todoBien)

    {

        try

        {

            cout << "Que producto desea: ";

            getline(cin, opc);



            if (validarOPC(opc) && (opc == "1" || opc == "2" || opc == "3" || opc == "4"))

            {

                opcInt = stoi(opc); 

                

                cout << "Ingrese su moneda: ";

                getline(cin, moneda);



                if (validarOPC(moneda)) 

                {

                    monedaInt = stoi(moneda);

                    maquinaGuayaca(monedaInt, opcInt); 

                    todoBien = false; 

                } 

                else 

                {

                    cout << "Ingrese su dinero" << endl;

                }

            }

            else

            {

                cout << "Opcion invalida" << endl;

            }

        }

        catch(const invalid_argument& e)

        {

            cout << "Ingrese una opcion correcta" << endl;

        }

    }


}



int main() 

{

    cout << "=========MAQUINA EXPENDEDORA============" << endl

         << "1.- Galletas 25 cntvs" << endl

         << "2.- Gaseosa 50 cntvs" << endl

         << "3.- Doritos 75 cntvs" << endl

         << "4.- Helados Magnum 100 cntvs" << endl;
     menuMG();    
     maquinaGuayaca();

    return 0;

}

    
