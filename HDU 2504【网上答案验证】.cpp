#include<iostream>  
using namespace std;  
int gcd(int a,int b)  
{return b==0? a:gcd(b,a%b); }  
int main()  
{  
    int t,a,b,c;  
    while(scanf("%d",&t)!=EOF)  
    {  
        while(t--)  
        {  
            scanf("%d%d",&a,&b);  
            c=2*b;  
            while(gcd(a,c)!=b)  
              c+=b;  
            printf("%d\n",c);  
        }  
    }  
    return 0;  
} 
