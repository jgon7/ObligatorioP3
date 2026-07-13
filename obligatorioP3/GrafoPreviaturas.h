#ifndef GRAFOPREVIATURAS_H_INCLUDED
#define GRAFOPREVIATURAS_H_INCLUDED
#include "Constantes.h"

typedef int Grafo[cantAsignaturas][cantAsignaturas];

void CrearGrafo (Grafo &G);
void AgregarPreviatura(Grafo &G, int asig1, int asig2);
bool EsPreviaDirecta(Grafo &G, int asig1, int asig2);
void buscarPreviaturas(Grafo G, int actual, int tope, bool visitado[])

#endif // GRAFOPREVIATURAS_H_INCLUDED
