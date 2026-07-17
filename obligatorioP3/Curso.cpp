#include "Curso.h"

void crearCurso(Curso &C, int numeroA, String nombreA, Fecha fecha, int calificacion){
    C.numeroAsignatura = numeroA;

    strCrear(C.nombreAsignatura);
    strCop(C.nombreAsignatura, nombreA);

    C.fecha = fecha;
    C.Calificacion = calificacion;
}

String obtenerNombreAsignatura(Curso curso){
    return curso.nombreAsignatura;
}

int obtenerNumeroAsignatura(Curso curso){
    return curso.numeroAsignatura;
}

Fecha obtenerFecha(Curso curso){
    return curso.fecha;
}
int obtenerCalificacion(Curso curso){
    return curso.Calificacion;
}
