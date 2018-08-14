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

bool bellman_ford(int s, int N) {
	int flag;
	for (int i = 0; i < N; i++) {
		flag = 0;//如果不能松弛，则停止
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (d[k] > d[j] + G[j][k]) {
					d[k] = d[j] + G[j][k];
					flag = 1;
				}
			}
		}
		if (!flag) return 1;//不存在负环
	}
	flag = 0;
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			if (d[k] > d[j] + G[j][k]) {
				flag = 1;
			}
		}
	}
	return !flag;
}

int main() {
	int F, N, M, W, S, E, T;
	cin >> F;
	while (F--) {
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
