#include <stdio.h>
#include <string.h>

char a[10000000], b[10000000];

int main()
{
	int lenth, i;
	scanf("%s", a);
	scanf("%s", b);
	lenth = strlen(a);
	for (i = 0; i < lenth; i++) {
		if (a[i] < b[i]) a[i] = b[i];
	}
	printf("%s", a);
	return 0;
}
