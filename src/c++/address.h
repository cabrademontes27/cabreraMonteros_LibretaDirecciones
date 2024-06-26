#ifndef ADDRESSBOOKAPLICATION_H
#define ADDRESSBOOKAPLICATION_H

#include <iostream>
#include "address_data.h"
using namespace std;


class Menu{
public:
    void getMenu(){
        cout<<"=================================="<< endl;
        cout<<"Eliga una opcion del menu"<< endl;
        cout<<"a) Cargar archivo"<<endl;
        cout<<"b) Agregar"<<endl;
        cout<<"c) Eliminar"<<endl;
        cout<<"d) Buscar" <<endl;
        cout<<"e) Mostrar" <<endl;
        cout<<"f) Salir"<<endl; 
        cout<<"=================================="<< endl; 
    }

    char setOpcion(){
        char opcion;
        cin >> opcion;
        return opcion;
    };

};


class AddressBookApplication{
private:
    Menu menu;
    AddresBook logica;
public:
    void seleccionarOpcion(){
        bool control = true;
        while(control){
            menu.getMenu();
            char opcion = menu.setOpcion();
            
            switch (opcion){
                case 'a': logica.importAddressTxt() ;break;
                case 'b': logica.createAddress()    ;break;
                case 'c': logica.deleteAddres()     ;break;
                case 'd': logica.searchAddres()     ;break;
                case 'e': logica.showAddres()       ;break;
                case 'f': control = false; cout<<"Hasta Luego..."<< endl;break;
                default: cout << "Seleccione unas de las opciones presentes \n" << endl;
            };
        };
    };

};

#endif //ADDRESSBOOKAPLICATION_H

