/**
 * @Date:   20-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: POJ 1986��LCA RMQ������.cpp
 * @Last modified time: 21-Apr-2017
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

// LCA
struct edge {
	int from, to, weight;
};
vector<edge> G[MAX_V];     // ͼ���ڽӱ��ʾ
int vs[MAX_V * 2 - 1];     // DFS���ʵ�˳��
int depth[MAX_V * 2 - 1];  // �ڵ�����
int id[MAX_V];             // ����������vs���״γ��ֵ��±�
int dis[MAX_V];           // �ڵ㵽���ڵ�ľ���
char input[10];
int d[MAX_V * 2 - 1][MAX_LOG_V];  // RMQ��BinaryIndexedTree�ڵ�

//������A����һ��d���������� ����Ai=min{AL, ..., AR}��i
//����:A�ĳ���n
void rmq_init(int n) {
    for (int i = 0; i < n; i++) {
        d[i][0] = i;
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            if (depth[d[i][j-1]] <= depth[d[i+(1 << (j-1))][j-1]]) {
                d[i][j] = d[i][j-1];
            }
            else {
                d[i][j] = d[i+(1 << (j-1))][j-1];
            }
        }
    }
}

int query(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) < r-l+1) k++;
    if (depth[d[l][k]] <= depth[d[r-(1 << k)][k]]) {
        return d[l][k];
    }
    else {
        return d[r-(1 << k)][k];
    }
}

void dfs(int v, int p, int d, int &k) {
    id[v] = k;
    vs[k] = v;
    depth[k++] = d;
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i].to != p) {
            dis[G[v][i].to] = dis[v] + G[v][i].weight;
            dfs(G[v][i].to, v, d + 1, k);
            vs[k] = v;
            depth[k++] = d;
        }
    }
}

// Ԥ����
void init_lca(int V) {
    // Ԥ�����vs��depth��id
    int k = 0, root = 0;
    dfs(root, -1, 0, k);
    // Ԥ�����RMQ�����صĲ�����Сֵ��������Сֵ��Ӧ���±꣩
    rmq_init(V * 2 - 1);
}

// ����u��v��LCA
int lca(int u, int v) {
    return vs[query(min(id[u], id[v]), max(id[u], id[v]) + 1)];
}

int dist(int u, int v) {
//	printf("lca%d %d: %d\n", u, v, lca(u, v));
    return dis[u] + dis[v] - 2 * dis[lca(u, v)];
}

void add_edge(int from, int to, int cost) {
	G[from].push_back(edge{from, to, cost});
	G[to].push_back(edge{to, from, cost});
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
