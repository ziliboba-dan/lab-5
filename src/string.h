#ifndef STRING_H
#define STRING_H

#include <stdio.h>

char *scpy(char *destptr, const char *srcptr);

char * strtok_r(char *s1, const char *s2, char **lasts);

char * stok( char * string, const char * delim);

int slen(const char *str);

int sspn(const char *str, const char *symb);

char * strchr (register const char *s, int c);

int scmp(const char *string1, const char *string2); 

#endif
