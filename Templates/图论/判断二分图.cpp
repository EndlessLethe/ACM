const int MAX_N = 1000010;
int color[MAX_N];
vector<int>G[MAX_N];//аз╫с╠М

bool bipartite(int u)
{
    for(int i = 0 ; i < G[u].size() ; i++)
    {
        int v = G[u][i];
        if(color[u]==color[v])return false;
        if(!color[v])
        {
            color[v] = 3 - color[u];
            if(!bipartite(v))return false;
        }
    }
    return true;
}
