#ifndef STRING_H
#define STRING_H

#include <stdio.h>

#define MAX_PATH 260

char *scpy(char *destptr, const char *srcptr);

char *stok(char *str, const char *delim);

int slen(const char *str);

int sspn(const char *str, const char *symb);

int scmp(const char *string1, const char *string2); 

char *get_str_stok();

void set_str_stok(char *str);

char *scat( char *destptr, const char *srcptr);

#endif
