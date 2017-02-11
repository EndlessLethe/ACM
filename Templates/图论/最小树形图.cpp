const int INF  = 0x7fffffff;
const int MAX_V = 105;
const int MAX_E = 1005;
const double eps  = 1e-4;

//struct Point
//{
//    double x, y;
//}p[MAX_V];
//
//double dis(Point a, Point b)
//{
//    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
//}

struct node
{
    int u, v;
    int w;
}edge[MAX_V * MAX_V];

int pre[MAX_V], id[MAX_V], vis[MAX_V];
int in[MAX_V];//入边的最小权值 

int Directed_MST(int root, int V, int E)
{
    int cost = 0;//最小树形图总权值 
    while(true)
    {
        //1.找最小入边
        for(int i = 0; i < V; i++) in[i] = INF;
        for(int i = 0; i < E; i++) {
            int u = edge[i].u;
            int v = edge[i].v;
            if(edge[i].w < in[v] && u != v) {
				pre[v] = u;
				in[v] = edge[i].w;
				if (u == root) son = i;//在连虚根时需要 
			}
        }
        for(int i = 0; i < V; i++) {
            if(i == root) continue;
            if(in[i] == INF) return -1;//除了根以外有点没有入边,则根无法到达它
        }
        //2.找环
        int cnt = 0;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        for(int i = 0; i < V; i++) {//标记每个环 
            cost += in[i];
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root) {
            //每个点寻找其前序点，要么最终寻找至根部，要么找到一个环
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1) {//缩点
                for(int u = pre[v]; u != v; u = pre[u]) 
                    id[u] = cnt;
                id[v] = cnt++;
            }
        }
        if(cnt == 0) break; //无环   则break
        for(int i = 0; i < V; i++)
            if(id[i] == -1) id[i] = cnt++;//没有被缩点 
        //3.建立新图
        for(int i = 0; i < E; i++) {
		//遍历了所有的边,除了被缩点的边外都保留了下来，都是可能的解 
            int u = edge[i].u;
            int v = edge[i].v;
            edge[i].u = id[u];
            edge[i].v = id[v];
            if(edge[i].u != edge[i].v) edge[i].w -= in[v];
			//不需要在这里判断自环,更新边权（重新连了一边，要拆掉一边,把之前花费减回来） 
        }
        V = cnt;
        root = id[root];
    }
    return cost;
}

int main()
{
	int N, M, r;
	while (scanf("%d%d", &N, &M) == 2) {
		r = 0;
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
			r += edge[i].w;//注意 
			if (edge[i].u == edge[i].v) edge[i].w = INF;//去除自环 
		}
		r++; 
		for (int i = M; i < M+N; i++) {
			edge[i].u = N;
			edge[i].v = i-M;//注意 
			edge[i].w = r;
		}
		int ans = Directed_MST(N, N+1, M+N);//注意 
		if (ans == -1 || ans >= 2*r) printf("impossible\n");
		else printf("%d %d\n", ans-r, son-M);//注意 
    }
    return 0;
}

