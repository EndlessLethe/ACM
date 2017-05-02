// LCA
int pa[MAX_LOG_V][MAX_V];  // ������2^k�������Ľڵ㣨������ʱ��Ϊ-1��
int depth[MAX_V];              // �ڵ�����
 
//�ڵ��Ŵ�0��ʼ 
void dfs(int v, int p, int d) {
    pa[0][v] = p;
    depth[v] = d;
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i] != p)
            dfs(G[v][i], v, d + 1);
    }
}
 
// Ԥ����
void init_lca(int V) {//init_lca(N) 
    dfs(0, -1, 0);
    // Ԥ�����pa
    for (int k = 0; k + 1 < MAX_LOG_V; k++) {
        for (int v = 0; v < V; v++) {
            if (pa[k][v] < 0)
                pa[k + 1][v] = -1;
            else {
                pa[k + 1][v] = pa[k][pa[k][v]];
            }
        }
    }
}
 
// ����u��v��LCA
int lca(int u, int v) {
    // ��u��v�����ߵ�ͬһ���
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_V; k++) {
    	//��ͬ��if(deep[a]-(1<<j)>=deep[b]) ��deep[a]-[b]�ֽ�Ϊ2�����ۼӵ���ʽ������Ҫ�ϵ��Ĵ��� 
        if ((depth[v] - depth[u]) >> k & 1) {//i�Ķ�������,ȡ��j+1λ�ϵ�ֵ
            v = pa[k][v];
        }
    }
    if (u == v) return u;
    //���ö�����������LCA ͬ��һ������
    for (int k = MAX_LOG_V - 1; k >= 0; k--) {
        if (pa[k][u] != pa[k][v]) {
            u = pa[k][u];
            v = pa[k][v];
        }
    }
    return pa[0][u];
}
 
int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

//
//ʾ������ 
//

/**
 * @Date:   19-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: POJ 1986��LCA ����������.cpp
 * @Last modified time: 20-Apr-2017
 * @Copyright: Copr. 2017 EndlessLethe. All rights reserved.
 * @Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <stack>
//#include <bits/stdc++.h>
using namespace::std;

#define MAX_V 40010
#define MAX_LOG_V 20
typedef pair<int, int> P;
vector<P> G[MAX_V];
char input[10];

void add_edge(int from, int to, int cost) {
	G[from].push_back(P(to, cost));
	G[to].push_back(P(from, cost));
}

// LCA
int pa[MAX_LOG_V][MAX_V];  // ������2^k�������Ľڵ㣨������ʱ��Ϊ-1��
int depth[MAX_V];              // �ڵ�����
int dis[MAX_V];

//�ڵ��Ŵ�0��ʼ
void dfs(int v, int p, int d, int di) {
    pa[0][v] = p;
    depth[v] = d;
	dis[v] = di;
//	printf("dis %d: %d\n", v, di);
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i].first != p)
            dfs(G[v][i].first, v, d+1, di+G[v][i].second);
    }
}

// Ԥ����
void init_lca(int V) {//init_lca(N)
    dfs(0, -1, 0, 0);
    // Ԥ�����pa
    for (int k = 0; k + 1 < MAX_LOG_V; k++) {
        for (int v = 0; v < V; v++) {
            if (pa[k][v] < 0)
                pa[k+1][v] = -1;
            else {
                pa[k+1][v] = pa[k][pa[k][v]];
            }
        }
    }
}

// ����u��v��LCA
int lca(int u, int v) {
    // ��u��v�����ߵ�ͬһ���
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_V; k++) {
    	//��ͬ��if(deep[a]-(1<<j)>=deep[b]) ��deep[a]-[b]�ֽ�Ϊ2�����ۼӵ���ʽ������Ҫ�ϵ��Ĵ���
        if ((depth[v] - depth[u]) >> k & 1) {//i�Ķ�������,ȡ��j+1λ�ϵ�ֵ
            v = pa[k][v];
        }
    }
    if (u == v) return u;
    //���ö�����������LCA ͬ��һ������
    for (int k = MAX_LOG_V - 1; k >= 0; k--) {
        if (pa[k][u] != pa[k][v]) {
            u = pa[k][u];
            v = pa[k][v];
        }
    }
    return pa[0][u];
}

int dist(int u, int v) {
//	printf("lca%d %d: %d\n", u, v, lca(u, v));
    return dis[u] + dis[v] - 2 * dis[lca(u, v)];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	int N, M, u, v, c, k;
	while (scanf("%d%d", &N, &M) == 2) {
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d%s", &u, &v, &c, input);
			add_edge(u-1, v-1, c);
		}
		init_lca(N);
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &u, &v);
			printf("%d\n", dist(u-1, v-1));
		}
		for (int i = 0; i < N; i++) if (!G[i].empty()) G[i].clear();
	}
	return 0;
}
