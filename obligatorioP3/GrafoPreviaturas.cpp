#include "GrafoPreviaturas.h"

void CrearGrafo (Grafo &G) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            G[i][j]=0;
}

void AgregarPreviatura (Grafo &G, int asig1, int asig2) {
    G[u][v]=1;
    if (u != v)
        G[v][u]=1;
}

bool ExistePreviatura (Grafo &G, int asig1, int asig2){
    boolean hay = FALSE;
    if (G[u][v] == 1)
    hay = TRUE;
    return hay;
}
