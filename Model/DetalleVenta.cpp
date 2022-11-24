#include <iostream>
using namespace std;
class DetalleVenta {
private:
    int codigoDetalleVenta;
    int codigoVenta;
    int codigoProducto;
    int cantidad;
    float precioVenta;

public:
    DetalleVenta() {
    }

    DetalleVenta(int codigoDetalleVenta, int codigoVenta, int codigoProducto, int cantidad, float precioVenta) {
        this->codigoDetalleVenta = codigoDetalleVenta;
        this->codigoVenta = codigoVenta;
        this->codigoProducto = codigoProducto;
        this->cantidad = cantidad;
        this->precioVenta = precioVenta;
    }

    int getCodigoDetalleVenta() {
        return codigoDetalleVenta;
    }

    void setCodigoDetalleVenta(int codigoDetalleVenta) {
        this->codigoDetalleVenta = codigoDetalleVenta;
    }

    int getCodigoVenta() {
        return codigoVenta;
    }

    void setCodigoVenta(int codigoVenta) {
        this->codigoVenta = codigoVenta;
    }

    void setCodigoProducto(int codigoProducto) {
        this->codigoProducto = codigoProducto;
    }

    void setCantidad(int cantidad) {
        this->cantidad = cantidad;
    }

    void setPrecioVenta(float precioVenta) {
        this->precioVenta = precioVenta;
    }


    int getCodigoProducto() {
        return codigoProducto;
    }

    int getCantidad() {
        return cantidad;
    }

    float getPrecioVenta() {
        return precioVenta;
    }

    float getSubTotal() {
        return getPrecioVenta() * getCantidad();
    }

};






