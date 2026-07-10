#include "Alumnos.h"
#include <iostream>

using namespace std;

const int B = 100;

typedef struct nodoL {
    Alumno alumno;
    nodoL * sig;
} Nodo;

typedef Nodo * Lista;
typedef Lista Hash[B];

static int hashCedula(String cedula);
static Alumno buscarEnLista(Lista lista, String cedula);


struct rep_alumnos {
    Hash tabla;
};

Alumnos crearAlumnos() {
    Alumnos alumnos = new rep_alumnos;

    for (int i = 0; i < B; i++) {
        alumnos->tabla[i] = 0;
    }
    return alumnos;
}


bool inscribirAlumno(Alumnos alumnos, String cedula, String nombre, String apellido, String telefono) {
    if (obtenerAlumno(alumnos, cedula) != 0) {
        cout << "Error: ya existe un alumno con esa cedula." << endl;
        return false;
    }

    Alumno alumno = crearAlumno(cedula, nombre, apellido, telefono);
    int cubeta = hashCedula(cedula);
    Lista nuevo = new Nodo;
    nuevo->alumno = alumno;
    nuevo->sig = alumnos->tabla[cubeta];
    alumnos->tabla[cubeta] = nuevo;
    return true;
}

Alumno obtenerAlumno(Alumnos alumnos, String cedula) {
    int cubeta = hashCedula(cedula);
    return buscarEnLista(alumnos->tabla[cubeta], cedula);
}

static int hashCedula(String cedula) {
    int numero = 0;
    int i = 0;

    while (cedula != 0 && cedula[i] != '\0') {
        if (cedula[i] >= '0' && cedula[i] <= '9') {
            numero = numero * 10 + (cedula[i] - '0');
        }
        i++;
    }
    return numero % B;
}

static Alumno buscarEnLista(Lista lista, String cedula) {
    while (lista != 0) {
        if (strEq(cedulaAlumno(lista->alumno), cedula)) {
            return lista->alumno;
        }
        lista = lista->sig;
    }
    return 0;
}
