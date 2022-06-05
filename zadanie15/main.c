#include <stdio.h>
#include "lib.c"

void printOptions()
{
    printf("Nastepna operacja:\n");
    printf("1 - dodaj element do drzewa\n");
    printf("2 - usun element z drzewa\n");
    printf("3 - szukaj elementu w drzewie\n");
    printf("4 - znajdz minimum\n");
    printf("5 - znajdz maksimum\n");
    printf("6 - znajdz poprzednika\n");
    printf("7 - znajdz nastepnika\n");
    printf("8 - pokaz drzewo\n");
    printf("9 - zapisz drzewo do pliku\n");
    printf("10 - wczytaj drzewo z pliku\n");
    printf("0 - zakoncz program\n");
    printf("Twoj wybor: ");
}

int main()
{
    ww tree = NULL;
    char *x = calloc(sizeof(char), MAX_BUFF + 1);
    char *value;
    int choice = 0, bool = 1;
    ww *element = NULL;
    ww tmp = NULL;
    int ch;

    while (bool)
    {
        printOptions();
        scanf("%d", &choice);
        clear_screen();
        switch (choice)
        {
        case 1:
            value = calloc(sizeof(char), MAX_BUFF + 1);
            printf("Podaj wartosc do dodania: ");
            while ((ch = getchar()) != '\n' && ch != EOF);
            fgets(value, MAX_BUFF, stdin);
            sscanf(value, "%" STR(MAX_BUFF) "s", value);
            clear_screen();
            if (!tree)
                tree = add(tree, value);
            else
                add(tree, value);
            break;
        case 2:
            printf("Podaj wartosc do usuniecia: ");
            scanf("%" STR(MAX_BUFF) "s", x);
            clear_screen();
            element = find(&tree, x);
            del(element);
            break;
        case 3:
            printf("Podaj wartosc szukana: ");
            scanf("%" STR(MAX_BUFF) "s", x);
            clear_screen();
            element = find(&tree, x);
            if (*element)
                printf("Element o wartosci %s lezy pod adresem %p\n\n", (*element)->wartosc, (*element));
            else
                printf("Brak elementu o podanej wartosci w drzewie!\n\n");
            break;
        case 4:
            element = min(&tree);
            if (*element)
                printf("Wartosc najmniejsza to %s\n\n", (*element)->wartosc);
            else
                printf("Drzewo jest puste!\n\n");
            break;
        case 5:
            element = max(&tree);
            if (*element)
                printf("Wartosc najwieksza to %s\n\n", (*element)->wartosc);
            else
                printf("Drzewo jest puste!\n\n");
            break;
        case 6:
            printf("Podaj wartosc dla ktorej szukamy poprzednika: ");
            scanf("%" STR(MAX_BUFF) "s", x);
            clear_screen();
            element = find(&tree, x);
            if (*element)
            {
                tmp = prev(*element);
                if (tmp)
                    printf("Poprzednikiem jest element o wartosci %s\n\n", tmp->wartosc);
                else
                    printf("Brak poprzednika dla podanej wartosci\n\n");
            }
            else
                printf("Brak elementu o podanej wartosci w drzewie!\n\n");
            break;
        case 7:
            printf("Podaj wartosc dla ktorej szukamy nastepnika: ");
            scanf("%" STR(MAX_BUFF) "s", x);
            clear_screen();
            element = find(&tree, x);
            if (*element)
            {
                tmp = next(*element);
                if (tmp)
                    printf("Nastepnikiem jest element o wartosci %s\n\n", tmp->wartosc);
                else
                    printf("Brak nastepnika dla podanej wartosci\n\n");
            }
            else
                printf("Brak elementu o podanej wartosci w drzewie!\n\n");
            break;
        case 8:
            printT(tree);
            printf("\n\n");
            break;
        case 9:
            write(tree);
            break;
        case 10:
            read(&tree);
            break;
        case 0:
            bool = 0;
            break;
        default:
            printf("Podano bledna opcje!\n\n");
        }
    }
}