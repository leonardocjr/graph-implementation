#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

GRAFO *criaGrafo (int v){
    int i;

    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g-> adj = (VERTICE *)malloc(v*sizeof(VERTICE));

    for(i=0; i<v; i++){
        g->adj[i].cab = NULL;
    }

    return g;
}

// Adicionando arestas ao grafo
ADJACENCIA *criaAdj(int v, int peso){
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;

    return temp;
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){
    // Se o grafo nao existe
    if(!gr) return false;

    // Se os valores nao sao negativos
    if((vf<0) || (vf >= gr->vertices)) return false;

    // Se os valores sao maiores que o numero de vertices do grafo
    if((vi<0) || (vf >= gr->vertices)) return false;

    ADJACENCIA *novo = criaAdj(vf, p); // Adjacencia com vertice final e peso
    
    // Coloca a adjacencia na lista de vertice inicial
    novo->prox = gr->adj[vi].cab; // O campo prox vai receber a cabeca da lista
    gr->adj[vi].cab = novo; // A cabeca da lista passa a ser o novo elemento
    gr->arestas++; // Atualizo o numero de arestas do grafo
    return true;
}

void imprime(GRAFO *gr){
    // Se o grafo nao existe
    if(!gr) return;

    printf("Vertices: %d | Arestas: %d \n", gr->vertices, gr->arestas);
    int i;

    for(i=0; i<gr->vertices; i++){
        printf("v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cab;
            while(ad){
                printf("v%d(%d) ", ad->vertice, ad->peso);
                ad = ad->prox;
            }
        printf("\n");
    }
}