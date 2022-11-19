//
// Created by emelc on 27/10/2022.
//
#include <iostream>
using namespace std;

class Categoria {

private:
    int codigoCategoria;
    string nombreCategoria;

public:
    Categoria(){}

    Categoria(int codigoCategoria, string nombreCategoria){
        this->codigoCategoria = codigoCategoria;
        this->nombreCategoria = nombreCategoria;
    }

    int getCodigoCategoria() {
        return codigoCategoria;
    }

    void setCodigoCategoria(int codigoCategoria) {
        codigoCategoria = codigoCategoria;
    }

    string getNombreCategoria() {
        return nombreCategoria;
    }

    void setNombreCategoria(string nombreCategoria) {
        nombreCategoria = nombreCategoria;
    }

};