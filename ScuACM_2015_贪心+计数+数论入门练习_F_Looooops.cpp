#include <stdio.h>

long long big_mod(long long a,long long p,long long m);
long long mod_pow(long long n);
long long gcd(long long a, long long b);
long long exgcd(long long a, long long b, long long x, long long y);

long long a, b, c, k, modk, powk, modba, gcdba;
long long t = 0;
long long x, y;

int main()
{
	while (scanf("%d %d %d %d", &a, &b, &c, &k), a != 0 || b != 0 || c != 0 || k != 0) {
		modk = big_mod(2, k, c);
		powk = mod_pow(k);
		modba = (b - a) % c;
		gcdba = gcd(c, modk);
		if ((b - a) % c == 0) {
			if (b - a > 0) {
				printf("%d\n", (b - a) / c);
			}
			else {
				printf("%d\n", powk / 2 - (b - a) / c);
			}
		}
		else if ((b - a) % c != 0 && modk == 0) {
			printf("FOREVER");
			continue;
		}
		
		//这里开始就有点想不清楚了 
		else if ((b - a) % c != 0 && modk != 0) {
			if (modba % gcdba != 0) {
				printf("FOREVER");
				continue;
			}
			else if (modba % gcdba == 0) {
				exgcd(modk, -c, x, y);
				t = modba / gcdba;
				t *= x;
				printf("%d\n", t * powk / 2 - (b - a) / c);
			}
		}
	}

	return 0;
}


long long big_mod(long long a,long long p,long long m)  //a^p%m
{
    if (a==0 || m==1)
        return 0;
    if (p==0)
        return 1;
    if (p%2)
        return ((a%m)*big_mod(a,p-1,m))%m;
    long long tmp=big_mod(a,p/2,m);
    return (tmp*tmp)%m;

}

long long mod_pow(long long n)
{
	if(n == 1) return 2;
	if(n % 2) {
		long long t=mod_pow((n-1)/2);
		return 2 * t * t;
	}
	else {
		int t=mod_pow(n/2);
		return t * t;
	}
}

long long gcd(long long a, long long b)
{
if(b == 0) return a;
return gcd(b, a % b);
}

long long exgcd(long long a, long long b, long long x, long long y)  
{  
    if(b==0)  
    {  
        x=1;  
        y=0;  
        return a;
	}
	
    long long d=exgcd(b,a%b,y,x);  
    y-=a/b*x;  
    return d;
}
