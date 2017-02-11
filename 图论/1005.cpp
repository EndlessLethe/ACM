#include <cstdio>  
#include <iostream>  
#include <string>  
#include <algorithm>  
#include <cmath>  
#include <cstring>  
using namespace std;  

const int maxn = 1e6 + 5;

int sa[maxn];//SA数组，表示将S的n个后缀从小到大排序后把排好序的
             //的后缀的开头位置顺次放入SA中
int t1[maxn],t2[maxn],c[maxn];//求SA数组需要的中间变量，不需要赋值
int ranki[maxn],height[maxn];
//待排序的字符串放在s数组中，从s[0]到s[n-1],长度为n,且最大值小于m,
//除s[n-1]外的所有s[i]都大于0，r[n-1]=0
//函数结束以后结果放在sa数组中
void build_sa(int s[],int n,int m){
    int i,j,p,*x=t1,*y=t2;
    //第一轮基数排序，如果s的最大值很大，可改为快速排序
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=s[i]]++;
    for(i=1;i<m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1){
        p=0;
        //直接利用sa数组排序第二关键字
        for(i=n-j;i<n;i++)y[p++]=i;//后面的j个数第二关键字为空的最小
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        //这样数组y保存的就是按照第二关键字排序的结果
        //基数排序第一关键字
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        //根据sa和x数组计算新的x数组
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        if(p>=n)break;
        m=p;//下次基数排序的最大值
    }
}

void getHeight(int s[],int n){
    int i,j,k=0;
    for(i=0;i<=n;i++)ranki[sa[i]]=i;
    for(i=0;i<n;i++){
        if(k)k--;
        j=sa[ranki[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[ranki[i]]=k;
    }
}

int lasti[maxn],str[maxn];
char s[maxn];
  
int main()  {  
//#ifdef LOCAL
//    freopen("in.txt", "r", stdin);
//#endif
    int t;
    long long ans;  
    char ch[10];
    scanf("%d",&t);  
    for (int cas = 1; cas <= t; cas++)  {  
        ans = 0;  
        scanf("%s",ch);
        scanf("%s",s);  
        int n = strlen(s);  
        lasti[n] = n;
        for (int i = 0 ; i < n ;i++) str[i] = s[i];
		build_sa(str,n + 1,128);
		getHeight(str,n); 
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ch[0]) 
				lasti[i] = i;
            else 
				lasti[i] = lasti[i + 1];
        }
        ans = n * n; 
        for(int i = 1; i <= n; i++) {  
            long long p = max(height[i], lasti[sa[i]] - sa[i]);
            ans -=   (sa[i] + p);  
        }  
        printf("Case #%d: %lld\n", cas, ans);  
    }  
    return 0;  
}
