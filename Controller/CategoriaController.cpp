//
// Created by emelc on 27/10/2022.
//
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../Model/Categoria.cpp"
using namespace std;

class CategoriaController {

private:
    vector<Categoria> vectorCategoria;

public:
    CategoriaController(){};

    void registrarCategoria(Categoria objetoCategoria){
        vectorCategoria.push_back(objetoCategoria);
    }

    Categoria getPosicion(int posicion){
        return vectorCategoria[posicion];
    }

    int size(){
        return vectorCategoria.size();
    }

    int getCorrelativo(){
        if (size() == 0){
            return 1;
        } else {
            return vectorCategoria[size() -1].getCodigoCategoria() +1;
        }
    }

    void guardarEnArchivo(Categoria objetoCategoria){
        cout <<"Guardando Categoria..."<<endl;
        try {
            fstream archivoCategoria;
            archivoCategoria.open("Categorias.csv", ios::app);
            if (archivoCategoria.is_open()){
                archivoCategoria <<objetoCategoria.getCodigoCategoria() <<";"<< objetoCategoria.getNombreCategoria() <<";"<<endl;
                archivoCategoria.close();
            }
        } catch (exception e) {
            cout <<"ocurrio un error al GUARDAR archivoCategoria"<<endl;
        }
    }

    void cargarDatosDelArchivoAlVector(){
        cout <<"Cargando Categoria del archvio..."<<endl;
        try {
            int i;
            size_t posicion;
            string linea;
            string arregloTemporal[2];
            fstream archivoCategoria;
            archivoCategoria.open("Categorias.csv", ios::in);
            if (archivoCategoria.is_open()){
                while (!archivoCategoria.eof() && getline(archivoCategoria, linea)){
                    i = 0;
                    while ((posicion = linea.find(";")) != string::npos){
                        arregloTemporal[i] = linea.substr(0, posicion);
                        linea.erase(0, posicion + 1);
                        ++i;
                    }

                    Categoria objCat(stoi(arregloTemporal[0]), arregloTemporal[1]);
                    registrarCategoria(objCat);
                }
            }
        } catch (exception e) {
            cout <<"Ocurrio un error al cargar Categoria del archivo"<<endl;
        }
    }
};
