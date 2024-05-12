#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string, string> dictionary = {
{"#include", "#incluir"},
    {"iostream", "<iostream>"},
    {"cstdlib", "<cstdlib>"},
    {"ctime", "<ctime>"},
    {"vector", "<vector>"},
    {"string", "<string>"},
    {"unordered_map", "<unordered_map>"},
    {"using", "usando"},
    {"namespace", "espacio_de_nombres"},
    {"struct", "estructura"},
    {"void", "vac�o"},
    {"int", "entero"},
    {"double", "doble"},
    {"char", "car�cter"},
    {"bool", "bool"},
    {"true", "verdadero"},
    {"false", "falso"},
    {"return", "retorno"},
    {"if", "si"},
    {"If", "si"},
    {"else", "si_no"},
    {"for", "para"},
    {"while", "mientras"},
    {"do", "hacer"},
    {"switch", "interruptor"},
    {"case", "caso"},
    {"default", "predeterminado"},
    {"break", "romper"},
    {"continue", "continuar"},
    {"goto", "ir_a"},
    {"try", "intentar"},
    {"catch", "capturar"},
    {"throw", "lanzar"},
    {"template", "plantilla"},
    {"typename", "tipo_nombre"},
    {"class", "clase"},
    {"public", "p�blico"},
    {"private", "privado"},
    {"protected", "protegido"},
    {"virtual", "virtual"},
    {"static", "est�tico"},
    {"extern", "externo"},
    {"const", "constante"},
    {"mutable", "mutable"},
    {"volatile", "vol�til"},
    {"friend", "amigo"},
    {"new", "nuevo"},
    {"delete", "eliminar"},
    {"operator", "operador"},
    {"sizeof", "tama�o_de"},
    {"typeid", "tipo_de_identificaci�n"},
    {"dynamic_cast", "conversi�n_din�mica"},
    {"static_cast", "conversi�n_est�tica"},
    {"const_cast", "convertir_constante"},
    {"reinterpret_cast", "conversi�n_forzada"},
    {"register", "registro"},
    {"union", "uni�n"},
    {"enum", "enumeraci�n"},
    {"typedef", "tipo_de_definici�n"},
    {"asm", "asm"},
    {"auto", "autom�tico"},
};

string translate(const string& word) {
    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        return it->second; // Retorna la traducci�n si la palabra est� en el diccionario
    } else {
        return word; // Retorna la palabra original si no se encuentra en el diccionario
    }
}

void translateCodeSnippet(const string& code) {
    stringstream ss(code);
    string line;

    while (getline(ss, line)) {
        // Eliminar espacios en blanco al principio y al final de la l�nea
        line.erase(line.begin(), find_if(line.begin(), line.end(), [](unsigned char ch) {
            return !isspace(ch);
        }));
        line.erase(find_if(line.rbegin(), line.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(), line.end());

        // Traducir palabras en la l�nea
        stringstream translatedLine;
        stringstream wordStream(line);
        string word;
        bool inFunction = false;

        while (wordStream >> word) {
            if (word == "{") {
                if (inFunction) {
                    translatedLine << " {" << endl;
                } else {
                    translatedLine << " { // " << translate("start") << " " << translate("block") << endl;
                }
            } else if (word == "}") {
                if (inFunction) {
                    translatedLine << " }" << endl;
                    inFunction = false;
                } else {
                    translatedLine << " // " << translate("end") << " " << translate("block") << " }" << endl;
                }
            } else if (word == "int" || word == "double" || word == "char" || word == "bool" || word == "void") {
                translatedLine << translate(word) << " ";
            } else if (word == "if" || word == "else" || word == "for" || word == "while" || word == "do" || word == "switch" || word == "case" || word == "default" || word == "break" || word == "continue" || word == "return" || word == "try" || word == "catch" || word == "throw") {
                translatedLine << translate(word) << " ";
            } else if (word == "class" || word == "struct" || word == "namespace" || word == "using") {
                translatedLine << translate(word) << " ";
            } else if (word == "(") {
                translatedLine << "(";
                inFunction = true;
            } else if (word == ")") {
                translatedLine << ") ";
            } else if (word == ";") {
                translatedLine << ";" << endl;
            } else {
                translatedLine << translate(word) << " ";
            }
        }

        cout << translatedLine.str();
    }
}

int main() {
    string input;
    cout << "Ingrese el c�digo C++ para traducir, ingrese Enter, Ctrl + z y nuevamente enter para ejecutar (terminar con una linea que contenga solo '.'):\n";

    stringstream code;
    while (getline(cin, input)) {
        if (input == ".") {
            break;
        }
        code << input << endl;
    }

    cout << "\nC�digo traducido:\n";
    translateCodeSnippet(code.str());

    return 0;
}


