#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "Escolaridad.h"
#include "String.h"


typedef struct {
    int cedula;
    String nombre;
    String apellido;
    int telefono;
    Escolaridad escolaridad;
} Alumno;

Alumno crearAlumno(int cedula, String nombre, String apellido, int telefono);
int cedulaAlumno(Alumno alumno);
Escolaridad escolaridadAlumno(Alumno alumno);
void imprimirResumenAlumno(Alumno alumno);

#endif // ALUMNO_H_INCLUDED
