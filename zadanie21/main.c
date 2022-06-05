#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib.c"

void ps(char *s)
{
    printf("%*s%*s", 10 + strlen(s) / 2, s, 10 - strlen(s) / 2, "");
}

int main(){
    srand(time(NULL));
    int cbubbleMax = 0, cbubbleMin = 0;
    float cbubbleAvg = 0;
    int cinsertMax = 0, cinsertMin = 0;
    float cinsertAvg = 0;
    int cshellMin = 0, cshellMax = 0;
    float cshellAvg = 0;
    int cquickMin = 0, cquickMax = 0;
    float cquickAvg = 0;
    int sbubbleMax = 0, sbubbleMin = 0;
    float sbubbleAvg = 0;
    int sinsertMax = 0, sinsertMin = 0;
    float sinsertAvg = 0;
    int sshellMin = 0, sshellMax = 0;
    float sshellAvg = 0;
    int squickMin = 0, squickMax = 0;
    float squickAvg = 0;
    int c, s;
    int i, k, size;
    int *tab;
    int *sort;
    int repetition = uniform_distribution(90, 110);
    char str[12];
    for(i = 0; i < repetition; i++){
        size = uniform_distribution(9000, 11000);
        tab = calloc(sizeof(int), size);
        sort = calloc(sizeof(int), size);
        for (k = 0; k < size; k++)
        {
            tab[k] = rand();
        }
        memcpy(sort, tab, size * sizeof(int));
        c = 0;
        s = 0;
        bubbleSort(sort, size, &c, &s);
        if(cbubbleMin > c || i == 0) cbubbleMin = c;
        if(cbubbleMax < c) cbubbleMax = c;
        if(sbubbleMin > s || i == 0) sbubbleMin = s;
        if(sbubbleMax < s) sbubbleMax = s;
        cbubbleAvg += c;
        sbubbleAvg += s;
        memcpy(sort, tab, size * sizeof(int));
        c = 0;
        s = 0;
        insertionSort(sort, size, &c, &s);

        if(cinsertMin > c || i == 0) cinsertMin = c;
        if(cinsertMax < c) cinsertMax = c;
        if(sinsertMin > s || i == 0) sinsertMin = s;
        if(sinsertMax < s) sinsertMax = s;
        cinsertAvg += c;
        sinsertAvg += s;
        memcpy(sort, tab, size * sizeof(int));
        c = 0;
        s = 0;
        shellSort(sort, size, &c, &s);
        if(cshellMin > c || i == 0) cshellMin = c;
        if(cshellMax < c) cshellMax = c;
        if(sshellMin > s || i == 0) sshellMin = s;
        if(sshellMax < s) sshellMax = s;
        cshellAvg += c;
        sshellAvg += s;
        memcpy(sort, tab, size * sizeof(int));
        c = 0;
        s = 0;
        quickSort(sort, 0, size - 1, &c, &s);
        if(cquickMin > c || i == 0) cquickMin = c;
        if(cquickMax < c) cquickMax = c;
        if(squickMin > s || i == 0) squickMin = s;
        if(squickMax < s) squickMax = s;
        cquickAvg += c;
        squickAvg += s;
        free(sort);
        free(tab);
    }  
    cbubbleAvg /= repetition;
    sbubbleAvg /= repetition;
    cinsertAvg /= repetition;
    sinsertAvg /= repetition;
    cshellAvg /= repetition;
    sshellAvg /= repetition;
    cquickAvg /= repetition;
    squickAvg /= repetition;

    printf("%20s|", ""); 
    ps("Bubble"); 
    printf("|"); 
    ps("Insert"); 
    printf("|"); 
    ps("Shell"); 
    printf("|"); 
    ps("Quick"); 
    printf("|\n");

    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Max porownan        |"); 
    sprintf(str, "%d", cbubbleMax);
    ps(str);
    printf("|");
    sprintf(str, "%d", cinsertMax);
    ps(str);
    printf("|");
    sprintf(str, "%d", cshellMax);
    ps(str);
    printf("|");
    sprintf(str, "%d", cquickMax);
    ps(str);
    printf("|\n");

    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Min porownan        |");
    sprintf(str, "%d", cbubbleMin);
    ps(str);
    printf("|");
    sprintf(str, "%d", cinsertMin);
    ps(str);
    printf("|");
    sprintf(str, "%d", cshellMin);
    ps(str);
    printf("|");
    sprintf(str, "%d", cquickMin);
    ps(str);
    printf("|\n");

    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Srednia porownan    |");
    sprintf(str, "%.2f", cbubbleAvg);
    ps(str);
    printf("|");
    sprintf(str, "%.2f", cinsertAvg);
    ps(str);
    printf("|");
    sprintf(str, "%.2f", cshellAvg);
    ps(str);
    printf("|");
    sprintf(str, "%.2f", cquickAvg);
    ps(str);
    printf("|\n");

    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Max podmian         |");
    sprintf(str, "%d", sbubbleMax);
    ps(str);
    printf("|");
    sprintf(str, "%d", sinsertMax);
    ps(str);
    printf("|");
    sprintf(str, "%d", sshellMax);
    ps(str);
    printf("|");
    sprintf(str, "%d", squickMax);
    ps(str);
    printf("|\n");

    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Min podmian         |");
    sprintf(str, "%d", sbubbleMin);
    ps(str);
    printf("|");
    sprintf(str, "%d", sinsertMin);
    ps(str);
    printf("|");
    sprintf(str, "%d", sshellMin);
    ps(str);
    printf("|");
    sprintf(str, "%d", squickMin);
    ps(str);
    printf("|\n");

    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Srednia podmian     |");
    sprintf(str, "%.2f", sbubbleAvg);
    ps(str);
    printf("|");
    sprintf(str, "%.2f", sinsertAvg);
    ps(str);
    printf("|");
    sprintf(str, "%.2f", sshellAvg);
    ps(str);
    printf("|");
    sprintf(str, "%.2f", squickAvg);
    ps(str);
    printf("|\n");

    printf("---------------------------------------------------------------------------------------------------------\n");
    system("pause");
}