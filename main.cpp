#include <iostream>
#include "Model/Clientes/Cliente.h"
#include "Model/Vendedores/Vendedor.h"
#include "Model/Productos/Producto.h"
#include "Controller/Ventas/Venta.h"

using namespace std;
#include <string>
#include <cstdlib>
#include <conio.h>

#define USER "Roberto"
#define Pass "123456"


void newFunction();

int main()
{
    string usuario, password;
    int contador = 0;
    bool ingresa = false;

    do{
        system("cls");
        cout<<"\t\t\tLOGIN DE USUSARIO" <<endl;
        cout<<"\t\t\t-----------------" <<endl;
        cout<<"\n\tUsuario: ";
        getline(cin, usuario);
        cout<<"\tPasssword: ";
        // getline(cin, password);
        char caracter;
        caracter = getch();

        password = "";

        while(caracter != 13){
            password.push_back(caracter);
            cout<<"*";
            caracter = getch();
        }

        if(usuario == USER && password == Pass){
            ingresa = true;
        }   else{
            cout<<"El usuario y/o pasword son incorrectos"<<endl;
            cin.get();
        }
    }while (ingresa == false && contador <3);

    if(ingresa == false) {
        cout<<"\n\tUsted no pudo ingresar al sistema. ADIOS"<<endl;
    }else{
        cout<<"\n\tBienvenido al sistema"<<endl;
        newFunction();
    }

    cin.get();
    return 0;

}

void newFunction(){
    cout<<Cliente().getApellidosCliente()<<endl;
    cout<< "Nombre de Producto: " <<Producto().getNombreProducto()<<endl;
    Venta().generarVenta();
    Venta().anularVenta();
}