#include "Asignaturas.h"
#include <iostream>

using namespace std;

void crearAsignaturas(Asignaturas &A, int numero, String nombre, int horas, bool optativa){
    if (A.tope < cantAsignaturas){
        crearAsignatura(&A.asignatura[A.tope], numero, nombre, horas, optativa);
        A.tope++;
    } else {
        cout << "Error: No se pueden agregar más asignaturas. " << endl;
    }

}
void inicializarArregloAsignaturas(Asignaturas &A) {
    A.tope = 0;
}

bool existeAsignatura(Asignaturas A, int numero) {
    return numero >= 0
        && numero < A.tope
        && A.asignatura[numero].numeroAsignatura == numero;
}

Asignatura obtenerAsignatura(Asignaturas A, int numero) {
    if (existeAsignatura(A, numero)) {
        return A.asignatura[numero];
    }

    Asignatura vacia;
    vacia.numeroAsignatura = -1;
    vacia.nombreAsignatura = NULL;
    vacia.cantidadHoras = 0;
    vacia.optativa = false;
    return vacia;
}

