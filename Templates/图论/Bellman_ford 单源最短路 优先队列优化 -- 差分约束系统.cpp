//读入的边 序号从0开始
//q, inq, cnt, d都在函数中初始化，main里面只用初始化G和edge 

//	edge.clear();   
//	for (int i = 0; i < N; i++) G[i].clear();

struct Edge{
	int from, to, dist;
};

const int MAX_V = 1010;
const int INF = 0x7fffffff;
int inq[MAX_V];//是否在队列中 
int d[MAX_V];//s到各点的距离 
//int p[MAX_V];//最短路中的上一条弧
int cnt[MAX_V];//进队次数 
vector <int> G[MAX_V];
vector <Edge> edge;
int n;

void add_edge(int from, int to, int dist) {//add_edge(a-1, b-1, c)
	edge.push_back((Edge){from, to, dist});
	int m = edge.size();
	G[from].push_back(m-1);
}

bool bellman_ford(int s) {
	queue <int> q;
	memset(inq, 0, sizeof(inq));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) d[i] = INF;
	d[s] = 0;
	inq[s] = true;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i = 0; i < G[u].size(); i++) {
			Edge &e = edge[G[u][i]];
			if (d[u] < INF && d[e.to] > d[u] + e.dist) {//u已经访问且e.to可以更新 
				d[e.to] = d[u] + e.dist;
//				p[e.to] = G[u][i];
				if (!inq[e.to]) {
					q.push(e.to);//只对没有访问的加入松弛队列//可能已经加入了队列 
					inq[e.to] = true;
					if (++cnt[e.to] > n) return false;//判断负圈 
				}
			}
		}
	}
	return true;
}


//	bool whether = bellman_ford(0);      
//	if (!whether) printf("-1\n");//有负环
//	else {                               
//		if (d[n-1] - d[0] >= INF) printf("-2\n");//无法到达（无约束） 
//		else printf("%d\n", d[n-1]-d[0]);

