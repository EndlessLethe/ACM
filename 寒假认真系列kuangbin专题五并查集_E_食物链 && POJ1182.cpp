#include <stdio.h>
#include <stdlib.h>

#define MAX_N 150000+10


int N, K;
int par[MAX_N];

void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = -1;
	}
}

int find(int x) {
	if (par[x] < 0) {
		return x;
	}
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
		freopen("input_寒假认真系列kuangbin专题五并查集_E_食物链 && POJ1182.txt", "r", stdin);
	#endif
	scanf("%d%d", &N, &K);
	init(N * 3);
	int ans = 0;
	for (int i = 0; i < K; i++) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		x--, y--;
		
		if (x < 0 || N <= x || y < 0 || N <= y) {
			ans++;
			continue;
		}
		
		if (t == 1) {
			if (same(x, y + N) || same(x, y + 2*N)) {
				ans++;
			}
			else {
				unite(x, y);
				unite(x + N, y + N);
				unite(x + 2*N, y + 2*N);
			}
		}
		else {
			if (same(x, y) || same(x, y + 2*N)) {
				ans++;
			}
			else {
				unite(x, y + N);
				unite(x + N, y + 2 * N);
				unite(x + 2*N, y);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}




