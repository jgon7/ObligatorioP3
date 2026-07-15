#include "Alumnos.h"
#include <stdio.h>

void crear (HashAlumnos &alumnos) {
    for (int i = 0; i < valorHash; i++) {
        alumnos[i] = NULL;
    }
}

void inscribirAlumno(HashAlumnos &alumnos, int cedula, String nombre, String apellido, int telefono) {
    if (hayAlumno(alumnos, cedula)) {
        printf("Error: ya existe un alumno con esa cedula.\n");
    }
    Alumno alumno = crearAlumno(cedula, nombre, apellido, telefono);
    InsertarEnHash(alumnos, alumno);
    printf("Alumno agregado correctamente.\n");
    /*
    Lista nuevo = new Nodo;
    nuevo->alumno = alumno;
    nuevo->sig = alumnos->tabla[cubeta];
    alumnos->tabla[cubeta] = nuevo;
    return true;
    */
}

Alumno &obtenerAlumno(HashAlumnos alumnos, int cedula) {
    int cubeta = funcionHash(cedula);
    return buscarEnLista(alumnos[cubeta], cedula);
}

int funcionHash(int cedula) {
    return cedula % valorHash;
}

Alumno &buscarEnLista(Lista lista, int cedula) {
    while (lista != NULL) {
        if (cedulaAlumno(lista->alumno) == cedula) {
            return lista->alumno;
        }
        lista = lista->sig;
    }
}

void InsertarEnHash (HashAlumnos &alumnos, Alumno e) {
    int cubeta = funcionHash(cedulaAlumno(e));

    Nodo * nuevo = new Nodo;
    nuevo->alumno = e;
    nuevo->sig = alumnos[cubeta];
    alumnos[cubeta] = nuevo;
}

bool hayAlumno(HashAlumnos alumnos, int cedula){
    int posicion = funcionHash(cedula);

    //lista que esta en esa posición
    Lista actual = alumnos[posicion];

    // Recorremos esa lista buscando la cedula
    while (actual != NULL) {
        if (cedulaAlumno(actual->alumno) == cedula) {
            return true;
        }
        actual = actual->sig;
    }

    return false;
}
