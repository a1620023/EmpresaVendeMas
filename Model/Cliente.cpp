//
// Created by eceledon on 5/10/2022.
//
#include <iostream>
using namespace std;

class Cliente {
private:
    int codigoCliente;
    string nombresCliente;
    string apellidosCliente ="Celedonio";
    string dniCliente;
    string edadCliente;

public:
    Cliente() {}

    Cliente(int codigoCliente, string nombresCliente, string apellidosCliente, string dniCliente, string edadCliente ) {
        this->codigoCliente = codigoCliente;
        this->nombresCliente = nombresCliente;
        this->apellidosCliente = apellidosCliente;
        this->dniCliente = dniCliente;
        this->edadCliente = edadCliente;
    }

    int getCodigoCliente() {
        return codigoCliente;
    }

    void setCodigoCliente(int codigoCliente) {
        codigoCliente = codigoCliente;
    }

    string getNombresCliente() {
        return nombresCliente;
    }

    void setNombresCliente(string nombresCliente) {
        nombresCliente = nombresCliente;
    }

    string getApellidosCliente() {
        return apellidosCliente;
    }

    void setApellidosCliente(string apellidosCliente) {
        apellidosCliente = apellidosCliente;
    }

};


