/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/6/11 12:06:58
File Name     :POJ 3169【重做】.cpp
Description   :差分约束系统
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

struct Edge {int from, to, dist;};
const int MAX = 1010;
const int INF = 0x7fffffff;
int inq[MAX], cnt[MAX], d[MAX];
vector <int> G[MAX];
vector <Edge> edge;
int N;

void add_edge(int from, int to, int dist) {
	edge.push_back((Edge){from, to, dist});
	int m = edge.size();
	G[from].push_back(m-1);
}

bool bellman_ford(int s) {
	queue <int> q;
	memset(inq, 0, sizeof(inq));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < N; i++) d[i] = INF;
	d[s] = 0;
	inq[s] = true;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i = 0; i < G[u].size(); i++) {
			Edge &e = edge[G[u][i]];
			if (d[u] < INF && d[e.to] > d[u] + e.dist) {
				d[e.to] = d[u] + e.dist;
				if (!inq[e.to]) {
					q.push(e.to);
					inq[e.to] = true;
					if (++cnt[e.to] > N) return false;
				}
			}
		}
	}
	return true;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int ML, MD, A, B, D;
	cin >> N >> ML >> MD;
	for (int i = 0; i < ML; i++) {
		cin >> A >> B >> D;
		add_edge(A-1, B-1, D);
	}
	for (int i = 0; i < MD; i++) {
		cin >> A >> B >> D;
		add_edge(B-1, A-1, -D);
	}
	for (int i = 0; i < N-1; i++) {
		add_edge(i+1, i, 0);
	}
	bool whether = bellman_ford(0);
	if (!whether) cout << -1 << endl;
	else {
		if (d[N-1]-d[0] >= INF) cout << -2 << endl;
		else cout << d[N-1]-d[0] << endl;
	}
//	for (int i = 0; i < N; i++) cout << d[i] << " " << endl;
    return 0;
}
