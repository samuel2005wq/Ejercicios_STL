#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

set<string> leerPalabras(const string &nombreArchivo)
{                                    // Función para leer palabras de un archivo
                                     // y devolver un conjunto de palabras únicas
    set<string> word;                // Conjunto para almacenar palabras únicas
    ifstream archivo(nombreArchivo); // Abrir el archivo
    string linea, palabra;           // Variables para almacenar cada línea y palabra

    if (!archivo.is_open())
    { // Verificar si el archivo se abrió correctamente
        cerr << "No se pudo abrir el archivo." << endl;
        return word;
    }

    while (getline(archivo, linea))
    {                           // Leer cada línea del archivo
        stringstream ss(linea); // Crear un stringstream para procesar la línea
        while (ss >> palabra)
        { // Leer cada palabra de la línea
            // Quitar signos de puntuación al final o al inicio de la palabra
            palabra.erase(remove_if(palabra.begin(), palabra.end(), ::ispunct), palabra.end());
            word.insert(palabra);
        }
    }

    archivo.close();
    return word; // Devolver el conjunto de palabras únicas
}

int main()
{
    set<string> resultado = leerPalabras("sampleFile.txt"); // Llamar a la función para leer palabras del archivo

    cout << "Palabras únicas encontradas:\n";
    for (const auto &palabra : resultado)
    {
        cout << palabra << endl;
    }

    return 0;
}
