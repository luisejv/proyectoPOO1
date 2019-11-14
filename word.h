#ifndef PROYECTO_CRISTIAN_WORD_H
#define PROYECTO_CRISTIAN_WORD_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

/*Aqui se define la clase Word que almacenara los datos en una
matriz de caracteres, contando los espacios en blanco. Ademas, tendra un
 atributo encript que me dira si el archibo esta encriptado o no y un
 atributo size que me permite saber de que tamaño es cada fila del archivo
 a guardar. Por ultimo, usamos el vector de strings "palabras" que nos ayudara
 con la busqueda y el reemplazo de palabras.
 */

class Word
{
private:
    vector<vector<char>> texto;
    vector<string> palabras;
    int size;
    bool encript;
    bool aligned;
public:
    //Contructor
    Word();
    //Getters y Setters
    const vector<vector<char>> &getTexto() const;

    bool isEncript() const;

    void setEncript(bool encript);

    int getSize() const;

    void setSize(int size);

    vector<string> getPalabras();

    bool isAligned() const;

    void setAligned(bool aligned);

    //metodos

    void justificar();

    void alinearDerecha();

    void alinearIzquierda();

    void alinearCentro();

    void findWord(string palabra);

    void reemplazar(string palabra, string palabra2);

    int contarPalabra(string palabra);

    void encriptar();

    void desencriptar();
};

#endif //PROYECTO_CRISTIAN_WORD_H
