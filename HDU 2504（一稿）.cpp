#include <bits/stdc++.h>

long long int f(long long int a, long long int b, long long int* val);
long long int fun(long long int m, long long int n);

int main()
{
	long long int n, i;
	scanf("%d", &n);
	long long int array[n];
	
	for (i = 0; i < n; i++)
	{
		long long int a = 0, b = 0;
		scanf("%lld %lld", &a, &b);
		if (a == 0){
			array[i] = 0;
		}
		else{
			long long int val[a] = {0};
			array[i] = f(a, b, val);
		}

	}
	
	for (i = 0; i < n; i++){	
		printf("%lld\n", array[i]);	
	}
	return 0;
}


long long int f(long long int a, long long int b, long long int* val){
	int k = 1;
	while (fun(a,k*b) != b){
		k++;
	}
	return k*b;		

}

long long int fun(long long int m, long long int n){
	while(m!=n) {
		if(m>n)
			m=m-n;
		else
			n=n-m;
	}
		return n;
}
