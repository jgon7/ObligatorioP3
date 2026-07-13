#include "Alumno.h"
#include <iostream>
using namespace std;


Alumno crearAlumno(int cedula, String nombre, String apellido, int telefono) {
    Alumno a;
    /*
    a->cedula = NULL; //para no borrar dirreciones invalidas
    a->nombre = NULL;
    a->apellido = NULL;
    a->telefono = NULL;
    */
    a.cedula = cedula;
    strCop(a.nombre, nombre);
    strCop(a.apellido, apellido);
    a.telefono = telefono;
    crearEscolaridad(a.escolaridad);
    return a;
}

int cedulaAlumno(Alumno alumno) {
    return alumno.cedula;
}

Escolaridad escolaridadAlumno(Alumno alumno) {
    return alumno.escolaridad;
}

void imprimirResumenAlumno(Alumno alumno) {
    cout << "Nombre: ";
    strPrint(alumno.nombre);
    cout << " | Apellido: ";
    strPrint(alumno.apellido);
    cout << " | Telefono: " <<  alumno.telefono;
    cout << " | Cursos registrados: " << cantidadCursos(alumno.escolaridad)
         << " | Cursos aprobados: " << cantidadCursosAprobados(alumno.escolaridad) << endl;
}
