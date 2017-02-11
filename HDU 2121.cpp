/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/5/17 17:03:48
File Name     :HDU 2121.cpp
Description   :
************************************************ */

#include <stdio.h>
#include <string.h>

using namespace std;

const int MAX_V = 1010;
const int INF = 0x7fffffff;

struct node {
	int u, v;
	int w;
} edge[MAX_V * MAX_V];

int pre[MAX_V], id[MAX_V], vis[MAX_V];
int in[MAX_V];
int son;

int Directed_MST(int root, int V, int E) {
	int cost = 0;
	while (1) {
		for (int i = 0; i < V; i++) {
			in[i] = INF;
		}
		for (int i = 0; i < E; i++) {
			int u = edge[i].u;
			int v = edge[i].v;
			if (edge[i].w < in[v] && u != v) {
				pre[v] = u;
				in[v] = edge[i].w;
				if (u == root) son = i; 
			}
		}
		for (int i = 0; i < V; i++)	{
			if (i == root) continue;
			if (in[i] == INF) return -1;
		}

		int cnt = 0;
		memset(id, -1, sizeof(id));
		memset(vis, -1, sizeof(vis));
		in[root] = 0;
		for (int i = 0; i < V; i++) {
			cost += in[i];
			int v = i;
			while (vis[v] != i && id[v] == -1 && v != root) {
				vis[v] = i;
				v = pre[v];
			}
			if (v != root && id[v] == -1) {
				for (int u = pre[v]; u != v; u = pre[u]) {
					id[u] = cnt;
				}
				id[v] = cnt++;
			}
		}
		if (cnt == 0) break;
		for (int i = 0; i < V; i++) {
			if (id[i] == -1) id[i] = cnt++;
		}
		for (int i = 0; i < E; i++) {
			int u = edge[i].u;
			int v = edge[i].v;
			edge[i].u = id[u];
			edge[i].v = id[v];
			if (edge[i].u != edge[i].v) edge[i].w -= in[v];
		}
		V = cnt;
		root = id[root];
	}
	return cost;
}
int main()
{
	#ifdef LOCAL
		freopen("input_HDU 2121.txt", "r", stdin);
	#endif
	int N, M, r;
	while (scanf("%d%d", &N, &M) == 2) {
		r = 0;
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
			r += edge[i].w;//注意 
			if (edge[i].u == edge[i].v) edge[i].w = INF;
		}
		r++; 
		for (int i = M; i < M+N; i++) {
			edge[i].u = N;
			edge[i].v = i-M;//注意 
			edge[i].w = r;
		}
		int ans = Directed_MST(N, N+1, M+N);//注意 
//		printf("%d %d %d ", N, M+N, ans);
		if (ans == -1 || ans >= 2*r) printf("impossible\n");
		else printf("%d %d\n", ans-r, son-M);//注意 
		printf("\n");
	} 
    return 0;
}
