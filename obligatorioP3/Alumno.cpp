#include "Alumno.h"
#include <iostream>

using namespace std;

struct rep_alumno {
    String cedula;
    String nombre;
    String apellido;
    String telefono;
    Escolaridad escolaridad;
};

Alumno crearAlumno(String cedula, String nombre, String apellido, String telefono) {
    Alumno a = new rep_alumno;
    a->cedula = NULL; /*para no borrar dirreciones invalidas*/
    a->nombre = NULL;
    a->apellido = NULL;
    a->telefono = NULL;
    strCop(a->cedula, cedula);
    strCop(a->nombre, nombre);
    strCop(a->apellido, apellido);
    strCop(a->telefono, telefono);
    a->escolaridad = crearEscolaridad();
    return a;
}

String cedulaAlumno(Alumno alumno) {
    return alumno->cedula;
}

Escolaridad escolaridadAlumno(Alumno alumno) {
    return alumno->escolaridad;
}

void imprimirResumenAlumno(Alumno alumno) {
    cout << "Nombre: ";
    strPrint(alumno->nombre);
    cout << " | Apellido: ";
    strPrint(alumno->apellido);
    cout << " | Telefono: ";
    strPrint(alumno->telefono);
    cout << " | Cursos registrados: " << cantidadCursos(alumno->escolaridad)
         << " | Cursos aprobados: " << cantidadCursosAprobados(alumno->escolaridad) << endl;
}
