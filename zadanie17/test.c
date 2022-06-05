#include <stdio.h>
#include "lib.c"

int main(){
    wcont root = NULL;
    wcont *element = NULL;
    int x;
    folderInitialize(&root);
    addElement(&root, "/", "kappa", 0);
    addElement(&root, "/", "plik", 1);
    addElement(&root, "/", "alfa", 1);
    addElement(&root, "/", "ziombel", 0);
    addElement(&root, "ziombel", "beta", 1);
    addElement(&root, "ziombel", "ult", 0);
    addElement(&root, "ziombel", "ult", 1);
    addElement(&root, "ult", "jeden", 1);

    x = findEl(&root, "ult", 1, &element);
    print(root);
    del(&root, "ult", 0);
    printf("\n");
    print(root);
}