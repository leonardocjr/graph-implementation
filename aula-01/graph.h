#ifndef GRAPH_H
#define GRAPH_H
#define true 1
#define false 0
typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia {
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
}ADJACENCIA;

typedef struct vertice {
    ADJACENCIA *cab;
}VERTICE;

typedef struct grafo {
    int vertices; // Numero de vertices totais no grafo
    int arestas; // Numero de arestas totais no grafo
    VERTICE *adj; // Arranjo de vertices na estrutura
}GRAFO;

GRAFO *criaGrafo (int v);

ADJACENCIA *criaAdj(int v, int peso);

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p);

void imprime(GRAFO *gr);

#endif