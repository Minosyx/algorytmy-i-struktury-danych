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
    printf("9 - polacz obie listy\n");
    printf("0 - zakoncz dzialanie programu\n");
    printf("Twoj wybor: ");
}

void listC()
{
    printf("Na ktorej liscie chcesz wykonac te akcje?\n");
    printf("    1. Liscie 1\n");
    printf("    2. Liscie 2\n");
    printf("Twoj wybor: ");
}

int main()
{
    wel lista = 0, lista2 = 0, *element = 0;
    int choice = 0, x = 0, bool = 1, wart = 0;
    int lc;

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

        lista2 = malloc(sizeof(el));
        lista2->x = INT_MAX;
        lista2->next = NULL;
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
            listC();
            scanf("%d", &lc);
            clear_screen();
            printf("Podaj wartosc do dodania: ");
            scanf("%d", &x);
            clear_screen();
            (lc == 1) ? addWel(&lista, x, wart) : addWel(&lista2, x, wart);
            break;
        case 2:
            listC();
            scanf("%d", &lc);
            clear_screen();
            element = (lc == 1) ? getFirst(&lista, wart) : getFirst(&lista2, wart);
            if (element)
                printf("Adres pierwszego elementu [%d] to: %p\n\n", (*element)->x, *element);
            else
                printf("Lista jest pusta!\n\n");
            break;
        case 3:
            listC();
            scanf("%d", &lc);
            clear_screen();
            element = (lc == 1) ? getLast(&lista, wart) : getLast(&lista2, wart);
            if (element)
                printf("Adres ostatniego elementu [%d] to: %p\n\n", (*element)->x, *element);
            else
                printf("Lista jest pusta!\n\n");
            break;
        case 4:
            listC();
            scanf("%d", &lc);
            clear_screen();
            printf("Podaj szukana wartosc: ");
            scanf("%d", &x);
            clear_screen();
            element = (lc == 1) ? findEl(&lista, x, wart) : findEl(&lista2, x, wart);
            if (element)
            {
                printf("Adres szukanej wartosci [%d] to: %p\n\n", (*element)->x, *element);
            }
            else
                printf("Brak podanego elementu na liscie\n\n");
            break;
        case 5:
            listC();
            scanf("%d", &lc);
            clear_screen();
            printf("Podaj wartosc elementu do usuniecia: ");
            scanf("%d", &x);
            element = (lc == 1) ? findEl(&lista, x, wart) : findEl(&lista2, x, wart);
            if (element)
                remEl(element);
            clear_screen();
            break;
        case 6:
            listC();
            scanf("%d", &lc);
            clear_screen();
            (lc == 1) ? readFile(&lista, wart) : readFile(&lista2, wart);
            break;
        case 7:
            listC();
            scanf("%d", &lc);
            clear_screen();
            (lc == 1) ? writeFile(lista, wart) : writeFile(lista2, wart);
            break;
        case 8:
            listC();
            scanf("%d", &lc);
            clear_screen();
            printf("Wybierz sposob wyswietlenia listy:\n	1. Do przodu\n	2. Do tylu\n");
            printf("Twoj wybor: ");
            scanf("%d", &x);
            clear_screen();
            if (x == 1)
                (lc == 1) ? showList(lista, wart) : showList(lista2, wart);
            else if (x == 2)
            {
                (lc == 1) ? rShowList(lista, wart) : rShowList(lista2, wart);
                printf("\n");
            }
            printf("\n");
            break;
        case 9:
            merge(&lista, &lista2, wart);
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