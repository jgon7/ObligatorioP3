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

void Crear(Escolaridad &e);
void InsBack(Escolaridad &e, Curso curso);
bool aproboAsignatura(Escolaridad escolaridad, int numeroAsignatura);
bool fechaPosteriorOIgualAlUltimoCurso(Escolaridad escolaridad, Fecha fecha);
int cantidadCursos(Escolaridad escolaridad);
int cantidadCursosAprobados(Escolaridad escolaridad);
void listarEscolaridad(Escolaridad escolaridad);
void copiarCurso(Curso &destino, Curso origen);
bool Vacia(Escolaridad e);

#endif // ESCOLARIDAD_H_INCLUDED
