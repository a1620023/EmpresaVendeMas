#include <iostream>

#include <string>
#include <conio.h>
#include <chrono>
#include "Controller/Login/Login.cpp"
#include "Controller/VendedorController.cpp"
#include "Controller/CategoriaController.cpp"
#include "Controller/ClienteController.cpp"
#include "Controller/ProductoController.cpp"
#include "Controller/VentaController.cpp"
#include "Controller/DetalleVentaController.cpp"

using namespace std;


void menuDeOpciones();
void registrarVendedorItems();

void registrarCategoriaItems();
void registrarProductoItems();

void registrarClienteItems();
void registrarVentaItems();
void registrarDetalleVentaItems(int codVenta);


void listarItemVendedores();
void listarItemCategorias();
void listarItemProductos();
void listarItemClientes();
void listarItemVentas();
void listarItemDetalleVentas();


Login* d = new Login();
VendedorController* vendedorController = new VendedorController();
CategoriaController* categoriaController = new CategoriaController();
ClienteController* clienteController = new ClienteController();
ProductoController* productoController = new ProductoController();
VentaController* ventaController = new VentaController();
DetalleVentaController* detalleVentaController = new DetalleVentaController();
 
int main(){
    //login();
    //d->log();
    menuDeOpciones();
    //registrarClienteItems();
    //registrarVentaItems();
}


void menuDeOpciones() {
    int opt;
    do {
        cout<<"MENU DE OPCIONES\n";
        cout<<"::   Ir a Mantenimiento  :  [1]\n";
        cout<<"::   Ir a Ventas         :  [2]\n";
        cout<<"::   Salir               :  [00]\n";
        cout<<"Escriba la opcion:";
        cin>>opt;
        switch(opt) {
            case 1:
                system("cls");
                do {
                    cout<<"AREA DE MANTENIMIENTO\n";
                    cout<<"::   Agregar Vendedor    :  [1]\n";
                    cout<<"::   Agregar Categorias  :  [2]\n";
                    cout<<"::   Agregar Productos   :  [3]\n";
                    cout<<"::   Listar Vendedor     :  [4]\n";
                    cout<<"::   Listar Categorias   :  [5]\n";
                    cout<<"::   Listar Productos    :  [6]\n";
                    cout<<"::   Salir               :  [00]\n";
                    cout<<"Escriba la opcion:";
                    cin>>opt;
                    switch(opt) {
                        case 1: system("cls");registrarVendedorItems();break;
                        case 2: system("cls");registrarCategoriaItems();break;
                        case 3:system("cls");registrarProductoItems();break;
                        case 4:system("cls");listarItemVendedores();break;
                        case 5:system("cls");listarItemCategorias();break;
                        case 6:system("cls");listarItemProductos();break;
                        case 00:cout<<"Gracias por usar nuestro programa\n";menuDeOpciones();break;
                        default:system("cls");cout<<"Escriba una opcion correcta | 1 -> 6 |\n";
                    }
                } while(opt != 00);
                break;
            case 2:
                system("cls");
                do {
                    cout<<"Sistema de Ventas\n";
                    cout<<"::   Registrar Cliente   :  [1]\n";
                    cout<<"::   Registrar Venta     :  [2]\n";
                    cout<<"::   Listar Clientes     :  [3]\n";
                    cout<<"::   Listar Ventas       :  [4]\n";
                    cout<<"::   Salir               :  [00]\n";
                    cout<<"Escriba la opcion:";
                    cin>>opt;
                    switch(opt) {
                        case 1:system("cls");registrarClienteItems();break;
                        case 2:system("cls");registrarVentaItems();break;
                        case 3:system("cls");listarItemClientes();break;
                        case 4:system("cls");listarItemVentas();break;
                        case 00:cout<<"Gracias por usar nuestro programa\n";menuDeOpciones();break;
                        default:system("cls");cout<<"Escriba una opcion correcta | 1 -> 4 |\n";
                    }
                } while(opt != 00);
                break;
            case 00:cout<<"Gracias por usar nuestro programa\n";menuDeOpciones();break;
            default:system("cls");cout<<"Escriba una opcion correcta | 1 -> 6 |\n";
        }
    } while(opt != 00);
}

void registrarVendedorItems(){
    string flag;
    int codigoVendedor;
    string nombresVendedor;
    string apellidosVendedor;
    string dniVendedor;

    do {
        codigoVendedor = vendedorController->getCorrelativo();
        cout<<"**********("<<codigoVendedor<<")************\n";
        cin.ignore();
        cout<<"Nombres: ";
        getline(cin, nombresVendedor);
        cout<<"Apellidos: ";
        getline(cin, apellidosVendedor);
        cout<<"DNI: ";
        cin>>dniVendedor;

        cout<<"Continuar(S/s):";
        cin>>flag;

        Vendedor objVendedor(codigoVendedor, nombresVendedor, apellidosVendedor, dniVendedor);
        vendedorController->registarVendedor(objVendedor);

        vendedorController->grabarEnArchivo(objVendedor);
        system("cls");
    } while (flag == "S" || flag == "s");
}//f

