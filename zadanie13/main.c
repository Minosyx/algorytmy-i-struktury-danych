#include <stdio.h>
#include <stdlib.h>
#include "lib.c"

void printOptions()
{
    printf("Nastepna operacja:\n");
    printf("1 - dodaj element do kolejki\n");
    printf("2 - pobierz element o najwiekszym priorytecie\n");
    printf("3 - zmien priorytet elementu\n");
    printf("4 - sprawdz czy kolejka jest pusta\n");
    printf("5 - pokaz kolejke\n");
    printf("0 - zakoncz dzialanie programu\n");
    printf("Twoj wybor: ");
}

int main()
{
    wel queue = 0, *element = NULL;
    wel qel = 0;
    int choice = 0, x = 0, p = 0, bool = 1;

    while (bool)
    {
        printOptions();
        scanf("%d", &choice);
        clear_screen();
        switch (choice)
        {
        case 1:
            printf("Podaj wartosc do dodania: ");
            scanf("%d", &x);
            printf("Podaj wartosc priorytetu: ");
            scanf("%d", &p);
            clear_screen();
            qel = createQ(x, p);
            if (qel) add(&queue, qel);
            break;
        case 2:
            qel = getHighest(&queue);
            if (qel)
            {
                printf("Pobrano element (%d) o priorytecie [%d]\n\n", qel->x, qel->priority);
                free(qel);
            }
            break;
        case 3:
            printf("Podaj wartosc i priorytet elemntu, ktorego priorytet chcesz zmienic.\n");
            printf("Wartosc: ");
            scanf("%d", &x);
            printf("Priorytet: ");
            scanf("%d", &p);
            clear_screen();
            element = findEl(&queue, x, p);
            if (element)
            {
                printf("Podaj nowy priorytet: ");
                scanf("%d", &p);
                changePriority(&queue, element, p);
            }
            else
                printf("Element nie zostal znaleziony!\n\n");
            break;
        case 4:
            emptyCheck(queue);
            break;
        case 5:
            printQueue(queue);
            printf("\n");
            break;
        case 0:
            bool = 0;
            break;
        default:
            clear_screen();
            printf("Wybrano bledna opcje!\n\n");
        }
    }
}