typedef struct elem el;
typedef el *wel;

wel createQ(int x, int p);
void add(wel *q, wel new_Q);
wel getHighest(wel *q);
void changePriority(wel *q, wel *el, int newP);
void emptyCheck(wel q);
void printQueue(wel q);
wel *findEl(wel *q, int x, int p);
void clear_screen();