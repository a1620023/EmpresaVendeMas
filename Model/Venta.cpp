#include <iostream>
using namespace std;
class Venta
{
private:
    int codigoVenta;
    int codigoCliente;
    int codigoVendedor;
    string fechaVenta;
    float totalVenta;

public:
    Venta()
    {

    }
    ~Venta() {}

    void setCodigoVenta(int codigoVenta)
    {
        codigoVenta = codigoVenta;
    }
    void setCodigoCliente(int codigoCliente)
    {
        codigoCliente = codigoCliente;
    }
    void setCodigoVendedor(int codigoVendedor)
    {
        codigoVendedor = codigoVendedor;
    }
    void setFechaVenta(string fechaVenta)
    {
        fechaVenta = fechaVenta;
    }
    void setTotalVenta(float totalVenta)
    {
        totalVenta = totalVenta;
    }

    int getCodigoCliente()
    {
        return this->codigoCliente;
    }
    int getCodigoVendedor()
    {
        return this->codigoVendedor;
    }

    string getFechaVenta()
    {
        return this->fechaVenta;
    }
    int getCodigoVenta()
    {
        return this->codigoVenta;
    }
    float getTotalVenta()
    {
        return this->totalVenta;
    }

};