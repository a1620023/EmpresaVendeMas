//
// Created by eceledon on 5/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <bitset>
using namespace std;


#define N 50
//char user[] = "trabajador";
//char contra[] = "cualquiera";
//void log();
//void menu();
//void leerPasw(char frase[]);
//void limpia();
//void cambio(char a[]);
//void encriptar(char contra2[]);


#define USER "Roberto"
#define PASS "123456"


class Login{
private:
    char user[20]="trabajador";
    char contra[20]="cualquiera";
    char user2[20],contra2[20];

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

public:
    Login(){
        log();
    }
void log() {
    int x=1000;

    cout << "*************LOGIN***********" << '\n'<<'\n';
    cout << "USUARIO:  " ;
    fgets(user2,20,stdin);
    cambio(user2);

    std::cout << "CLAVE:  " ;

    leerPasw(contra2);
    encriptar(contra2);

    for(int i = 0; i < 1; i++ ){
        std::cout <<'\n';
        std::cout << "Cargando" ;
        std::cout << "..." << '\n';
        Sleep(x);
    }

    if ((strcmp(user2,user)) == 0 && (strcmp(contra2,contra)) == 0){
        cout<<"                                     ";
        for(int i = 0; i < 1; i++ ){
            std::cout << "Accediendo al sistema " ;
            std::cout << "..." << '\n';

            Sleep(x);
        }
        limpia();
        menu();

    }else {
        cout<<"                                     ";
        cout << "Datos incorrectos" << '\n';
        cout << "Presione un tecla para volver a ingresar... " << '\n';		getch();
        limpia();
        log();

    }
}
void cambio(char a[]){
    int aux;
    aux = strlen(a);
    a[aux-1] = '\0';
}
void leerPasw(char frase[]){
    int i=0;
    cout.flush();
    int aux=0;

    do
    {
        frase[i] = (unsigned char)getch();

        if(frase[i]!=8)
        {
            cout << '*';
            i++;

            if (frase[i-1]==13){
                printf("\b \b");
            }
        }
        else if(i>0)
        {
            cout << (char)8 << (char)32 << (char)8;
            i--;
        }


        cout.flush();

    }while(frase[i-1]!=13);

    frase[i-1] = 0;
}

void limpia(){
    system("cls");
}
void menu(){
    int opt;
    do
    {
        cout<<"MENU DE OPCIONES\n";
        cout<<"Ingresar Nuevos Productos	[1]\n";
        cout<<"Eliminar Nuevos Productos	[2]\n";
        cout<<"Modificar Nuevos Productos	[3]\n";
        cout<<"Buscar Nuevos Productos	[4]\n";
        cout<<"Listar Productos			[5]\n";
        cout<<"Salir					[6]\n";
        cout<<"Ingrese una opcion[1-6]:";
        cin>>opt;
        /*switch(opt)
        {
          case 1:	system("cls");
              adicionarProductos();
              break;
          case 2:system("cls");eliminarProductos();break;
          case 3:system("cls");modificarProductos();break;
          case 4:system("cls");buscarAlumno();break;
          case 5:	system("cls");
              listarProductos();
              break;
          case 6:	cout<<"###########Gracias por tu compra##########\n";
              exit(0);
              break;
          default:cout<<"Ingrese una opcion correcta[1-6]"<<endl;
        }*/
    }
    while(opt!=6);
}

void encriptar(char contra2[]){
    float numero;
    ofstream salida;
    salida.open("cript.txt", ios::app);
    salida<<contra2<<endl;
    string str = contra2;

    for (int i = 0; i < str.length(); ++i) {
        bitset<8> bs4(str[i]);
        salida << bs4 << " ";

        if (i % 6 == 0 && i != 0)
            salida << endl;
    }
    salida << endl;



}


};