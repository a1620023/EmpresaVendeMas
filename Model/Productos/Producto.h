//
// Created by eceledon on 5/10/2022.
//

#ifndef EMPRESAVENTAMAS_PRODUCTO_H
#define EMPRESAVENTAMAS_PRODUCTO_H
#include <iostream>
using namespace std;

class Producto {
private:
    int codigoProducto;
    string nombreProducto = "Pasta";
    string descripcionProducto;
    float precioProducto;

public:
    Producto();

    Producto(int codigoProducto, string nombreProducto, string descripcionProducto, float precioProducto);

    int getCodigoProducto();

    void setCodigoProducto(int codigoProducto);

    string getNombreProducto();

    void setNombreProducto(string nombreProducto);

    string getDescripcionProducto();

    void setDescripcionProducto(string descripcionProducto);

    float getPrecioProducto();

    void setPrecioProducto(float precioProducto);
};


#endif //EMPRESAVENTAMAS_PRODUCTO_H
