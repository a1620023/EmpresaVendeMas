//
// Created by eceledon on 5/10/2022.
//

#ifndef EMPRESAVENTAMAS_CLIENTECONTROLLER_H
#define EMPRESAVENTAMAS_CLIENTECONTROLLER_H

#include <vector>
#include "../Model/Clientes/Cliente.h"


class ClienteController {
private:
    vector<Cliente> vectorCliente;

public:
    ClienteController();

    void registrarCliente(Cliente objCliente);

    Cliente getCliente(int posicion);

    int size();

    int getCorrelativo();

    void guardarEnArchivo(Cliente objCliente);

    void cargarDatosDelArchivoAlVector();
};


#endif //EMPRESAVENTAMAS_CLIENTECONTROLLER_H
