

/**
 * @Date:   18-Mar-2017
 * @Email:  zengsw_study@qq.com
 * @Filename: POJ 3253【哈夫曼树】.cpp
 * @Last modified time: 13-Aug-2018
 * @Copyright: ©2018 EndlessLethe. All rights reserved.
 */


#pragma comment(linker, "/STACK:102400000,102400000")

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long ll;

struct Node {
    ll x;
    Node* lson, * rson;
    Node(int x, Node* lson, Node* rson):x(x),lson(lson),rson(rson){;}
    Node(int x):x(x), lson(NULL), rson(NULL){;}
//    bool operator < (const Node a, const Node b) const {
//    	return a.x > b.x;
//	}
};

struct cmp {
	bool operator () (const Node* a, const Node* b) {
    	return a->x > b->x;
	}
};

priority_queue <Node*, vector<Node*>, cmp> pq;
//priority_queue <Node*> pq;

void printNode(Node* tmp) {
	cout << tmp->x << " " << tmp->lson << " " << tmp->rson << endl;
	if (tmp->lson != NULL) {
		cout << tmp->lson->x << endl;
	}
	if (tmp->rson != NULL) {
		cout << tmp->rson->x << endl;
	}
	return;
}

ll dfs(Node* root) {
	if (root == root->lson || root == root->rson) cout << "error" << endl;
	ll res = 0;
	if (root->lson != NULL) {
		res += dfs(root->lson);
	}
	if (root->rson != NULL) {
		res += dfs(root->rson);
	}
	return res + root->x;
}

int main() {
	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		freopen("test.txt","w",stdout);
	#endif
	ll N, M;
	cin >> N;
	while (N--) {
		cin >> M;
		Node *pTmp = new Node(M);
//		cout << M << " " << pTmp << endl;
		pq.push(pTmp);//pq.push((Node){M});
	}
	while (pq.size() > 1) {
		Node* pfir = pq.top(); pq.pop();
//		cout << "Lson: " << pfir << endl;
//		printNode(pfir);
		Node* psec = pq.top(); pq.pop();
//		cout << "Rson: " << psec << endl;
//		printNode(psec);
		Node* pparent = new Node(pfir->x + psec->x, pfir, psec);
//		cout << "Parent: " << pparent << endl;
//		printNode(pparent);
		pq.push(pparent);
	}
	Node* root = pq.top(); pq.pop();
//	cout << "Build Completed" << endl;
	cout << dfs(root)-root->x << endl;
	return 0;
}
