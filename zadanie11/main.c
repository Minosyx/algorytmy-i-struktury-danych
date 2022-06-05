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
    printf("11 - usun co k-ty\n");
    printf("0 - zakoncz dzialanie programu\n");
    printf("Twoj wybor: ");
}

int main()
{
    wel lista = 0, *element = 0;
    int choice = 0, x = 0, bool = 1;
    int tmp = 0, tmp1 = 0;
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
            addStart(&lista, x);
            break;
        case 2:
            printf("Podaj wartosc do dodania: ");
            scanf("%d", &x);
            clear_screen();
            addEnd(&lista, x);
            break;
        case 3:
            remStart(&lista);
            break;
        case 4:
            remEnd(&lista);
            break;
        case 5:
            printf("Podaj szukana wartosc: ");
            scanf("%d", &x);
            clear_screen();
            element = findEl(&lista, x);
            if (element == NULL)
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
            clear_screen();
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
            break;
        case 7:
            printf("Podaj wartosc elementu do usuniecia: ");
            scanf("%d", &x);
            element = findEl(&lista, x);
            remEl(element, &lista);
            clear_screen();
            break;
        case 8:
            readFile(&lista);
            break;
        case 9:
            writeFile(lista);
            break;
        case 10:
            printf("Wybierz sposob wyswietlenia listy:\n	1. Do przodu\n	2. Do tylu\n");
            printf("Twoj wybor: ");
            scanf("%d", &x);
            clear_screen();
            if (x == 1)
                showList(lista);
            else if (x == 2)
            {
                rShowList(lista, lista);
                printf("\n");
            }
            printf("\n");
            break;
        case 11:
            printf("Od jakiego elementu startowac?\n");
            printf("Twoj wybor: ");
            scanf("%d", &x);
            clear_screen();
            printf("Podaj krok: ");
            scanf("%d", &tmp);
            clear_screen();
            element = findEl(&lista, x);
            if (element && tmp > 0){
                delStep(element, &lista, tmp);
                printf("Wynikiem jest %d \n\n", lista->x);
            }
            else printf("Brak podanej liczby na liscie lub podano nieodpowiedni krok!\n\n");
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
