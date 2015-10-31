#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;

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
int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)==2) {
        long long q = mod(3, n, m);
        q = q - 1 + m;
        q = q % m;
        printf("%lld\n",q);
    }
}
