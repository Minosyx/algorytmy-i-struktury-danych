#include <stdio.h>
#include <stdlib.h>
#include "lib.c"

#define MAX_BUFF 20
#define STR2(x) #x
#define STR(X) STR2(X)

void printOptions(){
    printf("1. Dodaj slowa do tablicy\n");
    printf("2. Pokaz tablice slow\n");
    printf("3. Posortuj tablice\n");
    printf("0. Zakoncz program\n");
    printf("Twoj wybor: ");
}

int main(){
    char **arr;
    char buff[MAX_BUFF + 1];
    char *word;
    int bool = 1;
    int number, i = 0;
    int choice, it = 0;
    int size = 1;
    arr = calloc(size, sizeof(char *));
    while(bool){
        printOptions();
        scanf("%d", &choice);
        clear_screen();
        switch(choice){
            case 1:
                printf("Podaj ilosc slow do dodania: ");
                scanf("%d", &number);
                if(it + number > size){
                    size = it + number;
                    arr = realloc(arr, size * sizeof(char *));
                }
                clear_screen();
                for(i = 0; i < number; i++){
                    printf("Slowo[%d] = ", it);
                    scanf("%"STR(MAX_BUFF)"s", buff);
                    word = malloc(strlen(buff) + 1);
                    strcpy(word, buff);
                    arr[it++] = word;
                }
                clear_screen();
                break;
            case 2:
                showArr(arr, size);
                printf("\n");
                break;
            case 3:
                HeapSort(arr, size);
                break;
            case 0:
                bool = 0;
                break;
            default:
                printf("Podano bledna opcje!\n\n");
        }
    }
    for(i = 0; i < it; i++){
        free(arr[i]);
    }
    free(arr);
}