#include "Alumno.h"
#include <stdio.h>


Alumno crearAlumno(int cedula, String nombre, String apellido, int telefono) {
    Alumno a;
    a.cedula = cedula;
    strCrear(a.nombre);
    strCrear(a.apellido);
    strCop(a.nombre, nombre);
    strCop(a.apellido, apellido);
    a.telefono = telefono;
    crearEscolaridad(a.escolaridad);
    return a;
}

int cedulaAlumno(Alumno alumno) {
    return alumno.cedula;
}

Escolaridad &escolaridadAlumno(Alumno &alumno) {
    return alumno.escolaridad;
}

void imprimirResumenAlumno(Alumno alumno) {
    printf("Nombre: ");
    strPrint(alumno.nombre);
    printf(" | Apellido: ");
    strPrint(alumno.apellido);
    printf(" | Telefono: %d", alumno.telefono);
    printf(" | Cursos registrados: %d | Cursos aprobados: %d\n",
           cantidadCursos(alumno.escolaridad),
           cantidadCursosAprobados(alumno.escolaridad));
    printf("----------------------------------------------\n");
}
