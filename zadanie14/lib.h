typedef struct wezel_drzewa wezel;
typedef wezel *ww;

ww add(ww root, char *x);
ww *find(ww *root, char *x);
ww *min(ww *root);
ww *max(ww *root);
ww next(ww el);
ww prev(ww el);
void del(ww *el);
void printTree(ww root, int x);
void printT(ww root);
void clear_screen();