#ifndef PROYECTO_CRISTIAN_FUNCIONES_H
#define PROYECTO_CRISTIAN_FUNCIONES_H

#include <iostream>
#include "word.h"
#include "word.cpp"

using namespace std;

void savefile(Word* file){
    ofstream archivo;
    string nombreArchivo;
    cout << "Digite el nombre del archivo: " << endl;
    cin >> nombreArchivo;
    if (!(file->isAligned()) && !(file->isEncript())){
        file->alinearIzquierda();
    }
    archivo.open(nombreArchivo, ios::out);
    for (int i = 0; i<file->getTexto().size(); i++){
        for (int j = 0; j<file->getTexto()[i].size(); j++){
            archivo << file->getTexto()[i][j];
            cout << file->getTexto()[i][j];
        }
        archivo << '\n';
        cout << '\n';
    }
    archivo.close();
}

void menuFunction(char opcion, Word*& file)
{
    switch(opcion)
    {
        case '0':
        {
            file = new Word();
            break;
        }
        case '1':
        {
            if (file != nullptr){
                savefile(file);
                cout << "Guardado correctamente"<< endl;
            } else
                cout<<"No ha abierto un archivo, por favor seleccione opcion 0." <<endl;
            break;
        }
        case '2':
        {
            if (file != nullptr){
                file->justificar();
                cout << "Se justifico correctamente el texto" << endl;
            } else
                cout<<"No ha abierto un archivo, por favor seleccione opcion 0." <<endl;
            break;
        }
        case '3':
        {
            if (file != nullptr){
                file->alinearIzquierda();
                cout << "Se alineo correctamente el texto"<< endl;
            } else
                cout<<"No ha abierto un archivo, por favor seleccione opcion 0." <<endl;
            break;
        }
        case '4':
        {
            if (file != nullptr){
                file->alinearDerecha();
                cout<<"Se alineo correctamente el texto" << endl;
            } else
                cout<<"No ha abierto un archivo, por favor seleccione opcion 0." <<endl;
            break;
        }
        case '5':
        {
            if (file != nullptr){
                file->alinearCentro();
                cout << "Se alineo correctamente el texto" << endl;
            } else
                cout<<"No ha abierto un archivo, por favor seleccione opcion 0." <<endl;
            break;
        }
        case '6':
        {
            if (file != nullptr) {
                string palabra;
                cout << "Digite la palabra a buscar: ";
                cin >> palabra;
                file->findWord(palabra);
            } else
                cout<<"No ha abierto un archivo, por favor elija opcion 0." <<endl;
            break;
        }
        case '7':
        {
            if (file != nullptr){
                string palabra, palabra2;
                cout << "Digite la palabra a buscar: ";
                cin >> palabra;
                cout << "Digite la palabra a reemplazar: ";
                cin >> palabra2;
                file->reemplazar(palabra, palabra2);
            } else
                cout<<"No ha abierto un archivo, por favor elija opcion 0." <<endl;
            break;
        }
        case '8':
        {
            if (file != nullptr){
                string palabra;
                cout << "Digite la palabra a buscar: ";
                cin >> palabra;
                cout << "La cantidad de veces que aparece es: "<< file->contarPalabra(palabra) << endl;
            } else
                cout<<"No ha abierto un archivo, por favor elija opcion 0." <<endl;
            break;
        }
        case '9':
        {
            if (file != nullptr){
                if (file->isEncript()){
                    file->desencriptar();
                    cout << "Desencriptado correctamente" << endl;
                } else {
                    file->encriptar();
                    cout << "Encriptado correctamente" << endl;
                }
            } else
                cout<<"No ha abierto un archivo, por favor elija opcion 0." <<endl;
            break;
        }
        default:
        {
            cout<<"Ingrese otra opcion." <<endl;
        }
    }
}

void menu(){
    cout<<"\nBienvenido"<<endl;
    cout<<"0. Leer archivo"<< "  ";
    cout<<"1. Guardar archivo" << "  ";
    cout<<"2. Justificar texto" << endl;
    cout<<"3. Alinear a la izquierda" << "  ";
    cout<<"4. Alinear a la derecha" << "  ";
    cout<<"5. Centrar el texto" << endl;
    cout<<"6. Buscar una palabra" <<"  ";
    cout<<"7. Reemplazar una palabra" <<"  ";
    cout<<"8. Contar una palabra"<<"  ";
    cout<<"9. Encriptar/Desencriptar" <<endl;
}

void pantallaPrincipal(Word* file)
{
    char opcion;
    do{
        menu();
        cout << "Escriba el numero de una opcion (X para terminar): ";
        cin >> opcion;
        menuFunction(opcion, file);
    }while(opcion!='X');
}

#endif //PROYECTO_CRISTIAN_FUNCIONES_H
