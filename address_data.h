#ifndef ADDRESS_DATA_H
#define ADDRESS_DATA_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class AddressEntry{
private:
    string nombre,apellido,calle,ciudad;
    string estado,codigoPostal,correoElectronico,numeroTelefono;
public:
    AddressEntry(string _nombre, string _apellido, string _calle, string _ciudad, string _estado, string _codigoPostal, string _correoElectronico, string _numeroTelefono) :
        nombre(_nombre), apellido(_apellido), calle(_calle), ciudad(_ciudad), estado(_ciudad), 
        codigoPostal(_codigoPostal), correoElectronico(_correoElectronico), numeroTelefono(_numeroTelefono)
    {};

    string getNombre(){
        return nombre;
    };
    string getApellido(){
        return apellido;
    };
    string getCalle(){
        return calle;
    };
    string getCiudad(){
        return ciudad;
    };
    string getEstado(){
        return estado;
    };
    string getCodigoPostal(){
        return codigoPostal;
    };
    string getCorreoElectronico(){
        return correoElectronico;
    };
    string getNumeroTelefono(){
        return numeroTelefono;
    };


    void setNombre(string _nombre){
        nombre = _nombre;
    };
    void setApellido(string _apellido){
        apellido = _apellido;
    };
    void setCalle(string _calle){
        calle = _calle;
    };
    void setCiudad(string _ciudad){
        ciudad = _ciudad;
    };
    void setEstado(string _estado){
        estado = _estado;
    };
    void setCodigoPostal(string _codigoPostal){
        codigoPostal = _codigoPostal;
    };
    void setCorreoElectronico(string _correoElectronico){
        correoElectronico = _correoElectronico;
    };
    void setNumeroTelefono(string _numeroTelefono){
        numeroTelefono = _numeroTelefono;
    };

    void toString(){
        cout <<": "<< getNombre() << " " << getApellido() << endl;
        cout << getCalle() << endl;
        cout << getCiudad() << " " << getEstado() << " " << getCodigoPostal() << endl;
        cout << getCorreoElectronico() << endl;
        cout << getNumeroTelefono() << endl;
        cout << " "<< endl;
    };
};
   

class AddresBook{
private:
    vector<AddressEntry> entradasDirectorios;
    ifstream lectorDeArchivo;
public:
    void createAddress(){
        string nombre,apellido,calle,ciudad,estado;
        string codigoPostal,correoElectronico,numeroTelefono;

        cin.ignore();
        cout << "**Nombre**" << endl;
        getline(cin, nombre);
        cout << "**Apellido**" << endl;
        getline(cin, apellido);
        cout << "**Calle**" << endl;
        getline(cin, calle);
        cout << "**Ciudad**" << endl;
        getline(cin, ciudad);
        cout << "**Estado**" << endl;
        getline(cin, estado);
        cout << "**Codigo Postal**" << endl;
        getline(cin, codigoPostal);
        cout << "**Correo Electronico**" << endl;
        getline(cin, correoElectronico);
        cout << "**Numero de Telefono**" << endl;
        getline(cin, numeroTelefono);

        AddressEntry ingresoDeDatos(nombre,apellido,calle,ciudad,estado,codigoPostal,correoElectronico,numeroTelefono);
        addAddresVector(ingresoDeDatos);
        cout << "   " << endl;
        cout << "Se agrego exitosamente \n" << endl;
    };


    void addAddresVector(AddressEntry& entrada){
        entradasDirectorios.push_back(entrada);
    };
    

    void searchAddres(){
        cout << " " << endl;
        cout << "introduzca el numero de telefono de la direccion" << endl;
        string numeroTelefono;
        bool verificador = false;
        int posicion;
        cin >> numeroTelefono;

        for(size_t indice = 0; indice < entradasDirectorios.size(); indice++){
            if(entradasDirectorios[indice].getNumeroTelefono() == numeroTelefono){
                verificador = true;
                posicion = indice;
            };
        }

        if(verificador == true){
            cout << "directorio encontrado: \n" << endl;
            entradasDirectorios[posicion].toString();
        }else cout << "directorio no encontrado" << endl;
    };


    void importAddressTxt() {
        string nombre, apellido, calle, ciudad, estado;
        string codigoPostal, correoElectronico, numeroTelefono;
        bool verificadorArchivoAbierto = false;
        bool verificadorArchivoVacio = true;

        cout << "Ingresa el nombre del archivo:" << endl;
        string nombreArchivo;
        cin >> nombreArchivo;
        cout << " " << endl;

        ifstream VerificadorArchivo(nombreArchivo);

        if (!VerificadorArchivo.is_open()) {
            cout << "No se encontro ningun archivo con ese nombre" << endl;
        } else {
            verificadorArchivoAbierto = true;
            cout << "Archivo encontrado" << endl;
        }

        if (verificadorArchivoAbierto) {
            ifstream archivo(nombreArchivo, ios::ate);
            if (archivo.tellg() == 0) {
                verificadorArchivoVacio = true;
                cout << "El archivo esta vacio" << endl;
            } else {
                verificadorArchivoVacio = false;
            }
        }

        if (!verificadorArchivoVacio && verificadorArchivoAbierto) {
            fstream lectorDeArchivo(nombreArchivo);

            cin.ignore();
            getline(lectorDeArchivo, nombre);
            getline(lectorDeArchivo, apellido);
            getline(lectorDeArchivo, calle);
            getline(lectorDeArchivo, ciudad);
            getline(lectorDeArchivo, estado);
            getline(lectorDeArchivo, codigoPostal);
            getline(lectorDeArchivo, correoElectronico);
            getline(lectorDeArchivo, numeroTelefono);

            AddressEntry importarDatos(nombre, apellido, calle, ciudad, estado, codigoPostal, correoElectronico, numeroTelefono);
            addAddresVector(importarDatos);
            cout << "Se agrego el nuevo directorio correctamente" << endl;
        };
    };

    

    void deleteAddres(){
        cout << " " << endl;
        cout << "introduzca el numero de telefono de la direccion a eliminar" << endl;
        string numeroTelefono;
        bool verificador = false;
        int posicion;
        cin >> numeroTelefono;

        for(size_t indice = 0; indice < entradasDirectorios.size(); indice++){
            if(entradasDirectorios[indice].getNumeroTelefono() == numeroTelefono){
                verificador = true;
                posicion = indice;
            };
        }

        if(verificador == true){
            cout << "directorio encontrado: \n" << endl;
            entradasDirectorios[posicion].toString();
            cout << "Desea eliminarlo"<< endl;
            cout << "S/N" << endl;
            

            while(verificador == true){
                char opcion;
                cin >> opcion;
                switch(opcion){
                case 's':entradasDirectorios.erase(entradasDirectorios.begin() + posicion); cout <<"Se elimino exitosamente"<< endl; verificador = false;break;
                case 'n': cout<<"La operacion ha sido cancelada"<< endl; verificador = false ;break;
                default: cout << "Selecciona una de las opciones disponibles \n" << endl;
                };
            };
        };
    };


    void showAddres(){
        for(size_t indice = 0; indice < entradasDirectorios.size(); indice++){
            int indicador = indice;
            indicador++;
            cout << indicador;
            entradasDirectorios[indice].toString();
        };
    };

};



#endif // ADDRESS_DATA_H