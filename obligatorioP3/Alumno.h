#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "Escolaridad.h"
#include "String.h"

typedef struct rep_alumno *Alumno;

Alumno crearAlumno(String cedula, String nombre, String apellido, String telefono);
String cedulaAlumno(Alumno alumno);
Escolaridad escolaridadAlumno(Alumno alumno);
void imprimirResumenAlumno(Alumno alumno);

#endif // ALUMNO_H_INCLUDED
