#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <limits.h>

struct elem
{
    int x;
    struct elem *next;
    struct elem *prev;
};

wel tail = NULL;

void addStart(wel *l, int x)
{
    wel q = malloc(sizeof(el));
    if (q == NULL)
    {
        printf("Blad alokacji pamieci");
        return;
    }
    q->x = x;
    q->next = *l;
    q->prev = NULL;
    if (*l)
        (*l)->prev = q;
    *l = q;
    if (tail == NULL)
        tail = q;
}

wel *findEl(wel *l, int x)
{
    if (*l == NULL)
        return NULL;
    while (((*l) != NULL) && ((*l)->x != x))
    {
        l = &(*l)->next;
    }
    if (!(*l))
        return NULL;
    else
        return l;
}

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
    q->prev = (*l)->prev;
    (*l)->prev = q;
    *l = q;
}

void addAfter(wel *l, int x)
{
    wel q = malloc(sizeof(el));
    if (q == NULL)
    {
        printf("Blad alokacji pamieci");
        return;
    }
    q->x = x;
    q->next = (*l)->next;
    q->prev = *l;
    if ((*l)->next)
        (*l)->next->prev = q;
    (*l)->next = q;
    if (*l == tail)
        tail = q;
}

void remStart(wel *l)
{
    wel p;
    if (*l != 0)
    {
        p = *l;
        if (*l == tail)
            tail = NULL;
        *l = (*l)->next;
        if (*l)
            (*l)->prev = NULL;
        free(p);
    }
}

void remEl(wel *l)
{
    wel p, prev;
    if (*l == 0)
        return;
    prev = p = *l;
    *l = p->next;
    if (*l)
        (*l)->prev = p->prev;
    else
        prev = p->prev;
    if (p == tail)
        tail = p->prev;
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

void rShowList(wel l)
{
    printf("| => ");
    while (l)
    {
        printf("%d => ", l->x);
        l = l->prev;
    }
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

void readFile(wel *l)
{
    int x = 0, c;
    wel element;
    FILE *plik = fopen("data.txt", "r");
    if (plik == 0)
    {
        printf("Brak pliku data.txt, nie mozna wczytac danych!\n\n");
        return;
    }
    if (*l != NULL)
        emptyList(l, 0);
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
        if (*l)
            addAfter(&tail, x);
        else
            addStart(l, x);
    }
    fclose(plik);
}

void emptyList(wel *l, int wart)
{
    wel p = *l;
    tail = NULL;
    while (p)
    {
        if (wart && p->x == INT_MAX)
            return;
        *l = (*l)->next;
        free(p);
        p = *l;
    }
}

void addWel(wel *l, int x, int wart)
{
    if (wart && x == INT_MAX)
        return;
    if (*l == NULL || x < (*l)->x)
        addStart(l, x);
    else if (x == (*l)->x || x == tail->x)
        return;
    else if (x > tail->x)
        addAfter(&tail, x);
    else
    {
        while ((*l)->next && x > (*l)->next->x)
        {
            if (wart && (*l)->x == INT_MAX)
                return;
            l = &(*l)->next;
        }
        if ((*l)->next && (*l)->next->x != x)
            addAfter(l, x);
    }
}

wel *getFirst(wel *l, int wart)
{
    if (*l == NULL || (wart && *l && (*l)->x == INT_MAX))
        return NULL;
    return l;
}

wel *findEl_s(wel *l, int x, int wart)
{
    if (*l == 0 || (wart && *l && (*l)->x == INT_MAX))
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

void readFile_s(wel *l, int wart)
{
    int x = 0, c;
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