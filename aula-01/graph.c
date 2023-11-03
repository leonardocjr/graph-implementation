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

void criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){
    // Se o grafo nao existe
    if(!gr){ 
        printf("Grafo nao existe.\n");
        return;
    }
    // Se os valores nao sao negativos
    if((vf<0) || (vf >= gr->vertices)) {
        printf("Valores negativos no grafo\n");
        return;
    }
    // Se os valores sao maiores que o numero de vertices do grafo
    if((vi<0) || (vf >= gr->vertices)){
        printf("Valores maiores que o numero de vertices\n");
        return;
    }

    ADJACENCIA *novo = criaAdj(vf, p); // Adjacencia com vertice final e peso
    
    // Coloca a adjacencia na lista de vertice inicial
    novo->prox = gr->adj[vi].cab; // O campo prox vai receber a cabeca da lista
    gr->adj[vi].cab = novo; // A cabeca da lista passa a ser o novo elemento
    gr->arestas++; // Atualizo o numero de arestas do grafo
    printf("Aresta v%d -> v%d e peso: %d criada.\n", vi, vf, p);
}

void imprime(GRAFO *gr){
    // Se o grafo nao existe
    if(!gr) return;

    printf("\nVertices: %d | Arestas: %d \n", gr->vertices, gr->arestas);
    int i;

    for(i=0; i<gr->vertices; i++){
        printf("%d: ", i+1);
        ADJACENCIA *ad = gr->adj[i].cab;
            while(ad){
                printf("%d(%d) ", ad->vertice+1, ad->peso);
                ad = ad->prox;
            }
        printf("\n");
    }
}

int somaPeso(GRAFO *gr){
    // Se o grafo nao existe
    if(!gr) return 0;
    
    int i;
    int peso = 0;

    for(i=0; i<gr->vertices; i++){
        ADJACENCIA *ad = gr->adj[i].cab;
            while(ad){
               peso += ad->peso;
               ad = ad->prox;
            }
    }
    return peso;
}

void imprimeMatriz(GRAFO *gr){
    // Se o grafo nao existe
    if(!gr) return;

    int i, j;
    int M[gr->vertices][gr->vertices];

    for(i = 0; i < gr->vertices; i++){
        for(j = 0; j < gr->vertices; j++)
            M[i][j] = 0;
    }

    for(i=0; i < gr->vertices; i++){
        ADJACENCIA *ad = gr->adj[i].cab;
            while(ad){
                M[i][ad->vertice] = ad->peso;
                M[ad->vertice][i] = ad->peso;
                ad = ad->prox;
            }
    }

    printf("   ");
    for(i = 0; i < gr->vertices; i++)
        printf("| 0%d ", i+1);
    printf("\n");
    for(i = 0; i < gr->vertices; i++){
        printf("0%d ", i+1);
        for(j = 0; j < gr->vertices; j++){
            if(M[i][j]<10)
                printf("| 0%d ", M[i][j]);
            else
                printf("| %d ", M[i][j]);
        }
        printf("\n");
    }
}