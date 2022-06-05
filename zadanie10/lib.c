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

// lista dwukierunkowa cykliczna

struct delem
{
    int x;
    struct delem *next;
    struct delem *prev;
};

void addStart_d(wdel *l, int x)
{
    wdel q = malloc(sizeof(del));
    if (q == NULL)
    {
        printf("Blad alokacji pamieci");
        return;
    }
    wdel glowa = *l;
    q->x = x;
    if (glowa)
    {
        q->next = glowa;
        q->prev = glowa->prev;
        glowa->prev->next = q;
        glowa->prev = q;
    }
    else
    {
        q->next = q;
        q->prev = q;
    }
    *l = q;
}

void addEnd_d(wdel *l, int x)
{
    wdel q = malloc(sizeof(del));
    if (q == NULL)
    {
        printf("Blad alokacji pamieci");
        return;
    }
    wdel glowa = *l;
    q->x = x;
    if (glowa)
    {
        l = &glowa->prev->next;
        q->next = glowa;
        q->prev = glowa->prev;
        glowa->prev = q;
    }
    else
    {
        q->next = q;
        q->prev = q;
    }
    *l = q;
}

wdel *findEl_d(wdel *l, int x)
{
    wdel glowa = *l;
    if (*l == 0)
        return NULL;
    if ((*l)->x == x)
        return &(*l)->prev->next;
    do
    {
        l = &(*l)->next;
    } while (((*l) != glowa) && ((*l)->x != x));
    if ((*l)->x == x)
        return l;
    else
        return NULL;
}

void addBefore_d(wdel *l, wdel *head, int x)
{
    if(*l == *head)
    {
        addStart_d(head, x);
        return;
    }
    wdel q = malloc(sizeof(del));
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

void addAfter_d(wdel *l, int x)
{
    wdel q = malloc(sizeof(del));
    if (q == NULL)
    {
        printf("Blad alokacji pamieci");
        return;
    }
    q->x = x;
    q->next = (*l)->next;
    q->prev = *l;
    (*l)->next->prev = q;
    (*l)->next = q;
}

void remStart_d(wdel *l)
{
    wdel glowa = *l;
    if (*l == 0)
        return;
    if (*l == (*l)->next)
    {
        free(*l);
        *l = 0;
        return;
    }
    (*l)->prev->next = (*l)->next;
    (*l)->next->prev = (*l)->prev;
    (*l) = (*l)->next;
    free(glowa);
}

void remEnd_d(wdel *l)
{
    if (*l == 0)
        return;
    wdel p = (*l)->prev;
    if (*l == (*l)->next)
    {
        free(*l);
        *l = 0;
        return;
    }
    (*l)->prev = (*l)->prev->prev;
    (*l)->prev->next = (*l);
    free(p);
}

void remEl_d(wdel *q, wdel *l)
{
    wdel p;
    if (q == NULL)
        return;
    if (*q == (*q)->next)
    {
        free(*q);
        *l = 0;
        return;
    }
    else if (*q == *l)
        *l = (*l)->next;
    p = *q;
    (*q)->next->prev = (*q)->prev;
    *q = (*q)->next;
    free(p);
}

void showList_d(wdel l)
{
    wdel glowa = l;
    while (l)
    {
        printf("%d => ", l->x);
        l = l->next;
        if (glowa == l)
            break;
    }
    printf("|\n");
}

void rShowList_d(wdel l)
{
    wdel glowa = l;
    printf("| => ");
    while (l)
    {
        l = l->prev;
        printf("%d => ", l->x);
        if (glowa == l)
            break;
    }
    printf("\n");
}

void writeFile_d(wdel l)
{
    wdel glowa = l;
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

void readFile_d(wdel *l)
{
    int x = 0, c, sw = 1;
    FILE *plik = fopen("data.txt", "r");
    if (plik == 0)
    {
        printf("Brak pliku data.txt, nie mozna wczytac danych!\n\n");
        return;
    }
    if (*l != NULL)
        emptyList_d(l);
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
        addEnd_d(l, x);
    }
    fclose(plik);
}

void emptyList_d(wdel *l)
{
    wdel p, glowa = *l;
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