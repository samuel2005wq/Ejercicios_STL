#include <iostream>
#include <vector>
#include <algorithm> // find_if
using namespace std;

int main()
{
    vector<int> numeros = {7, 13, 9, 8, 15, 6, 21}; // Vector de números

    auto it = find_if(numeros.begin(), numeros.end(), [](int n) { // función lambda
        // Buscamos el primer número par
        // La función lambda recibe un número y devuelve true si es par
        return n % 2 == 0; // condición: número par
    });

    if (it != numeros.end())
    { // Si encontramos un número par
        cout << "El primer número par es: " << *it << endl;
    }
    else
    {
        cout << "No hay ningún número par." << endl;
    }

    return 0;
}
