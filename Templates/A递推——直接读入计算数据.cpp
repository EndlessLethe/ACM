#include <bits/stdc++.h>

#define MAX ******

long long int f(int a, long long int* val);

int main()
{
	int a = 0, i = 0, k = 0;
	long long int res[MAX], val[MAX];
	while (scanf("%d",&a) != ****) {
		res[i++] = f(a, val);
	}

	for (k = 0; k < i; k++) {	
		printf("%lld\n", res[k]);	
	}
}

long long int f(int a, long long int* val) {
	if (val[a-1]){
		;
	}
	else if (a < ***) {
		val[a-1] = 1;
	}
	else {
	****val[a-1] = f(a-1, val) + f(a-2, val);
	}
	return val[a-1];
}
