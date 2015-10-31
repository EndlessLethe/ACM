#include <stdio.h>
#include <math.h>

#define MAX 8000000
#define MOD 1000000007

long long int f(int a, long long *val);
long long val[MAX] = {0};
//我还是不知道为什么一跑就爆，以后就用shuaishuai的方法吧 

int main()
{
	long long int n = 0, i = 0;
	scanf("%lld", &n);
	long long int res[10000] = {0};
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

long long int f(int a, long long *val){
	if (val[a-1]){
		;
	}
	else if (a == 1) {
		val[a-1] = 1;
	}
	else{
		val[a-1] = a * (f(a-1, val) + 1);
		val[a-1] = val[a-1] % MOD;
	}
	return val[a-1];
}


