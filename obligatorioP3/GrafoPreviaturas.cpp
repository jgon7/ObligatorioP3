#include "GrafoPreviaturas.h"
#include "Constantes.h"
#include <iostream>
using namespace std;

void CrearGrafo (Grafo &G) {
    for (int i = 0; i < cantAsignaturas ; i++)
        for (int j = 0; j < cantAsignaturas; j++)
            G[i][j]=0;
}

void AgregarPreviatura (Grafo &G, int asig1, int asig2) {
    G[asig1][asig2]=1;
}

bool EsPreviaDirecta (Grafo &G, int asig1, int asig2){
    bool hay = false;
    if (G[asig1][asig2] == 1)
        hay = true;
    return hay;
}

bool ExistePreviatura(GrafoPreviaturas g, int origen, int destino, int tope) {
    bool visitado[cantAsignaturas] = { false };
    return ExisteCaminoAux(g, origen, destino, tope, visitado);
}

// Hay que recorrer el grafo de forma recursiva (DFS) para ver si hay un camino
bool ExisteCaminoAux(GrafoPreviaturas g, int actual, int destino, int tope, bool visitado[]) {
    if (actual == destino)
        return true;

    visitado[actual] = true;

    for (int i = 0; i < tope; i++) {
        //si i es previa directa de actual y no la visité aún..
        if (g[actual][i] && !visitado[i]) {
            if (ExisteCaminoAux(g, i, destino, tope, visitado)) {
                return true;
            }
        }
    }
    return false;
}


//igual que ExisteCaminoAux, pero acá en este DFS recorremos hacia atras en las previas para ir mostrando
void buscarPreviaturas(Grafo G, int actual, int tope, bool visitado[]) {
    for (int i = 0; i < tope; i++) {
        //cambiamos el orden en la matriz para buscar hacia atras
        if (G[i][actual] == 1 && !visitado[i]) {
            visitado[i] = true; // La marcamos como una previa encontrada
            buscarPreviasAux(G, i, tope, visitado);
        }
    }
}

