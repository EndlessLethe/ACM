#include <bits/stdc++.h>

#define MAX ******

int f(int a, int* val);

int main()
{
	int n = 0, i = 0, k = 0;
	scanf("%d",&n);
	int res[MAX], val[MAX];
	while (n != ****) {
		i = 0;
		res[i++] = f(n, val);
		scanf("%d",&n);
	}

	for (k = 0; k < i; k++) {	
		printf("%d\n", res[k]);	
	}
}

int f(int a, int* val) {
	if (val[a-1]){
		;
	}
	if else (a < ***) {
		val[a-1] = 1;
	}
	else {
	****
	}
	return val[a-1];
}
