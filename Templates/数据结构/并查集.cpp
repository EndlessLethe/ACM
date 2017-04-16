int pa[MAX];
//for (int i = 0; i < N; i++) {pa[i] = i;}
int findSet (int x) {
	return pa[x] != x ? pa[x] = findSet(pa[x]) : x;
}
//if (findSet(x) != findSet(y) {pa[findSet(y)] = findSet(x);} //unite过程 
//以上是两行并查集 

int p[MAX];
int sum[MAX];//可以同时维护很多个值，不仅仅是sum 

int find(int x) {
	if (pa[x] < 0) return x;//此时根节点维护了节点数，但就失去了唯一的标志
	//还可以是p[x] == x 
	return pa[x] = find(pa[x]);
}

void unite(int x, int y) {//为了方便书写，统一将y连向x
	x = find(x), y = find(y);
	if (x == y) return ;
	pa[x] += pa[y];
	pa[y] = x;
}

void init(int n) {
	for (int i = 0; i < n; i++) {
		pa[i] = -1;
//		sum[i] = 0; 
	}
}
