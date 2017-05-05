/**
 * @Date:   01-May-2017
 * @Email:  809810527@qq.com
 * @Filename: H_D Tree.cpp
 * @Last modified time: 02-May-2017
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
#pragma comment(linker,"/STACK:102400000,102400000")
#define INF 0x7fffffff
#define MAXN 100010
#define MAXM 100010
#define P 1000003
typedef long long ll;

struct node{
	int to, next;
} e[MAXM*2];
int len, sum, root, head[MAXN], f[MAXN], vis[MAXN], size[MAXN];
ll d[MAXN], deep[MAXN];
//int mp[P+2];
map<ll, int> mp;
int ans[2], W[MAXN], V[MAXN];
int n, K;

ll ine[P+2];
void pre() {
    ine[1] = 1;
    for (int i  = 2; i < P; i++) {
        int a = P-P/i, b = P%i;
        ine[i] = ine[b]*a%P;
		// if (i < 20) printf("%d %lld\n", i, ine[i]);
    }
}

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

//len为前向星的长度，初始化为0
//边的编号从1开始
void insert(int from, int to) {
	e[++len].next = head[from];
	head[from] = len;
	e[len].to = to;
}

//开始时的调用
//f[0] = INF; root = 0; sum = n; getroot(1, 0); solve(root);
void getroot(int v, int fa) {
	size[v] = 1;
	f[v] = 0;
	for (int i = head[v]; i; i = e[i].next) {
		if (e[i].to == fa || vis[e[i].to]) continue;
		getroot(e[i].to, v);
		size[v] += size[e[i].to];
		f[v] = max(f[v], size[e[i].to]);
	}
	f[v] = max(f[v], sum - size[v]);
	if (f[v] < f[root]) root = v;
}

void getans(int x, int y) {
	if (x > y) swap(x, y);
	if (ans[0] > x) {
		ans[0] = x;
		ans[1] = y;
	}
	else if (ans[0] == x) ans[1] = min(ans[1], y);
}

//对子树进行深度遍历
//可以证明一共找重心不超过logN,故总的复杂度不超过NlogN
void dfs(int v, int fa) {
	deep[++deep[0]] = d[v];//deep用来记录子树各点的信息
	V[deep[0]] = v;
//	 printf("to v %d d[v] %d id %d fa %d\n", v, d[v], deep[0], fa);
	for (int i = head[v]; i; i = e[i].next) {
		if (e[i].to == fa || vis[e[i].to]) continue;
		d[e[i].to] = d[v] * W[e[i].to] % P;
		dfs(e[i].to, v);
	}
}

//对于根的计算调用cal(v, 0);
int cal(int v, int w) {
//	printf("v clear %d\n", v);
	mp.clear();
//	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) printf("mp %d\n", (*it).first);
	deep[0] = 0;
	d[v] = w;
	deep[++deep[0]] = d[v];//deep用来记录子树各点的信息
	V[deep[0]] = v;
	mp[1] = v;
	for (int i = head[v]; i; i = e[i].next) {
		if (vis[e[i].to]) continue;
		d[e[i].to] = d[v] * W[e[i].to] % P;
		int tmp = deep[0];
		dfs(e[i].to, v);
		// printf("%d %d\n", tmp, deep[0]);
		for (int j = tmp+1; j < deep[0]+1; j++) {
			ll tmp = K*ine[W[v]*deep[j]%P]%P;
//			 printf("存在:%d 根:%d 点：%d 乘积：%d 逆：%d\n",
//			 tmp, v, V[j], W[v]*deep[j], K*ine[W[v]*deep[j]%P]%P);
			//deep[j]储存multi, mp储存对应multi的节点, V[j]储存deep对应的节点 
			if (mp[tmp]) getans(V[j], mp[tmp]);
		}
		for (int j = tmp+1; j < deep[0]+1; j++) {
			mp[deep[j]] = V[j];
//			 printf("push:%d %d\n", deep[j], V[j]);
		}
	}
	return 0;
}

void solve(int v) {
	cal(v, 1);
	vis[v] = 1;
	for (int i = head[v]; i; i = e[i].next) {
		if (vis[e[i].to]) continue;
		// ans -= cal(e[i].to, w[i]);//在子树中去掉重复的部分
		sum = size[e[i].to];//开始给子树找重心
		root = 0;
		getroot(e[i].to, 0);
		solve(root);
	}
}

void init() {
	ans[0] = INF, ans[1] = INF, root = 0, len = 0;
	memset(head, 0, sizeof(head));
	memset(vis, 0, sizeof(vis));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        freopen("input_H_D Tree.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	int u, v;
	pre();
	while(scanf("%d%d",&n,&K) == 2) {
		init();
		for (int i = 1; i <= n; i++) {
			W[i] = read();
		}
		for (int i = 0; i < n-1; i++) {
			u = read(), v = read();
			insert(u, v);
			insert(v, u);
		}
		f[0] = INF;
		sum = n;
		getroot(1, 0);
		solve(root);
		if (ans[0] != INF) printf("%d %d\n", ans[0], ans[1]);
		else printf("No solution\n");
	}
	return 0;
}
