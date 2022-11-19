//
// Created by eceledon on 5/10/2022.
//
#include <iostream>
using namespace std;

class Vendedor {

    private:
        int codigoVendedor;
        string nombresVendedor;
        string apellidosVendedor;
        string dniVendedor;


    public:
        Vendedor() {};

        Vendedor(int codigoVendedor, string nombresVendedor, string apellidosVendedor, string dniVendedor) {
        this->codigoVendedor = codigoVendedor;
        this->nombresVendedor = nombresVendedor;
        this->apellidosVendedor = apellidosVendedor;
        this->dniVendedor = dniVendedor;
        }

    int getCodigoVendedor() {
        return codigoVendedor;
    }

    void setCodigoVendedor(int codigoVendedor) {
        codigoVendedor = codigoVendedor;
    }

    string getNombresVendedor() {
        return nombresVendedor;
    }

    void setNombresVendedor(string nombresVendedor) {
        nombresVendedor = nombresVendedor;
    }

    string getApellidosVendedor() {
        return apellidosVendedor;
    }

    void setApellidosVendedor(string apellidosVendedor) {
        apellidosVendedor = apellidosVendedor;
    }

    string getDniVendedor() {
        return dniVendedor;
    }

    void setDniVendedor(string dniVendedor) {
        dniVendedor = dniVendedor;
    }

};