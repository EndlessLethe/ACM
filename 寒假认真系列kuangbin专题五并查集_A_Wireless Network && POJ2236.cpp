#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 150000+10


int N, d;
int par[MAX_N], X[MAX_N], Y[MAX_N];

int is_near(int x1, int y1, int x2, int y2) {
	return (int)sqrt((float)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) < d;
}

void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = -1;
	}
}

int find(int x) {
	if (par[x] < 0) return x;
	else {
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	
	if (par[x] > par[y]) {
		par[x] = y;
	}
	else {
		if (par[x] == par[y]) par[x]--;
		par[y] = x;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}


int main() {
	#ifdef LOCAL
		freopen("input_寒假认真系列kuangbin专题五并查集_A_Wireless Network && POJ2236.txt", "r", stdin);
	#endif
	int ch, x, y;
	scanf("%d%d", &N, &d);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &X[i], &Y[i]);
	}
	while (ch = getchar()) {
		if (ch == 'O') {
			scanf("%d", &x);
			printf("%d", x);
		}
		else if (ch == 'S') {
			scanf("%d%d", &x, &y);
			printf("%d%d", x, y);
		}
	}
	return 0;
}




