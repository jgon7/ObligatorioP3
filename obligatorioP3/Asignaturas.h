#ifndef COLECCION_ASIGNATURAS_H_INCLUDED
#define COLECCION_ASIGNATURAS_H_INCLUDED

#include "Constantes.h"
#include "Asignatura.h"
#include "String.h"

typedef struct { Asignatura asignatura[cantAsignaturas];
                 int tope;
               } Asignaturas;

void inicializarArregloAsignaturas(Asignaturas &A);
void crearAsignaturas(Asignaturas &A, int numero, String nombre, int horas, bool optativa);
int cantAsignaturasRegistradas(Asignaturas &A);
void listarAsignaturas(Asignaturas a);
bool existeAsignatura(Asignaturas A, int numero);
Asignatura obtenerAsignatura(Asignaturas A, int numero);
String obtenerNombreAsignatura(Asignaturas A, int numAsignatura);
void ordenarAsignaturas(Asignaturas &A);
#endif // COLECCION_ASIGNATURAS_H_INCLUDED
