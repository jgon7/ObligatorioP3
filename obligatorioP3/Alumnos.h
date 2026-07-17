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
typedef Lista Alumnos[valorHash];


void Crear(Alumnos &alumnos);
void inscribirAlumno(Alumnos &alumnos, int cedula, String nombre, String apellido, int telefono);
bool Pertenece(Alumnos alumnos, int cedula);
Alumno &Obtener(Alumnos alumnos, int cedula);
int funcionHash(int cedula);
Alumno &buscarEnLista(Lista lista, int cedula);
void Insertar(Alumnos &alumnos, Alumno alumno);

#endif // ALUMNOS_H_INCLUDED
