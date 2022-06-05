typedef struct elem el;
typedef el *wel;

void addBefore(wel *l, int x, int wart);
void addWel(wel *l, int x, int wart);
wel *getFirst(wel *l, int wart);
wel *getLast(wel *l, int wart);
wel *findEl(wel *l, int x, int wart);
void remEl(wel *q);
void showList(wel l, int wart);
void rShowList(wel l, int wart);
void clear_screen();
void writeFile(wel l, int wart);
void readFile(wel *l, int wart);
void emptyList(wel *l, int wart);
void diff(wel *p, wel *q, int wart);