#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

struct elem
{
    int x;
    struct elem *next;
};

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
    *l = q;
}

void addEnd(wel *l, int x)
{
    wel q = malloc(sizeof(el));
    if (q == NULL)
    {
        printf("Blad alokacji pamieci");
        return;
    }
    q->x = x;
    q->next = 0;
    while (*l)
    {
        l = &(*l)->next;
    }
    *l = q;
}

wel *findEl(wel *l, int x)
{
    if (*l == NULL)
        return NULL;
    while (((*l) != NULL) && ((*l)->x != x))
    {
        l = &(*l)->next;
    }
    if (*l && (*l)->x == x)
        return l;
    else
        return NULL;
}

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
    (*l)->next = q;
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

void remEnd(wel *l)
{
    if (*l == 0)
        return;
    while ((*l)->next)
    {
        l = &(*l)->next;
    }
    free(*l);
    *l = 0;
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
    int x = 0, c;
    wel element;
    FILE *plik = fopen("data.txt", "r");
    if (plik == 0)
    {
        printf("Brak pliku data.txt, nie mozna wczytac danych!\n\n");
        return;
    }
    if (*l != NULL)
        emptyList(l);
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
        element = malloc(sizeof(el));
        if (element == 0)
        {
            printf("Blad alokacji pamieci\n");
            return;
        }
        element->x = x;
        element->next = 0;
        while (*l)
        {
            l = &(*l)->next;
        }
        *l = element;
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

void usunniepodz(wel *l, int k)
{
    wel p;
    if (*l == 0 || k <= 0)
        return;
    while (*l)
    {
        if ((*l)->x % k)
        {
            p = *l;
            if ((*l)->next)
            {
                *l = (*l)->next;
            }
            else
                *l = 0;
            free(p);
        }
        else
            l = &(*l)->next;
    }
}