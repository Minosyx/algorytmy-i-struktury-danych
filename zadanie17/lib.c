#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define MAX_BUFF 25
#define STR2(x) #x
#define STR(X) STR2(X)

struct file{
    struct container *next;
};

struct directory{
    struct container *firstChild;
    struct container *next;
};

struct container{
    char *name;
    union{
        f file;
        d dir;
    };
    int type;
};

void folderInitialize(wcont *root){
    wcont q = malloc(sizeof(cont));
    q->name = "/";
    q->dir.firstChild = NULL;
    q->dir.next = NULL;
    q->type = 0;
    *root = q;
}

void traverseLevel(wcont *level, const char *name, const int type, wcont **element, int *result){
    *element = level;
    while(*level){
        if(type == 0 && (*level)->type == 1){
            break;
        }
        if(type == 1 && (*level)->type == 0){
            level = &(*level)->dir.next;
            *element = level;
            continue;
        }
        if(strcmp((*level)->name, name) < 0){
            if((*level)->type == 0)
                level = &(*level)->dir.next;
            else
                level = &(*level)->file.next;
            *element = level;
            continue;
        }
        if (strcmp((*level)->name, name) == 0){
            *result = 1;
            return;
        }
        else {
            *result = 0;
            return;
        }
    }
    *result = 0;
}

void traverseDir(wcont *root, const char *folder, const char *name, const int type, wcont **element, int *sw, const int opt){
    if(*root){
        if(strcmp((*root)->name, folder) == 0){
            if(*sw && (*root)->type == 0){
                traverseLevel(&(*root)->dir.firstChild, name, type, element, sw);
                return;
            }
            else if (type == (*root)->type) {
                *sw = 1;
                *element = root;
                return;
            }
            if(!opt) return;
        }
        if((*root)->type == 0)
            traverseDir(&(*root)->dir.next, folder, name, type, element, sw, opt);
        else if(opt)
            traverseDir(&(*root)->file.next, folder, name, type, element, sw, opt);
        if ((*root)->type == 0)
            traverseDir(&(*root)->dir.firstChild, folder, name, type, element, sw, opt);
    }
    return;
}

void findFolder(wcont* root, const char *folder, const char *name, const int type, wcont **element, int *result){
    traverseDir(root, folder, name, type, element, result, 0);
}

int findEl(wcont *root, const char *name, const int type, wcont **element){
    int result = 0;
    traverseDir(root, name, name, type, element, &result, 1);
    return result;
}

void addElement(wcont *root, const char *folder, char *name, const int type){
    wcont q;
    wcont *element = NULL;
    int sw = 1;
    findFolder(root, folder, name, type, &element, &sw); // sprawdzic czy folder
    if(sw) {
        free(name);
        return;
    }
    q = malloc(sizeof(cont));
    if(!q){
        printf("Blad alokacji pamieci!\n\n");
        return;
    }
    // q->name = malloc(sizeof(strlen(name)) + 1);
    // if (!q->name)
    // {
    //     printf("Blad alokacji pamieci!\n\n");
    //     return;
    // }
    // strcpy(q->name, name);
    q->name = name;
    if (type){
        q->file.next = *element;
    }
    else{
        q->dir.firstChild = NULL;
        q->dir.next = *element;
    }
    q->type = type;
    *element = q;
}

void delInterior(wcont *folder){
    wcont p;
    if(*folder){
        if((*folder)->type == 0 && (*folder)->dir.firstChild) delInterior(&(*folder)->dir.firstChild);
        p = *folder;
        if((*folder)->type == 0)
            *folder = (*folder)->dir.next;
        else
            *folder = (*folder)->file.next;
        free(p);
        if(*folder) delInterior(folder);
    }
    return;
}

void del(wcont *root, const char* name, const int type){
    wcont *element = NULL;
    wcont p;
    int check;
    if(strcmp(name, "/") == 0 && type == 0) {
        delInterior(&(*root)->dir.firstChild);
        return;
    }
    check = findEl(root, name, type, &element);
    if (!check) return;
    if(check && type == 0)
        delInterior(&(*element)->dir.firstChild);
    p = *element;
    if((*element)->type == 0)
        *element = (*element)->dir.next;
    else
        *element = (*element)->file.next;
    free(p);
}

void green(){
    printf("\033[1;32m");
}

void reset(){
    printf("\033[0m");
}

void printInt(wcont root, int step, int depth){
    if(root){
        for(int i = 0; i < depth; i++){
            printf("|");
            for(int j = 0; j < step; j++){
                printf(" ");
            }
        }
        printf("|-- ");
        if(root->type == 0) green();
        printf("%s\n", root->name);
        reset();
        if(root->type == 0 && root->dir.firstChild) printInt(root->dir.firstChild, step, depth + 1);
        if(root->type == 0 && root->dir.next) printInt(root->dir.next, step, depth);
        else if(root->type == 1 && root->file.next) printInt(root->file.next, step, depth);
    }
}

void print(wcont root){
    if(root->dir.firstChild)
        printInt(root->dir.firstChild, 4, 0);
}

void clear_screen(){
    system("cls||clear");
}