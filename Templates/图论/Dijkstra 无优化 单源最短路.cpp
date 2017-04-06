#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int INF = 0x7fffffff;
const int MAX_V = 10100;
int cost[MAX_V][MAX_V];//cost[u][v]表示边e=(u,v)的权值（不存在时为INF） 
int d[MAX_V];//顶点s出发的最短距离 
bool used[MAX_V];//已经使用过的点 
int V;//顶点数 

//求从起点s出发到各个顶点的最短距离 
void dijkstra(int s) {
	fill(d, d+V, INF);
	fill(used, used+V, false);
	d[s] = 0;

	while (true) {
		int u = -1;
		for (int i = 0; i < V; i++) {
			if (!used[i] && (u == -1 || d[i] < d[u])) u = i;
		}

		if (u == -1) break;
		used[u] = true;

		for (int i = 0; i < V; i++) {
			d[i] = min(d[i], d[u] + cost[u][i]);
		}
	}
}

int main() {
    int T, u, v, temp, N, M;
	while (scanf("%d%d", &N, &M) == 2) {
		if (M == 0 && N == 0) break;
		memset(cost, 0, sizeof(cost));
		V = N;//初始化全局变量V 
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &u, &v, &temp);
			u--;
			v--;
			cost[u][v] = cost[v][u] = temp;//边的计数从0开始 
		}
		dijkstra(0);
		if (N != 1) printf("%d\n", d[N-1]);
		else printf("0\n");
	}
    return 0;
}
