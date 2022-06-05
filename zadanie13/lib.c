#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

struct elem
{
    int x;
    int priority;
    struct elem *next;
};

wel createQ(int x, int p)
{
    wel new_Q = malloc(sizeof(el));
    if (!new_Q)
    {
        printf("Blad alokacji pamieci!\n\n");
        return NULL;
    }
    new_Q->x = x;
    new_Q->priority = p;
    new_Q->next = NULL;
    return new_Q;
}

void add(wel *q, wel new_Q)
{
    while (*q && (*q)->priority >= new_Q->priority)
    {
        q = &(*q)->next;
    }
    new_Q->next = NULL;
    if (*q)
        new_Q->next = *q;
    *q = new_Q;
}

wel getHighest(wel *q)
{
    if (!(*q))
        return NULL;
    else
    {
        wel tmp = *q;
        *q = (*q)->next;
        return tmp;
    }
}

void changePriority(wel *q, wel *el, int newP)
{
    if (!(*q)->next)
    {
        (*q)->priority = newP;
        return;
    }
    (*el)->priority = newP;
    wel tmp = *el;
    *el = (*el)->next;
    if (*el && tmp->priority <= (*el)->priority)
        add(&tmp, tmp);
    else
        add(q, tmp);
}

void emptyCheck(wel q)
{
    if (q)
        printf("Kolejka nie jest pusta!\n\n");
    else
        printf("Kolejka jest pusta!\n\n");
}

void printQueue(wel q)
{
    printf("Kolejka wyswietlana jest w postaci {wartosc}[priorytet]\n");
    while (q)
    {
        printf("{%d}[%d] <= ", q->x, q->priority);
        q = q->next;
    }
    printf("|\n");
}

wel *findEl(wel *q, int x, int p)
{
    if (!(*q))
        return NULL;
    while (*q && ((*q)->x != x || (*q)->priority != p))
    {
        q = &(*q)->next;
    }
    if (*q && (*q)->x == x && (*q)->priority == p)
        return q;
    else
        return NULL;
}

void clear_screen()
{
    system("cls||clear");
}