/**
 * @Date:   28-Jun-2018
 * @Email:  zengsw_study@qq.com
 * @Filename: POJ 3259【bellman-ford】.cpp
 * @Last modified time: 28-Jun-2018
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

const int MAXN = 500+10;
int G[MAXN][MAXN];
int d[MAXN];
int vis[MAXN];
queue <int> q;

bool bellman_ford(int s, int N) {
	d[s] = 0;
	int cnt = 0;
	q.push(s);
	q.push(cnt);
	vis[s] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		cnt = q.front(); q.pop();
		vis[x] = 0;
		if (cnt > N) return 0;
		for (int i = 0; i < N; i++) {
			if (d[i] > d[x] + G[x][i]) {
				d[i] = d[x] + G[x][i];
				if (!vis[i]) {
					q.push(i);
					q.push(cnt+1);
					vis[i] = 1;
				}
			}
		}
	}
	return 1;
}

int main() {
	int F, N, M, W, S, E, T;
	cin >> F;
	while (F--) {
		while (!q.empty()) q.pop();
		memset(G, 0x3f, sizeof(G));
		memset(d, 0x3f, sizeof(d));
		memset(vis, 0, sizeof(vis));
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			S--, E--;
			if (T < G[S][E]) G[S][E] = G[E][S] = T;
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			S--, E--;
			G[S][E] = -T;
		}
		if (bellman_ford(0, N)) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
