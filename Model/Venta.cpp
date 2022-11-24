#include <iostream>
using namespace std;
class Venta
{
private:
    int codigoVenta;
    int codigoCliente;
    int codigoVendedor;
    string fechaVenta;
    long totalVenta;
    int estadoVenta;

public:
    Venta() {}
    Venta(int codigoVenta, int codigoCliente, int codigoVendedor, string fechaVenta, long totalVenta, int estadoVenta) {
        this->codigoVenta = codigoVenta;
        this->codigoCliente = codigoCliente;
        this->codigoVendedor = codigoVendedor;
        this->fechaVenta = fechaVenta;
        this->totalVenta = totalVenta;
        this->estadoVenta = estadoVenta;
    }

    void setCodigoVenta(int codigoVenta) {
        this->codigoVenta = codigoVenta;
    }

    void setCodigoCliente(int codigoCliente) {
        this->codigoCliente = codigoCliente;
    }

    void setCodigoVendedor(int codigoVendedor) {
        this->codigoVendedor = codigoVendedor;
    }

    void setFechaVenta(string fechaVenta) {
        this->fechaVenta = fechaVenta;
    }

    void setTotalVenta(long totalVenta) {
        this->totalVenta = totalVenta;
    }

    int getCodigoCliente() {
        return codigoCliente;
    }

    int getCodigoVendedor() {
        return codigoVendedor;
    }

    string getFechaVenta() {
        return fechaVenta;
    }

    int getCodigoVenta() {
        return codigoVenta;
    }

    long getTotalVenta() {
        return totalVenta;
    }

    int getEstadoVenta() {
        return estadoVenta;
    }

    void setEstadoVenta(int estadoVenta) {
        this->estadoVenta = estadoVenta;
    }

};