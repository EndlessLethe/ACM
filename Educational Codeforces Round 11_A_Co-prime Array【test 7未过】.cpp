#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace::std;

#define MAX 1010
long long A[3*MAX];

bool gcd(long long int n, long long int m)  
{  
    long long int i;  
    while(m)  
    {  
        i=n%m;  
        n=m;  
        m=i;  
    }  
    if(n==1)  
        return true;  
    else  
        return false;  
}  

int main()
{
	#ifdef LOCAL
		freopen("input_Educational Codeforces Round 11_A_Co-prime Array.txt", "r", stdin);
	#endif
	int n, i;
	std::ios::sync_with_stdio(false);
	cin >> n;
	cin >> A[0];
	int cnt = 0;
	i = 1;
	for (int k = 1; k < n; k++) {
		cin >> A[i];
		 if(A[i-1] > A[i]) {  
            if (!gcd(A[i-1], A[i])) {
            	A[i+1] = A[i];
            	A[i] = A[i-1]+1;
            	i++;
            	cnt++;
			}
        }  
        else {
        	if (!gcd(A[i], A[i-1])) {
            	A[i+1] = A[i];
            	A[i]++;
            	i++;
            	cnt++;
			}
		}
		i++;
	}
	printf("%d\n", cnt);
	for  (int k = 0; A[k] != 0; k++) {
		printf("%I64d ", A[k]);
	}
	return 0;
}

