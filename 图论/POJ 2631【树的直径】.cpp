/**
 * @Date:   10-Jul-2018
 * @Email:  zengsw_study@qq.com
 * @Filename: POJ 2631【树的直径】.cpp
 * @Last modified time: 10-Jul-2018
 * @Copyright: ©2018 EndlessLethe. All rights reserved.
 */


#pragma comment(linker, "/STACK:102400000,102400000")

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long ll;
int N;
const int MAXN = 10000+50;
struct edge {
	int v, w;
	edge(int v, int w):v(v), w(w){;}
};
vector<edge> G[MAXN];
void add_edge(int u, int v, int w) {
	G[u].push_back(edge(v,w));
	G[v].push_back(edge(u,w));
}
int vis[MAXN];
int d[MAXN];

queue<int> q;
int bfs(int s) {
	memset(d, 0, sizeof(d));
	memset(vis, 0, sizeof(vis));
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int tmp = q.front(); q.pop();
//		cout << tmp << endl;
		for (int i = 0; i < G[tmp].size(); i++) {
			edge e = G[tmp][i];
			if (vis[e.v]  != 1) {
				d[e.v] = d[tmp] + e.w;
				q.push(e.v);
				vis[e.v] = 1;
			}
		}
	}
	int res = 0, val = 0;
	for (int i = 0; i < N; i++) {
		if (val < d[i]) {
			val = d[i];
			res = i;
		}
	}
	return res;
}

int main(int argc, char const *argv[]) {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	int U, V, W;
	while (cin >> U >> V >> W) {
		N = max(N, U);
		N = max(N, V);
		U--, V--;
		add_edge(U, V, W);
	}
	int s = bfs(0);
	s = bfs(s);
	cout << d[s] << endl;
	return 0;
}
