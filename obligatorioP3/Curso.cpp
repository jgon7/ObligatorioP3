#include "Curso.h"

void crearCurso(Curso &C, int numeroA, String nombreA, Fecha fecha, int calificacion){
    C.numeroAsignatura = numeroA;

    strCrear(C.nombreAsignatura);
    strCop(C.nombreAsignatura, nombreA);

    C.fecha = fecha;
    C.Calificacion = calificacion;
}

String obtenerNombre(Curso curso){
    return curso.nombreAsignatura;
}
