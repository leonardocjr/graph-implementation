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

    printf("Vertices: %d | Arestas: %d \n", gr->vertices, gr->arestas);
    int i;

    for(i=0; i<gr->vertices; i++){
        printf("%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cab;
            while(ad){
                printf("%d(%d) ", ad->vertice, ad->peso);
                ad = ad->prox;
            }
        printf("\n");
    }
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

    printf("     ");
    for(i = 0; i < gr->vertices; i++)
        if(i<10)
            printf("| 0%d ", i);
        else
            printf("| %d ", i);
        
    printf("\n");
    for(i = 0; i < gr->vertices; i++){
        if(i<10)
            printf("| 0%d ", i);
        else
            printf("| %d ", i);
        
        for(j = 0; j < gr->vertices; j++){
            if(M[i][j]<10)
                printf("| 0%d ", M[i][j]);
            else
                printf("| %d ", M[i][j]);
        }
        printf("\n");
    }
}

void imprimeCaminho(GRAFO *grafo, int inicio, int destino) {
    if (inicio == destino) {
        printf("%d ", inicio);
    } else {
        printf(" -> [ %d ]\n\nCaminho encontrado: %d ", destino, destino);
    }
}

void buscaEmLargura(GRAFO *grafo, int inicio, int destino) {
    int iniFila = 0;
    int tamFila = 1;
    int i;

    VERTICE *FILA[grafo->vertices];
    
    for (i = 0; i < grafo->vertices; i++) {
        grafo->adj[i].visitado = false;
    }

    grafo->adj[inicio].visitado = true;
    FILA[iniFila] = &(grafo->adj[inicio]);
    printf("Vertices percorridas: \n");
    while (iniFila < tamFila) {
        VERTICE *atual = FILA[iniFila];
        printf("[%d]", atual - grafo->adj);

        ADJACENCIA *temp = atual->cab;
        while (temp != NULL) {
            if (!grafo->adj[temp->vertice].visitado) {
                grafo->adj[temp->vertice].visitado = true;
                FILA[tamFila] = &(grafo->adj[temp->vertice]);
                tamFila++;
                
                if (temp->vertice == destino) {
                    imprimeCaminho(grafo, inicio, destino);
                    return;
                }
            }
            temp = temp->prox;
        }
        printf(" -> ");
        iniFila++;
    }
    printf("\n\nCaminho de [%d] para [%d] nao encontrado.\n", inicio, destino);
}

void imprimeSequencia(int *sequencia, int n) {
    printf("Vertices descobertos: \n");
    for (int i = 0; i < n; i++) {
        printf("[%d]", sequencia[i]);
        if(!(n == (i+1)))
            printf(" -> ");
    }
}

void dfsVisita(GRAFO *grafo, int vertice, int *sequencia, int *contador) {
    grafo->adj[vertice].visitado = true;
    sequencia[(*contador)++] = vertice;

    ADJACENCIA *temp = grafo->adj[vertice].cab;
    while (temp != NULL) {
        int vizinho = temp->vertice;
        if (!grafo->adj[vizinho].visitado) {
            dfsVisita(grafo, vizinho, sequencia, contador);
        }
        temp = temp->prox;
    }
}

void buscaEmProfundidade(GRAFO* grafo, int inicio) {
    int *sequencia = (int *)malloc(grafo->vertices * sizeof(int));
    int contador = 0;
    int i;

    for (i = 0; i < grafo->vertices; i++) {
        grafo->adj[i].visitado = false;
    }

    for (i = 0; i < grafo->vertices; i++) {
        if (!grafo->adj[i].visitado) {
            dfsVisita(grafo, i, sequencia, &contador);
        }
    }

    imprimeSequencia(sequencia, grafo->vertices);
    free(sequencia);
}