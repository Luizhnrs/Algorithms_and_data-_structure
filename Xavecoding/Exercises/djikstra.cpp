#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

#define V 9  // Número de vértices no grafo

// Função para encontrar o vértice com a menor distância ainda não processado
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

// Função para imprimir o array de distâncias
void printSolution(int dist[]) {
    cout << "Vértice \t Distância da Origem\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

// Função que implementa o algoritmo de Dijkstra para um grafo representado
// por uma matriz de adjacência
void dijkstra(int graph[V][V], int src) {
    int dist[V];  // Array de saída. dist[i] guardará a menor distância de src até i

    bool sptSet[V];  // sptSet[i] será verdadeiro se o vértice i estiver incluído no caminho mais curto

    // Inicializa todas as distâncias como infinito e o sptSet como falso
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // A distância do nó de origem até ele mesmo é sempre 0
    dist[src] = 0;

    // Encontra o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolhe o vértice de distância mínima a partir dos vértices
        // ainda não processados
        int u = minDistance(dist, sptSet);

        // Marca o vértice escolhido como processado
        sptSet[u] = true;

        // Atualiza o valor de dist[] dos vértices adjacentes do vértice escolhido
        for (int v = 0; v < V; v++) {
            // Atualiza dist[v] se não estiver em sptSet, houver uma aresta de u para v,
            // e o peso total do caminho de src até v através de u for menor que dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Imprime o array de distâncias
    printSolution(dist);
}

int main() {
    /* Exemplo de grafo representado por uma matriz de adjacência:
           0    1    2    3    4    5    6    7    8
    0 ->  { 0,   4,   0,   0,   0,   0,   0,   8,   0 }
    1 ->  { 4,   0,   8,   0,   0,   0,   0,  11,   0 }
    2 ->  { 0,   8,   0,   7,   0,   4,   0,   0,   2 }
    3 ->  { 0,   0,   7,   0,   9,  14,   0,   0,   0 }
    4 ->  { 0,   0,   0,   9,   0,  10,   0,   0,   0 }
    5 ->  { 0,   0,   4,  14,  10,   0,   2,   0,   0 }
    6 ->  { 0,   0,   0,   0,   0,   2,   0,   1,   6 }
    7 ->  { 8,  11,   0,   0,   0,   0,   1,   0,   7 }
    8 ->  { 0,   0,   2,   0,   0,   0,   6,   7,   0 }
    */

    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);  // Calcula o caminho mais curto a partir do nó de origem (0)

    return 0;
}