#ifndef FILE_H
#define FILE_H

#include "list.h"

int openFile(const char *path, int flags);
void saveListToFile(const char *path, const List *list);
void getListFromFile(const char *path, List *list);

#endif
