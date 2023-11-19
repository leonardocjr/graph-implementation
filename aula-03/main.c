#include "graph.c"

int main(){
    GRAFO *graph1 = NULL;
    graph1 = criaGrafo(6);

    // 0 -> 1
    // 0 -> 2
    criaAresta(graph1, 0, 1, 1);
    criaAresta(graph1, 0, 2, 4);

    // 1 -> 2
    // 1 -> 3
    // 1 -> 4
    criaAresta(graph1, 1, 2, 4);
    criaAresta(graph1, 1, 3, 2);
    criaAresta(graph1, 1, 4, 7);

    // 2 -> 3
    // 2 -> 4
    criaAresta(graph1, 2, 3, 3);
    criaAresta(graph1, 2, 4, 5);

    // 3 -> 4
    // 3 -> 5
    criaAresta(graph1, 3, 4, 4);
    criaAresta(graph1, 3, 5, 6);

    // 4 -> 5
    criaAresta(graph1, 4, 5, 7);

    printf("\n");
    imprime(graph1);
    printf("\n");
    imprimeMatriz(graph1);
    printf("\n");
    caminho_mais_curto(graph1, 0, 5);
    return 0;
}