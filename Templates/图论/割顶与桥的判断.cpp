int low[maxn],pre[maxn],dfs_clock = 0;
vector<int>G[maxn];
bool iscut[maxn],isbridge[maxn][maxn];
int n,m;

int dfs(int u,int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i = 0;i < G[u].size();i++)
    {
        int v = G[u][i];
        if(!pre[v])
        {
            child++;
            int lowv = dfs(v,u);
            lowu = min(lowu,lowv);
            if(lowu >= pre[u])
            {
                iscut[u] = true;
                if(lowu > pre[u])
                    isbridge[u][v] = true;
            }
        }
        else if(pre[v] < pre[u]&& v != fa)
            lowu = min(lowu,pre[v]);
    }
    if(fa < 0&&child==1)
        iscut[u] = false;
    low[u] = lowu;
    return lowu;
}
