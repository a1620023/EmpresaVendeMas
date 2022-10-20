//
// Created by eceledon on 6/10/2022.
//

#ifndef EMPRESAVENTAMAS_VENDEDORCONTROLLER_H
#define EMPRESAVENTAMAS_VENDEDORCONTROLLER_H

#include <vector>
#include "../Model/Vendedores/Vendedor.h"

class VendedorController {
private:
    vector<Vendedor> vectorVendedor;

public:
    VendedorController();

    void registarVendedor(Vendedor objVendedor);

    Vendedor getVendedor(int posicion);

    int size();

    int getCorrelativo();

    void guardarEnArchivo(Vendedor objVendedor);

    void cargarDatosDelArchivoAlVector();
};


#endif //EMPRESAVENTAMAS_VENDEDORCONTROLLER_H
