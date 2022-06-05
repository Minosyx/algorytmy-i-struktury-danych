#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define INDENT 12
#define MAX_BUFF 25
#define STR2(x) #x
#define STR(X) STR2(X)

struct wezel_drzewa
{
    char *wartosc;
    struct wezel_drzewa *rodzic;
    struct wezel_drzewa *lewy;
    struct wezel_drzewa *prawy;
};

int check = 0;

ww add(ww root, char *x)
{
    if (root)
    {
        if (strcmp(x, root->wartosc) < 0){
            root->lewy = add(root->lewy, x);
            root->lewy->rodzic = root;
        }
        else if (strcmp(x, root->wartosc) >= 0){
            root->prawy = add(root->prawy, x);
            root->prawy->rodzic = root;
        }
    }
    else
    {
        ww nowy = malloc(sizeof(wezel));
        if (!nowy)
        {
            printf("Blad alokacji pamieci");
            return root;
        }
        nowy->wartosc = x;
        nowy->lewy = NULL;
        nowy->prawy = NULL;
        nowy->rodzic = NULL;
        return nowy;
    }
    return root;
}

ww *find(ww *root, char *x)
{
    if (!(*root) || strcmp(x, (*root)->wartosc) == 0)
        return root;
    else if (strcmp(x, (*root)->wartosc) < 0)
        return find(&(*root)->lewy, x);
    else
        return find(&(*root)->prawy, x);
}

ww *min(ww *root)
{
    if (*root)
        while ((*root)->lewy)
            root = &(*root)->lewy;
    return root;
}

ww *max(ww *root)
{
    if (*root)
        while ((*root)->prawy)
            root = &(*root)->prawy;
    return root;
}

ww next(ww el)
{
    if (el)
    {
        if (el->prawy)
            return *min(&el->prawy);
        ww k = el->rodzic;
        while (k && el == k->prawy)
        {
            el = k;
            k = k->rodzic;
        }
        return k;
    }
}

ww prev(ww el)
{
    if (el)
    {
        if (el->lewy)
            return *max(&el->lewy);
        ww k = el->rodzic;
        while (k && el == k->lewy)
        {
            el = k;
            k = k->rodzic;
        }
        return k;
    }
}

void del(ww *el)
{
    ww *tmp, q;
    if(!(*el)) return;
    if (!(*el)->lewy && !(*el)->prawy)
        tmp = el;
    else
    {
        if(!(*el)->lewy)
            tmp = min(&(*el)->prawy);
        else if(!(*el)->prawy)
            tmp = max(&(*el)->lewy);
        else{
            if (!check)
                tmp = max(&(*el)->lewy);
            else
                tmp = min(&(*el)->prawy);
        }
        (*el)->wartosc = (*tmp)->wartosc;
    }
    q = *tmp;

    if (!(*tmp)->lewy)
    {
        *tmp = (*tmp)->prawy;
        if (*tmp)
            (*tmp)->rodzic = *el;
    }
    else
    {
        *tmp = (*tmp)->lewy;
        if (*tmp)
            (*tmp)->rodzic = *el;
    }
    free(q);
    if (check)
        check = 0;
    else
        check = 1;
}

void printTree(ww root, int x)
{
    int i;
    if (root == NULL)
        return;
    x += INDENT;

    printTree(root->prawy, x);

    printf("\n");
    for (i = INDENT; i < x; i++)
        printf(" ");
    printf("%s\n", root->wartosc);

    printTree(root->lewy, x);
}

void printT(ww root)
{
    printTree(root, 0);
}

void clear_screen(){
    system("cls||clear");
}