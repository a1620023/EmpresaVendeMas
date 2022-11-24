//
// Created by eceledon on 5/10/2022.
//
#include <iostream>
using namespace std;

class Cliente {
private:
    int codigoCliente;
    string nombresCliente;
    string apellidosCliente;
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
        this->codigoCliente = codigoCliente;
    }

    string getNombresCliente() {
        return nombresCliente;
    }

    void setNombresCliente(string nombresCliente) {
        this->nombresCliente = nombresCliente;
    }

    string getApellidosCliente() {
        return apellidosCliente;
    }

    void setApellidosCliente(string apellidosCliente) {
        this->apellidosCliente = apellidosCliente;
    }

    const string getDniCliente() const {
        return dniCliente;
    }

    void setDniCliente(const string &dniCliente) {
        this->dniCliente = dniCliente;
    }

    const string getEdadCliente() const {
        return edadCliente;
    }

    void setEdadCliente(const string &edadCliente) {
        this->edadCliente = edadCliente;
    }

};


