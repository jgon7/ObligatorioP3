#include "Asignaturas.h"

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
