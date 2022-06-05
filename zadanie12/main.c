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
    printf("11 - usun z listy elementy wystepujace w drugiej liscie\n");
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
    int choice = 0, x = 0, bool = 1;
    int tmp = 0, tmp1 = 0;
    int lc;

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
            (lc == 1) ? addStart(&lista, x) : addStart(&lista2, x);
            break;
        case 2:
            listC();
            scanf("%d", &lc);
            clear_screen();
            printf("Podaj wartosc do dodania: ");
            scanf("%d", &x);
            clear_screen();
            (lc == 1) ? addEnd(&lista, x) : addEnd(&lista2, x);
            break;
        case 3:
            listC();
            scanf("%d", &lc);
            clear_screen();
            (lc == 1) ? remStart(&lista) : remStart(&lista2);
            break;
        case 4:
            listC();
            scanf("%d", &lc);
            clear_screen();
            (lc == 1) ? remEnd(&lista) : remEnd(&lista2);
            break;
        case 5:
            listC();
            scanf("%d", &lc);
            clear_screen();
            printf("Podaj szukana wartosc: ");
            scanf("%d", &x);
            clear_screen();
            element = (lc == 1) ? findEl(&lista, x) : findEl(&lista2, x);
            if (element == NULL)
            {
                printf("Brak podanego elementu na liscie\n\n");
                break;
            }
            printf("Adres szukanej wartosci [%d] to: %p\n\n", (*element)->x, *element);
            break;
        case 6:
            listC();
            scanf("%d", &lc);
            clear_screen();
            printf("Podaj wartosc do wstawienia: ");
            scanf("%d", &x);
            printf("Podaj wartosc elementu, ktorego szukasz: ");
            scanf("%d", &tmp);
            printf("Gdzie wstawic nowy element\n	1. Przed podanym\n	2. Po podanym\n");
            printf("Twoj wybor: ");
            scanf("%d", &tmp1);
            clear_screen();
            if (lc == 1)
            {
                element = findEl(&lista, tmp);
                if (tmp1 == 1 && element != NULL)
                {
                    addBefore(element, &lista, x);
                }
                else if (tmp1 == 2 && element != NULL)
                {
                    addAfter(element, x);
                }
                else
                    ("Bledny wybor!\n\n");
            }
            else
            {
                element = findEl(&lista2, tmp);
                if (tmp1 == 1 && element != NULL)
                {
                    addBefore(element, &lista2, x);
                }
                else if (tmp1 == 2 && element != NULL)
                {
                    addAfter(element, x);
                }
                else
                    ("Bledny wybor!\n\n");
            }
            break;
        case 7:
            listC();
            scanf("%d", &lc);
            clear_screen();
            printf("Podaj wartosc elementu do usuniecia: ");
            scanf("%d", &x);
            if (lc == 1)
            {
                element = findEl(&lista, x);
                remEl(element, &lista);
            }
            else
            {
                element = findEl(&lista2, x);
                remEl(element, &lista2);
            }
            clear_screen();
            break;
        case 8:
            listC();
            scanf("%d", &lc);
            clear_screen();
            (lc == 1) ? readFile(&lista) : readFile(&lista2);
            break;
        case 9:
            listC();
            scanf("%d", &lc);
            clear_screen();
            (lc == 1) ? writeFile(lista) : writeFile(lista2);
            break;
        case 10:
            listC();
            scanf("%d", &lc);
            clear_screen();
            printf("Wybierz sposob wyswietlenia listy:\n	1. Do przodu\n	2. Do tylu\n");
            printf("Twoj wybor: ");
            scanf("%d", &x);
            clear_screen();
            if (x == 1)
                (lc == 1) ? showList(lista) : showList(lista2);
            else if (x == 2)
            {
                (lc == 1) ? rShowList(lista, lista) : rShowList(lista2, lista2);
                printf("\n");
            }
            printf("\n");
            break;
        case 11:
            listC();
            scanf("%d", &lc);
            clear_screen();
            (lc == 1) ? delFrom(&lista2, &lista) : delFrom(&lista, &lista2);
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
