#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define LEFT(i) (2*i + 1)
#define RIGHT(i) (2*i + 2)

void swap(char **x, char **y){
    char *tmp = *x;
    *x = *y;
    *y = tmp;
}

void Heapify(char **arr, int i, int heapSize){
    int l, r, x, largest;
    l = LEFT(i);
    r = RIGHT(i);
    if (l < heapSize && strcmp(arr[l], arr[i]) > 0) largest = l;
    else largest = i;
    if (r < heapSize && strcmp(arr[r], arr[largest]) > 0) largest = r;
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        Heapify(arr, largest, heapSize);
    }
}

void BuildHeap(char **arr, int size){
    int i;
    for (i = (size - 1) / 2; i >= 0; i--) 
        Heapify(arr, i, size);
}

void HeapSort(char **arr, int size){
    int i, x, heapSize = size;
    BuildHeap(arr, size);
    for (i = size - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        Heapify(arr, 0, --heapSize);
    }
}

void showArr(char **arr, int size){
    if(*arr){
        int i;
        for(i = 0; i < size; i++){
            printf("%s ", arr[i]);
        }
    }
    printf("\n");
}

void clear_screen(){
    system("cls||clear");
}