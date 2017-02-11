/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/5/12 13:52:44
File Name     :南阳理工OJ 20 吝啬的国度.cpp
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

const int MAX = 100010;
int p[MAX];
vector<int> G[MAX];

void dfs(int u, int fa) {
	if (G[u].size() == 1) return;
	for (int i = 0; i < G[u].size(); i++) {
		if (G[u][i] != fa) dfs(G[u][i], p[G[u][i]] = u);
	}
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	int cases, N, S, u, v;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%d", &N, &S);
		for (int i = 0; i < MAX; i++) G[i].clear();
		memset(p, 0, sizeof(p));
		for (int i = 0; i < N-1; i++)	{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		p[S] = -1;
		G[S].push_back(-1);
		dfs(S, -1);
		for (int i = 1; i <= N; i++) {
			if (i != N) printf("%d ", p[i]);
			else printf("%d", p[i]);
		}
		printf("\n");
	}
    return 0;
}
