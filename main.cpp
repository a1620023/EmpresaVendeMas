#include <iostream>
#include "Model/Clientes/Cliente.h"
#include "Model/Vendedores/Vendedor.h"
#include "Model/Productos/Producto.h"
#include "Model/Ventas/Venta.h"
#include "Controller/Login/Login.h"

using namespace std;
#include <string>
#include <cstdlib>
#include <conio.h>

#define USER "Toxica"
#define Pass "123456"


void newFunction();

int main(){
    //Login().login();
    newFunction();
}


void newFunction(){
    cout<<Cliente().getApellidosCliente()<<endl;
    cout<< "Nombre de Producto: " <<Producto().getNombreProducto()<<endl;
    Venta().generarVenta();
    Venta().anularVenta();
}