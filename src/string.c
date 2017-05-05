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

char *strtok_r(char *s1, const char *s2, char **lasts) {
	char *ret;
	if (s1 == NULL)
	s1 = *lasts;
	while(*s1 && strchr(s2, *s1))
		++s1;
	if(*s1 == '\0')
		return NULL;
	ret = s1;
	while(*s1 && !strchr(s2, *s1))
		++s1;
	if(*s1)
		*s1++ = '\0';
	*lasts = s1;
	return ret;
}

char *strchr(register const char *s, int c) {
	do {
		if (*s == c) {
			return (char*)s;
		}
	} while (*s++);
	return 0;
}

char *stok( char * string, const char * delim){
	static char *lasts;
	
	return strtok_r(string, delim, &lasts);	
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
