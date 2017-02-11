#include <queue>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct Edge{
	int from, to, dist;
};

const int MAX_V = 1010;
const int INF = 0x7fffffff;
int inq[MAX_V];//是否在队列中 
int d[MAX_V];//s到各点的距离 
//int p[MAX_V];//最短路中的上一条弧  现在没用，后面Dinic有用 
int cnt[MAX_V];//进队次数 

int height[MAX_V];
vector <int> G[MAX_V];
vector <Edge> edge;
int n;

struct building{
	int num, height;
}B[MAX_V];

int cmp(const void *a, const void *b) {
	struct building *c = (struct building *) a;
	struct building *d = (struct building *) b;
	return d->height - c->height;
}

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
//				p[e.to] = G[u][i];
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
	#ifdef LOCAL
		freopen("in.txt", "r", stdin);
	#endif
	int cases, N, D, temp;
	scanf("%d", &cases);
	for (int what = 1; what <= cases; what++) {
		scanf("%d%d", &N, &D);
		memset(B, 0, sizeof(B));
		for (int i = 0; i < N; i++) G[i].clear();
		for (int i = 0; i < N; i++) {
			scanf("%d", &B[i].height);
			B[i].num = i;
//			printf("%d %d \n", B[i].height, B[i].num);
		}
		qsort(B, N, sizeof(B[0]),cmp);
		int st = B[0].num < B[N-1].num ? B[0].num : B[N-1].num;
		int ed = B[0].num < B[N-1].num ? B[N-1].num : B[0].num;
//		for (int i = 0; i < N; i++) printf("%d %d\n", B[i].height, B[i].num);
//		printf("%d %d", st, ed);
		for (int i = 0; i < N-1; i++) {
			add_edge(i+1, i, -1);//注意 
			if (B[i].num > B[i+1].num) add_edge(B[i+1].num, B[i].num, D);
			else add_edge(B[i].num, B[i+1].num, D);
		}
		bool wether = bellman_ford(st);
		if (!wether) printf("Case %d: -1\n", what);
		else printf("Case %d: %d\n", what,d[ed]);
//		else printf("%d\n", d[B[0].num<B[N-1].num?B[N-1].num:B[0].num]);
	}
}