void registrarCategoriaItems(){
    char flag;
    int codigoCategoria;
    string nombreCategoria;

    do {
        codigoCategoria = categoriaController->getCorrelativo();
        cout<<"Codigo de Categoria: "<<codigoCategoria<<" \n";
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
    } while (flag == 'S' || flag == 's');
}

void registrarProductoItems(){
    char flag;
    int codigoProducto;
    string nombreProducto = "Pasta";
    string descripcionProducto;
    float precioProducto;
    int stockProducto;
    int codigoCategoria;

    do {
        codigoProducto = productoController->getCorrelativo();
        cout<<"Codigo de Producto: "<<codigoProducto<<"\n";
        cin.ignore();
        cout<<"Nombre de Producto: ";
        getline(cin, nombreProducto);
        cout<<"Descripcion: ";
        getline(cin, descripcionProducto);
        cout<<"Precio: ";
        cin>>precioProducto;
        cout<<"Stock: ";
        cin>>stockProducto;

        listarItemCategorias();
        cout<<"Codigo de Categoria: ";
        cin>>codigoCategoria;

        cout<<"Continuar(S/s):";
        cin>>flag;

        Producto objProducto(codigoProducto, nombreProducto, descripcionProducto, precioProducto, stockProducto, codigoCategoria);
        productoController->registrarProducto(objProducto);

        productoController->guardarEnArchivo(objProducto);
        system("cls");
        listarItemProductos();
    } while (flag == 'S' || flag == 's');
}

void registrarClienteItems(){
    system("cls");
    string flag;
    int codigoCliente;
    string nombresCliente;
    string apellidosCliente;
    string dniCliente;
    string edadCliente;

    do {
        codigoCliente = clienteController->getCorrelativo();
        cout<<" Registro: "<<codigoCliente<<"\n";
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
    } while (flag == "S" || flag == "s");
}

void registrarVentaItems(){
    system("cls");
    string flag;
    int codigoVenta;
    int codigoCliente;
    int codigoVendedor;
    string fechaVenta;
    long totalVenta;
    string busquedaPorDNI;

    time_t tAct = time(nullptr);
    tm* now = localtime(&tAct);
    fechaVenta=to_string(now->tm_mday) + "/"+ to_string(now->tm_mon) +"/"+ to_string(now->tm_year)+")";//asctime(localtime(&tAct));


    do {
        codigoVenta = ventaController->getCorrelativo()+1;
        cout << "\t........ VENTA DE PRODUCTOS ........\t" << endl;
        cout<<"Codigo de Venta: "<<codigoVenta<<" \n";
        cin.ignore();

        cout<<"Fecha de Venta: "<<fechaVenta<<"\n";
        cin.ignore();

        cout<<"________________CLIENTES________________________ "<<endl;
        cout<<"Ingrese codigo de cliente: ";
        cin>>codigoCliente;
        //cout<<"Ingrese numero de Documento del cliente: ";
        //cin>>busquedaPorDNI;
        //codigoCliente = clienteController->getCorrelativo(); //busqueda por nombre
        //cout<<clienteController->buscarCodigoCliente(busquedaPorDNI)<<endl;
        //listarItemClientes();
        cout<<"________________________________________________ "<<endl;

        cout<<"________________VENDEDORES________________________ "<<endl;
        cout<<"Ingrese codigo de vendedor: ";
        cin>>codigoVendedor;
        //listarItemVendedores();
        cout<<"__________________________________________________ \n";

        cout<<"________________DETALLE DE VENTA________________________ "<<endl;
        registrarDetalleVentaItems(codigoVenta);
        cout<<"__________________________________________________ \n";

        cout<<"Total de Venta: ";
        cin>> totalVenta;
        cout<<""<<endl;


        cout<<"Continuar(S/s):";
        cin>>flag;

        Venta objVenta(codigoVenta, codigoCliente, codigoVendedor, fechaVenta, totalVenta, 1);
        ventaController->registrarVenta(objVenta);

        ventaController->guardarEnArchivo();
        //listarItemVentas();
        system("pause");
    } while (flag == "S" || flag == "s");
}//f

