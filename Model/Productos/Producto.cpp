//
// Created by eceledon on 5/10/2022.
//

#include "Producto.h"

Producto::Producto() {}

Producto::Producto(int codigoProducto, string nombreProducto, string descripcionProducto, float precioProducto) {
    this->codigoProducto = codigoProducto;
    this->nombreProducto = nombreProducto;
    this->descripcionProducto = descripcionProducto;
    this->precioProducto = precioProducto;
}

int Producto::getCodigoProducto() {
    return codigoProducto;
}

void Producto::setCodigoProducto(int codigoProducto) {
    Producto::codigoProducto = codigoProducto;
}

string Producto::getNombreProducto() {
    return nombreProducto;
}

void Producto::setNombreProducto(string nombreProducto) {
    Producto::nombreProducto = nombreProducto;
}

string Producto::getDescripcionProducto() {
    return descripcionProducto;
}

void Producto::setDescripcionProducto(string descripcionProducto) {
    Producto::descripcionProducto = descripcionProducto;
}

float Producto::getPrecioProducto() {
    return precioProducto;
}

void Producto::setPrecioProducto(float precioProducto) {
    Producto::precioProducto = precioProducto;
}

