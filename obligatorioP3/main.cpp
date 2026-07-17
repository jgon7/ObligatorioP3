#include <iostream>
#include "Alumnos.h"
#include "Asignaturas.h"
#include "GrafoPreviaturas.h"
#include "Menu.h"

using namespace std;

int main()
{
    Grafo G;
    Asignaturas A;
    Alumnos alumnos;

    CrearGrafo(G);
    inicializarArregloAsignaturas(A);
    Crear(alumnos);

    ejecutarMenu(G, A, alumnos);

    return 0;
}
