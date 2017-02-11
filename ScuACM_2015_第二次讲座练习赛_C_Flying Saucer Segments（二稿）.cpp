#include <stdio.h>

long long mod(long long x,long long m,long long p);

int main()
{	
	long long  a= 0, b = 0;
	long long ans = 1;
	scanf("%lld %d", &a, &b);
	ans = mod(3, a, b);
	ans = (ans -1 +b)%b;
	printf("%lld\n", ans);
	return 0;
}

long long mod(long long x,long long m,long long p){
    long long s = x;
    long long ans = 1;
    while (m) {
        if (m & 1) {
            ans = s * ans % p;
        }
        s = s * s % p;
        m >>=1;
    }
    return ans;
}
