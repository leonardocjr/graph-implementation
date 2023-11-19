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

int** geraMatriz(GRAFO *gr){
    // Se o grafo nao existe
    if(!gr) return NULL;

    int i, j;
    int** M = malloc(gr->vertices * sizeof(int *));
    for (i=0; i<gr->vertices; i++)
         M[i] = malloc(gr->vertices * sizeof(int));

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
    return M;
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

void caminho_mais_curto(GRAFO *gr, int origem, int destino){
    int i, vert, k, NovaDist, min;
    int *M, *L, *A, *caminho;
    M = (int*) malloc(gr->vertices*sizeof(int));
    L = (int*) malloc(gr->vertices*sizeof(int));
    A = (int*) malloc(gr->vertices*sizeof(int));
    caminho = (int*) malloc(gr->vertices*3*sizeof(int)); // vetor auxiliar
    
    int** Mat = (int**) malloc(gr->vertices*sizeof(int*)); // Matriz do grafo
    Mat = geraMatriz(gr);
    
    // Inicializando as variaveis
    for(i=0;i<gr->vertices;i++){
        M[i] = 0; // False -> determina se o vertice ja foi visitado
        L[i] = 300000; // Infinito -> determina o comprimento do caminho mais curto
        A[i] = -1; // Determina o caminho mais curto entre origem e destino
    }
    vert = origem;
    L[vert] = 0;
    while (vert != destino && vert != -1){
        for(i=0;i<gr->vertices;i++)
            if(Mat[vert][i] != 0 && M[i] == 0){
                NovaDist = L[vert] + Mat[vert][i];
                if(NovaDist < L[i]){
                    L[i] = NovaDist;
                    A[i] = vert;
                }
            }
        M[vert] = 1;
        min = 300000;
        vert = -1;
        
        for(i=0;i<gr->vertices;i++)
            if(M[i]==0 && L[i] < min){
                min = L[i];
                vert = i;
            }
        
    }

    if(vert == destino){
        printf("O caminho mais curto entre v%d e v%d, tem comprimento: %d\nCaminho: ", origem, destino, L[destino]);
        caminho[0] = destino;
        k = 1;
        while(vert != origem){
            caminho[k] = A[vert];
            vert = A[vert];
            k++;
        }
        for(i=k-1;i>=0;i--){
            printf("%d", caminho[i]);
            if(i > 0)
                printf(" -> ");
        }
    }else
        printf("Nao existe caminho entre v%d e v%d", origem, destino);
}