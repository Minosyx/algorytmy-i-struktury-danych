typedef struct elem el;
typedef el *wel;

void addStart(wel *l, int x);
void addEnd(wel *l, int x);
wel *findEl(wel *l, wel *prev, int x);
void addBefore(wel *l, int x);
void addAfter(wel *l, int x);
void remStart(wel *l);
void remEnd(wel *l);
void remEl(wel *l, wel *q);
void showList(wel l);
void rShowList(wel l);
void clear_screen();
void readFile(wel *l);
void writeFile(wel l);
void emptyList(wel *l);