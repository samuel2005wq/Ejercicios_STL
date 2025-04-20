#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Tarea // Estructura para representar una tarea
{
    int prioridad;      // Prioridad de la tarea
    string descripcion; // Descripción de la tarea

    // Invertimos la comparación para que la prioridad menor salga primero
    bool operator<(const Tarea &otra) const // Sobrecarga del operador <
    {
        return prioridad > otra.prioridad; // Cambiamos el signo para que la prioridad menor salga primero
    }
};

int main()
{
    priority_queue<Tarea> colaTareas; // Cola de prioridad para almacenar tareas

    // Agregamos las tareas
    colaTareas.push({3, "Revisión de informes"});
    colaTareas.push({1, "Preparar presentación"});
    colaTareas.push({4, "Responder correos urgentes"});
    colaTareas.push({2, "Reunión con el equipo"});
    colaTareas.push({5, "Planificar nueva estrategia"});

    cout << "Tareas en orden de prioridad:\n";
    while (!colaTareas.empty()) // Mientras la cola no esté vacía
    // Imprimimos las tareas en orden de prioridad
    {
        Tarea t = colaTareas.top();                                           // Obtenemos la tarea con mayor prioridad
        cout << "Prioridad " << t.prioridad << ": " << t.descripcion << '\n'; // Imprimimos la tarea
        colaTareas.pop();                                                     // Eliminamos la tarea de la cola
    }

    return 0;
}
