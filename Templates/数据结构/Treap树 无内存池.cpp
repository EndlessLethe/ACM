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

struct MyRand {//每次迭代利用x
	int a, b, p;
	long long x;
	MyRand() {
		a = 810; b = 1102; p = 1992122981; x = 617;
	}
	int rand() {return x = (a * x + b) % p;}
}

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
}

void rotate(Node* &o, int d) {
	Node* k = o->ch[d^1];
	o->ch[d^1] = k->ch[d];
	k->ch[d] = o;
	o->maintain();//务必要先o
	k->maintain();
	o = k;
}

//在以o为根的子树中插入键值x
void insert(Node* &o, int x) { 
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
		remove(o->ch[d], x);
	}
	if (o != NULL) o->maintain();
}

//在insert和remove前查找某一元素是否存在
int find(Node* o, int x) {
	while (o != NULL) {
		int d = o->cmp(x);
		if (d == -1) return 1;
		else o = o->ch[d];
	}
	return 0;
}

//查询第k大
int kth(Node* o, int k) {
	if (o == NULL || k < 0 || k > o->s) return 0;
	int s = (o->ch[1] == NULL ? 0 : o->ch[1]->s);
	if (k == s+1) return o->v;
	else if (k <= s) return kth(o->ch[1], k);
	else return kth(o->ch[0], k-s-1);
}

//将src逐一插入到dest中,可以在调用之前“启发式”一下(比较元素数量)
//复杂度O(src log dest) 
void merge(Node* &src, Node* &dest) {
	if (src->ch[0] != NULL) merge(src->ch[0], dest);
	if (src->ch[1] != NULL) merge(src->ch[1], dest);
	insert(dest, stc->v);
	delete src;
	src = NULL;
}


void removeTree(Node* &x) {
	if (x->ch[0] != NULL) removeTree(x->ch[0]);
	if (x->ch[1] != NULL) removeTree(x->ch[1]);
	delete x;
	x = NULL;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    return 0;
}
