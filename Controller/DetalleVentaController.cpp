#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../Model/DetalleVenta.cpp"
using namespace std;
using  std::stof;
using  std::stoi;

class DetalleVentaController {
private:
    vector<DetalleVenta> detalleVentaVector;

public:
    DetalleVentaController() {}

    void add(DetalleVenta obj) {
        detalleVentaVector.push_back(obj);
    }

    DetalleVenta get(int pos) {
        return detalleVentaVector[pos];
    }

    int rows() {
        return detalleVentaVector.size();
    }

    void grabarArchivo() {
        try {
            fstream archivoDetalle;
            archivoDetalle.open("DetalleVenta.txt", ios::app);
            if (archivoDetalle.is_open()) {
                for (DetalleVenta l : detalleVentaVector) {
                    archivoDetalle << l.getPrecioVenta() << ";" << l.getDescripcion() << ";" << l.getCodigoProducto() << ";" << l.getCantidad() << ";" << l.getPrecioVenta() << ";" << endl;
                }
                archivoDetalle.close();
            }
        }catch (exception e) {
            cout << "�ERROR AL GRABAR EL REGISTRO!";
        }
    }

    void cargarDatosDelArchivoAlVector() {
        try {
            int i;
            size_t posi; //Cantida Maxima
            string linea;
            string temporal[5];
            fstream archivoDetalle;
            archivoDetalle.open("DetalleVenta.txt", ios::in);
            if (archivoDetalle.is_open()) {
                while (!archivoDetalle.eof()) {
                    while (getline(archivoDetalle, linea)) {
                        i = 0;
                        while ((posi = linea.find(";")) != string::npos) //npos vale -1
                        {
                            temporal[i] = linea.substr(0, posi);
                            linea.erase(0, posi + 1);
                            i++;
                        }
                        //Crear un objeto tipo Cliente
                        DetalleVenta detalle;
                        detalle.setCodigoVenta(std::stoi(temporal[0]));
                        detalle.setDescripcion(temporal[1]);
                        detalle.setCodigoProducto(std::stoi(temporal[2]));
                        detalle.setCantidad(std::stoi(temporal[3]));
                        detalle.setPrecioVenta(std::stof(temporal[4]));

                        add(detalle);
                    }
                }
            }
            archivoDetalle.close();
        } catch (exception e) {
            cout << "�Ocurrio un ERROR al momento de leer el archivo!";
        }
    }
    void grabarModificarEliminarArchivo() {
        try {
            fstream archivoDetalle;
            archivoDetalle.open("DetalleVenta.txt", ios::out);
            if (archivoDetalle.is_open()) {
                for (DetalleVenta x : detalleVentaVector) {
                    archivoDetalle <<
                                   x.getCodigoVenta() << "." << x.getCodigoProducto() << "." << x.getCantidad() << "." << x.getPrecioVenta() << "." << "\n";
                }
                archivoDetalle.close();
            }
        }catch (exception e) {
            cout << "Ocurrio un error al grabar en el archivo";
        }
    }

    void listarProdVector(DetalleVenta obj) {
        cout << "Codigo del producto: " << obj.getCodigoProducto() << endl;
        cout << "Cantidad del producto: " << obj.getCantidad() << endl;
        cout << "Subtotal: " << obj.getSubTotal() << endl;
    }

};

