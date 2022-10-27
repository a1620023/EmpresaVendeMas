//
// Created by eceledon on 5/10/2022.
//
#include <fstream>
#include <vector>
#include "../Model/Producto.cpp"

class ProductoController {

private:
    vector<Producto> vectorProducto;

public:
    ProductoController(){}

    void registrarProducto(Producto objetoProducto){
        vectorProducto.push_back(objetoProducto);
    }

    Producto getPosicion(int posicion){
        return vectorProducto[posicion];
    }

    int size(){
        return vectorProducto.size();
    }

    int getCorrelativo() {
        if (size() == 0){
            return 1;
        } else {
            return vectorProducto[size() -1].getCodigoProducto() +1;
        }
    }

    void guardarEnArchivo(Producto objetoProducto) {
        cout <<"Guardando Producto..."<<endl;
        try {
            fstream archivoProducto;
            archivoProducto.open("Productos.csv", ios::app);
            if (archivoProducto.is_open()){
                archivoProducto <<objetoProducto.getCodigoProducto() <<";"<< objetoProducto.getNombreProducto() <<";"<<
                objetoProducto.getDescripcionProducto() <<";"<< objetoProducto.getPrecioProducto() <<";"<<
                objetoProducto.getStockProducto() <<";"<< objetoProducto.getCodigoCategoria() <<";"<<endl;
                archivoProducto.close();
            }
        } catch (exception e) {
            cout <<"ocurrio un error al GUARDAR archivoProducto"<<endl;
        }
    }

    void cargarDatosDelArchivoAlVector() {
        cout <<"Cargando Productos del archvio..."<<endl;
        try {
            int i;
            size_t posicion;
            string linea;
            string arregloTemporal[4];
            fstream archivoProducto;
            archivoProducto.open("Productos.csv", ios::in);
            if (archivoProducto.is_open()){
                while (!archivoProducto.eof() && getline(archivoProducto, linea)){
                    i = 0;
                    while ((posicion = linea.find(";")) != string::npos){
                        arregloTemporal[i] = linea.substr(0, posicion);
                        linea.erase(0, posicion + 1);
                        ++i;
                    }

                    Producto objProd(stoi(arregloTemporal[0]), arregloTemporal[1], arregloTemporal[2], stoi(arregloTemporal[3]), stoi(arregloTemporal[4]), stoi(arregloTemporal[5]));
                    registrarProducto(objProd);
                }
            }
        } catch (exception e) {
            cout <<"Ocurrio un error al cargar Productos del archivo"<<endl;
        }
    }

};
