#include <bits/stdc++.h>

#define MAX ******

long long int f(int a, long long int* val);

int main()
{
	int n = 0, i = 0;
	scanf("%d", &n);
	long long int res[n] = {0}, val[MAX] = {0};
	for (i = 0; i < n; i++){
		int a = 0;
		scanf("%d", &a);
		if (a == 0){
			res[i] = 0;
		}
		else{
			res[i] = f(a, val);
		}
	}
	for (i = 0; i < n; i++){	
		printf("%lld\n", res[i]);	
	}
}

long long int f(int a, long long int* val){
	if (val[a-1]){
		;
	}
	else if (a == 1 || a == 2) {
		val[a-1] = 1;
	}
	else{
		val[a-1] = f(a-1, val) + f(a-2, val);
	}
	return val[a-1];
}
