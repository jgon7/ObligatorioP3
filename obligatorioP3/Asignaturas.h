#ifndef ASIGNATURAS_H_INCLUDED
#define ASIGNATURAS_H_INCLUDED

#include "Constantes.h"
#include "Asignatura.h"

typedef struct { Asignatura asignatura[cantAsignaturas];
                 int tope;
               } Asignaturas;

void inicializarArregloAsignaturas(Asignaturas &A);
void crearAsignaturas(Asignaturas &A);
void listarAsignaturas(Asignaturas a);
#endif // ASIGNATURAS_H_INCLUDED
