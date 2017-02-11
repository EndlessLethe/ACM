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

const int maxn = 1000010;

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
   	int c;
	Node(int v, int c) :v(v), c(c) {
		r = mr.rand();
		ch[0] = ch[1] = NULL;
	}
	int cmp(int x) const {
		if (x == v) return -1;
		return x < v ? 0 : 1;
	}
};



void printtree(Node* &src) {
	if (src->ch[0] != NULL) printtree(src->ch[0]);
	if (src->ch[1] != NULL) printtree(src->ch[1]);
	cout << " " << src->c << endl;
}

void rotate(Node* &o, int d) {
	Node* k = o->ch[d^1];
	o->ch[d^1] = k->ch[d];
	k->ch[d] = o;
	o = k;
}

void insert(Node* &o, int x, int y) {//在以o为根的子树中插入键值x 
	if (o == NULL) o = new Node(x, y);
	else {
		int d = (x < o->v ? 0 : 1);
		insert(o->ch[d], x, y);
		if (o->ch[d]->r > o->r) rotate(o, d^1);
	}
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
}

int find_min(Node* o) {//查找某一元素是否存在
	if (o == NULL) return 0;
	while (o != NULL) {
		if (o->ch[0] != NULL) o = o->ch[0];
		else break;
	}
	cout << o->c << endl;
	return o->v;
}

int find_max(Node* o) {//查找某一元素是否存在
	if (o == NULL) return 0;
	while (o != NULL) {
		if (o->ch[1] != NULL) o = o->ch[1];
		else break;
	}
	cout << o->c << endl;
	return o->v;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int N, a, b;
    Node* root = NULL;
    while (cin >> N) {
    	if (N == 0) return 0;
		else if (N == 1) {
    		cin >> a >> b;
    		insert(root, b, a);
		}
		else if (N == 2) {
			int temp = find_max(root);
			if (temp == 0) cout << "0" << endl;
			else remove(root, temp);
		}
		else if (N == 3) {
			int temp = find_min(root);
			if (temp == 0) cout << "0" << endl;
			else remove(root, temp);
		}
	}
    return 0;
}
