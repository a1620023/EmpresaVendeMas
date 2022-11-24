#include<iostream>
#include<vector>
#include "../Model/Venta.cpp"
#include<fstream>
using namespace std;
using  std::stof;
using  std::stoi;
class VentaController {
protected:
    vector<Venta> vectorVenta;

public:
    VentaController() {
        //cargarDatosDelArchivoAlVector();
    }

    void registrarVenta(Venta objetoVenta){
        vectorVenta.push_back(objetoVenta);
    }

    Venta getPosicion(int posicion) //Entregar el objeto actual, segun la posicion pasada como parametro
    {
        return vectorVenta[posicion];
    }

    int size()
    {
        return vectorVenta.size(); //Cantidad total de elementos del vector
    }

    int getCorrelativo() {
        int i = 0;
        try {
            size_t posi; //Cantida Maxima
            string linea;
            fstream archivoVenta;
            archivoVenta.open("Ventas.txt", ios::in);
            if (archivoVenta.is_open()) {
                while (!archivoVenta.eof()) {
                    while (getline(archivoVenta, linea)) {

                        i += 1;//i=1+1
                        return i;
                    }
                }
                archivoVenta.close();
            }
        } catch (exception e) {
            cout << "¡Ocurrio un ERROR al momento de leer el archivo!";
        }
        return i; //1
    }

    void guardarEnArchivo() {
        try {
            fstream archivoVenta;
            archivoVenta.open("Venta.txt", ios::app);
            if (archivoVenta.is_open()) {
                for (Venta venta : vectorVenta)
                {
                    archivoVenta << venta.getCodigoVenta() << ";" << venta.getCodigoCliente() << ";" << venta.getCodigoVendedor() << ";" << venta.getFechaVenta() << ";" << venta.getTotalVenta() << ";"  << endl;
                }
                archivoVenta.close();
            }
        } catch (exception e)
        {
            cout << "¡ERROR AL GRABAR EL REGISTRO!";
        }
    }


    void cargarDatosDelArchivoAlVector() {
        try {
            int i;
            size_t posicion; //Cantida Maxima
            string linea;
            string temporal[5];
            fstream archivoVenta;
            archivoVenta.open("Venta.txt", ios::in);
            if (archivoVenta.is_open())
            {
                while (!archivoVenta.eof())
                {
                    while (getline(archivoVenta, linea))
                    {
                        i = 0;
                        while ((posicion = linea.find(".")) != string::npos) //npos vale -1
                        {
                            temporal[i] = linea.substr(0, posicion);
                            linea.erase(0, posicion + 1);
                            i++;
                        }
                        //Crear un objeto tipo Venta
                        Venta venta;
                        venta.setCodigoVenta(std::stoi(temporal[0]));
                        venta.setCodigoCliente(std::stoi(temporal[1]));
                        venta.setCodigoVendedor(std::stoi(temporal[2]));
                        venta.setFechaVenta(temporal[3]);
                        venta.setTotalVenta(std::stof(temporal[4]));


                        registrarVenta(venta);
                    }
                }
            }
            archivoVenta.close();
        } catch (exception e) {
            cout << "¡Ocurrio un ERROR al momento de leer el archivo!";
        }
    }
};










