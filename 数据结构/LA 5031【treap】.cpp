/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/7/18 9:30:16
File Name     :LA 5031.cpp
Description   :treap树
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

const int maxc = 50000+10;
struct Command {
	char type;
	int x, p;
} commands[maxc];
const int maxn = 20000+10;
const int maxm = 60000+10;
int n, m, weight[maxn], from[maxm], to[maxm], removed[maxm];

struct MyRand {//每次迭代利用x
	int a, b, p;
	long long x;
	MyRand() {
		a = 810; b = 1102; p = 1992122981; x = 617;
	}
	int rand() {return x = (a * x + b) % p;}
};

MyRand mr;

struct Node {
	Node *ch[2];
	int r; //优先级
   	int v; //值
   	int s; //子树节点数
	Node(int v) :v(v) {
		ch[0] = ch[1] = NULL;
		r = mr.rand();
		s = 1;
	}
	bool operator < (const Node& rhs) const {
		return r < rhs.r;
	}
	int cmp(int x) const {
		if (x == v) return -1;
		return x < v ? 0 : 1;
	}
	void maintain() {//维护其子树的结点数
		 s = 1;
		 if (ch[0] != NULL) s += ch[0]->s;
		 if (ch[1] != NULL) s += ch[1]->s;
	}
};

void rotate(Node* &o, int d) {
	Node* k = o->ch[d^1];
	o->ch[d^1] = k->ch[d];
	k->ch[d] = o;
	o->maintain();//务必要先o
	k->maintain();
	o = k;
}

void insert(Node* &o, int x) {//在以o为根的子树中插入键值x 
	if (o == NULL) o = new Node(x);
	else {
		int d = (x < o->v ? 0 : 1);
		insert(o->ch[d], x);
		if (o->ch[d]->r > o->r) rotate(o, d^1);
	}
	o->maintain();
}

void remove(Node* &o, int x) {
	int d = o->cmp(x);
	if (d == -1) {
		Node* u = o;
		if (o->ch[0] != NULL && o->ch[1] != NULL) {
			int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
			rotate(o, d2);
			remove(o->ch[d2], x);
		}
		else {
			if (o->ch[0] == NULL) o = o->ch[1];
			else o = o->ch[0];
			delete u;
		}
	}
	else {
		remove(o->ch[0], x);
	}
	if (o != NULL) o->maintain();
}

int find(Node* o, int x) {//查找某一元素是否存在
	while (o != NULL) {
		int d = o->cmp(x);
		if (d == -1) return 1;
		else o = o->ch[d];
	}
	return 0;
}

int kth(Node* o, int k) {//查询第k大
	if (o == NULL || k < 0 || k > o->s) return 0;
	int s = (o->ch[1] == NULL ? 0 : o->ch[1]->s);
	if (k == s+1) return o->v;
	else if (k <= s) return kth(o->ch[1], k);
	else return kth(o->ch[0], k-s-1);
}

void mergeto(Node* &src, Node* &dest) {
	if (src->ch[0] != NULL) mergeto(src->ch[0], dest);
	if (src->ch[1] != NULL) mergeto(src->ch[1], dest);
	insert(dest, src->v);
	delete src;
	src = NULL;
}


void removetree(Node* &x) {
	if (x->ch[0] != NULL) removetree(x->ch[0]);
	if (x->ch[1] != NULL) removetree(x->ch[1]);
	delete x;
	x = NULL;
}

int pa[maxn];
int findset(int x) {
	return pa[x] != x ? pa[x] = findset(pa[x]) : x;
}

Node* root[maxn];

void add_edge(int x) {
	int u = findset(from[x]), v = findset(to[x]);
	if (u != v) {
		if (root[u]->s < root[v]->s) {
			pa[u] = v;
			mergeto(root[u], root[v]);
		}
		else {
			pa[v] = u;
			mergeto(root[v], root[u]);
		}
	}
}

int query_cnt;
long long query_tot;
void query(int x, int k) {
	query_cnt++;
	query_tot += kth(root[findset(x)], k);
}

void change_weight(int x, int v) {
	int u = findset(x);
	remove(root[u], weight[x]);
	insert(root[u], v);
	weight[x] = v;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int kase = 0;
	while(scanf("%d%d", &n, &m) == 2 && n) {
		for (int i = 0; i <= n; i++) scanf("%d", &weight[i]);
		for (int i = 0; i <= m; i++) scanf("%d%d", &from[i], &to[i]);
		memset(removed, 0, sizeof(removed));

		int c = 0;
		for (;;) {
			char type;
			int x, p = 0, v = 0;
			scanf(" %c", &type);
			if (type == 'E') break;
			scanf("%d", &x);
			if (type == 'D') removed[x] = 1;
			if (type == 'Q') scanf("%d", &p);
			if (type == 'C') {
				scanf("%d", &v);
				p = weight[x];
				weight[x] = v;
			}
			commands[c++] = (Command) {type, x, p};
		}

		for (int i = 1; i <= n; i++) {
			pa[i] = i;
			if (root[i] != NULL) removetree(root[i]);
			root[i] = new Node(weight[i]);
		}
		for (int i = 1; i <= m; i++) if (!removed[i]) add_edge(i);

		query_tot = query_cnt = 0;
		for (int i = c-1; i >= 0; i--) {
			if (commands[i].type == 'D') add_edge(commands[i].x);
			if (commands[i].type == 'Q') query(commands[i].x, commands[i].p);
			if (commands[i].type == 'C') change_weight(commands[i].x, commands[i].p);
		}
		printf("Case %d: %.6lf\n", ++kase, query_tot/ (double)query_cnt);
	}
    return 0;
}
