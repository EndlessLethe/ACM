#include<stdio.h>  
#include<stack>  
using namespace std;  
typedef struct  
{  
    int x;  
    int l, m, r;  
}Point;  
Point s[100005];  
__int64 sum[100005];  
stack<Point> t;  
int main(void)  
{  
	freopen("in.txt","r",stdin);
    int n, i, l, r;  
    __int64 ans, temp;  
    while(scanf("%d", &n)!=EOF)  
    {  
        sum[0] = 0;  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d", &s[i].x), s[i].m = i;  
            sum[i] = sum[i-1]+s[i].x;  
        }  
        for(i=1;i<=n;i++)  
        {  
            s[i].l = i;  
            while(t.empty()==0 && t.top().x>s[i].x)  
            {  
                s[t.top().m].r = i-1;  
                s[i].l = s[t.top().m].l;  
                t.pop();  
            }  
            t.push(s[i]);  
        }  
        while(t.empty()==0)  
        {  
            s[t.top().m].r = n;  
            t.pop();  
        }  
        ans = -1;  
        for(i=1;i<=n;i++)  
        {  
            temp = (sum[s[i].r]-sum[s[i].l-1])*s[i].x;  
            if(temp>ans)  
                ans = temp, l = s[i].l, r = s[i].r;  
        }  
        printf("%I64d\n%d %d\n", ans, l, r);  
    }  
    return 0;  
}  
