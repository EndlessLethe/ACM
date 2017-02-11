const int MAX_V = 20010;
const int INF = 0x7fffffff;

struct edge {int to, cap, rev;};
vector <edge> G[MAX_V];
int level[MAX_V];//距原点的距离 
int iter[MAX_V];//当前弧 

void add_edge(int from, int to, int cap) {
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size()-1});
}

void bfs(int s) {//建立当前残余网络的层次图 
	memset(level, -1, sizeof(level));//注意是-1 
	queue<int> q;
	level[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] +1;
				q.push(e.to); 
			}
		}
	}
}

int dfs(int v, int t, int f) {
	if (v == t) return f;//f为当前能传输的最大值 
	for (int &i = iter[v]; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to]) {//保证离汇点更近（not only+1） 
			int d = dfs(e.to, t, min(f, e.cap));//min求一个瓶颈 
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		bfs(s);
		if (level[t] < 0) return flow;
		memset(iter, 0, sizeof(iter));
		int f = dfs(s, t, INF);
		while (f > 0) {
			flow += f;
			f = dfs(s, t, INF);
		}
	}
}

int main()
{
    int N, M, A, B, a, b, c;
    scanf("%d%d", &N, &M);
    int s = N, t = s + 1;//顶点编号从0开始 
    for (int i = 0; i < N; i++) {
    	scanf("%d%d", &A, &B);
    	add_edge(s, i, A);
    	add_edge(i, t, B);
	}
	for (int i = 0; i < M; i++){
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a-1, b-1, c);
		add_edge(b-1, a-1, c);
	}
	printf("%d\n", max_flow(s, t));
    return 0;
}
