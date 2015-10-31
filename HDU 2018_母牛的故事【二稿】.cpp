#include <bits/stdc++.h>

#define MAX 60

long long int f(long long int a, long long int* val);

int main()
{
	long long int n, i, k;
	i = 0;
	long long int res[MAX] = {0}, val[MAX]= {0};
	scanf("%d",&n);
	while (n != 0) {
			res[i++] = f(n, val);
			scanf("%I64d",&n);
		} ;

	for (k = 0; k < i; k++)
	{	
		printf("%I64d\n", res[k]);	
	}
	return 0;
}

long long int f(long long int a, long long int* val) {
	if (val[a-1]){
		;
	}
	else if (a > 0 && a < 5) {
		val[a-1] = a;
	}
	else if (a % 4 == 0){
		val[a-1] = f(a-1, val) + a/4 ;
		//理解有问题，不是1年多一只，而是一年比前年多一只 
	}
	else {
		val[a-1] = f(a-1, val) + a/4 + 1 ;
	}
	return val[a-1];
}

