#include <queue>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
using namespace std;

struct Edge{
	int from, to, dist;
};

const int MAX_V = 1010;
const int INF = 0x7fffffff;
int inq[MAX_V], d[MAX_V], p[MAX_V], cnt[MAX_V];
vector <int> G[MAX_V];
vector <Edge> edge;
int n;

void add_edge(int from, int to, int dist) {
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
			if (d[u] < INF && d[e.to] > d[u] + e.dist) {
				d[e.to] = d[u] + e.dist;
				p[e.to] = G[u][i];
				if (!inq[e.to]) {
					q.push(e.to);
					inq[e.to] = true;
					if (++cnt[e.to] > n) return false;
				}
//				printf("%d ", d[e.to]);
			}
		}
	}
	return true;
}

int main()
{
//	#ifdef LOCAL
//		freopen("in.txt", "r", stdin);
//	#endif
	edge.clear();   
	for (int i = 0; i < n; i++) G[i].clear();
	int L, D, a, b, c;
	scanf("%d%d%d", &n, &L, &D);
	for (int i = 0; i < L; i++) {//a+c >= b 
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a-1, b-1, c);
	}
	for (int i = 0; i < D; i++) {
		scanf("%d%d%d", &a, &b, &c);
		add_edge(b-1, a-1, -c);
	}
	for (int i = 0; i < n-1; i++) {//满足d[i]>=d[i-1] 
		add_edge(i+1, i, 0);
	}
	bool whether = bellman_ford(0);
	if (!whether) printf("-1\n");//有负环 
	else {
		if (d[n-1] - d[0] >= INF) printf("-2\n");//无法到达（无约束） 
		else printf("%d\n", d[n-1]);
	}
}
