#include "Escolaridad.h"
#include <iostream>
using namespace std;

void crearEscolaridad(Escolaridad &escolaridad){
    escolaridad.prim = NULL;
    escolaridad.ult = NULL;
}

void registrarCurso(Escolaridad &escolaridad, Curso curso){

    NodoCurso *nuevo = new NodoCurso;

    copiarCurso(nuevo->curso, curso);

    nuevo->sig = NULL;

    if(escolaridad.prim == NULL){
        escolaridad.prim = nuevo;
        escolaridad.ult = nuevo;
    }
    else{
        escolaridad.ult->sig = nuevo;
        escolaridad.ult = nuevo;
    }
}

void copiarCurso(Curso &destino, Curso origen){
    crearCurso(destino,
               origen.numeroAsignatura,
               origen.nombreAsignatura,
               origen.fecha,
               origen.Calificacion);
}

bool aproboAsignatura(Escolaridad escolaridad, int numeroAsignatura) {
    NodoCurso * actual = escolaridad.prim;

    while (actual != NULL) {
        if (actual->curso.numeroAsignatura == numeroAsignatura &&
            actual->curso.Calificacion >= 6) {
            return true;
        }
        actual = actual->sig;
    }
    return false;
}

bool fechaPosteriorOIgualAlUltimoCurso(Escolaridad escolaridad, Fecha fecha) {
    if (esVacia(escolaridad)) {
        return true;
    }
    return esMayorFechas(fecha, escolaridad.ult->curso.fecha) ||
           sonIgualesFechas(fecha, escolaridad.ult->curso.fecha);
}

int cantidadCursos(Escolaridad escolaridad) {
    int cantidad = 0;
    NodoCurso * actual = escolaridad.prim;

    while (actual != NULL) {
        cantidad++;
        actual = actual->sig;
    }
    return cantidad;
}

int cantidadCursosAprobados(Escolaridad escolaridad) {
    int cantidad = 0;
    NodoCurso * actual = escolaridad.prim;

    while (actual != NULL) {
        if (actual->curso.Calificacion >= 6) {
            cantidad++;
        }
        actual = actual->sig;
    }
    return cantidad;
}

void listarEscolaridad(Escolaridad escolaridad) {
    NodoCurso * actual = escolaridad.prim;

    if (esVacia(escolaridad)) {
        cout << "No hay cursos registrados en la escolaridad." << endl;
    }

    while (actual != NULL) {
        cout << "Asignatura " << actual->curso.numeroAsignatura << " - ";
        strPrint(actual->curso.nombreAsignatura);
        cout << " | Fecha: ";
        mostrarFecha(actual->curso.fecha);
        cout << " | Calificacion: " << actual->curso.Calificacion
             << " | " << (actual->curso.Calificacion >= 6 ? "Aprobada" : "No aprobada") << endl;
        actual = actual->sig;
    }
}

bool esVacia(Escolaridad e) {
    return (e.prim == NULL);
}
