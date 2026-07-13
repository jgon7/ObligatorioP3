#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED
#include "String.h"

typedef struct {
    int numeroAsignatura;
    String nombreAsignatura;
    int cantidadHoras;
    bool optativa;
} Asignatura;


void crearAsignatura(Asignatura &A, int numero, String nombre, int horas, bool optativa);
String obtenerNombre(Asignatura A);
void mostrarAsignatura(Asignatura A);

#endif // ASIGNATURA_H_INCLUDED
