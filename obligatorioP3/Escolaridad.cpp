#include "Escolaridad.h"
#include <stdio.h>

void Crear(Escolaridad &e){
    e.prim = NULL;
    e.ult = NULL;
}

void InsBack(Escolaridad &e, Curso curso){

    NodoCurso *nuevo = new NodoCurso;

    copiarCurso(nuevo->curso, curso);

    nuevo->sig = NULL;

    if(e.prim == NULL){
        e.prim = nuevo;
        e.ult = nuevo;
    }
    else{
        e.ult->sig = nuevo;
        e.ult = nuevo;
    }
}

void copiarCurso(Curso &destino, Curso origen){
    crearCurso(destino,
               obtenerNumeroAsignatura(origen),
               obtenerNombreAsignatura(origen),
               obtenerFecha(origen),
               obtenerCalificacion(origen)
                );
}

bool aproboAsignatura(Escolaridad escolaridad, int numeroAsignatura) {
    NodoCurso * actual = escolaridad.prim;

    while (actual != NULL) {

        if (obtenerNumeroAsignatura(actual->curso) == numeroAsignatura &&
            obtenerCalificacion(actual->curso) >= 6) {
            return true;
        }
        actual = actual->sig;
    }
    return false;
}

bool fechaPosteriorOIgualAlUltimoCurso(Escolaridad escolaridad, Fecha fecha) {
    if (Vacia(escolaridad)) {
        return true;
    }
    return esMayorFechas(fecha, (obtenerFecha(escolaridad.ult->curso))) ||
           sonIgualesFechas(fecha, obtenerFecha(escolaridad.ult->curso));
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
        if ((obtenerCalificacion(actual->curso)) >= 6) {
            cantidad++;
        }
        actual = actual->sig;
    }
    return cantidad;
}

void listarEscolaridad(Escolaridad escolaridad) {
    NodoCurso * actual = escolaridad.prim;

    if (Vacia(escolaridad)) {
        printf("No hay cursos registrados en la escolaridad.\n");
    }

    while (actual != NULL) {
        printf("Asignatura %d - ", obtenerNumeroAsignatura(actual->curso));
        strPrint(obtenerNombreAsignatura(actual->curso));
        printf(" | Fecha: ");
        mostrarFecha(obtenerFecha(actual->curso));
        printf(" | Calificacion: %d | %s\n", obtenerCalificacion(actual->curso),
               obtenerCalificacion(actual->curso) >= 6 ? "Aprobada" : "No aprobada");
        actual = actual->sig;
    }
}

bool Vacia(Escolaridad e) {
    return (e.prim == NULL);
}
