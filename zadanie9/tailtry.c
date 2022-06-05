#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

struct elem
{
    int x;
    struct elem *next;
    struct elem *prev;
};

void addStart(wel *l, int x) // okej
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
}

void addEnd(wel *l, int x) // okej
{
    wel prev = NULL;
    wel q = malloc(sizeof(el));
    if (q == NULL)
    {
        printf("Blad alokacji pamieci");
        return;
    }
    q->x = x;
    q->next = NULL;
    while (*l)
    {
        prev = *l;
        l = &(*l)->next;
    }
    q->prev = prev;
    *l = q;
}

wel *findEl(wel *l, int x) // okej
{
    while (((*l) != NULL) && ((*l)->x != x))
    {
        l = &(*l)->next;
    }
    return l;
}

void addBefore(wel *l, int x) // okej
{
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

void addAfter(wel *l, int x) // okej
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
}

void remStart(wel *l)
{
    wel p;
    if (*l != 0)
    {
        p = *l;
        *l = (*l)->next;
        if (*l)
            (*l)->prev = NULL;
        free(p);
    }
}

void remEnd(wel *l) // okej
{
    wel p;
    if (*l == 0)
        return;
    // while ((*l)->next)
    // {
    //     l = &(*l)->next;
    // }
    p = *l;
    *l = (*l)->prev;
    free(p);
    if (*l)
        (*l)->next = NULL;
}

void remEl(wel *l) // okej
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
    while (l)
    {
        printf("%d => ", l->x);
        l = l->prev;
    }
    printf("|\n");
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
    wel element, prev = NULL;
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
        element = malloc(sizeof(el));
        if (element == 0)
        {
            printf("Blad alokacji pamieci\n\n");
            return;
        }
        element->x = x;
        element->next = NULL;
        while (*l)
        {
            prev = *l;
            l = &(*l)->next;
        }
        *l = element;
        element->prev = prev;
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
