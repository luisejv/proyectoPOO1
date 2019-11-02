#include <iostream>
#include <fstream>
#include <string.h>
#include "word.h"
#include <sstream>

using namespace std;

/* Este es el constructor, que al inicializar los objetos
llena la matriz de caracteres con los datos del texto
 */

Word::Word(){
    ifstream archivo;
    char caracter;
    string nomArch;
    cout<<"Digite el nombre del archivo: ";
    cin>>nomArch;
    archivo.open(nomArch,ios::in);
    if(!archivo){
        cout<<"No se puede abrir el archivo";
        exit(1);
    } else {
        /*el contador es por si hay saltos de linea en el archivo,
         * y lo que hace es pasar a la siguiente fila de la matriz
         */
        int cont = 0;
        /*Creamos otro contador que nos ayude a saltar de linea
         * cuando la linea este llena*/
        int cont2 = 0;
        /* Aqui tambien seteamos el tamano de cada linea
         * */
        cout << "Digite la longitud de cada linea del archivo: ";
        cin >> size;
        //redimensionamos las filas, el valor 20 es momentaneo
        texto.resize(20);
        //comenzamos a leer el archivo y guardarlo en la matriz
        while(archivo >> noskipws >> caracter){
            //checkeamos que no sea salto de linea y escribimos en la matrix
            //caso contrario, saltamos de linea.
            if (caracter != '\n'){
                //cuando llegamos a la cantidad maxima de caracteres en una linea,
                //pasamos a la siguiente linea sumando cont y reseteando cont2 a 0
                if (cont2==size){
                    cont++;
                    cont2 = 0;
                }
                texto[cont].push_back(caracter);
                cont2++;
            } else
                cont++;
        }
        archivo.close();
        /* este bucle es de prueba para ver si se guardo correctamente
        for (int i = 0; i<texto.size(); i++){
            for (int j = 0; j<texto[i].size(); j++){
                cout << texto[i][j];
            }
            cout << texto[i].size() << endl;
        }*/
        //aqui llenaremos el vector palabras
        archivo.open(nomArch,ios::in);
        string palabra, linea;
        //palabras.resize(50);
        while(getline(archivo, linea)){
            stringstream linea2(linea);
            while(linea2 >> palabra){
                palabras.push_back(palabra);
            }
        }
        archivo.close();
    }
}

//a partir de aqui vienen los setters y getters

vector<string> Word::getPalabras(){
    return palabras;
}

int Word::getSize() const {
    return size;
}

void Word::setSize(int size) {
    Word::size = size;
}

bool Word::isEncript() const {
    return encript;
}

void Word::setEncript(bool encript) {
    Word::encript = encript;
}

const vector<vector<char>> &Word::getTexto() const {
    return texto;
}

//a partir de aqui empieza la definicion de los metodos

void Word::justificar(){

}

void Word::alinearDerecha(){

}

void Word::alinearIzquierda(){

}

void Word::alinearCentro(){

}

void Word::findWord(string palabra){
    int cont = 0;
    bool encontrado = false;
    for (auto i: palabras){
        if (i == palabra){
            encontrado = true;
            cout << "Se encontro la palabra en la posicion " << cont << endl;
        }
        cont++;
    }
    if (!encontrado)
        cout << "No se encontro la palabra en el texto" << endl;
}

void Word::reemplazar(string palabra, string palabra2){
    bool encontrado = false;
    for (int i =0; i<palabras.size(); i++){
        if (palabras[i]==palabra){
            encontrado = true;
            palabras[i] = palabra2;
        }
    }
    if (!encontrado)
        cout << "No se encontro la palabra a reemplazar en el texto" << endl;
    else
        cout << "Se reemplazaron todas las ocurrencias" << endl;
}

int Word::contarPalabra(string palabra){
    int cont=0;
    for (int i = 0; i<palabras.size(); i++){
        if (palabras[i] == palabra){
            cont++;
        }
    }
    return cont;
}

void Word::encriptar(){

}

void Word::desencriptar(){

}

