#ifndef PROYECTO_CRISTIAN_FUNCIONES_H
#define PROYECTO_CRISTIAN_FUNCIONES_H

#include <iostream>
#include "word.h"
#include "word.cpp"

using namespace std;

//void matrizAMatriz(Word* file){}

void savefile(Word* file){
    ofstream archivo;
    string nombreArchivo;
    cout << "Digite el nombre del archivo: " << endl;
    cin >> nombreArchivo;
    archivo.open(nombreArchivo, ios::out);
    for (int i = 0; i<file->getTexto().size(); i++){
        for (int j = 0; j<file->getTexto()[i].size(); j++){
            archivo << file->getTexto()[i][j];
        }
        archivo << '\n';
    }
    archivo.close();
}

void menuFunction(int opcion, Word*& file)
{
    switch(opcion)
    {
        case 1:
        {
            file = new Word();
            cout << "Cargado correctamente" << endl;
            break;
        }
        case 2:
        {
            if (file != nullptr){
                savefile(file);
                cout << "Guardado correctamente"<< endl;
            } else
                cout<<"No ha abierto un archivo, por favor seleccione opcion 1." <<endl;
            break;
        }
        case 3:
        {
            if (file != nullptr){
                file->justificar();
                cout << "Se justifico correctamente el texto" << endl;
            } else
                cout<<"No ha abierto un archivo, por favor seleccione opcion 1." <<endl;
            break;
        }
        case 4:
        {
            if (file != nullptr){
                file->alinearIzquierda();
                cout << "Se alineo correctamente el texto"<< endl;
            } else
                cout<<"No ha abierto un archivo, por favor seleccione opcion 1." <<endl;
            break;
        }
        case 5:
        {
            if (file != nullptr){
                file->alinearDerecha();
                cout<<"Se alineo correctamente el texto" << endl;
            } else
                cout<<"No ha abierto un archivo, por favor seleccione opcion 1." <<endl;
            break;
        }
        case 6:
        {
            if (file != nullptr){
                file->alinearCentro();
                cout << "Se alineo correctamente el texto" << endl;
            } else
                cout<<"No ha abierto un archivo, por favor seleccione opcion 1." <<endl;
            break;
        }
        case 7:
        {
            if (file != nullptr) {
                string palabra;
                cout << "Digite la palabra a buscar: ";
                cin >> palabra;
                file->findWord(palabra);
            } else
                cout<<"No ha abierto un archivo, por favor elija opcion 1." <<endl;
            break;
        }
        case 8:
        {
            if (file != nullptr){
                string palabra, palabra2;
                cout << "Digite la palabra a buscar: ";
                cin >> palabra;
                cout << "Digite la palabra a reemplazar: ";
                cin >> palabra2;
                file->reemplazar(palabra, palabra2);
            } else
                cout<<"No ha abierto un archivo, por favor elija opcion 1." <<endl;
            break;
        }
        case 9:
        {
            if (file != nullptr){
                string palabra;
                cout << "Digite la palabra a buscar: ";
                cin >> palabra;
                cout << "La cantidad de veces que aparece es: "<< file->contarPalabra(palabra) << endl;
            } else
                cout<<"No ha abierto un archivo, por favor elija opcion 1." <<endl;
            break;
        }
        case 10:
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
                cout<<"No ha abierto un archivo, por favor elija opcion 1." <<endl;
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
    cout<<"1. Leer archivo"<< "  ";
    cout<<"2. Guardar archivo" << "  ";
    cout<<"3. Justificar texto" << endl;
    cout<<"4. Alinear a la izquierda" << "  ";
    cout<<"5. Alinear a la derecha" << "  ";
    cout<<"6. Centrar el texto" << endl;
    cout<<"7. Buscar una palabra" <<"  ";
    cout<<"8. Reemplazar una palabra" <<"  ";
    cout<<"9. Contar una palabra"<<"  ";
    cout<<"10. Encriptar/Desencriptar" <<endl;
}

void pantallaPrincipal(Word* file)
{
    int opcion = 0;
    do{
        menu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        menuFunction(opcion, file);
    }while(opcion!=0);
}

#endif //PROYECTO_CRISTIAN_FUNCIONES_H
