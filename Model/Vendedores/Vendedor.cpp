//
// Created by eceledon on 5/10/2022.
//

#include "Vendedor.h"
#include <iostream>
using namespace std;

Vendedor::Vendedor() {}

Vendedor::Vendedor(int codigoVendedor, string nombresVendedor, string apellidosVendedor, string direccion) {
    this->codigoVendedor = codigoVendedor;
    this->nombresVendedor = nombresVendedor;
    this->apellidosVendedor = apellidosVendedor;
    this->direccion = direccion;
}

int Vendedor::getCodigoVendedor() {
    return codigoVendedor;
}

void Vendedor::setCodigoVendedor(int codigoVendedor) {
    Vendedor::codigoVendedor = codigoVendedor;
}

string Vendedor::getNombresVendedor() {
    return nombresVendedor;
}

void Vendedor::setNombresVendedor(string nombresVendedor) {
    Vendedor::nombresVendedor = nombresVendedor;
}

string Vendedor::getApellidosVendedor() {
    return apellidosVendedor;
}

void Vendedor::setApellidosVendedor(string apellidosVendedor) {
    Vendedor::apellidosVendedor = apellidosVendedor;
}

string Vendedor::getDireccion() {
    return direccion;
}

void Vendedor::setDireccion(string direccion) {
    Vendedor::direccion = direccion;
}