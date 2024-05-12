#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Definición del diccionario
unordered_map<string, string> dictionary = {
    {"hello", "hola"},
    {"world", "mundo"},
    {"asm", "ensamble"},
    {"auto", "automatico"},
    {"bool", "booleano"},
    {"break", "romper"},
    {"case", "caso"},
    {"cath", "atrapar"},
    {"class", "clase"},
    {"const", "constante"},
    {"const_cast", "operador"},
    {"continue", "continuar"},
    {"default", "Por defecto"},
    {"delete", "borrar"},
    {"do", "hacer"},
    {"else", "no"},
    {"enum", "enumeracion"},
    {"explicit", "explicito"},
    {"extern", "externo"},
    {"false", "falso"},
    {"float", "flotante"},
    {"for", "para"},
    {"friend", "amigo"},
    {"goto", "ir a"},
    {"if", "si"},
    {"inline", "en linea"},
    {"int", "entero"},
    {"long", "largo"},
    {"mutable", "mutable"},
    {"namespace", "espacio de nombres"},
    {"new", "nuevo"},
    {"operator", "operador"},
    {"private", "privado"},
    {"protected", "protegido"},
    {"public", "publico"},
    {"register", "registro"},
    {"reinterpret_cast", "conversion forzada"},
    {"return", "regreso"},
    {"short", "corto"},
    {"signed", "firmado"},
    {"sizeof", "tamano"},
    {"static", "estatico"},
    {"static_cast", "conversion estatica"},
    {"struct", "estructura"},
    {"switch", "selector"},
    {"template", "plantilla"},
    {"this", "este"},
    {"throw", "lanzar"},
    {"true", "verdadero"},
    {"try", "intentar"},
    {"typedef", "tipo de definicion"},
    {"typeid", "tipo de identificacion"},
    {"typename", "nombre de tipo"},
    {"union", "union"},
    {"unsigned", "no firmado"},
    {"using", "usando"},
    {"virtual", "virtual"},
    {"void", "vacio"},
    {"volatile", "volatil"},
    {"while", "mientras"},

};

string translate(const string& word) {
    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        return it->second; // Retorna la traducción si la palabra está en el diccionario
    } else {
        return "Traducción no encontrada"; // Mensaje de error si la palabra no está en el diccionario
    }
}

int main() {
    char opcion;
    string input;

    while (true) {
        cout <<"¿Deseas traducir una palabra de c++ (S/N)?"<< endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 'S':
            case 's': {
                cout << "Ingrese una palabra en ingles para traducir o escriba'exit' para salir (escriba en letras minusculas): ";
                while (cin >> input) {
                if (input == "exit") {
                break; // Salir del bucle si el usuario ingresa 'exit'
                }
                cout << "Traduccion: " << translate(input) << endl;
                cout << "Ingrese otra palabra en ingles para traducir (o 'exit' para salir): ";
            }
    
            break;
            }

            case 'N':
            case 'n':
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Error, por favor escriba solo S o N." << endl;
                break;
        }
    }

    return 0;
}