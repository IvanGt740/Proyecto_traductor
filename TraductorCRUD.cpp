#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Definicion del diccionario
struct WordEntry {
    string palabraEnglish;
    string palabraSpanish;
    string concepto;
};

//Diccionario de palabras predefinidas

unordered_map<string, WordEntry> dictionary = {
    {"hello", {"hello", "hola", "Saludo amistoso"}},
    {"world", {"world", "mundo", "Planeta Tierra"}},
    {"asm", {"asm", "ensamble", "En C++, asm se utiliza para incluir instrucciones de lenguaje ensamblador en un programa."}},
    {"auto", {"auto", "automatico", "En C++, auto se utiliza para declarar variables con un tipo de dato automaticamente inferido por el compilador."}},
    {"bool", {"bool", "booleano", "En C++, bool es un tipo de dato que puede tener solo dos valores: verdadero (true) o falso (false)."}},
    {"break", {"break", "interrumpir", "En C++, break se utiliza dentro de bucles (como for, while o do-while) para salir del bucle en el punto especificado."}},
    {"case", {"case", "caso", "En C++, case se utiliza dentro de instrucciones switch para definir diferentes casos para la evaluacion de una expresion."}},
    {"catch", {"catch", "capturar", "En C++, catch se utiliza junto con bloques try para capturar y manejar excepciones lanzadas dentro del bloque try."}},
    {"char", {"char", "caracter", "En C++, char es un tipo de dato que representa un unico caracter ASCII."}},
    {"class", {"class", "clase", "En C++, class se utiliza para definir una plantilla de un tipo de objeto con sus atributos y metodos."}},
    {"const", {"const", "constante", "En C++, const se utiliza para declarar constantes, es decir, valores que no pueden ser modificados una vez definidos."}},
    {"const_cast", {"const_cast", "convertir constante", "En C++, const_cast se utiliza para convertir entre tipos de datos constante y no constante."}},
    {"continue", {"continue", "continuar", "En C++, continue se utiliza dentro de bucles para saltar a la siguiente iteracion del bucle."}},
    {"default", {"default", "Por defecto", "En C++, default se utiliza dentro de instrucciones switch para definir el caso predeterminado cuando ninguno de los otros casos coincide."}},
    {"delete", {"delete", "eliminar", "En C++, delete se utiliza para liberar la memoria asignada dinamicamente a un objeto creado con new."}},
    {"do", {"do", "hacer", "En C++, do se utiliza junto con while para crear un bucle que ejecuta un bloque de codigo al menos una vez y luego repite mientras se cumple una condicion."}},
    {"double", {"double", "doble", "En C++, double es un tipo de dato que representa numeros de punto flotante de doble precision."}},
    {"dynamic_cast", {"dynamic_cast", "conversion dinamica", "En C++, dynamic_cast se utiliza para realizar conversiones de tipos dinamicos entre clases relacionadas mediante herencia."}},
    {"else", {"else", "no", "En C++, else se utiliza junto con if para especificar un bloque de codigo que se ejecuta si la condicion de if es falsa."}},
    {"enum", {"enum", "enumeracion", "En C++, enum se utiliza para definir un tipo de datos que consta de un conjunto de constantes con nombre."}},
    {"explicit", {"explicit", "explicito", "En C++, explicit se utiliza para declarar constructores que no pueden ser invocados de manera implicita por el compilador."}},
    {"extern", {"extern", "externo", "En C++, extern se utiliza para declarar variables y funciones que se definen en otro lugar."}},
    {"false", {"false", "falso", "En C++, false es un valor booleano que representa la negacion de verdadero."}},
    {"float", {"float", "flotante", "): En C++, float es un tipo de dato que representa numeros de punto flotante de precision simple."}},
    {"for", {"for", "para", "En C++, for se utiliza para crear un bucle que ejecuta un bloque de codigo un numero especifico de veces."}},
    {"friend", {"friend", "amigo", "En C++, friend se utiliza para permitir que una funcion o clase acceda a miembros privados de otra clase."}},
    {"goto", {"goto", "ir a", "): En C++, goto se utiliza para saltar a una etiqueta especifica dentro de un programa."}},
    {"if", {"if", "si", "En C++, if se utiliza para realizar una evaluacion condicional y ejecutar un bloque de codigo si la condicion es verdadera."}},
    {"inline", {"inline", "en linea", "En C++, inline se utiliza para sugerir al compilador que una funcion debe ser expandida en linea en lugar de invocarla."}},
    {"int", {"int", "entero", "En C++, int es un tipo de dato que representa numeros enteros con signo."}},
    {"long", {"long", "largo", "En C++, long es un tipo de dato que representa numeros enteros largos con signo."}},
    {"mutable", {"mutable", "mutable", "En C++, mutable se utiliza para permitir que los miembros de un objeto constante puedan ser modificados."}},
    {"namespace", {"namespace", "espacio de nombres", "En C++, namespace se utiliza para evitar conflictos de nombres al agrupar elementos relacionados bajo un nombre unico."}},
    {"new", {"new", "nuevo", "En C++, new se utiliza para asignar memoria dinamicamente para un objeto y devolver un puntero a esa memoria asignada."}},
    {"operator", {"operator", "operador", "): En C++, operator se utiliza para sobrecargar operadores y definir el comportamiento personalizado para operaciones especificas."}},
    {"private", {"private", "privado", "En C++, private se utiliza para especificar que los miembros de una clase solo pueden ser accedidos desde la propia clase."}},
    {"protected", {"protected", "protegido", "En C++, protected se utiliza para especificar que los miembros de una clase son accesibles desde la propia clase y sus clases derivadas."}},
    {"public", {"public", "publico", "En C++, public se utiliza para especificar que los miembros de una clase son accesibles desde cualquier parte del programa."}},
    {"register", {"register", "registro", "En C++, register se utiliza como una sugerencia para el compilador para almacenar una variable en un registro del procesador para acceso mas rapido."}},
    {"reinterpret_cast", {"reinterpret_cast", "conversion forzada", "En C++, reinterpret_cast se utiliza para realizar conversiones de tipos sin restricciones entre diferentes tipos de datos."}},
    {"return", {"return", "retornar", "En C++, return se utiliza para salir de una funcion y devolver un valor opcional al punto de llamada."}},
    {"short", {"short", "corto", "En C++, short es un tipo de dato que representa numeros enteros cortos con signo."}},
    {"signed", {"signed", "firmado", "signed es un modificador que se puede utilizar con cualquier tipo entero excepto bool"}},
    {"bool", {"bool", "booleano", "En C++, signed se utiliza para declarar variables de tipo entero con signo."}},
    {"sizeof", {"sizeof", "tamano de", "En C++, sizeof se utiliza para obtener el tamaño en bytes de un tipo de dato o una variable."}},
    {"static", {"static", "estatico", "En C++, static se utiliza para declarar variables y funciones que conservan su valor entre llamadas a la funcion."}},
    {"static_cast", {"static_cast", "conversion estatica", "En C++, static_cast se utiliza para realizar conversiones de tipos seguras entre tipos de datos relacionados."}},
    {"struct", {"struct", "estructura", "En C++, struct se utiliza para definir una estructura de datos que puede contener tanto datos como funciones."}},
    {"switch", {"switch", "selector", "En C++, switch se utiliza para realizar una seleccion entre multiples opciones basada en el valor de una expresion."}},
    {"template", {"template", "plantilla", "En C++, template se utiliza para definir plantillas de funciones y clases que pueden aceptar tipos genericos."}},
    {"this", {"this", "este", "La palabra clave this hace referencia a la instancia actual de la clase y tambien se usa como modificador del primer parametro de un metodo de extension."}},
    {"throw", {"throw", "lanzar", "Palabra clave utilizada para lanzar una excepcion."}},
    {"true", {"true", "verdadero", "Valor booleano que representa la afirmacion de una condicion."}},
    {"try", {"try", "intentar", "Palabra clave utilizada para comenzar un bloque de codigo donde se pueden lanzar excepciones."}},
    {"typedef", {"typedef", "tipo de definicion", "Utilizado para crear un alias de tipo."}},
    {"typeid", {"typeid", "tipo de identificacion", "Operador utilizado para obtener informacion sobre el tipo de un objeto"}},
    {"typename", {"typename", "nombre de tipo", "Utilizado para declarar nombres de tipos en plantillas."}},
    {"union", {"union", "union", "Palabra clave utilizada para definir una estructura que permite almacenar diferentes tipos de datos en la misma direccion de memoria."}},
    {"unsigned", {"unsigned", "no firmado", "Tipo de dato que representa numeros enteros sin signo."}},
    {"using", {"using", "usando", "Palabra clave utilizada para crear un alias de nombre para un espacio de nombres especifico"}},
    {"virtual", {"virtual", "virtual", "Palabra clave utilizada para declarar una funcion que puede ser sobrescrita en una clase derivada."}},
    {"void", {"void", "vacio", "Cuando se usa como un tipo de valor devuelto de funcion, la palabra clave void especifica que la funcion no devuelve ningun valor."}},
    {"volatile", {"volatile", "volatil", "La palabra clave volatile indica que un campo puede ser modificado por varios subprocesos que se ejecutan al mismo tiempo."}},
    {"while", {"while", "mientras", "El bucle while es otra estructura de control de flujo, concretamente lo que hace es repetir un codigo mientras dure una determinada condicion."}},
    

};

