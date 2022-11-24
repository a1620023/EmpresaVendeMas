//
// Created by eceledon on 6/10/2022.
//

#include <fstream>
#include <vector>
#include "../Model/Vendedores/Vendedor.cpp"


class VendedorController {
private:
    vector<Vendedor> vectorVendedor;

public:
VendedorController() {}

void registarVendedor(Vendedor objVendedor) {
    vectorVendedor.push_back(objVendedor);
}

Vendedor getPosicion(int posicion) {
    return vectorVendedor[posicion];
};

int size() {
    return vectorVendedor.size();
}

int getCorrelativo() {
    if (size() == 0){
        return 1;
    } else {
        return vectorVendedor[size() - 1].getCodigoVendedor() + 1;
    }
}

void grabarEnArchivo(Vendedor obj)
{
    try
    {
        fstream archivoVendedor;
        archivoVendedor.open("vendedor.csv",ios::app);
        if(archivoVendedor.is_open())
        {
            archivoVendedor<<obj.getCodigoVendedor()<<";"<<obj.getNombresVendedor()<<";"<<obj.getApellidosVendedor()<<";"<<obj.getDniVendedor()<<";"<<endl;
            archivoVendedor.close();
        }
    }
    catch(exception e)
    {
        cout<<"Ocurrio un error al grabar el archivo";
    }
}

void cargarDatosDelArchivoAlVector()
{
    try{
        int 	i;
        size_t 	posicion;
        string 	linea;
        string 	temporal[4];
        fstream	archivoVendedor;
        archivoVendedor.open("vendedor.csv",ios::in);
        if(archivoVendedor.is_open())
        {
            while(!archivoVendedor.eof() && getline(archivoVendedor,linea))
            {
                i = 0;
                while((posicion = linea.find(";")) != string::npos)
                {
                    temporal[i] = linea.substr(0,posicion);
                    linea.erase(0,posicion+1);
                    ++i;
                }

                //Vendedor objVendedors(stoi(temporal[0]), temporal[1], temporal[2], stoi(temporal[3]));
                //Vendedor objVendedor(stoi(temporal[0]), temporal[1], temporal[2], temporal[3], stoi(temporal[4]));

                //registarVendedor(objVendedor);

            }
        }
    }
    catch(exception e)
    {
        cout<<"Ocurrio un error al grabar el archivo";
    }
}

};


