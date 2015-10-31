#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
#define MOD 1000000007
long long number[8000020] = {0};
int main(){
    for (int i = 1; i < 8000020; i++) {
        number[i] = (number[i-1] + 1)* i %MOD;
    }
    int t;
    scanf("%d",&t);
    while (t--) {
        int q;
        scanf("%d",&q);
        printf("%lld\n",number[q]);
    }
}
