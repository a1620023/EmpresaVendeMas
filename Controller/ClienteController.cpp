//
// Created by eceledon on 5/10/2022.
//

#include <fstream>
#include "ClienteController.h"
#include "../Model/Clientes/Cliente.h"

ClienteController::ClienteController() {}

void ClienteController::registrarCliente(Cliente objCliente) {}

Cliente ClienteController::getCliente(int posicion) {
    return vectorCliente[posicion];
}

int ClienteController::size() {
    return vectorCliente.size();
}

int ClienteController::getCorrelativo() {
    if (size() == 0){
        return 1;
    } else {
        return vectorCliente[size() - 1].getCodigoCliente() + 1;
    }
}

void ClienteController::guardarEnArchivo(Cliente objCliente) {
    cout<<"...guardando cliente"<<endl;
    try {
        fstream archivoCliente;
        archivoCliente.open("Clientes.csv", ios::app);
        if (archivoCliente.is_open()){
            archivoCliente<<objCliente.getCodigoCliente()<<";"<<objCliente.getNombresCliente()<<";"<<objCliente.getApellidosCliente() <<";"<<endl;
            archivoCliente.close();
        }
    } catch (exception e) {
        cout<<"ocurrio un error al GUARDAR archivoCliente" <<endl;
    }
}

void ClienteController::cargarDatosDelArchivoAlVector() {
    cout<<"...cargando datos del archivo"<<endl;
    try {
        int i;
        size_t posicion;
        string linea;
        string temporal[4];
        fstream archivoCliente;
        archivoCliente.open("Clientes.csv",ios::in);


    } catch (exception e) {
        cout<<"ocurrio un error al CARGAR archivoCliente" <<endl;
    }
}

