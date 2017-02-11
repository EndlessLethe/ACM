/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/5/18 16:09:15
File Name     :POJ 3469..cpp
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

const int MAX_V = 20010;
const int INF = 0x7fffffff;

struct edge {int to, cap, rev;};
vector <edge> G[MAX_V];
int level[MAX_V];//��ԭ��ľ��� 
int iter[MAX_V];//��ǰ�� 

void add_edge(int from, int to, int cap) {
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size()-1});
}

void bfs(int s) {//������ǰ��������Ĳ��ͼ 
//	printf("a new layer");
	memset(level, -1, sizeof(level));//ע����-1 
	queue<int> q;
	level[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
//			printf("whyyyyyyyyyyyyyyyyyyyyyyyyyyyyy %d %d %d\n", e.to, level[e.to], v);
			if (e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] +1;
				q.push(e.to); 
//				printf("whyyyyyyyyyyyyyyyyyyyyyyyyyyyyy %d %d %d\n", e.to, level[e.to], v);
			}
//			printf("%d %u %d %d\n", i, G[v].size(), e.to, level[e.to]);
		}
	}
}

int dfs(int v, int t, int f) {
	if (v == t) return f;//fΪ��ǰ�ܴ�������ֵ 
	for (int &i = iter[v]; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to]) {//��֤���������not only+1�� 
			int d = dfs(e.to, t, min(f, e.cap));//min��һ��ƿ�� 
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;
//	printf("3333");
	for (;;) {
		bfs(s);
		if (level[t] < 0) return flow;
		memset(iter, 0, sizeof(iter));
		int f = dfs(s, t, INF);
//		printf("why??");
		while (f > 0) {
			flow += f;
//			printf("%d", f);
			f = dfs(s, t, INF);
		}
	}
}

int main()
{
//    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int N, M, A, B, a, b, c;
    scanf("%d%d", &N, &M);
    int s = N, t = s + 1;
    for (int i = 0; i < N; i++) {
    	scanf("%d%d", &A, &B);
    	add_edge(s, i, A);
    	add_edge(i, t, B);
	}
	for (int i = 0; i < M; i++){
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a-1, b-1, c);
		add_edge(b-1, a-1, c);
	}
	printf("%d\n", max_flow(s, t));
    return 0;
}
