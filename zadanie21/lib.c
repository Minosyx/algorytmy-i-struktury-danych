#include <stdlib.h>
#include "lib.h"

int uniform_distribution(int rangeLow, int rangeHigh)
{
    int range = rangeHigh - rangeLow + 1;
    int copies = RAND_MAX / range;
    int limit = range * copies;
    int myRand = -1;
    while (myRand < 0 || myRand >= limit)
    {
        myRand = rand();
    }
    return myRand / copies + rangeLow;
}

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int *arr, int size, int *comparison, int *substitution){
    int i, j;
    for (i = 0; i < size - 1; i++){
        for (j = 0; j < size - i - 1; j++){
            (*comparison)++;
            if(arr[j] > arr[j+1]){
                (*substitution)++;
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void insertionSort(int *arr, int size, int *comparison, int *substitution){
    int i, j, val;
    for(i = 1; i < size; i++){
        val = arr[i];
        j = i - 1;

        while (j >= 0){
            (*comparison)++;
            if (arr[j] > val){
                (*substitution)++;
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            else break;
        }
        if(arr[j + 1] != val) (*substitution)++;
        arr[j + 1] = val;
    }
}

void shellSort(int *arr, int size, int *comparison, int *substitution){
    int i, j, k, tmp;
    for (i = size / 2; i > 0; i = i / 2)
    {
        for (j = i; j < size; j++)
        {
            for (k = j - i; k >= 0; k = k - i)
            {   
                (*comparison)++;
                if (arr[k + i] >= arr[k])
                    break;
                else
                {
                    (*substitution)++;
                    swap(&arr[k + i], &arr[k]);
                }
            }
        }
    }
}

int partition(int* arr, int start, int end, int *comparison, int *substitution){
    int _end = rand() % (end - start + 1) + start, x, i, j;
    x = arr[start];
    arr[start] = arr[_end];
    arr[_end] = x;
    x = arr[start];
    i = start - 1;
    j = end + 1;
    do
    {
        do { 
            j--; 
            (*comparison)++;
        }
        while (arr[j] > x);
        do { 
            i++;
            (*comparison)++;
        }
        while (arr[i] < x);
        if (i < j){
            swap(&arr[i], &arr[j]);
            (*substitution)++;
        }
    }
    while (i < j);
    return j;
}

void quickSort(int *arr, int start, int end, int *comparison, int *substitution){
    int q;
    if (start < end){
        q = partition(arr, start, end, comparison, substitution);
        quickSort(arr, start, q, comparison, substitution);
        quickSort(arr, q + 1, end, comparison, substitution);
    }
}

void printArr(int *arr, int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}