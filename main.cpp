#include <iostream>
#include <cstdlib>
#include <string>
#include "Controller/ClienteController.cpp"
#include "Controller/ProductoController.cpp"

using namespace std;

void menuDeOpciones();
void registrarClienteItems();
void registrarProductoItems();
void listarItemClientes();
void listarItemProductos();


ClienteController* clienteController = new ClienteController();
ProductoController* productoController = new ProductoController();
int main(){
    //Login().login();
    menuDeOpciones();
}

void menuDeOpciones()
{
    int opt;
    do
    {
        cout<<"MENU DE OPCIONES\n";
        cout<<"::           Agregar Productos:  [1]\n";
        cout<<"::           Agregar Cliente  :  [2]\n";
        cout<<"::           Listar Productos :  [3]\n";
        cout<<"::           Listar Clientes  :  [4]\n";
        cout<<"::           Salir            :  [5]\n";
        cout<<"Escriba la opcion:";
        cin>>opt;
        switch(opt)
        {   case 1:system("cls");registrarProductoItems();break;
            case 2:system("cls");registrarClienteItems();break;
            case 3:system("cls");listarItemProductos();break;
            case 4:system("cls");listarItemClientes();break;
            case 5:cout<<"Gracias por usar nuestro programa\n";break;
            default:system("cls");cout<<"Escriba una opcion correcta | 1 -> 5 |\n";
        }
    }
    while(opt!=5);
}

void registrarClienteItems(){
    string flag;
    int codigoCliente;
    string nombresCliente;
    string apellidosCliente;
    string dniCliente;
    string edadCliente;

    do {
        codigoCliente = clienteController->getCorrelativo();
        cout<<"**********("<<codigoCliente<<")************\n";
        cin.ignore();
        cout<<"Nombres: ";
        getline(cin, nombresCliente);
        cout<<"Apellidos: ";
        getline(cin, apellidosCliente);
        cout<<"DNI: ";
        cin>>dniCliente;
        cout<<"Edad: ";
        cin>>edadCliente;
        cout<<"Continuar(S/s):";
        cin>>flag;

        Cliente objCliente(codigoCliente, nombresCliente, apellidosCliente, dniCliente, edadCliente);
        clienteController->registrarCliente(objCliente);

        clienteController->guardarEnArchivo(objCliente);
        system("cls");
    } while (flag == "S" || flag == "s");
}

void registrarProductoItems(){
    string flag;
    int codigoProducto;
    string nombreProducto = "Pasta";
    string descripcionProducto;
    float precioProducto;

    do {
        codigoProducto = productoController->getCorrelativo();
        cout<<"**********("<<codigoProducto<<")************\n";
        cin.ignore();
        cout<<"Nombre de Producto: ";
        getline(cin, nombreProducto);
        cout<<"Descripción: ";
        getline(cin, descripcionProducto);
        cout<<"Precio: ";
        cin>>precioProducto;
        cout<<"Continuar(S/s):";
        cin>>flag;

        Producto objProducto(codigoProducto, nombreProducto, descripcionProducto, precioProducto);
        productoController->registrarProducto(objProducto);

        productoController->guardarEnArchivo(objProducto);
        system("cls");
    } while (flag == "S" || flag == "s");
}

void listarItemClientes(){
    cout<<"...listando Clientes"<<endl;
    for(int i = 0;i<clienteController->size();i++)
    {
        cout<<clienteController->getPosicion(i).getCodigoCliente() <<"\t"<<clienteController->getPosicion(i).getNombresCliente()<<"\t"
            <<clienteController->getPosicion(i).getApellidosCliente()<<"\t"<<endl;
    }

    system("pause");
    system("cls");
}

void listarItemProductos(){
    cout<<"...listando Productos"<<endl;
    for(int i = 0;i<productoController->size();i++)
    {
        cout<<productoController->getPosicion(i).getCodigoProducto() <<"\t"<<productoController->getPosicion(i).getNombreProducto()<<"\t"
            <<productoController->getPosicion(i).getDescripcionProducto()<<"\t"<<productoController->getPosicion(i).getPrecioProducto()<<"\t"<<endl;
    }

    system("pause");
    system("cls");
}

