#include "Asignaturas.h"
#include <iostream>

using namespace std;

void crearAsignaturas(Asignaturas &A, int numero, String nombre, int horas, bool optativa){
    if (A.tope < cantAsignaturas){
        crearAsignatura(A.asignatura[A.tope], numero, nombre, horas, optativa);
        A.tope++;
    } else {
        cout << "No se pueden agregar mas asignaturas " << endl;
    }

}
void inicializarArregloAsignaturas(Asignaturas &A) {
    A.tope = 0;
}

int cantAsignaturasRegistradas(Asignaturas &A) {
    return A.tope;
}

String obtenerNombreAsignatura(Asignaturas A, int numAsignatura) {
    return obtenerNombre(A.asignatura[numAsignatura]);
}

bool existeAsignatura(Asignaturas A, int numero) {
    return numero >= 0
        && numero < A.tope
        && A.asignatura[numero].numeroAsignatura == numero;
}

Asignatura obtenerAsignatura(Asignaturas A, int numero) {
    return A.asignatura[numero];
}

void listarAsignaturas(Asignaturas a) {
    if (a.tope == 0) {
        cout << "No hay asignaturas registradas en el sistema" << endl;
        return;
    }

    ordenarAsignaturas(a);

    cout << "LISTADO DE ASIGNATURAS" << endl;
    cout << "-----------------------" << endl;

    for (int i = 0; i < a.tope; i++) {
        mostrarAsignatura(a.asignatura[i]);
    }
}

//Funcion auxiliar para ordenar el arreglo
void ordenarAsignaturas(Asignaturas &a) {
    for (int i = 0; i < a.tope - 1; i++) {
        for (int j = 0; j < a.tope - i - 1; j++) {
            if (a.asignatura[j].numeroAsignatura > a.asignatura[j + 1].numeroAsignatura) {
                Asignatura aux = a.asignatura[j];
                a.asignatura[j] = a.asignatura[j + 1];
                a.asignatura[j + 1] = aux;
            }
        }
    }
}