void registrarDetalleVentaItems(int codVenta){
    string flag;
    int codigoDetalleVenta;
    int codigoVenta;
    int codigoProducto;
    int cantidad;
    float precioVenta;

    do {
        codigoDetalleVenta = detalleVentaController->getCorrelativo();
        cout<<"Detalle: "<<codigoDetalleVenta<<" ************\n";
        cin.ignore();

        codigoVenta = codVenta;
        cout<<"Codigo de Venta: "<<codigoVenta;
        cin.ignore();
        //cin>>codigoVenta;

        for (int i = 0; i < detalleVentaController->size(); ++i) {
            cout << "Codigo:" << "000" << detalleVentaController->getPosicion(i).getCodigoProducto() << "\n";
            cout << "Precio:" << "S/. " << detalleVentaController->getPosicion(i).getPrecioVenta() << "\n";
            cout << "---------------------------" << endl;
        }
        cout<<" Codigode de Producto: ";
        cin>>codigoProducto;
        cout<<"Cantidad: ";
        cin>>cantidad;
        cout<<"Precio de Venta: ";
        cin>>precioVenta;

        cout<<"Continuar(S/s):";
        cin>>flag;

        DetalleVenta objetoDetalleVenta(codigoDetalleVenta, codigoVenta, codigoProducto, cantidad, precioVenta);
        detalleVentaController->registrarDetalleVenta(objetoDetalleVenta);

        detalleVentaController->guardarEnArchivo(objetoDetalleVenta);
        system("cls");
        listarItemDetalleVentas();
    } while (flag == "S" || flag == "s");
}//f




void listarItemVendedores(){
    cout<<"...listando Vendedores"<<endl;
    for(int i = 0;i<vendedorController->size();i++)
    {
        cout<<vendedorController->getPosicion(i).getCodigoVendedor() <<"\t"<<vendedorController->getPosicion(i).getNombresVendedor()<<"\t"
            <<vendedorController->getPosicion(i).getApellidosVendedor()<<"\t"<<vendedorController->getPosicion(i).getDniVendedor()<<"\t"<<endl;
    }

    //system("pause");
    system("cls");
}//f

void listarItemCategorias(){
    cout<<"...listando Categorias"<<endl;
    for(int i = 0;i<categoriaController->size();i++) {
        cout<<categoriaController->getPosicion(i).getCodigoCategoria() <<"\t"<<categoriaController->getPosicion(i).getNombreCategoria()<<"\t"<<endl;
    }
    categoriaController->cargarDatosDelArchivoAlVector();
    //system("pause");
    system("cls");
}

void listarItemProductos(){
    if (productoController->size() >= 1){
        cout<<"...listando Productos"<<endl;
        for(int i = 0;i<productoController->size();i++)
        {
            cout<<productoController->getPosicion(i).getCodigoProducto() <<"\t"<<productoController->getPosicion(i).getNombreProducto()<<"\t"
                <<productoController->getPosicion(i).getDescripcionProducto()<<"\t"<<productoController->getPosicion(i).getPrecioProducto()<<"\t"<<
                productoController->getPosicion(i).getStockProducto()<<"\t"<<productoController->getPosicion(i).getCodigoCategoria()<<"\t"<<endl;
        }
    } else{
        cout<<"...lista vacia"<<endl;
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

void listarItemVentas(){
    cout<<"...listando Ventas"<<endl;
    for(int i = 0;i<ventaController->size();i++)
    {
        cout<<ventaController->getPosicion(i).getCodigoVenta() <<"\t"<<ventaController->getPosicion(i).getCodigoCliente()<<"\t"
            <<ventaController->getPosicion(i).getCodigoVendedor()<<"\t"<<ventaController->getPosicion(i).getFechaVenta()<<"\t"
            <<ventaController->getPosicion(i).getTotalVenta()<<"\t"<<endl;
    }

    system("pause");
    system("cls");
    listarItemDetalleVentas();
}//f

void listarItemDetalleVentas(){
    cout<<"...listando Detalle de Venta"<<endl;

    cout<<"| Codigo de Detalle |Codigo de Venta | codigo de Producto | Cantidad | SubTotal|"<<endl;
    for(int i = 0;i<detalleVentaController->size();i++) {
        cout<<detalleVentaController->getPosicion(i).getCodigoDetalleVenta() <<"\t"<<detalleVentaController->getPosicion(i).getCodigoVenta()<<"\t"
            <<detalleVentaController->getPosicion(i).getCodigoProducto()<<"\t"<<detalleVentaController->getPosicion(i).getCantidad()<<"\t"
            <<detalleVentaController->getPosicion(i).getPrecioVenta()<<"\t"<<detalleVentaController->getPosicion(i).getSubTotal()<<"\t"<<endl;
    }
    system("pause");
    system("cls");
}//f

