#ifndef ASIGNATURAS_H_INCLUDED
#define ASIGNATURAS_H_INCLUDED
#include "String.h"

typedef struct {
    int numeroAsignatura;
    String nombreAsignatura;
    int cantidadHoras;
    bool optativa;
} Asignatura;

void crearAsignatura(Asignatura &A, int numero, String nombre, int horas, bool optativa);
String obtenerNombre(Asignatura asig);

#endif // ASIGNATURAS_H_INCLUDED
