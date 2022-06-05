#include <stdio.h>
#include "lib.c"

void printOptions()
{
    printf("Nastepna operacja:\n");
    printf("1 - dodaj element do drzewa\n");
    printf("2 - usun element z drzewa\n");
    printf("3 - szukaj elementu w drzewie\n");
    printf("4 - pokaz drzewo\n");
    printf("0 - zakoncz program\n");
    printf("Twoj wybor: ");
}

int main()
{
    wf tree = NULL;
    char *x = (char *)calloc(MAX_BUFF + 1, sizeof(char));
    char *tmp = (char *)calloc(MAX_BUFF + 1, sizeof(char));
    int choice = 0, bool = 1;
    wf *element = NULL;
    int ch;

    folderInitialize(&tree);

    while (bool)
    {
        printOptions();
        scanf("%d", &choice);
        clear_screen();
        switch (choice)
        {
        case 1:
            printf("Podaj, do ktorego folderu dodac element (/ dla katalogu glownego): ");
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            fgets(tmp, MAX_BUFF, stdin);
            sscanf(tmp, "%" STR(MAX_BUFF) "[^\n]", tmp);
            printf("Podaj wartosc do dodania: ");
            fgets(x, MAX_BUFF, stdin);
            sscanf(x, "%" STR(MAX_BUFF) "[^\n]", x);
            clear_screen();
            addElement(&tree, tmp, x);
            break;
        case 2:
            printf("Podaj wartosc do usuniecia: ");
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            fgets(x, MAX_BUFF, stdin);
            sscanf(x, "%" STR(MAX_BUFF) "[^\n]", x);
            clear_screen();
            del(&tree, x);
            break;
        case 3:
            printf("Podaj wartosc szukana: ");
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            fgets(x, MAX_BUFF, stdin);
            sscanf(x, "%" STR(MAX_BUFF) "[^\n]", x);
            clear_screen();
            findEl(&tree, x, &element);
            if (*element)
                printf("Element o wartosci %s lezy pod adresem %p\n\n", (*element)->name, (*element));
            else
                printf("Brak elementu o podanej wartosci w drzewie!\n\n");
            break;
        case 4:
            print(tree);
            printf("\n\n");
            break;
        case 0:
            bool = 0;
            break;
        default:
            printf("Podano bledna opcje!\n\n");
        }
    }
    free(x);
    free(tmp);
}