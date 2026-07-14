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
    printf("-----------------------\n");
    printf("NUMERO: \n\n");
    printf("%d\n", A.numeroAsignatura);
    printf("\n NOMBRE: \n\n");
    strPrint(A.nombreAsignatura);
    printf("\n HORAS: \n\n");
    printf("%d\n", A.cantidadHoras);
    printf("\n TIPO ASIGNATURA: \n\n");
    if (A.optativa) {
        printf("Optativa\n");
    } else {
        printf("Obligatoria\n");
    }
    printf("-----------------------\n");
}
