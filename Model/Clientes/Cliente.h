//
// Created by eceledon on 5/10/2022.
//
#ifndef EMPRESAVENTAMAS_CLIENTE_H
#define EMPRESAVENTAMAS_CLIENTE_H
#include <iostream>
using namespace std;

class Cliente {

private:
    int codigoCliente;
    string nombresCliente;
    string apellidosCliente ="Celedonio";

public:
    Cliente();

    Cliente(int codigoCliente, string nombresCliente, string apellidosCliente);

    int getCodigoCliente();

    void setCodigoCliente(int codigoCliente);

    string getNombresCliente();

    void setNombresCliente(string nombresCliente);

    string getApellidosCliente();

    void setApellidosCliente(string apellidosCliente);

    Cliente(int i, string basicString, string basicString1, int i1);
};


#endif //EMPRESAVENTAMAS_CLIENTE_H
