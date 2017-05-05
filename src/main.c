#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <ctype.h>

int check(char *str)
{
	char *buf = malloc(sizeof(char)*slen(str));
	if ((str[0] != '\\') || (str[1] != '\\')) {
		printf("Wrong start ip or domen name\n");
		return 1;
	}
	if (sspn(str, "*?<>|/") > 0) {
		printf("Wrong symbol #%d\n", sspn(str, "*?<>|/"));
		return 1;
	}
	int i = 2;
	int j = 0;
	while (str[i] != '\\') {
		buf[j] = str[i];
		i++;
		j++;
	}
	//printf("%s\n", buf);

	//Проверка на допустимость айпи и домена 
	char *tpr = stok(buf, ".");
	int prov = 0;
	for (int i = 0; i < slen(tpr); i++) {
		if (!isdigit(tpr[i])) {
			prov = 1;
		}
	}
	int n = 1;
	int p = 1;
	char domen[3];
	if (prov == 0) {
		while (tpr != NULL) {
			printf("%s\n", tpr);
			if (n > 4) {
				printf("Wrong ip\n");
				return 1;
			}
			if (atoi(tpr) > 255) {
				printf("Wrong ip > 255\n");
				return 1;
			}
			tpr = stok(NULL, ".");
			n++;
		}
		if (n < 4) {
			printf("Error ip\n");
			return 1;
		}
	}	
	else {
		while (tpr != NULL) {
			printf("%s\n", tpr);
			//if ()
			if (p > 4) {
				printf("Wrong domen number\n");
				return 1;
			}
			scpy(domen, tpr);
			tpr = stok(NULL, ".");
			p++;
		}
		if (p < 2) {
			printf("Error domen\n");
			return 1;
		}
		printf("%s\n", domen);
		if (scmp(domen, "com") && scmp(domen, "org") && scmp(domen, "ru")) {
			printf("Wrong domen name\n");
			return 1;
		}
	}
	free(buf);
	return 0;
}

void process(char *pch, const char *delim)
{
	if (slen(pch) >= 260) {
		printf("Wrong size path\n");
		return;
	}
	char *str = stok(pch, delim);
	while (str != NULL) {
		printf("%s\n", str);
		if (check(str) == 1) {
			return;
		}
		else printf("TWO%s\n", str);
		str = stok(NULL, delim);
		printf("%d\n", str);
	}
		
}

void output()
{


}

int main()
{
	printf("delim: ");
	char delim[10];
	scanf("%s", delim);
	char pch[300];
	scanf("%s", pch);	
	printf("%d\n", slen(pch));

	process(pch, delim);
	return 0;
}

