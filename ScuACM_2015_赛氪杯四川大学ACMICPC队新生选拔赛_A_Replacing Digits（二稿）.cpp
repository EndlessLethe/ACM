#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

char a[10000000], b[10000000];
int t, j, token;

int compDec(const void *a, const void *b)
{
	return *(char*)b-*(char*)a;
}
//从大到小排序 

int main()
{

	
	int lenth, i;
	scanf("%s", a);
	scanf("%s", b);
	lenth = strlen(a);

	
	int len = 0, temp = 0;
	len = sizeof(b) / sizeof(b[0]);   
	qsort(b, len, sizeof(b[0]), compDec);  

	for (i = 0; i < lenth; i++) {
		if (a[i] < b[token]) {
			a[i] = b[token];
			token++;
		}
	}	
	
	printf("%s", a);
	return 0;
}
