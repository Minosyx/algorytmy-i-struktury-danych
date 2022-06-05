typedef struct wezel_drzewa wezel;
typedef wezel *ww;

ww add(ww root, int x);
ww *find(ww *root, int x);
ww *min(ww *root);
ww *max(ww *root);
ww next(ww el);
ww prev(ww el);
int del(ww *el);
void printTree(ww root, int x);
void printT(ww root);
void preOrderWrite(ww root, FILE *f);
void write(ww root);
void dellAll(ww *root);
void preOrderRead(ww *node, FILE *f, ww parent, int *ctree);
void read(ww *root, int *ctree);

int AddToArray(ww node, int *arr, int i);
int inOrderF(ww node, int *table, int it, int *res);
int diffTree(ww t1, ww t2, int ctree);

void clear_screen();