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
void delStep(wel *l, wel *head, int step);