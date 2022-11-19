#include <iostream>
#include <string>
#include <conio.h>
#include "Controller/Login/Login.cpp"
#include "Controller/CategoriaController.cpp"
#include "Controller/ClienteController.cpp"
#include "Controller/ProductoController.cpp"

using namespace std;


void menuDeOpciones();
void registrarCategoriasItems();
void registrarClienteItems();
void registrarProductoItems();
void listarItemCategorias();
void listarItemClientes();
void listarItemProductos();


CategoriaController* categoriaController = new CategoriaController();
ClienteController* clienteController = new ClienteController();
ProductoController* productoController = new ProductoController();
Login* d = new Login();

int main(){
    //login();
    d->log();
    menuDeOpciones();
}


void menuDeOpciones()
{
    int opt;
    do
    {
        cout<<"MENU DE OPCIONES\n";
        cout<<"::           Agregar Categorias  :  [1]\n";
        cout<<"::           Agregar Productos   :  [2]\n";
        cout<<"::           Agregar Cliente     :  [3]\n";
        cout<<"::           Listar Categorias   :  [4]\n";
        cout<<"::           Listar Productos    :  [5]\n";
        cout<<"::           Listar Clientes     :  [6]\n";
        cout<<"::           Salir               :  [00]\n";
        cout<<"Escriba la opcion:";
        cin>>opt;
        switch(opt)
        {   case 1:system("cls");registrarCategoriasItems();break;
            case 2:system("cls");registrarProductoItems();break;
            case 3:system("cls");registrarClienteItems();break;
            case 4:system("cls");listarItemCategorias();break;
            case 5:system("cls");listarItemProductos();break;
            case 6:system("cls");listarItemClientes();break;
            case 00:cout<<"Gracias por usar nuestro programa\n";break;
            default:system("cls");cout<<"Escriba una opcion correcta | 1 -> 6 |\n";
        }
    }
    while(opt!=00);
}

void registrarCategoriasItems(){
    string flag;
    int codigoCategoria;
    string nombreCategoria;

    do {
        codigoCategoria = categoriaController->getCorrelativo();
        cout<<"**********("<<codigoCategoria<<")************\n";
        cin.ignore();
        cout<<"Nombres: ";
        getline(cin, nombreCategoria);
        cout<<"Continuar(S/s):";
        cin>>flag;

        Categoria objCategoria(codigoCategoria, nombreCategoria);
        categoriaController->registrarCategoria(objCategoria);

        categoriaController->guardarEnArchivo(objCategoria);
        system("cls");
        listarItemCategorias();
    } while (flag == "S" || flag == "s");
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
    int stockProducto;
    int codigoCategoria;

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
        cout<<"Stock: ";
        cin>>stockProducto;

        cout<<"Codigo de Categoria: ";
        listarItemCategorias();
        cin>>codigoCategoria;

        cout<<"Continuar(S/s):";
        cin>>flag;

        Producto objProducto(codigoProducto, nombreProducto, descripcionProducto, precioProducto, stockProducto, codigoCategoria);
        productoController->registrarProducto(objProducto);

        productoController->guardarEnArchivo(objProducto);
        system("cls");
        listarItemProductos();
    } while (flag == "S" || flag == "s");
}

void listarItemCategorias(){
    cout<<"...listando Categorias"<<endl;
    for(int i = 0;i<categoriaController->size();i++)
    {
        cout<<categoriaController->getPosicion(i).getCodigoCategoria() <<"\t"<<categoriaController->getPosicion(i).getNombreCategoria()<<"\t"<<endl;
    }

    system("pause");
    system("cls");
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
            <<productoController->getPosicion(i).getDescripcionProducto()<<"\t"<<productoController->getPosicion(i).getPrecioProducto()<<"\t"<<
            productoController->getPosicion(i).getStockProducto()<<"\t"<<productoController->getPosicion(i).getCodigoCategoria()<<"\t"<<endl;
    }

    system("pause");
    system("cls");
}

