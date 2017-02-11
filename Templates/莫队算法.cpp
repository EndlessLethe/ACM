#include<bits/stdc++.h>
using namespace std;
const int maxn = 120010;

int a[maxn], pos[maxn];
long long ans, flag[5000000];
long long Ans[maxn];//记录询问对应的答案 
int k;
struct query {
    int l, r, id;
} Q[maxn];

bool cmp(query a, query b) {
    if(pos[a.l] == pos[b.l])
        return a.r < b.r;
    return pos[a.l] < pos[b.l];
}

//根据题目不同，这两个函数会有不同的内容 
void Updata(int x) {
    ans += flag[a[x]^k];
    flag[a[x]]++;
}
void Delete(int x) {
    flag[a[x]]--;
    ans -= flag[a[x]^k];
}

int main()
{
    int n, m;
    scanf("%d%d%d", &n, &m, &k);
    int MAGIC = floor(sqrt(1.0*n));
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[i] = (i-1) / MAGIC;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &Q[i].l, &Q[i].r);
        Q[i].id = i;
    }
    sort(Q+1, Q+1+m, cmp);
    int l = 1, r = 0;
    ans = 0;
    flag[0] = 1;
    
    for(int i = 1; i <= n; i++) a[i] ^= a[i-1];//预读入数据 //这里处理的是前缀和 
    
    for(int i = 1;i <= m; i++)
    {
        int id = Q[i].id;
        while(r < Q[i].r) {
            r++;
            Updata(r);
        }
        while(l > Q[i].l) {
            l--;
            Updata(l-1);
        }
        while(r > Q[i].r) {
            Delete(r);
            r--;
        }
        while(l < Q[i].l) {
            Delete(l-1);
            l++;
        }
        Ans[id] = ans;
    }
    for(int i = 1; i <= m; i++)
        printf("%lld\n", Ans[i]);
}
