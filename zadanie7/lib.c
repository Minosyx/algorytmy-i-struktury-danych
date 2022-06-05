#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lib.h"

struct elem
{
    int x;
    struct elem *next;
};

void addBefore(wel *l, int x, int wart)
{
    if (wart && x == INT_MAX)
        return;
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

void addWel(wel *l, int x, int wart)
{
    if (wart && x == INT_MAX)
        return;
    if (*l == NULL)
        addBefore(l, x, wart);
    else
    {
        while ((*l) != NULL && x > (*l)->x)
        {
            if (wart && (*l)->x == INT_MAX)
                return;
            l = &(*l)->next;
        }
        if (*l == NULL || (*l)->x != x)
            addBefore(l, x, wart);
    }
}

wel *getFirst(wel *l, int wart)
{
    if (*l == NULL || (wart && *l && (*l)->x == INT_MAX))
        return NULL;
    return l;
}

wel *getLast(wel *l, int wart)
{
    if (*l == NULL || (wart && *l && (*l)->x == INT_MAX))
        return NULL;
    while ((*l)->next)
    {
        if (wart && (*l)->next->x == INT_MAX)
            return l;
        l = &(*l)->next;
    }
    return l;
}

wel *findEl(wel *l, int x, int wart)
{
    if (*l == NULL || (wart && *l && (*l)->x == INT_MAX))
        return NULL;
    while (((*l) != NULL) && ((*l)->x < x))
    {
        l = &(*l)->next;
        if (wart && (*l)->x == INT_MAX)
            return NULL;
    }
    if ((*l) && (*l)->x == x)
        return l;
    else
    {
        return NULL;
    }
}

void remEl(wel *q)
{
    wel p;
    if (*q == NULL)
        return;
    p = *q;
    *q = (*q)->next;
    free(p);
}

void showList(wel l, int wart)
{
    while (l)
    {
        if (wart && l->x == INT_MAX)
            break;
        printf("%d => ", l->x);
        l = l->next;
    }
    printf("|\n");
}

void rShowList(wel l, int wart)
{
    if (l == 0 || (wart && l->x == INT_MAX))
    {
        printf("| => ");
        return;
    }
    rShowList(l->next, wart);
    printf("%d => ", l->x);
}

void clear_screen()
{
    system("cls||clear");
}

void writeFile(wel l, int wart)
{
    FILE *plik = fopen("list.txt", "w");
    while (l)
    {
        if (wart && l->x == INT_MAX)
            break;
        fprintf(plik, "%d ", l->x);
        l = l->next;
    }
    fclose(plik);
}

void readFile(wel *l, int wart)
{
    int x, c;
    FILE *plik = fopen("data.txt", "r");
    if (plik == 0)
    {
        printf("Brak pliku data.txt, nie mozna wczytac danych!\n\n");
        return;
    }
    if (wart && *l && (*l)->x != INT_MAX)
        emptyList(l, wart);
    else if (*l)
        emptyList(l, wart);
    c = fgetc(plik);
    if (c == EOF)
    {
        fclose(plik);
        return;
    }
    else
    {
        ungetc(c, plik);
    }
    while (!feof(plik))
    {
        fscanf(plik, "%d", &x);
        addWel(l, x, wart);
    }
    fclose(plik);
}

void emptyList(wel *l, int wart)
{
    wel p = *l;
    while (p)
    {
        if (wart && p->x == INT_MAX)
            return;
        *l = (*l)->next;
        free(p);
        p = *l;
    }
}

void merge(wel *p, wel *q, int wart)
{
    if (*p == 0 || *q == 0)
        return;
    wel head;
    wel tmp, tmp2;
    if ((*q)->x < (*p)->x)
    {
        tmp = *q;
        *q = *p;
        *p = tmp;
    }
    head = *p;
    while (*q)
    {
        while ((*p)->next && (*p)->next->x <= (*q)->x)
        {
            *p = (*p)->next;
        }
        if (wart && (*p)->x == INT_MAX)
            break;
        tmp = (*p)->next;
        (*p)->next = *q;
        if (!tmp)
        {
            *q = NULL;
            break;
        }
        while ((*q)->next && (*q)->next->x <= tmp->x)
        {
            *q = (*q)->next;
        }
        if (wart && (*q)->x == INT_MAX)
            break;
        tmp2 = (*q)->next;
        (*q)->next = tmp;
        *p = (*q)->next;
        *q = tmp2;
    }
    *p = head;
}