string translate(const string& word) {
    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        return "Traduccion: " + it->second.palabraSpanish + "\nConcepto: " + it->second.concepto; // Retorna la traduccion y el concepto si la palabra esta en el diccionario
    } else {
        return "Traduccion no encontrada"; // Mensaje de error si la palabra no esta en el diccionario
    }
}

void addWord(const string& palabraEnglish, const string& palabraSpanish, const string& concepto) {
    dictionary[palabraEnglish] = {palabraEnglish, palabraSpanish, concepto};
}

void updateWord(const string& palabraEnglish, const string& palabraSpanish, const string& concepto) {
    if (dictionary.find(palabraEnglish) != dictionary.end()) {
        dictionary[palabraEnglish] = {palabraEnglish, palabraSpanish, concepto};
        cout << "Palabra actualizada exitosamente." << endl;
    } else {
        cout << "La palabra no existe en el diccionario." << endl;
    }
}

void deleteWord(const string& palabraEnglish) {
    if (dictionary.find(palabraEnglish) != dictionary.end()) {
        dictionary.erase(palabraEnglish);
        cout << "Palabra eliminada exitosamente." << endl;
    } else {
        cout << "La palabra no existe en el diccionario." << endl;
    }
}

void listAllWords() {
    cout << "Palabras en el diccionario:" << endl;
    for (const auto& pair : dictionary) {
        cout << pair.second.palabraEnglish << " - " << pair.second.palabraSpanish << " - " << pair.second.concepto << endl;
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
                string palabraEnglish, palabraSpanish, concepto;
                cout << "Ingrese la palabra en ingles: ";
                cin >> palabraEnglish;
                cout << "Ingrese la traduccion al espanol: ";
                cin.ignore(); // Limpiar el buffer del teclado
                getline(cin, palabraSpanish);
                cout << "Ingrese el concepto de la palabra: ";
                getline(cin, concepto);
                addWord(palabraEnglish, palabraSpanish, concepto);
                break;
            }
            case 'B':
            case 'b': {
                string palabraEnglish, palabraSpanish, concepto;
                cout << "Ingrese la palabra en ingles a actualizar: ";
                cin >> palabraEnglish;
                cout << "Ingrese la nueva traduccion al espanol: ";
                cin.ignore(); // Limpiar el buffer del teclado
                getline(cin, palabraSpanish);
                cout << "Ingrese el nuevo concepto de la palabra: ";
                getline(cin, concepto);
                updateWord(palabraEnglish, palabraSpanish, concepto);
                break;
            }
            case 'D':
            case 'd': {
                string palabraEnglish;
                cout << "Ingrese la palabra en ingles a eliminar: ";
                cin >> palabraEnglish;
                deleteWord(palabraEnglish);
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
                    cout << translate(input) << endl;
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
