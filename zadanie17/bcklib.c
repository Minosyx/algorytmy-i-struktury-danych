#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define MAX_BUFF 25
#define STR2(x) #x
#define STR(X) STR2(X)

struct folder
{ // moge obslugiwac typ
    char *name;
    struct folder *firstChild;
    struct folder *next;
};

void folderInitialize(wf *root)
{
    wf q = malloc(sizeof(f));
    q->name = "/";
    q->firstChild = NULL;
    q->next = NULL;
    *root = q;
}

void traverseLevel(wf *level, const char *name, wf **element, int *result)
{
    *element = level;
    while (*level)
    {
        if (strcmp((*level)->name, name) < 0)
        {
            level = &(*level)->next;
            *element = level;
            continue;
        }
        if (strcmp((*level)->name, name) == 0)
        {
            *result = 1;
            return;
        }
        else
        {
            *result = 0;
            return;
        }
    }
    *result = 0;
}

void traverseDir(wf *root, const char *folder, const char *name, wf **element, int *sw)
{
    if (*root)
    {
        if (strcmp((*root)->name, folder) == 0)
        {
            if (*sw)
            {
                traverseLevel(&(*root)->firstChild, name, element, sw);
                return;
            }
            else
            {
                *sw = 1;
                *element = root;
                return;
            }
        }
        traverseDir(&(*root)->next, folder, name, element, sw);
        traverseDir(&(*root)->firstChild, folder, name, element, sw);
    }
    return;
}

void findFolder(wf *root, char *folder, char *name, wf **element, int *result)
{
    traverseDir(root, folder, name, element, result);
}

int findEl(wf *root, char *name, wf **element)
{
    int result = 0;
    traverseDir(root, name, name, element, &result);
    return result;
}

void addElement(wf *root, char *folder, char *name)
{
    wf q;
    wf *element = NULL;
    int sw = 1;
    findFolder(root, folder, name, &element, &sw);
    if (sw)
        return;
    q = malloc(sizeof(f));
    if (!q)
    {
        printf("Blad alokacji pamieci!\n\n");
        return;
    }
    q->firstChild = NULL;
    q->next = *element;
    q->name = malloc(sizeof(strlen(name)));
    if (!q->name)
    {
        printf("Blad alokacji pamieci!\n\n");
        return;
    }
    strcpy(q->name, name);
    *element = q;
}

void delInterior(wf *folder)
{
    wf p;
    if (*folder)
    {
        if ((*folder)->firstChild)
            delInterior(&(*folder)->firstChild);
        p = *folder;
        *folder = (*folder)->next;
        free(p);
        if (*folder)
            delInterior(folder);
    }
    return;
}

void del(wf *root, char *name)
{
    wf *element = NULL;
    wf p;
    int check;
    if (strcmp(name, "/") == 0)
    {
        delInterior(&(*root)->firstChild);
        return;
    }
    check = findEl(root, name, &element);
    if (!check)
        return;
    if (check && (*element)->firstChild)
        delInterior(&(*element)->firstChild);
    p = *element;
    *element = (*element)->next;
    free(p);
}

void printInt(wf root, int step, int depth)
{
    if (root)
    {
        for (int i = 0; i < depth; i++)
        {
            printf("|");
            for (int j = 0; j < step; j++)
            {
                printf(" ");
            }
        }
        printf("|-- %s\n", root->name);
        if (root->firstChild)
            printInt(root->firstChild, step, depth + 1);
        if (root->next)
            printInt(root->next, step, depth);
    }
}

void print(wf root)
{
    if (root->firstChild)
        printInt(root->firstChild, 4, 0);
}

void clear_screen()
{
    system("cls||clear");
}