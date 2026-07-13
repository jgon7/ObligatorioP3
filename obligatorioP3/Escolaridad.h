#ifndef ESCOLARIDAD_H_INCLUDED
#define ESCOLARIDAD_H_INCLUDED

#include "Curso.h"

typedef struct NodoE{
                    Curso curso;
                    NodoE * sig;
                } NodoCurso;

typedef struct{
                NodoCurso * prim;
                NodoCurso * ult;
                } Escolaridad;

//typedef struct rep_escolaridad *Escolaridad;

void crearEscolaridad(Escolaridad &escolaridad);
void registrarCurso(Escolaridad &escolaridad, Curso curso); //insertarAlFinal
bool aproboAsignatura(Escolaridad escolaridad, int numeroAsignatura);
bool fechaPosteriorOIgualAlUltimoCurso(Escolaridad escolaridad, Fecha fecha);
int cantidadCursos(Escolaridad escolaridad);
int cantidadCursosAprobados(Escolaridad escolaridad);
void listarEscolaridad(Escolaridad escolaridad);
void copiarCurso(Curso &destino, Curso origen);
int cantidadCursos(Escolaridad escolaridad);
bool esVacia(Escolaridad escolaridad);

#endif // ESCOLARIDAD_H_INCLUDED
