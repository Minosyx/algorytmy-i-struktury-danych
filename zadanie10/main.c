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

int main()
{
    wel lista = 0, *element = 0;
    wdel dlista = 0, *delement = 0;
    int choice = 0, x = 0, bool = 1;
    int tmp = 0, tmp1 = 0;
    int lc = 1;
    printf("Wybierz typ listy:\n");
    printf("    1. Jednokierunkowa cykliczna\n");
    printf("    2. Dwukierunkowa cykliczna\n");
    printf("Twoj wybor: ");
    scanf("%d", &lc);
    clear_screen();
    if (lc != 1 && lc != 2)
    {
        printf("Nieprawidlowy wybor!\n");
        printf("Nastapi wybranie jednokierunkowej listy cyklicznej!\n\n");
        lc = 1;
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
            (lc == 1) ? addStart(&lista, x) : addStart_d(&dlista, x);
            break;
        case 2:
            printf("Podaj wartosc do dodania: ");
            scanf("%d", &x);
            clear_screen();
            (lc == 1) ? addEnd(&lista, x) : addEnd_d(&dlista, x);
            break;
        case 3:
            (lc == 1) ? remStart(&lista) : remStart_d(&dlista);
            break;
        case 4:
            (lc == 1) ? remEnd(&lista) : remEnd_d(&dlista);
            break;
        case 5:
            printf("Podaj szukana wartosc: ");
            scanf("%d", &x);
            clear_screen();
            if (lc == 1)
            {
                element = findEl(&lista, x);
                if (element == NULL)
                {
                    printf("Brak podanego elementu na liscie\n\n");
                    break;
                }
                printf("Adres szukanej wartosci [%d] to: %p\n\n", (*element)->x, *element);
            }
            else
            {
                delement = findEl_d(&dlista, x);
                if (delement == NULL)
                {
                    printf("Brak podanego elementu na liscie\n\n");
                    break;
                }
                printf("Adres szukanej wartosci [%d] to: %p\n\n", (*delement)->x, *delement);
            }
            break;
        case 6:
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
                delement = findEl_d(&dlista, tmp);
                if (tmp1 == 1 && delement != NULL)
                {
                    addBefore_d(delement, &dlista, x);
                }
                else if (tmp1 == 2 && delement != NULL)
                {
                    addAfter_d(delement, x);
                }
                else
                    ("Bledny wybor!\n\n");
            }
            break;
        case 7:
            printf("Podaj wartosc elementu do usuniecia: ");
            scanf("%d", &x);
            if (lc == 1)
            {
                element = findEl(&lista, x);
                remEl(element, &lista);
            }
            else
            {
                delement = findEl_d(&dlista, x);
                remEl_d(delement, &dlista);
            }
            clear_screen();
            break;
        case 8:
            (lc == 1) ? readFile(&lista) : readFile_d(&dlista);
            break;
        case 9:
            (lc == 1) ? writeFile(lista) : writeFile_d(dlista);
            break;
        case 10:
            printf("Wybierz sposob wyswietlenia listy:\n	1. Do przodu\n	2. Do tylu\n");
            printf("Twoj wybor: ");
            scanf("%d", &x);
            clear_screen();
            if (x == 1)
                (lc == 1) ? showList(lista) : showList_d(dlista);
            else if (x == 2)
            {
                (lc == 1) ? rShowList(lista, lista) : rShowList_d(dlista);
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
