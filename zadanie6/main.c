#include <stdio.h>
#include "lib.c"

void printOptions()
{
    printf("Nastepna operacja:\n");
    printf("1 - dodaj element na liscie\n");
    printf("2 - pobierz pierwszy element\n");
    printf("3 - pobierz ostatni element\n");
    printf("4 - znajdz wskazany element\n");
    printf("5 - usun wskazany element\n");
    printf("6 - wczytaj zawartosc listy z pliku\n");
    printf("7 - zapisz zawartosc listy do pliku\n");
    printf("8 - wyswietl zawartosc listy\n");
    printf("0 - zakoncz dzialanie programu\n");
    printf("Twoj wybor: ");
}

int main()
{
    wel lista = 0, *element = 0;
    int choice = 0, x = 0, bool = 1, wart = 0;

    printf("Wybierz rodzaj listy:\n");
    printf("    1. Bez wartownika\n");
    printf("    2. Z wartownikiem\n");
    printf("Twoj wybor: ");
    scanf("%d", &x);
    clear_screen();
    if (x == 2)
    {
        lista = malloc(sizeof(el));
        lista->x = INT_MAX;
        lista->next = NULL;
        wart = 1;
    }
    else if (x != 2 && x != 1)
    {
        printf("Podano bledna opcje!\n");
        printf("Nastapi wybranie opcji bez wartownika!\n\n");
    }

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
            clear_screen();
            addWel(&lista, x, wart);
            break;
        case 2:
            element = getFirst(&lista, wart);
            if (element)
                printf("Adres pierwszego elementu [%d] to: %p\n\n", (*element)->x, *element);
            else
                printf("Lista jest pusta!\n\n");
            break;
        case 3:
            element = getLast(&lista, wart);
            if (element)
                printf("Adres ostatniego elementu [%d] to: %p\n\n", (*element)->x, *element);
            else
                printf("Lista jest pusta!\n\n");
            break;
        case 4:
            printf("Podaj szukana wartosc: ");
            scanf("%d", &x);
            clear_screen();
            element = findEl(&lista, x, wart);
            if (element)
            {
                printf("Adres szukanej wartosci [%d] to: %p\n\n", (*element)->x, *element);
            }
            else
                printf("Brak podanego elementu na liscie\n\n");
            break;
        case 5:
            printf("Podaj wartosc elementu do usuniecia: ");
            scanf("%d", &x);
            element = findEl(&lista, x, wart);
            if (element)
                remEl(element);
            clear_screen();
            break;
        case 6:
            readFile(&lista, wart);
            break;
        case 7:
            writeFile(lista, wart);
            break;
        case 8:
            printf("Wybierz sposob wyswietlenia listy:\n	1. Do przodu\n	2. Do tylu\n");
            printf("Twoj wybor: ");
            scanf("%d", &x);
            clear_screen();
            if (x == 1)
                showList(lista, wart);
            else if (x == 2)
            {
                rShowList(lista, wart);
                printf("\n");
            }
            printf("\n");
            break;
        case 0:
            bool = 0;
            break;
        default:
            clear_screen();
            printf("Podano zly wybor!\n\n");
        }
    }
}