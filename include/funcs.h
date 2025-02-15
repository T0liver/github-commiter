#ifndef FUNCS_H
#define FUNCS_H

#include <stdlib.h>
#include <stdio.h>

int FileExists(const char *path);

int ReadConfigs(const char *path, char *uname, char *email);

int ExecuteCommand(const char *cmd, char *output);

int CompareStrings(const char *str1, const char *str2);

int StringCat(char *str1, const char *str2);

int GitInit();

int Commit(int cnt);

int Push();

int Pull();

int Fetch();

#endif
