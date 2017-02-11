#include <cstdio>  
#include <iostream>  
#include <string>  
#include <algorithm>  
#include <cmath>  
#include <cstring>  
using namespace std;  

const int maxn = 1e6 + 5;

int sa[maxn];//SA���飬��ʾ��S��n����׺��С�����������ź����
             //�ĺ�׺�Ŀ�ͷλ��˳�η���SA��
int t1[maxn],t2[maxn],c[maxn];//��SA������Ҫ���м����������Ҫ��ֵ
int ranki[maxn],height[maxn];
//��������ַ�������s�����У���s[0]��s[n-1],����Ϊn,�����ֵС��m,
//��s[n-1]�������s[i]������0��r[n-1]=0
//���������Ժ�������sa������
void build_sa(int s[],int n,int m){
    int i,j,p,*x=t1,*y=t2;
    //��һ�ֻ����������s�����ֵ�ܴ󣬿ɸ�Ϊ��������
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=s[i]]++;
    for(i=1;i<m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1){
        p=0;
        //ֱ������sa��������ڶ��ؼ���
        for(i=n-j;i<n;i++)y[p++]=i;//�����j�����ڶ��ؼ���Ϊ�յ���С
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        //��������y����ľ��ǰ��յڶ��ؼ�������Ľ��
        //���������һ�ؼ���
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        //����sa��x��������µ�x����
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        if(p>=n)break;
        m=p;//�´λ�����������ֵ
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
