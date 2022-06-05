#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "lib.h"

#define BFS 0
#define DFS 1

struct ListNode{
    int dest;
    int weight;
    struct ListNode *next;
};

struct List{
    struct ListNode *head;
    struct ListNode *it;
};

struct Graph{
    int vertices;
    int directed;
    struct List *array;
};

ListNode *makeListNode(int dest, int weight){
    ListNode *l = malloc(sizeof(ListNode));
    l->dest = dest;
    l->weight = weight;
    l->next = NULL;
    return l;
}

Graph *makeGraph(int vertices, int directed){
    int i;
    Graph *g = malloc(sizeof(Graph));
    g->vertices = vertices;
    g->directed = directed;
    g->array = malloc(sizeof(List) * vertices);

    for (i = 0; i < vertices; i++){
        g->array[i].head = NULL;
    }
    return g;
}

void addEdge(Graph *g, int src, int dest, int weight){
    ListNode *node = makeListNode(dest, weight);
    node->next = g->array[src].head;
    g->array[src].head = node;

    if (g->directed == 0){
        node = makeListNode(src, weight);
        node->next = g->array[dest].head;
        g->array[dest].head = node;
    }
}

struct MinHeapNode{
    int vertices;
    int dist;
};

struct MinHeap{
    int size;
    int capacity;

    int *position;
    struct MinHeapNode **array;
};

MinHeapNode *makeMinHeapNode(int vertices, int dist){
    MinHeapNode *mhp = malloc(sizeof(MinHeapNode));
    mhp->vertices = vertices;
    mhp->dist = dist;
    return mhp;
}

MinHeap *makeMinHeap(int capacity){
    MinHeap *mh = malloc(sizeof(MinHeap));
    mh->position = malloc(capacity * sizeof(int));
    mh->size = 0;
    mh->capacity = capacity;
    mh->array = malloc(capacity * sizeof(MinHeapNode *));
    return mh;
}

void swap(MinHeapNode **x, MinHeapNode **y){
    MinHeapNode *tmp = *x;
    *x = *y;
    *y = tmp;
}

void minHeapify(MinHeap *mh, int idx){
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < mh->size && mh->array[left]->dist < mh->array[smallest]->dist)
        smallest = left;

    if (right < mh->size && mh->array[right]->dist < mh->array[smallest]->dist)
        smallest = right;

    if (smallest != idx){
        MinHeapNode *smallestNode = mh->array[smallest];
        MinHeapNode *idxNode = mh->array[idx];
        mh->position[smallestNode->vertices] = idx;
        mh->position[idxNode->vertices] = smallest;
        swap(&mh->array[smallest], &mh->array[idx]);
        minHeapify(mh, smallest);
    }
}

int isEmpty(MinHeap *mh){
    return mh->size == 0;
}

MinHeapNode *extractMin(MinHeap *mh){
    if(isEmpty(mh)) return NULL;

    MinHeapNode *root = mh->array[0];
    MinHeapNode *last = mh->array[mh->size-1];
    mh->array[0] = last;

    mh->position[root->vertices] = mh->size-1;
    mh->position[last->vertices] = 0;

    --mh->size;
    minHeapify(mh, 0);

    return root;
}

void decrKey(MinHeap *mh, int vertices, int dist){
    int i = mh->position[vertices];

    mh->array[i]->dist = dist;
    while (i && mh->array[i]->dist < mh->array[(i - 1)/2]->dist){
        mh->position[mh->array[i]->vertices] = (i - 1)/2;
        mh->position[mh->array[(i - 1)/2]->vertices] = i;
        swap(&mh->array[i], &mh->array[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

int isInMinHeap(MinHeap *mh, int vertices){
    if (mh->position[vertices] < mh->size)
        return 1;
    return 0;
}

void printPath(int *parent, int j){
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

int printSolution(int *dist, int v, int *parent, int src){
    printf("Vertex\t Distance\tPath");
    for (int i = 0; i < v; i++){
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}

void dijkstra(Graph *g, int src){
    int vertices = g->vertices;
    int *dist = malloc(vertices * sizeof(int));
    int v;
    int *parent = malloc(vertices * sizeof(int));

    MinHeap *mh = makeMinHeap(vertices);

    for(v = 0; v < vertices; v++){
        parent[v] = -1;
        dist[v] = INT_MAX;
        mh->array[v] = makeMinHeapNode(v, dist[v]);
        mh->position[v] = v;
    }

    dist[src] = 0;
    decrKey(mh, src, dist[src]);
    
    mh->size = v;

    while(!isEmpty(mh)){
        MinHeapNode *mhn = extractMin(mh);
        int tmp = mhn->vertices;

        ListNode *it = g->array[tmp].head;

        while(it != NULL){
            v = it->dest;
            if(isInMinHeap(mh, v) && dist[tmp] != INT_MAX && it->weight + dist[tmp] < dist[v]){
                parent[v] = tmp;
                dist[v] = dist[tmp] + it->weight;
                decrKey(mh, v, dist[v]);
            }
            it = it->next;
        }
    }
    printSolution(dist, vertices, parent, src);
    printf("\n");
}

void DFS_inside(Graph *g, int *visited, int src){
    if(visited[src] == 1) return;
    visited[src] = 1;
    printf("v: %d ", src);
    if(g->array[src].it){
        DFS_inside(g, visited, g->array[src].it->dest);
    }
    while (g->array[src].it && g->array[src].it->next){
        g->array[src].it = g->array[src].it->next;
        DFS_inside(g, visited, g->array[src].it->dest);
    }
}

void BFS_inside(Graph *g, int *visited, int src, int sw) {
    if (visited[src] == 1) return;
    visited[src] = 1;
    printf("v: %d ", src);
    if (g->array[src].it && g->array[src].it->next){
        if (sw) g->array[src].it = g->array[src].it->next;
        BFS_inside(g, visited, g->array[src].it->dest, 1);
    }
    if (g->array[src].it)
        BFS_inside(g, visited, g->array[src].it->dest, 2);
}

void search_caller(Graph *g, int src, int type){
    int *visited = malloc(sizeof(int) * g->vertices);
    int i;
    for (i = 0; i < g->vertices; i++) {
        visited[i] = 0;
        g->array[i].it = g->array[i].head;
    }

    if (type == 0) BFS_inside(g, visited, src, 0);
    else DFS_inside(g, visited, src);

    if (g->directed = 1){
        for (i = 0; i < g->vertices; i++)
        {
            if (type == 0)
                BFS_inside(g, visited, i, 0);
            else
                DFS_inside(g, visited, i);
        }
    }
    printf("\n");
}