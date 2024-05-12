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
        return "Traduccion no encontrada"; // Mensaje de error si la palabra no está en el diccionario
    }
}

void addWord(const string& word, const string& translation) {
    dictionary[word] = translation;
}

void updateWord(const string& word, const string& translation) {
    if (dictionary.find(word) != dictionary.end()) {
        dictionary[word] = translation;
        cout << "Palabra actualizada exitosamente." << endl;
    } else {
        cout << "La palabra no existe en el diccionario." << endl;
    }
}

void deleteWord(const string& word) {
    if (dictionary.find(word) != dictionary.end()) {
        dictionary.erase(word);
        cout << "Palabra eliminada exitosamente." << endl;
    } else {
        cout << "La palabra no existe en el diccionario." << endl;
    }
}

void listAllWords() {
    cout << "Palabras en el diccionario:" << endl;
    for (const auto& pair : dictionary) {
        cout << pair.first << " - " << pair.second << endl;
    }
}

int main() {
    char opcion;
    string input;

    while (true) {
        cout <<"¿Que deseas hacer?"<< endl;
        cout << "A - Agregar palabra" << endl;
        cout << "B - Actualizar palabra" << endl;
        cout << "D - Eliminar palabra" << endl;
        cout << "L - Listar todas las palabras" << endl;
        cout << "T - Traducir una palabra" << endl;
        cout << "X - Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 'A':
            case 'a': {
                string word, translation;
                cout << "Ingrese la palabra en ingles: ";
                cin >> word;
                cout << "Ingrese la traduccion en espanol: ";
                cin >> translation;
                addWord(word, translation);
                break;
            }
            case 'B':
            case 'b': {
                string word, translation;
                cout << "Ingrese la palabra en ingles a actualizar: ";
                cin >> word;
                cout << "Ingrese la nueva traduccion en espanol: ";
                cin >> translation;
                updateWord(word, translation);
                break;
            }
            case 'D':
            case 'd': {
                string word;
                cout << "Ingrese la palabra en ingles a eliminar: ";
                cin >> word;
                deleteWord(word);
                break;
            }
            case 'L':
            case 'l':
                listAllWords();
                break;
            case 'T':
            case 't': {
                cout << "Ingrese una palabra en ingles para traducir o escriba 'exit' para salir: ";
                while (cin >> input) {
                    if (input == "exit") {
                        break; // Salir del bucle si el usuario ingresa 'exit'
                    }
                    cout << "Traduccion: " << translate(input) << endl;
                    cout << "Ingrese otra palabra en ingles para traducir (o 'exit' para salir): ";
                }
                break;
            }
            case 'X':
            case 'x':
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Error, opcion no valida." << endl;
                break;
        }
    }

    return 0;
}
