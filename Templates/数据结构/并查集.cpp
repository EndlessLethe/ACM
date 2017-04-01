int p[MAX];
int findSet (int x) {
	return pa[x] != x ? pa[x] = findSet(pa[x]) : x;
}
//以上是两行并查集 


int sum[MAX];//可以同时维护很多个值，不仅仅是sum 

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {//为了方便书写，统一将y连向x
	x = find(x), y = find(y);
	if (x == y) return ;
	pa[x] += pa[y];
	pa[y] = x;
}

void init(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = -1;
//		sum[i] = 0; 
	}
}
