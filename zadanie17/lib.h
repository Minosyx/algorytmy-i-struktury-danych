typedef struct container cont;
typedef cont * wcont;
typedef struct directory d;
typedef d * wd;
typedef struct file f;
typedef f * wf;

void folderInitialize(wcont *root);
void traverseLevel(wcont *level, const char *name, const int type, wcont **element, int *result);
void traverseDir(wcont *root, const char *folder, const char *name, const int type, wcont **element, int* sw, const int opt);
void findFolder(wcont *root, const char *folder, const char *name, const int type, wcont **element, int *result);
int findEl(wcont *root, const char *name, const int type, wcont **element);
void addElement(wcont *root, const char *folder, char *name, const int type);
void delInterior(wcont *folder);
void del(wcont *root, const char *name, const int type);
void printInt(wcont root, int step, int depth);
void print(wcont root);
void clear_screen();