#include "graph.c"

int main(){
    GRAFO *graph1 = NULL;
    graph1 = criaGrafo(5);

    // 1 -> 1
    // 1 -> 3
    criaAresta(graph1, 0, 0, 1);
    criaAresta(graph1, 0, 2, 1);

    // 3 -> 2
    // 3 -> 4
    criaAresta(graph1, 2, 1, 1);
    criaAresta(graph1, 2, 3, 1);

    // 2 -> 4
    // 2 -> 5
    criaAresta(graph1, 1, 3, 1);
    criaAresta(graph1, 1, 4, 1);

    // 4 -> 5
    criaAresta(graph1, 3, 4, 1);

    // Impressao do grafo
    imprime(graph1);
    printf("\nMatriz de Adjacencia: \n");
    imprimeMatriz(graph1);

    /* Segunda saida com grafo ponderado */
    GRAFO *graph2 = NULL;
    graph2 = criaGrafo(5);
    int peso;
    printf("\n---------------------------------------------------\n\nGrafo ponderado:\n");
    // 1 -> 1
    printf("Digite o peso do caminho [1]->[1]: ");
    scanf("%d", &peso);
    criaAresta(graph2, 0, 0, peso);

    // 1 -> 3
    printf("Digite o peso do caminho [1]->[3]: ");
    scanf("%d", &peso);
    criaAresta(graph2, 0, 2, peso);

    // 3 -> 2
    printf("Digite o peso do caminho [3]->[2]: ");
    scanf("%d", &peso);
    criaAresta(graph2, 2, 1, peso);

    // 3 -> 4
    printf("Digite o peso do caminho [3]->[4]: ");
    scanf("%d", &peso);
    criaAresta(graph2, 2, 3, peso);

    // 2 -> 4
    printf("Digite o peso do caminho [2]->[4]: ");
    scanf("%d", &peso);
    criaAresta(graph2, 1, 3, peso);
    
    // 2 -> 5
    printf("Digite o peso do caminho [2]->[5]: ");
    scanf("%d", &peso);
    criaAresta(graph2, 1, 4, peso);

    // 4 -> 5
    printf("Digite o peso do caminho [4]->[5]: ");
    scanf("%d", &peso);
    criaAresta(graph2, 3, 4, peso);

    //Impressao do grafo
    imprime(graph2);
    printf("\nMatriz de Adjacencia: \n");
    imprimeMatriz(graph2);
    printf("\nA soma dos pesos desse grafo eh: %d", somaPeso(graph2));
    return 0;
}