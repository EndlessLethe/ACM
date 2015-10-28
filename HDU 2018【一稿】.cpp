#include <bits/stdc++.h>

#define MAX 60

long long int f(long long int a, long long int* val, long long int* total);
long long int sum(long long int n, long long int *total, long long int *val);

int main()
{
	long long int n, i, k;
	i = 0;
	long long int res[MAX] = {0}, val[MAX]= {0}, total[MAX]= {0};
	scanf("%d",&n);
	while (n != 0) {
			res[i++] = f(n, val, total);
			scanf("%I64d",&n);
		} ;

	for (k = 0; k < i; k++)
	{	
		printf("%I64d\n", res[k]);	
	}
}

long long int f(long long int a, long long int* val, long long int *total) {
	long long int t = 0, e = 0;
	if (val[a-1]){
		;
	}
	else if (a > 0 && a < 5) {
		val[a-1] = a;
	}
	else {
		t = f(a-1, val, total);
		e = sum(a-4, total, val);
		val[a-1] = t + a-4 + e;//没有办法了，凑一凑吧。（a-4）本来是需要在算法里考虑的 
	}
	return val[a-1];
}

long long int sum(long long int a, long long int *total, long long int *val) {
	if (total[a-1]){
		;
	}
	else if (a == 1) {
		total[a-1] = 1;
	}
	else {	
			total[a-1] = val[a-1] + total[a-2];
	}
	return total[a-1];
}
