const int MAX_E = 100;
const int MAX_V = 50;
long long int sum[MAX];//可以同时维护很多个值，不仅仅是sum 
int p[MAX];
struct edge{int from, to, cost;} E[MAX];
int E, V;//E是边数，V是顶点数，都需要读入or计算得到 

bool cmp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {//为了方便书写，统一将y连向x
	x = find(x), y = find(y);
	if (x == y) return ;
	pa[x] += pa[y];
	pa[y] = x;
}

void init(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = -1;
//		sum[i] = 0; 
	}
}

int kruskal() {
	sort(es, es+E, cmp);
//	for (int i = 0; i < E; i++) cout << es[i].cost << ' ';
	init(V+3);
	int res = 0;
	for (int i = 0; i < E; i++) {
		edge e = es[i];
		if (find(e.u) != find(e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
