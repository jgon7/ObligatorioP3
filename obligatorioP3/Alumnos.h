#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED
#include "Alumno.h"
#include "Asignaturas.h"
#include "GrafoPreviaturas.h"
#include "Constantes.h"

#include <stdio.h>

typedef struct NodoL {
    Alumno alumno;
    NodoL* sig;
} Nodo;

typedef Nodo* Lista;
typedef Lista HashAlumnos[valorHash];


void crear(HashAlumnos &alumnos);
bool inscribirAlumno(HashAlumnos &alumnos, int cedula, String nombre, String apellido, int telefono);
bool hayAlumno(HashAlumnos alumnos, int cedula);
Alumno &obtenerAlumno(HashAlumnos alumnos, int cedula);
int funcionHash(int cedula);
Alumno &buscarEnLista(Lista lista, int cedula);
void InsertarEnHash (HashAlumnos &alumnos, Alumno e);

#endif // ALUMNOS_H_INCLUDED
