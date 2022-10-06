//
// Created by eceledon on 5/10/2022.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;

#define USER "Toxica"
#define Pass "123456"

#include "Login.h"

int Login::login(){
    {
        string usuario, password;
        int contador = 0;
        bool ingresa = false;

        do{
            system("cls");
            cout<<"\t\t\tLOGIN DE USUSARIO" <<endl;
            cout<<"\t\t\t-----------------" <<endl;
            cout<<"\n\tUsuario: ";
            getline(cin, usuario);
            cout<<"\tPasssword: ";
            // getline(cin, password);
            char caracter;
            caracter = getch();

            password = "";

            while(caracter != 13){
                password.push_back(caracter);
                cout<<"*";
                caracter = getch();
            }

            if(usuario == USER && password == Pass){
                ingresa = true;
            }   else{
                cout<<"El usuario y/o pasword son incorrectos"<<endl;
                cin.get();
            }
        }while (ingresa == false && contador <3);

        if(ingresa == false) {
            cout<<"\n\tUsted no pudo ingresar al sistema. ADIOS"<<endl;
        }else{
            cout<<"\n\tBienvenido al sistema"<<endl;
        }

        cin.get();
        return 0;

    }
}