#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED

#include "Alumno.h"
#include "Asignaturas.h"
#include "GrafoPreviaturas.h"

typedef struct rep_alumnos *Alumnos;

Alumnos crearAlumnos();
bool inscribirAlumno(Alumnos alumnos, String cedula, String nombre, String apellido, String telefono);
Alumno obtenerAlumno(Alumnos alumnos, String cedula);

#endif // ALUMNOS_H_INCLUDED
