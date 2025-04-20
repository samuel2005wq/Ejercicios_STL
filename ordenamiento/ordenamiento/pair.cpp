#include <iostream>
#include <vector>
#include <algorithm> // sort
using namespace std;

int main()
{
    vector<pair<int, string>> datos = {// Vector de pares (número, palabra)
                                       {3, "pera"},
                                       {4, "kiwi"},
                                       {6, "mango"},
                                       {5, "manzana"},
                                       {2, "banana"},
                                       {8, "naranja"},
                                       {1, "uva"},
                                       {7, "pera"}};

    // Ordenar en orden descendente según el valor numérico (primer elemento del pair)
    sort(datos.begin(), datos.end(), [](const pair<int, string> &a, const pair<int, string> &b)
         { return a.first > b.first; });

    // Mostrar el resultado
    for (const auto &item : datos)
    {
        cout << item.first << " - " << item.second << endl;
    }

    return 0;
}
