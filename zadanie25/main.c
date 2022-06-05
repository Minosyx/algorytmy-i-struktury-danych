#include "lib.c"

int main(){
    int V = 8;
    int directed = 0;
    Graph *graph = makeGraph(V, directed);

    addEdge(graph, 0, 6, 5);
    addEdge(graph, 6, 4, 12);
    addEdge(graph, 6, 1, 2);
    addEdge(graph, 6, 3, 9);
    addEdge(graph, 1, 4, 8);
    addEdge(graph, 3, 5, 6);
    addEdge(graph, 4, 2, 3);
    addEdge(graph, 2, 7, 5);

    // addEdge(graph, 0, 2, 3);
    // addEdge(graph, 0, 3, 1);
    // addEdge(graph, 2, 3, 1);
    // addEdge(graph, 3, 1, 5);
    // addEdge(graph, 3, 4, 2);
    // addEdge(graph, 4, 1, 2);

    dijkstra(graph, 6);

    search_caller(graph, 6, DFS);
    search_caller(graph, 6, BFS);
}