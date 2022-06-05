#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

struct elem
{
    int x;
    struct elem *next;
};

void addBefore(wel *l, int x)
{
    wel q = malloc(sizeof(el));
    if (q == NULL)
    {
        printf("Blad alokacji pamieci");
        return;
    }
    q->x = x;
    q->next = *l;
    *l = q;
}

void remStart(wel *l)
{
    wel p;
    if (*l != 0)
    {
        p = *l;
        *l = (*l)->next;
        free(p);
    }
}

void addWel(wel *l, int x)
{
    if (*l == NULL)
        addBefore(l, x);
    else
    {
        while ((*l) != NULL && x > (*l)->x)
        {
            l = &(*l)->next;
        }
        addBefore(l, x);
    }
}

wel *getFirst(wel *l)
{
    return l;
}

wel *getLast(wel *l)
{
    if (*l == NULL || (*l)->next == NULL)
    {
        return l;
    }
    while ((*l)->next)
    {
        l = &(*l)->next;
    }
    return l;
}

wel *findEl(wel *l, wel *prev, int x)
{
    *prev = 0;
    if (*l == 0)
        return l;
    while (((*l) != NULL) && ((*l)->x < x))
    {
        *prev = *l;
        l = &(*l)->next;
    }
    if ((*l) && (*l)->x == x)
        return l;
    else
    {
        *prev = NULL;
        return NULL;
    }
}

void remEl(wel *l, wel *q)
{ // przerobic z wartownikiem
    wel p;
    if (*l == 0)
        return;
    else if (*q == 0)
    {
        remStart(l);
        return;
    }
    p = (*q)->next;
    if ((*q)->next && (*q)->next->next)
    {
        (*q)->next = (*q)->next->next;
    }
    else if ((*q)->next)
    {
        (*q)->next = 0;
    }
    else
        *q = 0;
    free(p);
}

void showList(wel l)
{
    while (l)
    {
        printf("%d => ", l->x);
        l = l->next;
    }
    printf("|\n");
}

void rShowList(wel l)
{
    if (l == 0)
    {
        printf("| => ");
        return;
    }
    rShowList(l->next);
    printf("%d => ", l->x);
}

void clear_screen()
{
    system("cls||clear");
}

void writeFile(wel l)
{
    FILE *plik = fopen("list.txt", "w");
    while (l)
    {
        fprintf(plik, "%d ", l->x);
        l = l->next;
    }
    fclose(plik);
}

void readFile(wel *l)
{
    int x = 0;
    FILE *plik = fopen("data.txt", "r");
    if (plik == 0)
    {
        printf("Brak pliku data.txt, nie mozna wczytac danych!\n\n");
        return;
    }
    if (*l != NULL)
        emptyList(l);
    while (!feof(plik))
    {
        fscanf(plik, "%d", &x);
        addWel(l, x);
    }
    fclose(plik);
}

void emptyList(wel *l)
{
    wel p = *l;
    while (p)
    {
        *l = (*l)->next;
        free(p);
        p = *l;
    }
}