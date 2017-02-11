/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/8/14 11:25:25
File Name     :O.cpp
Description   :
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int INF = 0x7fffffff;
const int MAX_V = 1010;
int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V;

void dijkstra(int s) {
	fill(d, d+V, 0);
	fill(used, used+V, false);
	d[s] = INF;

	while (1) {
		int u = -1;
		for (int i = 0; i < V; i++) {
			if (!used[i] && (u == -1 || d[i] > d[u])) u = i;
		}

		if (u == -1) break;
		used[u] = true;

		for (int i = 0; i < V; i++) {
			if (cost[u][i] > 0) d[i] = max(d[i], min(d[u], cost[u][i]));
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int T, u, v, temp, N, M;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(cost, 0, sizeof(cost));
		scanf("%d%d", &N, &M);
		V = N;
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &u, &v, &temp);
			u--;
			v--;
			cost[u][v] = cost[v][u] = temp;
		}
		dijkstra(0);
		if (N != 1) printf("Scenario #%d:\n%d\n\n", t, d[N-1]);
		else printf("Scenario #%d:\n0\n\n", t);
	}
    return 0;
}
