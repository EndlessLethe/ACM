#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define N 1010

int p[N*10];    //��iΪ��������p[i[==1
int used[N],sequence[N];  //used[i]==1��ʾi�Ѿ���sequence��
int m,n,d;  //m,n,d����ֱ���description��ʾ
void prime(void)
{
    //����ɸ���ó�������
    int i,j;
    memset(p,1,sizeof(p));  //�ȼ�����������������
    p[0]=p[1]=0;
    for(i=2;i*i<N*10;i++)
    {
        if(p[i])
            for(j=2*i;j<N*10;j+=i) p[j]=0;
    }
}
int judge(int index,int value)
{
    //judge()�����ж�sequence��indexλ�õĺ�����Ϊvalue�Ƿ����
    int sum,i,indexleft;    //sum���ڼ������ڵ�d�����ĺͣ�indexleft������ߵ������±�
    indexleft=index-d+1;
    if(indexleft<0) indexleft=0;
    sum=value;          //����sequence[index]=value;
    for(i=index-1;i>=indexleft;i--)
    {
        sum+=sequence[i];   //����d��������Ƿ��ܵõ�����
        if(p[sum])  return FALSE;  //�����ӹ����еõ����������򷵻�FALSE,˵��indexλ�ò��ܷ�value
    }
    return TRUE;
}
int dfs(int index)
{
    //�õݹ�ķ���д����
    int i;
    if(index==n-m+1) return TRUE;    //���������±�Ϊn-m+1����˵��sequence�е�n-m+1��Ԫ���Ѿ�ȫ���ҵ�
    for(i=m;i<=n;i++)
    {
        if(!used[i]&&judge(index,i))
        {
            sequence[index]=i;
            used[i]=1;      //���indexλ�ÿ��Է�i����used[i]��Ϊ1���������ù�
            if(dfs(index+1))    return TRUE;
            used[i]=0;      //���������һ��λ�õ�ֵ�����Ƿ���m~n�����У���˵��indexλ�ò��ܷ�i
            //�ʽ�used[i]����Ϊ0
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
