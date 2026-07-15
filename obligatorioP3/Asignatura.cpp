#include "Asignatura.h"
#include <stdio.h>

void crearAsignatura(Asignatura &A, int numero, String nombre, int horas, bool optativa){
    strCrear(A.nombreAsignatura);
    A.numeroAsignatura = numero;
    strCop(A.nombreAsignatura, nombre);
    A.cantidadHoras = horas;
    A.optativa = optativa;
}

String obtenerNombre(Asignatura A){
    return A.nombreAsignatura;
}

void mostrarAsignatura(Asignatura A){
    printf("Numero: %d", A.numeroAsignatura);
    printf(" | Nombre: ");
    strPrint(A.nombreAsignatura);
    printf(" | Horas: %d", A.cantidadHoras);
    printf(" | Tipo Asignatura: ");
    if (A.optativa) {
        printf("Optativa");
    } else {
        printf("Obligatoria");
    }
    printf("----------------------------------------------\n");
}

int obtenerNumero(Asignatura A){
    return A.numeroAsignatura;
}

