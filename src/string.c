#include "string.h"

int slen(const char *s)
{
	int i;
	for(i = 0; s[i] != '\0'; i++);
	return i;
}
 
char *scpy(char *destptr, const char *srcptr)
{
	int i = 0;
	for (; srcptr[i] != 0; i++) {
		destptr[i] = srcptr[i];
	}
	destptr[i] = 0;
	return destptr;
}

int sspn(const char *str, const char *sym)
{
	for (int i = 0; str[i] != 0; i++) {
		for (int j = 0; sym[j] != 0; j++) {
			if (str[i] == sym[j]) {
				return i + 1;
			}
		}
	}
	return 0;
}

char *str_stok = NULL;

char *get_str_stok()
{
	return str_stok;
}

void set_str_stok(char *str)
{
	str_stok = str;
}

char *stok(char *str, const char *delim)
{
	if (str != NULL) {
		str_stok = str;
	}
	if (str_stok == NULL) {
		return NULL;
	}
	for (int i = 0; str_stok[i] != 0; i++) {
		for (int j = 0; delim[j] != 0; j++) {
			if (str_stok[i] == delim[j]) {
				str_stok[i] = 0;
				char *result = str_stok;
				str_stok = str_stok + i + 1;
				return result;
			}
		}
	}
	if (str_stok != NULL) {
		char *result = str_stok;
		str_stok = NULL;
		return result;
	} else {
		return NULL;
	}
}

int scmp(const char *string1, const char *string2) 
{	
	for (int i = 0; i < slen(string2); i++) {
		if (string1[i] != string2[i]) {
			return 1;
		}
	}
	return 0;
}
