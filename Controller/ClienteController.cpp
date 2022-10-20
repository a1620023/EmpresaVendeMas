//
// Created by eceledon on 19/10/2022.
//
#include <fstream>
#include <vector>
#include "../Model/Cliente.cpp"

class ClienteController {
private:
    vector<Cliente> vectorCliente;

public:
    ClienteController(){
        cargarDatosDelArchivoAlVector();
    }
    void registrarCliente(Cliente objCliente) {
        vectorCliente.push_back(objCliente);
    }

    Cliente getPosicion(int posicion) {
        return vectorCliente[posicion];
    }

    int size() {
        return vectorCliente.size();
    }

    int getCorrelativo() {
        if (size() == 0) {
            return 1;
        } else {
            return vectorCliente[size() - 1].getCodigoCliente() + 1;
        }
    }

    void guardarEnArchivo(Cliente objCliente) {
        cout << "...guardando cliente" << endl;
        try {
            fstream archivoCliente;
            archivoCliente.open("Clientes.csv", ios::app);
            if (archivoCliente.is_open()) {
                archivoCliente << objCliente.getCodigoCliente() << ";" << objCliente.getNombresCliente() << ";"
                               << objCliente.getApellidosCliente() << ";" << endl;
                archivoCliente.close();
            }
        } catch (exception e) {
            cout << "ocurrio un error al GUARDAR archivoCliente" << endl;
        }
    }

    void cargarDatosDelArchivoAlVector() {
        cout << "...cargando datos del archivo" << endl;
        try {
            int i;
            size_t posicion;
            string linea;
            string temporal[4];
            fstream archivoCliente;
            archivoCliente.open("Clientes.csv", ios::in);
            if (archivoCliente.is_open()) {
                while (!archivoCliente.eof() && getline(archivoCliente, linea)) {
                    i = 0;
                    while ((posicion = linea.find(";")) != string::npos) {
                        temporal[i] = linea.substr(0, posicion);
                        linea.erase(0, posicion + 1);
                        ++i;
                    }

                    Cliente objCliente(stoi(temporal[0]), temporal[1], temporal[2], temporal[3], temporal[4]);
                    registrarCliente(objCliente);
                }
            }

        } catch (exception e) {
            cout << "ocurrio un error al CARGAR archivoCliente" << endl;
        }
    }
};