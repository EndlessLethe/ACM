#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <string.h>

char str[100]; 
int lenth = 0;
int i = 0, m = 0;

int main()
{
	while (scanf("%s", str) == 1) {
		lenth = strlen(str);
		int res[lenth];
		for (i = 0; i < lenth; i++) {
			if (isdigit(str[i])) {
				res[i] = str[i];
			}
			if (isalpha(str[i])) {
				res[i] = toupper(str[i]);
			}
		}
		for (i = 0;lenth > 0; i++, lenth--) {
			printf("%c", res[i]);
		}
		printf("\n");
	}
}
