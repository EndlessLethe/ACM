#include <stdio.h>
#include <math.h>

#define MAX 8000020
#define MOD 1000000007

long long val[MAX] = {0};

int main()
{
	long long int n = 0, i = 0, a = 0;;
	val[0] = 0;
	for (i = 1; i < MAX; i++) {
		val[i] = i * (val[i-1] + 1);
		val[i] = val[i] % MOD;
	}
	scanf("%lld", &n);
	for (i = 0; i < n; i++){
		scanf("%lld", &a);
		printf("%lld\n",val[a]);
	}

}
