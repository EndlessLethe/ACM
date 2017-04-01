/* ***********************************************
Author        :EndlessLethe
Created Time  :2016/7/20 15:49:41
File Name     :UVa 11922 【splay】.cpp
Description   :
主要支持以下操作：
1.splay 将左数第k个元素旋转到根（不改变中序遍历/保持原本的大小关系）
2.split 把第k小的元素伸展到根，然后断开树根及其右子树的连接关系
3.merge 合并left和right。假设left的所有元素比right小（才能保证有序）。
  注意：right可以为null，left不可以
4.pushDown 如果该节点有标记，则执行操作并下放标记 
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


struct Node {
	Node *ch[2];
	int v = 0, s;//v在这里是1到n，其他地方可能是传入的字符串str[v]
	int flip;//标记
	//每个Node有s,v和flip标记,三个成员  
	Node(){}
	Node(int v, Node* null):v(v) {
		s = 1;
		ch[0] = ch[1] = null;
		flip = 0;
	}
	int cmp(int x) const {//比较的是位序 
		int ss = ch[0]->s;
		if (x == ss + 1) return -1;
		return x < ss + 1 ? 0 : 1;
	}
	void maintain() {
		s = 1;
		s += ch[0]->s + ch[1]->s;
	}
};

Node *root, *null;

void build(Node* &o, int n) {
	if (n >= 0) {//虚拟节点0
		o = new Node(n, null);
		build(o->ch[0], n-1);
		o->maintain();
	}
}

void init(int n) {
	null = new Node;
	null->ch[0] = null->ch[1] = null;
	null->v = null->s = null->flip = 0;
	root = null;
	build(root, n);
}

void rotate(Node* &o, int d) {
	Node *k = o->ch[d^1];
	o->ch[d^1] = k->ch[d];
	k->ch[d] = o;
	o->maintain();
	k->maintain();
	o = k;
}

//如果该节点有标记，则执行操作并下放标记 
void pushDown(Node * &o) {
	if (o->flip) {
		o->flip = 0;
		swap(o->ch[0], o->ch[1]);
		o->ch[0]->flip ^= 1;
		o->ch[1]->flip ^= 1;
	}
}

//将左数第k个元素旋转到根（不改变中序遍历/保持原本的大小关系）
void splay(Node * &o, int k) {
	pushDown(o);//
	int d = o->cmp(k);
	if (d == 1) k -= o->ch[0]->s + 1;
	if (d != -1) {
		Node *p = o->ch[d];
		pushDown(p);//
		int d2 = p->cmp(k);
		int k2 = (d2 == 0 ? k : k - p->ch[0]->s - 1);
		if (d2 != -1) {
			splay(p->ch[d2], k2);
			if (d == d2) rotate(o, d^1);
			else rotate(o->ch[d], d);
		}
		rotate(o, d^1);
	}
}

//合并left和right。假设left的所有元素比right小。注意：right可以为null，left不可以
Node* merge(Node* left, Node* right) {。
	splay(left, left->s);
	left->ch[1] = right;
	left->maintain();
	return left;
}

//把第k小的元素伸展到根，然后断开树根及其右子树的连接关系 
//把o的前k小的节点放在left里（包括一个虚拟节点），其他的放在right里。当k=o->s时，right = NULL
void split(Node* o, int k, Node* &left, Node* &right) {
	splay(o, k);
	left = o;
	right = o->ch[1];
	o->ch[1] = null;
	left->maintain();
}

void print(Node* root) {
	if (root == null) return;
	pushDown(root);
	print(root->ch[0]);
	if (root->v > 0) cout << root->v << endl;
	print(root->ch[1]);
}

void debug(Node* &o)  
    {  
        if(o == null) return ;  
  
        printf("%d(",o->v);  
        if(o->ch[0]!=null) printf("%d,",o->ch[0]->v);  
        else printf("null,");  
        if(o->ch[1]!=null) printf("%d",o->ch[1]->v);  
        else printf("null");  
        puts(")");  
  
        if(o->ch[0]!=null) debug(o->ch[0]);  
        if(o->ch[1]!=null) debug(o->ch[1]);  
    }  

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int N, act, a, b;
	Node *left, *mid, *right, *temp;
	cin >> N >> act;
	init(N);//注意已经有虚拟节点了
	for (int i = 0; i < act; i++) {
		cin >> a >> b;
		split(root, a, left, temp);
		split(temp, b-a+1, mid, right);
		mid->flip ^= 1;
		merge(left, right);
		root = merge(left, mid);
	}
	print(root);
    return 0;
}
