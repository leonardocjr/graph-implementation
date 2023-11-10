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
    bool visitado;
    ADJACENCIA *cab;
}VERTICE;

typedef struct grafo {
    int vertices; // Numero de vertices totais no grafo
    int arestas; // Numero de arestas totais no grafo
    VERTICE *adj; // Arranjo de vertices na estrutura
}GRAFO;

GRAFO *criaGrafo (int v);

ADJACENCIA *criaAdj(int v, int peso);

void criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p);

void imprime(GRAFO *gr);

void imprimeMatriz(GRAFO *gr);

void imprimeCaminho(GRAFO *grafo, int inicio, int destino);

void buscaEmLargura(GRAFO *grafo, int inicio, int destino);

void imprimeSequencia(int *sequencia, int n);

void dfsVisita(GRAFO *grafo, int vertice, int *sequencia, int *contador);

void buscaEmProfundidade(GRAFO *grafo, int inicio);

#endif