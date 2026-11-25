#ifndef INIFILE_H
#define INIFILE_H
void strcpynlower(char *d, char *s, int n);
char *ExtractFileExt(char *name);
int GetIniString(char *dst, char *buffer, char *section, char *ident);
int GetIniIdentCount(char *buffer, char *section);
int GetIniIdentString(char *dst, char *buffer, char *section, int index);
#endif
