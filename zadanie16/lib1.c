#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "lib.h"

#define MAX_BUFFER 25
#define START_BUFFER 1;
#define INCREMENT 1;
#define INDENT 8

struct wezel_drzewa
{
    int wartosc;
    struct wezel_drzewa *rodzic;
    struct wezel_drzewa *lewy;
    struct wezel_drzewa *prawy;
};

int check = 0;

ww add(ww root, int x)
{
    if (root)
    {
        if (x < root->wartosc)
        {
            root->lewy = add(root->lewy, x);
            root->lewy->rodzic = root;
        }
        else if (x >= root->wartosc)
        {
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

ww *find(ww *root, int x)
{
    if (!(*root) || (*root)->wartosc == x)
        return root;
    else if (x < (*root)->wartosc)
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

int del(ww *el)
{
    ww *tmp, q;
    int res = 0;
    if(!(*el)) return res;
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
    if(q) res = 1;
    free(q);
    if(check)
        check = 0;
    else
        check = 1;
    return res;
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
    printf("%d\n", root->wartosc);

    printTree(root->lewy, x);
}

void printT(ww root)
{
    printTree(root, 0);
}

void preOrderWrite(ww node, FILE *f)
{
    if (node)
    {
        fprintf(f, "%d ", node->wartosc);
        preOrderWrite(node->lewy, f);
        preOrderWrite(node->prawy, f);
    }
    else
        fprintf(f, "%c ", 'x');
    return;
}

void write(ww root)
{
    if (!root)
        return;
    FILE *f = fopen("tree.txt", "w");
    preOrderWrite(root, f);
    fclose(f);
}

void delAll(ww *root)
{
    while (*root)
    {
        del(root);
    }
}

void preOrderRead(ww *node, FILE *f, ww parent, int *ctree)
{
    if (!feof(f))
    {
        char *buff = malloc(sizeof(char) * MAX_BUFFER);
        fscanf(f, "%s", buff);
        if (strcmp(buff, "x") != 0)
        {
            ww q = malloc(sizeof(wezel));
            q->wartosc = atoi(buff);
            q->rodzic = parent;
            q->lewy = NULL;
            q->prawy = NULL;
            (*ctree)++;
            *node = q;
            preOrderRead(&(*node)->lewy, f, *node, ctree);
            preOrderRead(&(*node)->prawy, f, *node, ctree);
        }
        else
            free(buff);
        return;
    }
    return;
}

void read(ww *root, int *ctree)
{
    int c;
    *ctree = 0;
    ww parent = NULL;
    FILE *f = fopen("data.txt", "r");
    if (*root)
        delAll(root);
    c = fgetc(f);
    if (c == EOF)
    {
        fclose(f);
        return;
    }
    else
    {
        ungetc(c, f);
    }
    while (!feof(f))
    {
        preOrderRead(root, f, NULL, ctree);
    }
    fclose(f);
}

int AddToArray(ww node, int* arr, int i){
    if (node == NULL)
        return i;
    if (node->lewy)
        i = AddToArray(node->lewy, arr, i);
    arr[i] = node->wartosc;
    i++;
    if (node->prawy)
        i = AddToArray(node->prawy, arr, i);
    return i;
}

void inOrderF(ww node, ww node2, int *res, int rsw){
    if(rsw && node2->prawy)
        inOrderF(node, node2->prawy, res, 1);
    if(node->lewy)
        inOrderF(node->lewy, node2, res, 0);
    if(node2->lewy)
        inOrderF(node, node2->lewy, res, 0);
    if (*res == 0) return;
    *res = 0;
    if(node->wartosc == node2->wartosc) *res = 1;
    if (*res == 0) return;
    if(node->prawy) 
        inOrderF(node->prawy, node2, res, 1);
    return;
}

int diffTree(ww t1, ww t2){
    int res = 1;
    inOrderF(t1, t2, &res, 0);
    return res;
}

void clear_screen(){
    system("cls||clear");
}