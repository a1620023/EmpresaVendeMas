//
// Created by eceledon on 5/10/2022.
//

#ifndef EMPRESAVENTAMAS_VENDEDOR_H
#define EMPRESAVENTAMAS_VENDEDOR_H
#include <iostream>
using namespace std;

class Vendedor {

private:
    int codigoVendedor;
    string nombresVendedor;
    string apellidosVendedor;
    string direccion;


public:
    Vendedor();

    Vendedor(int codigoVendedor, string nombresVendedor, string apellidosVendedor, string direccion);


    int getCodigoVendedor();

    void setCodigoVendedor(int codigoVendedor);

    string getNombresVendedor();

    void setNombresVendedor(string nombresVendedor);

    string getApellidosVendedor();

    void setApellidosVendedor(string apellidosVendedor);

    string getDireccion();

    void setDireccion(string direccion);
};


#endif //EMPRESAVENTAMAS_VENDEDOR_H
