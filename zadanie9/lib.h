typedef struct elem el;
typedef el *wel;

wel tail;

void addStart(wel *l, int x);
wel *findEl(wel *l, int x);
void addBefore(wel *l, int x, int wart);
void addAfter(wel *l, int x);
void remStart(wel *l);
void remEl(wel *l);
void showList(wel l, int wart);
void rShowList(wel l);
void clear_screen();
void readFile(wel *l);
void writeFile(wel l, int wart);
void emptyList(wel *l, int wart);
void addWel(wel *l, int x, int wart);
wel *getFirst(wel *l, int wart);
wel *findEl_s(wel *l, int x, int wart);
void readFile_s(wel *l, int wart);