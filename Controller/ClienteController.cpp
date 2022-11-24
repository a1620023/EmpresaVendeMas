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
        //cargarDatosDelArchivoAlVector();
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

    void buscarPorDocumento(string datoDeBusqueda){
        int codigoCliente;
        string nombresCliente;
        string apellidosCliente;
        string dniCliente;
        string edadCliente;
        bool registroEncontrado = false;

        cout << "Buscando... : "<< datoDeBusqueda << endl;

        fstream lectura;
        lectura.open("Clientes.csv", ios::in);

        while (!lectura.eof() && !registroEncontrado){
            lectura>>codigoCliente >>nombresCliente >>apellidosCliente >>dniCliente >>edadCliente;

            if(dniCliente == datoDeBusqueda){
                cout << "Codigo----------: "<< codigoCliente << endl;
                cout << "Nombres---------: "<< nombresCliente << endl;
                cout << "Apellidos-------: "<< apellidosCliente << endl;
                cout << "DNI-------------: "<< dniCliente << endl;
                cout << "Edad------------: "<< edadCliente << endl;
                cout << "-------------------------------------------" << endl;
                registroEncontrado = true;
            }
            //lectura>>nombresCliente;
        }
        lectura.close();
        if(!registroEncontrado){
            cout << "====== Registro no encontrado ======" << endl;
        }
        system("pause");
    }

    string buscarCodigoCliente(string buscarDNI) {
        int codigoCliente;
        string nombresCliente;
        string apellidosCliente;
        string dniCliente;
        string edadCliente;
        //bool registroEncontrado = false;

        ifstream Leer;
        system("cls");
        Leer.open("Clientes.csv");
        Leer>>codigoCliente >>nombresCliente >>apellidosCliente >>dniCliente >>edadCliente;
        bool encontrado = false;
        //cout<<"Ingrese su numero de cedula para buscar"<<endl;
        //cin>>buscarDNI;
        while(!Leer.eof()) {
            Leer>>dniCliente;
            if(dniCliente==buscarDNI) {
                encontrado=true;
                cout<<"----------------------------"<<endl;
                cout<<"Codigo:    "<<codigoCliente<<endl;
                cout<<"Nombre:    "<<nombresCliente<<endl;
                cout<<"Apellido:  "<<apellidosCliente<<endl;
                cout<<"dniCliente:      "<<dniCliente<<" anio"<<endl;
                cout<<"edadCliente:  "<<edadCliente<<endl;
                cout<<"----------------------------"<<endl;
                cout<<endl;
            }
            Leer>>codigoCliente >>nombresCliente >>apellidosCliente >>dniCliente >>edadCliente;
        }
        if(encontrado==false) {
            cout<<"DNI no encontrado"<<endl;
        }
        Leer.close();
        //buscarPorDocumento(codigo);
    }

    void guardarEnArchivo(Cliente objCliente) {
        cout << "...guardando cliente" << endl;
        try {
            fstream archivoCliente;
            archivoCliente.open("Clientes.csv", ios::app);
            if (archivoCliente.is_open()) {
                archivoCliente << objCliente.getCodigoCliente() << ";" << objCliente.getNombresCliente() << ";"
                               << objCliente.getApellidosCliente() << ";" << objCliente.getDniCliente() << ";"
                               << objCliente.getEdadCliente() << ";" << endl;
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