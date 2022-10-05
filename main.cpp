#include <iostream>
#include "Model/Clientes/Cliente.h"
#include "Model/Vendedores/Vendedor.h"
#include "Model/Productos/Producto.h"

using namespace std;

//proto
void newFunction();

int main() {
    cout << "Hello, World!" << endl;
    newFunction();
    return 0;
}

void newFunction(){
    cout<<Cliente().getApellidosCliente()<<endl;
    cout<< "Nombre de Producto: " <<Producto().getNombreProducto()<<endl;
}