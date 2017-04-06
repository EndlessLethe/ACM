#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int INF = 0x7fffffff;
const int MAX_V = 10100;
struct edge { int to, cost;};
typedef pair<int, int> P;
int d[MAX_V];//顶点s出发的最短距离 
int V;//顶点数 
vector <edge> G[MAX_V];

void add_edge(int from, int to, int val) {//add_edge(a-1,b-1,c)
	G[from].push_back(edge{to, val});
	G[to].push_back(edge{from, val});
}

//求从起点s出发到各个顶点的最短距离 
void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+V, INF);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main() {
    int T, u, v, temp, N, M;
	while (scanf("%d%d", &N, &M) == 2) {
		if (M == 0 && N == 0) break;
		V = N;//初始化全局变量V 
		for (int i = 0; i < V; i++) G[i].clear();
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &u, &v, &temp);
			add_edge(u-1, v-1, temp);//边的计数从0开始 
			add_edge(v-1, u-1, temp);
		}
		dijkstra(0);
		if (N != 1) printf("%d\n", d[N-1]);
		else printf("0\n");
	}
    return 0;
}
