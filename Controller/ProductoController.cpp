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

    Producto buscarPorCodigo(int dato)
    {
        Producto objError;
        objError.setNombreProducto("Error");
        for (int i = 0; i < vectorProducto.size(); i++)
        {
            if (dato == vectorProducto[i].getCodigoProducto())
            {
                return vectorProducto[i];
            }
        }
        return objError;
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
            size_t posi; //Cantida Maxima
            string linea;
            string temporal[6];
            fstream archivoProducto;
            archivoProducto.open("Productos.txt", ios::in);
            if (archivoProducto.is_open()) {
                while (!archivoProducto.eof()) {
                    while (getline(archivoProducto, linea)) {
                        i = 0;
                        while ((posi = linea.find(".")) != string::npos) //npos vale -1
                        {
                            temporal[i] = linea.substr(0, posi);
                            linea.erase(0, posi + 1);
                            i++;
                        }
                        //Crear un objeto tipo Producto
                        Producto objProducto;
                        objProducto.setCodigoProducto(stoi(temporal[0]));
                        objProducto.setNombreProducto(temporal[1]);
                        objProducto.setDescripcionProducto(temporal[2]);
                        objProducto.setPrecioProducto(stoi(temporal[3]));
                        objProducto.setStockProducto(stof(temporal[4]));
                        objProducto.setCodigoCategoria(stof(temporal[5]));

                        registrarProducto(objProducto);
                    }
                }
            }
            archivoProducto.close();
        }
        catch (exception e) {
            cout << "Ocurrio un ERROR al momento de leer el archivo";
        }
    }

};
