#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <ctype.h>

void newpath(char *str)
{	
	char *buf = malloc(sizeof(char)*slen(str));
	int j = 0;
	int check = 0;
	for(int i = 2; i < slen(str); i++) {
		if (str[i] == '\\') {
			if (check == 0) {
				buf[j] = ':';
				j++;
				buf[j] = '/';
				check = 1;
				j++;
			}
			else {
				buf[j] = '/';
				j++;
			}
		}
		else {
			buf[j] = str[i];
			j++;
		}
	}
	scpy(str, buf);	
	free(buf);

}

int check(char *str)
{
	char *buf = malloc(sizeof(char)*slen(str));

	if (slen(str) >= MAX_PATH) {
		printf("Wrong size path\n");
		return 1;
	}
	if ((str[0] != '\\') || (str[1] != '\\')) {
		printf("Wrong start ip or domen name\n");
		return 1;
	}
	if ((str[2] == '\\')) {
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
			//printf("%s\n", tpr);
			if (n > 4) {
				printf("Wrong ip number\n");
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
			//printf("%s\n", tpr);
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
		//printf("%s\n", domen);
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
	char *result = malloc(sizeof(char) * slen(pch));
	char *str = stok(pch, delim);
	while (str != NULL) {
		//printf("%s\n", str);
		char *stok_tmp = get_str_stok();
		int pl = check(str);
		if (pl == 1) {
			printf("error\n");
		}
		else {
			newpath(str);
			//printf("%s\n", str);
			scat(result, str);
		}
		set_str_stok(stok_tmp);
		str = stok(NULL, delim);
		if (str != NULL) {
			scat(result, "+");
		}
	}
	//printf("R%s\n", result);
	scpy(pch, result);
	free(result);	
}

void output(const char *pch)
{
	printf("new paths: %s\n", pch);

}

void input(char *pch, char* delim)
{
	printf("delim: ");
	scanf("%s", delim);
	printf("paths: ");
	scanf("%s", pch);
}

int main()
{
	char delim[10];
	char pch[300];	

	input(pch, delim);
	process(pch, delim);

	output(pch);
	return 0;
}

