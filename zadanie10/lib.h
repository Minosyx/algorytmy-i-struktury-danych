typedef struct elem el;
typedef el *wel;

void addStart(wel *l, int x);
void addEnd(wel *l, int x);
wel *findEl(wel *l, int x);
void addBefore(wel *l, wel *head, int x);
void addAfter(wel *l, int x);
void remStart(wel *l);
void remEnd(wel *l);
void remEl(wel *q, wel *l);
void showList(wel l);
void rShowList(wel l, wel glowa);
void clear_screen();
void readFile(wel *l);
void writeFile(wel l);
void emptyList(wel *l);

typedef struct delem del;
typedef del *wdel;

void addStart_d(wdel *l, int x);
void addEnd_d(wdel *l, int x);
wdel *findEl_d(wdel *l, int x);
void addBefore_d(wdel *l, wdel *head, int x);
void addAfter_d(wdel *l, int x);
void remStart_d(wdel *l);
void remEnd_d(wdel *l);
void remEl_d(wdel *q, wdel *l);
void showList_d(wdel l);
void rShowList_d(wdel l);
void readFile_d(wdel *l);
void writeFile_d(wdel l);
void emptyList_d(wdel *l);