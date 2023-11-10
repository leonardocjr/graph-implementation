#include "graph.c"

int main(){
    GRAFO *graph1 = NULL;
    graph1 = criaGrafo(15);

    // 0 -> 1
    // 0 -> 2
    criaAresta(graph1, 0, 1, 1);
    criaAresta(graph1, 0, 2, 1);

    // 1 -> 3
    // 1 -> 4
    // 1 -> 5
    criaAresta(graph1, 1, 3, 1);
    criaAresta(graph1, 1, 4, 1);
    criaAresta(graph1, 1, 5, 1);

    // 3 -> 6
    // 3 -> 7
    criaAresta(graph1, 3, 6, 1);
    criaAresta(graph1, 3, 7, 1);

    // 5 -> 8
    // 5 -> 9
    criaAresta(graph1, 5, 8, 1);
    criaAresta(graph1, 5, 9, 1);

    // 7 -> 10
    // 7 -> 11
    // 7 -> 12
    criaAresta(graph1, 7, 10, 1);
    criaAresta(graph1, 7, 11, 1);
    criaAresta(graph1, 7, 12, 1);

    // 9 -> 13
    // 9 -> 14
    criaAresta(graph1, 9, 13, 1);
    criaAresta(graph1, 9, 14, 1);

    // Impressao do grafo + busca em largura
    printf("\n");
    imprime(graph1);
    printf("\n");
    printf("Busca em Largura a partir do vertice 1 ao 14:\n");
    buscaEmLargura(graph1, 1, 14);
    printf("\n\n-------------------------------------------------------------------\n\n");

// -------------------------------------------------------------------

    GRAFO *graph2 = NULL;
    graph2 = criaGrafo(10);

    // 0 -> 1
    // 0 -> 2
    criaAresta(graph2, 0, 1, 1);

    // 1 -> 2
    // 1 -> 4
    // 1 -> 5
    criaAresta(graph2, 1, 2, 1);
    criaAresta(graph2, 1, 4, 1);

    // 2 -> 3
    // 2 -> 4
    // 2 -> 9
    criaAresta(graph2, 2, 3, 1);
    criaAresta(graph2, 2, 4, 1);
    criaAresta(graph2, 2, 9, 1);

    // 3 -> 8
    criaAresta(graph2, 3, 8, 1);

    // 4 -> 5
    // 4 -> 6
    // 4 -> 7
    criaAresta(graph2, 4, 5, 1);
    criaAresta(graph2, 4, 6, 1);
    criaAresta(graph2, 4, 7, 1);

    // 5 -> 6
    criaAresta(graph2, 5, 6, 1);

    // 7 -> 8
    // 7 -> 9
    criaAresta(graph2, 7, 8, 1);
    criaAresta(graph2, 7, 9, 1);

    // Impressao do grafo + busca em profundidade
    printf("\n");
    imprime(graph2);
    printf("\n");
    printf("Busca em Profundidade a partir do vertice 0:\n");
    buscaEmProfundidade(graph2, 0);
    printf("\n");

    return 0;
}