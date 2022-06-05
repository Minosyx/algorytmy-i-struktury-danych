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
    wel glowa = *l;
    q->x = x;
    if (glowa)
        q->next = glowa;
    else
        q->next = q;
    while (*l && (*l)->next != glowa)
    {
        *l = (*l)->next;
    }
    if (glowa)
        (*l)->next = q;
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
    wel glowa = *l;
    q->x = x;
    if (glowa)
        q->next = glowa;
    else
        q->next = q;
    if (*l)
        l = &(*l)->next;
    while (*l != glowa)
    {
        l = &(*l)->next;
    }
    *l = q;
}

wel *findEl(wel *l, int x)
{
    wel glowa = *l;
    if (*l == 0)
        return NULL;
    if ((*l)->x == x)
        return l;
    do
    {
        l = &(*l)->next;
    } while (((*l) != glowa) && ((*l)->x != x));
    if ((*l)->x == x)
        return l;
    else
        return NULL;
}

void addBefore(wel *l, wel *head, int x)
{
    if (*l == *head)
    {
        addStart(head, x);
        return;
    }
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
    wel glowa = *l;
    if (*l == 0)
        return;
    *l = (*l)->next;
    while (*l != glowa)
    {
        l = &(*l)->next;
    }
    if (*l == (*l)->next)
    {
        free(*l);
        *l = 0;
    }
    else
    {
        glowa = glowa->next;
        free(*l);
        *l = glowa;
    }
}

void remEnd(wel *l)
{
    wel glowa = *l;
    if (*l == 0)
        return;
    while ((*l)->next != glowa)
    {
        l = &(*l)->next;
    }
    if (*l == (*l)->next)
    {
        free(*l);
        *l = 0;
    }
    else
    {
        free(*l);
        *l = glowa;
    }
}

void remEl(wel *q, wel *l)
{
    wel p;
    if (q == NULL)
        return;
    if (*q == *l && *l == (*l)->next)
    {
        free(*l);
        *l = 0;
        return;
    }
    else if (*q == *l)
    {
        remStart(l);
        return;
    }
    p = *q;
    *q = (*q)->next;
    free(p);
}

void showList(wel l)
{
    wel glowa = l;
    while (l)
    {
        printf("%d => ", l->x);
        l = l->next;
        if (glowa == l)
            break;
    }
    printf("|\n");
}

void rShowList(wel l, wel glowa)
{
    if (l == 0)
    {
        printf("| => ");
        return;
    }
    else if (l->next == glowa)
    {
        printf("| => ");
        printf("%d => ", l->x);
        return;
    }
    rShowList(l->next, glowa);
    printf("%d => ", l->x);
}

void clear_screen()
{
    system("cls||clear");
}

void writeFile(wel l)
{
    wel glowa = l;
    FILE *plik = fopen("list.txt", "w");
    while (l)
    {
        fprintf(plik, "%d ", l->x);
        l = l->next;
        if (l == glowa)
            break;
    }
    fclose(plik);
}

void readFile(wel *l)
{
    int x = 0, c, sw = 1;
    wel element, glowa;
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
            printf("Blad alokacji pamieci\n\n");
            return;
        }
        if (sw)
        {
            glowa = element;
            sw = 0;
        }
        element->x = x;
        element->next = 0;
        while (*l)
        {
            l = &(*l)->next;
        }
        *l = element;
    }
    (*l)->next = glowa;
    fclose(plik);
}

void emptyList(wel *l)
{
    wel p, glowa = *l;
    if (*l == 0)
        return;
    *l = (*l)->next;
    p = *l;
    while (p)
    {
        if (glowa == *l)
        {
            free(*l);
            *l = 0;
            return;
        }
        *l = (*l)->next;
        free(p);
        p = *l;
    }
}

void delFrom(wel *l1, wel *l2)
{
    if (*l1 == 0 || *l2 == 0)
        return;
    wel h1 = *l1;
    do
    {
        wel *h2 = l2;
        h2 = &(*h2)->next;
        while (*l2)
        {
            if (*l2 && (*l1)->x == (*h2)->x)
            {
                remEl(h2, l2);
            }
            else if (*l2 == *h2)
                break;
            else
                h2 = &(*h2)->next;
        }
        *l1 = (*l1)->next;
    } while (*l1 != h1);
}