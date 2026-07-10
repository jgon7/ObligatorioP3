#ifndef ESCOLARIDAD_H__INCLUDED
#define ESCOLARIDAD_H_INCLUDED

#include "Curso.h"

typedef struct rep_escolaridad *Escolaridad;

Escolaridad crearEscolaridad();
bool registrarCurso(Escolaridad escolaridad, Curso curso);
bool aproboAsignatura(Escolaridad escolaridad, int numeroAsignatura);
bool fechaPosteriorOIgualAlUltimoCurso(Escolaridad escolaridad, Fecha fecha);
int cantidadCursos(Escolaridad escolaridad);
int cantidadCursosAprobados(Escolaridad escolaridad);
void listarEscolaridad(Escolaridad escolaridad);

#endif // ESCOLARIDAD_H_INCLUDED
