//
// Created by eceledon on 5/10/2022.
//
#include <iostream>
using namespace std;

class Producto {

private:
    int codigoProducto;
    string nombreProducto = "Pasta";
    string descripcionProducto;
    float precioProducto;
    int stockProducto;
    int codigoCategoria;

public:
    Producto() {}

    Producto(int codigoProducto, string nombreProducto, string descripcionProducto, float precioProductoint, int stockProducto, int codigoCategoria) {
        this->codigoProducto = codigoProducto;
        this->nombreProducto = nombreProducto;
        this->descripcionProducto = descripcionProducto;
        this->precioProducto = precioProducto;
        this->stockProducto = stockProducto;
        this->codigoCategoria =codigoCategoria;
    }

    int getCodigoProducto() {
        return codigoProducto;
    }

    void setCodigoProducto(int codigoProducto) {
        Producto::codigoProducto = codigoProducto;
    }

    string getNombreProducto() {
        return nombreProducto;
    }

    void setNombreProducto(string nombreProducto) {
        Producto::nombreProducto = nombreProducto;
    }

    string getDescripcionProducto() {
        return descripcionProducto;
    }

    void setDescripcionProducto(string descripcionProducto) {
        descripcionProducto = descripcionProducto;
    }

    float getPrecioProducto() {
        return precioProducto;
    }

    void setPrecioProducto(float precioProducto) {
        precioProducto = precioProducto;
    }

    int getStockProducto() {
        return stockProducto;
    }

    void setStockProducto(int stockProducto) {
        stockProducto = stockProducto;
    }

    int getCodigoCategoria() {
        return codigoCategoria;
    }

    void setCodigoCategoria(int codigoCategoria) {
        codigoCategoria = codigoCategoria;
    }
};
