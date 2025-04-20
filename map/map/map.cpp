#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// Función para contar la frecuencia de palabras en un archivo de texto
// y devolver un mapa con la palabra como clave y su frecuencia como valor
map<string, int> contarPalabras(const string &nombreArchivo)
{

    map<string, int> frecuencia;     // Mapa para almacenar la frecuencia de palabras
    ifstream archivo(nombreArchivo); // Abrir el archivo
    string linea, palabra;           // Variables para almacenar cada línea y palabra

    if (!archivo.is_open())
    { // Verificar si el archivo se abrió correctamente
        cerr << "No se pudo abrir el archivo." << std::endl;
        return frecuencia;
    }

    while (getline(archivo, linea))
    {                           // Leer cada línea del archivo
        stringstream ss(linea); // Crear un stringstream para procesar la línea
        while (ss >> palabra)
        {
            // Eliminar signos de puntuación
            palabra.erase(std::remove_if(palabra.begin(), palabra.end(), ::ispunct), palabra.end());

            // Opcional: convertir todo a minúsculas
            std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);

            frecuencia[palabra]++; // Incrementar la frecuencia de la palabra
        }
    }

    archivo.close();   // Cerrar el archivo
    return frecuencia; // Devolver el mapa con la frecuencia de palabras
}

int main()
{
    map<string, int> resultado = contarPalabras("sampleFile.txt");

    cout << "Frecuencia de palabras:\n";
    for (const auto &[palabra, frecuencia] : resultado)
    {
        cout << palabra << ": " << frecuencia << endl;
    }

    return 0;
}
