#include "Escolariad.h"

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
