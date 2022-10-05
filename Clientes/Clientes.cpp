//
// Created by eceledon on 5/10/2022.
//
#include <iostream>
using namespace std;
#include "Clientes.h"



Clientes::Clientes() {}

Clientes::Clientes(int, string, string ) {
    this->codigo = codigo;
    this->nombres = nombres;
    this->apellidos = apellidos;
}

int Clientes::getCodigo() const {
    return codigo;
}

void Clientes::setCodigo(int codigo) {
    Clientes::codigo = codigo;
}

const string &Clientes::getNombres() const {
    return nombres;
}

void Clientes::setNombres(const string &nombres) {
    Clientes::nombres = nombres;
}

const string &Clientes::getApellidos() const {
    return apellidos;
}

void Clientes::setApellidos(const string &apellidos) {
    Clientes::apellidos = apellidos;
}

