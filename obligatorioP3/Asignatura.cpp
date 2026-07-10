#include "Asignatura.h"

void crearAsignatura(Asignatura &A, int numero, String nombre, int horas, bool optativa){
    strCrear(A.nombreAsignatura);
    A.numeroAsignatura = numero;
    strCop(A.nombreAsignatura, nombre);
    A.cantidadHoras = horas;
    A.optativa = optativa;
}

String obtenerNombre(Asignatura asig){
    return asig.nombreAsignatura;
}
