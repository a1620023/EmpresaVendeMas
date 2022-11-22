#include <iostream>
using namespace std;
class DetalleVenta {
private:
    int codigoVenta;
    string descripcion;
    int codigoProducto;
    int cantidad;
    float precioVenta;

public:
    DetalleVenta() {
    }

    ~DetalleVenta() {}

    void setCodigoVenta(int codigoVenta) {
        codigoVenta = codigoVenta;
    }

    void setCodigoProducto(int codigoProducto) {
        codigoProducto = codigoProducto;
    }

    void setCantidad(int cantidad) {
        cantidad = cantidad;
    }

    void setPrecioVenta(float precioVenta) {
        precioVenta = precioVenta;
    }

    void setDescripcion(string descripcion) {
        descripcion = descripcion;
    }

    int getCodigoVenta() {
        return this->codigoVenta;
    }

    int getCodigoProducto() {
        return this->codigoProducto;
    }

    int getCantidad() {
        return this->cantidad;
    }

    float getPrecioVenta() {
        return this->precioVenta;
    }

    float getSubTotal() {
        return getPrecioVenta() * getCantidad();
    }

    string getDescripcion() {
        return  this->descripcion;
    }

};






