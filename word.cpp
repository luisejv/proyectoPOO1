#include <iostream>
#include <fstream>
#include <string>
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
        //exit(1);
    } else {
        //aqui llenaremos el vector palabras
        string palabra, linea;
        int max = 0;
        while(getline(archivo, linea)){
            stringstream linea2(linea);
            while(linea2 >> palabra){
                if (palabra.length() > max){
                    max = palabra.length();
                }
                palabras.push_back(palabra);
            }
        }
        archivo.close();
        //aqui empieza la lectura por caracteres
        bool correcto = false;
        while (!correcto){
            cout << "Digite la longitud de cada linea del archivo" <<
            " (debe ser al menos "<< max <<"): ";
            cin >> size;
            if (size >= max){
                correcto = true;
            }
        }
        //comenzamos a leer el archivo y guardarlo en la matriz
        vector<char> line;
        int cont = 0;
        while(archivo >> noskipws >> caracter){
            //checkeamos que no sea salto de linea y escribimos en la matrix
            //caso contrario, saltamos de linea.
            if (caracter != '\n' && cont<size){
                 line.push_back(caracter);
                 cont++;
            } else{
                texto.push_back(line);
                line.clear();
                cont = 0;
            }
        }
        archivo.close();
        cout << "Cargado correctamente" << endl;
    }
    encript = false;
    aligned = false;
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
    texto.clear();
    int cantPalabras = 0;
    bool acabar = false;
    cout << palabras.size() << endl;
    while (!acabar){
        int i = 0;
        vector<char> linea;
        bool vacio = true;
        while (vacio && cantPalabras<palabras.size()){
            if (palabras[cantPalabras].size()<=(size-i) && (size-i)>=0){
                cout << palabras[cantPalabras] << " " << palabras[cantPalabras].size() << " " << size - i << endl;
                for(int j = 0; j<palabras[cantPalabras].size(); j++){
                    linea.push_back(palabras[cantPalabras][j]);
                    i++;
                }
                cantPalabras++;
                linea.push_back(' ');
                i++;
                for (auto it: linea){
                    cout << it;
                }
                cout << " " << linea.size() << " " << size-i << endl;
            } else {
                //para remover el último espacio en la linea
                i--;
                linea.pop_back();
                vacio = false;
                for (auto it: linea){
                    cout << it;
                }
                int cantEspacios = size - i;
                cout << " " << linea.size() << " " << cantEspacios << endl;
                bool espaciosAsignados = false;
                int recorre = 0;
                while(!espaciosAsignados){
                    while(recorre!=size && cantEspacios!=0){
                        if (linea[recorre]==' '){
                            //insertar espacio
                            linea.insert(linea.begin()+recorre, ' ');
                            cantEspacios--;
                            recorre++;
                        }
                        recorre++;
                    }
                    if (cantEspacios == 0)
                        espaciosAsignados = true;
                    else
                        recorre = 0;
                }
                for (auto it: linea){
                    cout << it;
                }
                cout << " " << linea.size() << endl;
                texto.push_back(linea);
            }
        }
        if (cantPalabras == palabras.size())
            acabar = true;
    }
    aligned = true;
}

void Word::alinearDerecha(){
    texto.clear();
    int cantPalabras = 0;
    bool acabar = false;
    while (!acabar){
        int i = 0;
        vector<char> linea;
        bool vacio = true;
        while (vacio && cantPalabras<palabras.size()){
            if (palabras[cantPalabras].size()<(size-i)){
                for(int j = 0; j<palabras[cantPalabras].size(); j++){
                    linea.push_back(palabras[cantPalabras][j]);
                    i++;
                }
                cantPalabras++;
                linea.push_back(' ');
                i++;
            } else {
                //para remover el último espacio en el arreglo
                i--;
                linea.pop_back();
                vacio = false;
                int cantEspacios = size - i;
                for (int j=0; j<cantEspacios; j++){
                    linea.insert(linea.begin(), ' ');
                }
                texto.push_back(linea);
            }
        }
        if (cantPalabras == palabras.size())
            acabar = true;
    }
    aligned = true;
}

void Word::alinearIzquierda(){
    texto.clear();
    int cantPalabras = 0;
    bool acabar = false;
    while (!acabar){
        int i = 0;
        vector<char> linea;
        bool vacio = true;
        while (vacio && cantPalabras<palabras.size()){
            if (palabras[cantPalabras].size()<(size-i)){
                for(int j = 0; j<palabras[cantPalabras].size(); j++){
                    linea.push_back(palabras[cantPalabras][j]);
                    i++;
                }
                cantPalabras++;
                linea.push_back(' ');
                i++;
            } else {
                //para remover el último espacio en el arreglo
                i--;
                linea.pop_back();
                vacio = false;
                texto.push_back(linea);
            }
        }
        if (cantPalabras == palabras.size())
            acabar = true;
    }
    aligned = true;
}

void Word::alinearCentro(){
    texto.clear();
    int cantPalabras = 0;
    bool acabar = false;
    while (!acabar){
        int i = 0;
        vector<char> linea;
        bool vacio = true;
        while (vacio && cantPalabras<palabras.size()){
            if (palabras[cantPalabras].size()<(size-i)){
                for(int j = 0; j<palabras[cantPalabras].size(); j++){
                    linea.push_back(palabras[cantPalabras][j]);
                    i++;
                }
                cantPalabras++;
                linea.push_back(' ');
                i++;
            } else {
                //para remover el último espacio en el arreglo
                i--;
                linea.pop_back();
                vacio = false;
                int cantEspacios = size - i;
                for (int j = 0; j < cantEspacios; j++){
                    if (j%2==0){
                        linea.insert(linea.begin(), ' ');
                    }
                }
                texto.push_back(linea);
            }
        }
        if (cantPalabras == palabras.size())
            acabar = true;
    }
    aligned = true;
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
    for(int i=0; i<texto.size(); i++) {
        for (int j = 0; j < texto[i].size(); j++) {
            texto[i][j] = texto[i][j] - 65;
        }
    }
    encript = true;
}

void Word::desencriptar(){
    for(int i=0; i<texto.size(); i++) {
        for (int j = 0; j < texto[i].size(); j++) {
            texto[i][j] = texto[i][j] + 65;
        }
    }
    encript = false;
}

bool Word::isAligned() const {
    return aligned;
}

void Word::setAligned(bool aligned) {
    Word::aligned = aligned;
}

