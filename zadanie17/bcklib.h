typedef struct folder f;
typedef f *wf;

void folderInitialize(wf *root);
void traverseLevel(wf *level, const char *name, wf **element, int *result);
void traverseDir(wf *root, const char *folder, const char *name, wf **element, int *sw);
void findFolder(wf *root, char *folder, char *name, wf **element, int *result);
int findEl(wf *root, char *name, wf **element);
void addElement(wf *root, char *folder, char *name);
void delInterior(wf *folder);
void del(wf *root, char *name);
void printInt(wf root, int step, int depth);
void print(wf root);
void clear_screen();