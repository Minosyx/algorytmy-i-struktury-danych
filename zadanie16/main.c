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
    printf("11 - porownaj drzewa\n");
    printf("0 - zakoncz program\n");
    printf("Twoj wybor: ");
}

void treeCh(){
    printf("Wybierz numer drzewa:\n");
    printf("\t1. Drzewo\n");
    printf("\t2. Drzewo\n");
    printf("Twoj wybor: ");
}

int main()
{
    ww tree = NULL;
    ww tree2 = NULL;
    int x, sw = 0;
    int choice = 0, bool = 1;
    int ctree = 0, ctree2 = 0;
    ww *element = NULL;
    ww tmp = NULL;
    int ret = 0;

    while (bool)
    {
        printOptions();
        scanf("%d", &choice);
        clear_screen();
        switch (choice)
        {
        case 1:
            treeCh();
            scanf("%d", &sw);
            clear_screen();
            printf("Podaj wartosc do dodania: ");
            scanf("%d", &x);
            clear_screen();
            if(sw == 2){
                if (!tree2)
                    tree2 = add(tree2, x);
                else
                    add(tree2, x);
                ctree2++;
            }else{
                if (!tree)
                    tree = add(tree, x);
                else
                    add(tree, x);
                ctree++;
            }
            break;
        case 2:
            treeCh();
            scanf("%d", &sw);
            clear_screen();
            printf("Podaj wartosc do usuniecia: ");
            scanf("%d", &x);
            clear_screen();
            element = (sw == 2) ? find(&tree2, x) : find(&tree, x);
            ret = del(element);
            if (ret && sw == 2) ctree2--;
            else if (ret) ctree--;
            break;
        case 3:
            treeCh();
            scanf("%d", &sw);
            clear_screen();
            printf("Podaj wartosc szukana: ");
            scanf("%d", &x);
            clear_screen();
            element = (sw == 2) ? find(&tree2, x) : find(&tree, x);
            if (*element)
                printf("Element o wartosci %d lezy pod adresem %p\n\n", (*element)->wartosc, (*element));
            else
                printf("Brak elementu o podanej wartosci w drzewie!\n\n");
            break;
        case 4:
            treeCh();
            scanf("%d", &sw);
            clear_screen();
            element = (sw == 2) ? min(&tree2) : min(&tree);
            if (*element)
                printf("Wartosc najmniejsza to %d\n\n", (*element)->wartosc);
            else
                printf("Drzewo jest puste!\n\n");
            break;
        case 5:
            treeCh();
            scanf("%d", &sw);
            clear_screen();
            element = (sw == 2) ? max(&tree2) : max(&tree);
            if (*element)
                printf("Wartosc najwieksza to %d\n\n", (*element)->wartosc);
            else
                printf("Drzewo jest puste!\n\n");
            break;
        case 6:
            treeCh();
            scanf("%d", &sw);
            clear_screen();
            printf("Podaj wartosc dla ktorej szukamy poprzednika: ");
            scanf("%d", &x);
            clear_screen();
            element = (sw == 2) ? find(&tree2, x) : find(&tree, x);
            if (*element)
            {
                tmp = prev(*element);
                if (tmp)
                    printf("Poprzednikiem jest element o wartosci %d\n\n", tmp->wartosc);
                else
                    printf("Brak poprzednika dla podanej wartosci\n\n");
            }
            else
                printf("Brak elementu o podanej wartosci w drzewie!\n\n");
            break;
        case 7:
            treeCh();
            scanf("%d", &sw);
            clear_screen();
            printf("Podaj wartosc dla ktorej szukamy nastepnika: ");
            scanf("%d", &x);
            clear_screen();
            element = (sw == 2) ? find(&tree2, x) : find(&tree, x);
            if (*element)
            {
                tmp = next(*element);
                if (tmp)
                    printf("Nastepnikiem jest element o wartosci %d\n\n", tmp->wartosc);
                else
                    printf("Brak nastepnika dla podanej wartosci\n\n");
            }
            else
                printf("Brak elementu o podanej wartosci w drzewie!\n\n");
            break;
        case 8:
            treeCh();
            scanf("%d", &sw);
            clear_screen();
            (sw == 2) ? printT(tree2) : printT(tree);
            printf("\n\n");
            break;
        case 9:
            treeCh();
            scanf("%d", &sw);
            clear_screen();
            (sw == 2) ? write(tree2) : write(tree);
            break;
        case 10:
            treeCh();
            scanf("%d", &sw);
            clear_screen();
            (sw == 2) ? read(&tree2, &ctree2) : read(&tree, &ctree);
            break;
        case 11:
            if (ctree != ctree2) {
                printf("Drzewa NIE skladaja sie z takiego samego ciagu liczb!\n\n");
                break;
            }
            x = diffTree(tree, tree2, ctree);
            if (x) printf("Drzewa skladaja sie z takiego samego ciagu liczb!\n\n");
            else printf("Drzewa NIE skladaja sie z takiego samego ciagu liczb!\n\n");
            break;
        case 0:
            bool = 0;
            break;
        default:
            printf("Podano bledna opcje!\n\n");
        }
    }
}