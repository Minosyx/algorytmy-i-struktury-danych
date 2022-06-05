#include <stdio.h>
#include "lib.c"

void printOptions()
{
    printf("Nastepna operacja:\n");
    printf("1 - dodaj element na poczatku listy\n");
    printf("2 - dodaj element na koncu listy\n");
    printf("3 - usun pierwszy element listy\n");
    printf("4 - usun ostatni element listy\n");
    printf("5 - odszukaj zadany element\n");
    printf("6 - dodaj nowy element przed lub za wskazanym\n");
    printf("7 - usun wskazany element\n");
    printf("8 - wczytaj zawartosc listy z pliku\n");
    printf("9 - zapisz zawartosc listy do pliku\n");
    printf("10 - wyswietl zawartosc listy\n");
    printf("0 - zakoncz dzialanie programu\n");
    printf("Twoj wybor: ");
}

void printOptions2()
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
    int choice = 0, x = 0, bool = 1, sorted = 0, wart = 0;
    int tmp = 0, tmp1 = 0;

    printf("Wybierz typ listy:\n");
    printf("    1. Nieposortowana\n");
    printf("    2. Posortowana\n");
    printf("Twoj wybor: ");
    scanf("%d", &x);
    clear_screen();
    if (x == 2)
    {
        sorted = 1;
    }
    else if (x != 2 && x != 1)
    {
        printf("Podano bledna opcje!\n");
        printf("Nastapi wybranie listy nieposortowanej\n\n");
    }
    if (sorted)
    {
        clear_screen();
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
            lista->prev = NULL;
            lista->next = NULL;
            tail = lista->prev;
            wart = 1;
        }
        else if (x != 2 && x != 1)
        {
            printf("Podano bledna opcje!\n");
            printf("Nastapi wybranie opcji bez wartownika!\n\n");
        }
    }

    while (bool)
    {
        if (sorted == 0)
            printOptions();
        else
            printOptions2();
        scanf("%d", &choice);
        clear_screen();
        if (sorted == 0)
        {
            switch (choice)
            {
            case 1:
                printf("Podaj wartosc do dodania: ");
                scanf("%d", &x);
                clear_screen();
                addStart(&lista, x);
                break;
            case 2:
                printf("Podaj wartosc do dodania: ");
                scanf("%d", &x);
                clear_screen();
                if (tail == NULL)
                    addStart(&lista, x);
                else
                    addAfter(&tail, x);
                break;
            case 3:
                remStart(&lista);
                break;
            case 4:
                if (tail && tail->prev)
                    remEl(&tail->prev->next);
                else
                    remStart(&lista);
                break;
            case 5:
                printf("Podaj szukana wartosc: ");
                scanf("%d", &x);
                clear_screen();
                element = findEl(&lista, x);
                if (!element)
                {
                    printf("Brak podanego elementu na liscie\n\n");
                    break;
                }
                printf("Adres szukanej wartosci [%d] to: %p\n\n", (*element)->x, *element);
                break;
            case 6:
                printf("Podaj wartosc do wstawienia: ");
                scanf("%d", &x);
                printf("Podaj wartosc elementu, ktorego szukasz: ");
                scanf("%d", &tmp);
                printf("Gdzie wstawic nowy element\n	1. Przed podanym\n	2. Po podanym\n");
                printf("Twoj wybor: ");
                scanf("%d", &tmp1);
                element = findEl(&lista, tmp);
                clear_screen();
                if (tmp1 == 1 && element)
                {
                    addBefore(element, x, 0);
                }
                else if (tmp1 == 2 && element)
                {
                    addAfter(element, x);
                }
                else
                    ("Bledny wybor!\n\n");
                break;
            case 7:
                printf("Podaj wartosc elementu do usuniecia: ");
                scanf("%d", &x);
                element = findEl(&lista, x);
                if (element)
                    remEl(element);
                clear_screen();
                break;
            case 8:
                readFile(&lista);
                break;
            case 9:
                writeFile(lista, 0);
                break;
            case 10:
                printf("Wybierz sposob wyswietlenia listy:\n	1. Do przodu\n	2. Do tylu\n");
                printf("Twoj wybor: ");
                scanf("%d", &x);
                clear_screen();
                if (x == 1)
                    showList(lista, 0);
                else if (x == 2)
                {
                    rShowList(tail);
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
        else
        {
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
                clear_screen();
                if (element)
                    printf("Adres pierwszego elementu [%d] to: %p\n\n", (*element)->x, *element);
                else
                    printf("Lista jest pusta!\n\n");
                break;
            case 3:
                element = getFirst(&tail, wart);
                clear_screen();
                if (element)
                    printf("Adres ostatniego elementu [%d] to: %p\n\n", (*element)->x, *element);
                else
                    printf("Lista jest pusta!\n\n");
                break;
            case 4:
                printf("Podaj szukana wartosc: ");
                scanf("%d", &x);
                clear_screen();
                element = findEl_s(&lista, x, wart);
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
                element = findEl_s(&lista, x, wart);
                if (element && (*element)->x != INT_MAX)
                    remEl(element);
                clear_screen();
                break;
            case 6:
                readFile_s(&lista, wart);
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
                    rShowList(tail);
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
}
