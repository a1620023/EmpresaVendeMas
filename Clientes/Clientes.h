//
// Created by eceledon on 5/10/2022.
//
#ifndef EMPRESAVENTAMAS_CLIENTES_H
#define EMPRESAVENTAMAS_CLIENTES_H


class Clientes {

private:
    int codigo;
    string nombres;
    string apellidos;

public:
    Clientes();
public:
    Clientes(int codigo, string nombres, string apellidos);

    int getCodigo() const;

    void setCodigo(int codigo);

    const string &getNombres() const;

    void setNombres(const string &nombres);

    const string &getApellidos() const;

    void setApellidos(const string &apellidos);
};


#endif //EMPRESAVENTAMAS_CLIENTES_H
