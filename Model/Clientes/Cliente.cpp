//
// Created by eceledon on 5/10/2022.
//
#include <iostream>
using namespace std;
#include "Cliente.h"



Cliente::Cliente() {}

Cliente::Cliente(int codigoCliente, string nombresCliente, string apellidosCliente ) {
    this->codigoCliente = codigoCliente;
    this->nombresCliente = nombresCliente;
    this->apellidosCliente = apellidosCliente;
}

int Cliente::getCodigoCliente() {
    return codigoCliente;
}

void Cliente::setCodigoCliente(int codigoCliente) {
    Cliente::codigoCliente = codigoCliente;
}

string Cliente::getNombresCliente() {
    return nombresCliente;
}

void Cliente::setNombresCliente(string nombresCliente) {
    Cliente::nombresCliente = nombresCliente;
}

string Cliente::getApellidosCliente() {
    return apellidosCliente;
}

void Cliente::setApellidosCliente(string apellidosCliente) {
    Cliente::apellidosCliente = apellidosCliente;
}

