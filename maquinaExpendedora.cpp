#include <iostream>
#include <string>
#include <stdexcept>

const int precios[] = {25, 50, 75, 100};

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

void maquinaSuiza(int precioProducto, int producto, int monedaTotal, int &vuelto)
{
    int estado = INICIO;
    string productoComprado = "Ninguno";

    switch (producto)
    {
        case GALLETA:
        {
            if (producto == 1 && precioProducto == precios[0])
            {
                productoComprado = "una galleta";
                vuelto = monedaTotal - precios[0];
            }
            else if (producto == 1 && precioProducto > precios[0])
            {
                productoComprado = "una Galleta";
                vuelto = monedaTotal - precioProducto;
            }
            else
                estado = COLA;
            break;
        }
        case COLA:
        {
            if (producto == 2 && precioProducto == precios[1])
            {
                productoComprado = "una cola";
                vuelto = monedaTotal - precios[1];
            }
            else if (producto == 2 && precioProducto > precios[1])
            {
                productoComprado = "una cola";
                vuelto = monedaTotal - precioProducto;
            }
            else
                estado = DORITOS;
            break;
        }
        case DORITOS:
        {
            if (producto == 3 && precioProducto == precios[2])
            {
                productoComprado = "un dorito";
                vuelto = monedaTotal - precios[2];
            }
            else if (producto == 3 && precioProducto > precios[2])
            {
                productoComprado = "un orito";
                vuelto = monedaTotal - precioProducto;
            }
            else
                estado = HELADO;
            break;
        }
        case HELADO:
        {
            if (producto == 4 && precioProducto == precios[3])
            {
                productoComprado = "un helado";
                vuelto = monedaTotal - precios[3];
            }
            else if (producto == 4 && precioProducto > precios[3])
            {
                productoComprado = "un helado";
                vuelto = monedaTotal - precioProducto;
            }
            else
                estado = ERROR;
            break;
        }
        case ERROR:
            break;
        default:
            estado = ERROR;
            break;
    }

    if (estado == ERROR)
    {
        cout << "Te falta dinero" << endl;
    }
    else if (productoComprado != "Ninguno")
    {
        cout << "Has comprado un " << productoComprado << endl;
        if (vuelto > 0)
        {
            cout << "Tu vuelto es: " << vuelto << " cntvs" << endl;
        }
    }
}

void maquinaGuayaca(int precioProducto, int producto, int monedaTotal, int &vuelto)
{
    int estado = INICIO;
    string productoComprado = "Ninguno";

    switch (producto)
    {
        case GALLETA:
        {
            if (precioProducto >= precios[0])
                productoComprado = "una galleta";
            else
                estado = COLA;
            break;
        }
        case COLA:
        {
            if (precioProducto >= precios[1])
                productoComprado = "una cola";
            else
                estado = DORITOS;
            break;
        }
        case DORITOS:
        {
            if (precioProducto >= precios[2])
                productoComprado = "un dorito";
            else
                estado = HELADO;
            break;
        }
        case HELADO:
        {
            if (precioProducto >= precios[3])
                productoComprado = "un helado";
            else
                estado = ERROR;
            break;
        }
        case ERROR:
            break;
        default:
            estado = ERROR;
            break;
    }

    if (estado == ERROR)
    {
        cout << "Te falta dinero" << endl;
    }
    else if (productoComprado != "Ninguno")
    {
        cout << "Has comprado " << productoComprado << endl;
    }
}

int main()
{
    string opc, moneda;
    int opcInt, monedaInt;
    bool todoBien = true;

    cout << "=========MAQUINA EXPENDEDORA============" << endl
         << "1.- Galletas 25 cntvs" << endl
         << "2.- Gaseosa 50 cntvs" << endl
         << "3.- Doritos 75 cntvs" << endl
         << "4.- Helados Magnum 100 cntvs" << endl
         << "Ingrese hasta 4 monedas:" << endl;

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
                    int vuelto = monedaInt - precios[opcInt - 1];
                    cout << "Maquina que miente:" << endl;
                    maquinaGuayaca(precios[opcInt - 1], opcInt, monedaInt, vuelto);
                    cout << "Maquina honesta:" << endl;
                    maquinaSuiza(precios[opcInt - 1], opcInt, monedaInt, vuelto);
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
        catch (const invalid_argument &e)
        {
            cout << "Ingrese una opcion correcta" << endl;
        }
    }

    return 0;
}
