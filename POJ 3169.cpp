/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/5/18 21:42:52
File Name     :POJ 3169.cpp
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

struct Bellman_Ford {
	int n, m;
	vector <Edge> edge;
	vector <int> G[MAX_N];
	bool inq[MAX_N];//是否在队列中 
	int d[MAX_N];//s到各点的距离 
	int p[MAX_N];//最短路上的上一条弧
	int cnt[MAX_N];//进队次数 

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) G[i].clear();
		edge.clear();
	}

	void add_edge(int from, int to, int dist) {
		edge.push_back((Edge){from, to, dist});
		m = edge.size();
		G[from].push_back(m-1);
	}

	bool negative_cycle() {
		queue <int> q;
		memset(inq, 0, sizeof(inq));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			d[i] = 0;
			inq[0] = 0;
			q.push(i);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				inq[u] = false;
				for (int i = 0; i < G[u].size(); i++) {
					edge &e = edge[G[u][i]];
					if (d[e.to] > d[u] + e.dist) {
						d[e.to] = d[u] + e.dist;
						p[e.to] = G[u][i];
						if (!inq[e.to]) {
							q.push(e.to);
							inq[e.to] = true;
							if (++cnt[e.to] > n) return true;
						}
					}
				}
			}
		}
		return false;
	}
};




int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    return 0;
}
