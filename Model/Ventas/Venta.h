//
// Created by eceledon on 5/10/2022.
//

#ifndef EMPRESAVENTAMAS_VENTA_H
#define EMPRESAVENTAMAS_VENTA_H


class Venta {
private:
    int idVenta;
    int codigoProducto;
    int valorVentaReal;

public:
    void generarVenta();

    void anularVenta();

};


#endif //EMPRESAVENTAMAS_VENTA_H
