#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED
#include "Fecha.h"
#include "String.h"
#include "Asignatura.h"

typedef struct {
    int numeroAsignatura;
    String nombreAsignatura;
    Fecha fecha;
    int Calificacion;
} Curso;

void crearCurso(Curso &C, int numeroA, String nombreA, Fecha fecha, int calificacion);
String obtenerNombre(Curso curso);


#endif // CURSO_H_INCLUDED
