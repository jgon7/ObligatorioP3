#include "Alumnos.h"
#include <stdio.h>

void Crear(Alumnos &alumnos) {
    for (int i = 0; i < valorHash; i++) {
        alumnos[i] = NULL;
    }
}

void inscribirAlumno(Alumnos &alumnos, int cedula, String nombre, String apellido, int telefono) {
    if (Pertenece(alumnos, cedula)) {
        printf("Error: ya existe un alumno con esa cedula.\n");
    } else {
        Alumno alumno = crearAlumno(cedula, nombre, apellido, telefono);
        Insertar(alumnos, alumno);
        printf("Alumno agregado correctamente.\n");
    }
    /*
    Lista nuevo = new Nodo;
    nuevo->alumno = alumno;
    nuevo->sig = alumnos->tabla[cubeta];
    alumnos->tabla[cubeta] = nuevo;
    return true;
    */
}

Alumno &Obtener(Alumnos alumnos, int cedula) {
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

void Insertar(Alumnos &alumnos, Alumno alumno) {
    int cubeta = funcionHash(cedulaAlumno(alumno));

    Nodo * nuevo = new Nodo;
    nuevo->alumno = alumno;
    nuevo->sig = alumnos[cubeta];
    alumnos[cubeta] = nuevo;
}

bool Pertenece(Alumnos alumnos, int cedula){
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
