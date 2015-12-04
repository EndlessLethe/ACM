#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define N 1010

int p[N*10];    //若i为素数，则p[i[==1
int used[N],sequence[N];  //used[i]==1表示i已经在sequence中
int m,n,d;  //m,n,d含义分别如description所示
void prime(void)
{
    //利用筛法得出素数表
    int i,j;
    memset(p,1,sizeof(p));  //先假设所有数都是素数
    p[0]=p[1]=0;
    for(i=2;i*i<N*10;i++)
    {
        if(p[i])
            for(j=2*i;j<N*10;j+=i) p[j]=0;
    }
}
int judge(int index,int value)
{
    //judge()用来判断sequence的index位置的函数置为value是否合适
    int sum,i,indexleft;    //sum用于计算相邻的d个数的和，indexleft是最左边的数的下标
    indexleft=index-d+1;
    if(indexleft<0) indexleft=0;
    sum=value;          //假设sequence[index]=value;
    for(i=index-1;i>=indexleft;i--)
    {
        sum+=sequence[i];   //检验d个数相加是否能得到合数
        if(p[sum])  return FALSE;  //如果相加过程中得到了素数，则返回FALSE,说明index位置不能放value
    }
    return TRUE;
}
int dfs(int index)
{
    //用递归的方法写深搜
    int i;
    if(index==n-m+1) return TRUE;    //若搜索到下标为n-m+1，则说明sequence中的n-m+1个元素已经全部找到
    for(i=m;i<=n;i++)
    {
        if(!used[i]&&judge(index,i))
        {
            sequence[index]=i;
            used[i]=1;      //如果index位置可以放i，则将used[i]置为1，代表已用过
            if(dfs(index+1))    return TRUE;
            used[i]=0;      //如果深搜下一个位置的值，但是发现m~n都不行，则说明index位置不能放i
            //故将used[i]重置为0
        }
    }
    return FALSE;
}
int main()
{
    int i;
    prime();
    while(scanf("%d%d%d",&m,&n,&d)==3&&(m+n+d))
    {
        memset(used,0,sizeof(used));
        if(dfs(0))
        {
            for(i=0;i<n-m;i++)    printf("%d,",sequence[i]);
            printf("%d\n",sequence[n-m]);
        }
        else
            printf("No anti-prime sequence exists.\n");
    }
    return 0;
}
