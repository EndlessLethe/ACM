#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define MAX_V 30005
#define MAX_E 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;

void read(int &x){
    x=0;char c;
    while((c=getchar())<'0');
    do x=x*10+c-'0';while((c=getchar())>='0');
}

vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];
int res[MAX_V];
int val[MAX_V];
int dp[MAX_V];
int V,E;

void dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v,int k,int &sum){
    used[v]=true;
    cmp[v]=k;
    sum+=res[v];
    for(int i=0;i<rG[v].size();i++){
        if(!used[rG[v][i]]) rdfs(rG[v][i],k,sum);
    }
}

void DFS(int v){
    dp[v]+=val[v];
    val[v]=0;
    int maxcost=0;
    for(int i=0;i<rG[v].size();i++){
        int &to=rG[v][i];
        if(!dp[to]) DFS(to);
        maxcost=max(maxcost,dp[to]);
    }
    dp[v]+=maxcost;
}

void slove(){
    memset(used,0,sizeof(used));
    for(int i=1;i<=V;i++){
        if(!used[i]) dfs(i);
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(!used[vs[i]]){
            val[k]=0;
            rdfs(vs[i],k,val[k]);
            k++;
        }
    }
    for(int i=1;i<=V;i++) while(!rG[i].empty()) rG[i].pop_back();
    for(int v=1;v<=V;v++){
        for(int i=0;i<G[v].size();i++){
            int &to=G[v][i];
            if(cmp[v]!=cmp[to]){
                rG[cmp[v]].push_back(cmp[to]);
            }
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<k;i++){
        if(!dp[i]) DFS(i);
//      printf("->> %d \n",dp[i]);
    }
    int ans=0;
    for(int i=0;i<k;i++)
        if(dp[i]>ans)
            ans=dp[i];
    printf("%d\n",ans);
    for(int i=1;i<=V;i++) while(!G[i].empty()) G[i].pop_back();
    for(int i=0;i<k;i++) while(!rG[i].empty()) rG[i].pop_back();
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("sample.out", "w", stdout);
    while(scanf("%d%d",&V,&E)!=EOF){
        for(int i=1;i<=V;i++)
            read(res[i]);
        int x,y;
        for(int i=0;i<E;i++){
            read(x);read(y);
            G[x].push_back(y);
            rG[y].push_back(x);
        }
        slove();
    }
    return 0;
}
