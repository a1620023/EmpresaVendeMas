//
// Created by eceledon on 5/10/2022.
//
#include <iostream>
using namespace std;

class Producto {

private:
    int codigoProducto;
    string nombreProducto;
    string descripcionProducto;
    long precioProducto;
    int stockProducto;
    int codigoCategoria;

public:
    Producto() {}

    Producto(int codigoProducto, string nombreProducto, string descripcionProducto, long precioProducto, int stockProducto, int codigoCategoria) {
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
        this->codigoProducto = codigoProducto;
    }

    string getNombreProducto() {
        return nombreProducto;
    }

    void setNombreProducto(string nombreProducto) {
        this->nombreProducto = nombreProducto;
    }

    string getDescripcionProducto() {
        return descripcionProducto;
    }

    void setDescripcionProducto(string descripcionProducto) {
        this->descripcionProducto = descripcionProducto;
    }

    long getPrecioProducto() {
        return precioProducto;
    }

    void setPrecioProducto(long precioProducto) {
        this->precioProducto = precioProducto;
    }

    int getStockProducto() {
        return stockProducto;
    }

    void setStockProducto(int stockProducto) {
        this->stockProducto = stockProducto;
    }

    int getCodigoCategoria() {
        return codigoCategoria;
    }

    void setCodigoCategoria(int codigoCategoria) {
        this->codigoCategoria = codigoCategoria;
    }
};
