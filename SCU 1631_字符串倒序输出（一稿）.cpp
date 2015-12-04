#include <stdio.h>
#include <string.h>

char str[100]; 
int lenth = 0;
int i = 0;
int c;

int main()
{
	while ((c = getchar()) != ' ' && c != '\t') {
		str[i++] = c;
	}
		lenth = strlen(str);
		char res[lenth];
		for (i = 0; i < lenth; i++) {
			res[i] = str[i];
		}
		lenth--;
		for (; lenth >= 0; lenth--) {
			printf("%c", res[lenth]);
		}
}

//WA没什么办法，不知道怎么让它停止 
