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
int in[MAX_V];//��ߵ���СȨֵ 

int Directed_MST(int root, int V, int E)
{
    int cost = 0;//��С����ͼ��Ȩֵ 
    while(true)
    {
        //1.����С���
        for(int i = 0; i < V; i++) in[i] = INF;
        for(int i = 0; i < E; i++) {
            int u = edge[i].u;
            int v = edge[i].v;
            if(edge[i].w < in[v] && u != v) {
				pre[v] = u;
				in[v] = edge[i].w;
				if (u == root) son = i;//�������ʱ��Ҫ 
			}
        }
        for(int i = 0; i < V; i++) {
            if(i == root) continue;
            if(in[i] == INF) return -1;//���˸������е�û�����,����޷�������
        }
        //2.�һ�
        int cnt = 0;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        for(int i = 0; i < V; i++) {//���ÿ���� 
            cost += in[i];
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root) {
            //ÿ����Ѱ����ǰ��㣬Ҫô����Ѱ����������Ҫô�ҵ�һ����
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1) {//����
                for(int u = pre[v]; u != v; u = pre[u]) 
                    id[u] = cnt;
                id[v] = cnt++;
            }
        }
        if(cnt == 0) break; //�޻�   ��break
        for(int i = 0; i < V; i++)
            if(id[i] == -1) id[i] = cnt++;//û�б����� 
        //3.������ͼ
        for(int i = 0; i < E; i++) {
		//���������еı�,���˱�����ı��ⶼ���������������ǿ��ܵĽ� 
            int u = edge[i].u;
            int v = edge[i].v;
            edge[i].u = id[u];
            edge[i].v = id[v];
            if(edge[i].u != edge[i].v) edge[i].w -= in[v];
			//����Ҫ�������ж��Ի�,���±�Ȩ����������һ�ߣ�Ҫ���һ��,��֮ǰ���Ѽ������� 
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
			r += edge[i].w;//ע�� 
			if (edge[i].u == edge[i].v) edge[i].w = INF;//ȥ���Ի� 
		}
		r++; 
		for (int i = M; i < M+N; i++) {
			edge[i].u = N;
			edge[i].v = i-M;//ע�� 
			edge[i].w = r;
		}
		int ans = Directed_MST(N, N+1, M+N);//ע�� 
		if (ans == -1 || ans >= 2*r) printf("impossible\n");
		else printf("%d %d\n", ans-r, son-M);//ע�� 
    }
    return 0;
}

