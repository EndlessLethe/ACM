#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mp[10][10];
int row[10];
int n, k, cnt;

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", mp[i][j]);
		}
		printf("\n");
	}
}

void dfs(int c, int num) {
	if (c > n) return;
	if (num == k) {
		cnt++;
		return;
	}
	dfs(c+1, num);
	for (int i = 0; i < n; i++) {
		if (mp[c][i] == '#') {
			if (row[i] == 0) {
				row[i] = 1;
				dfs(c+1, num+1);
				row[i] = 0;
			}
		}
	}
}

int main() {
	while (scanf("%d%d", &n, &k) == 2) {
		if (n == -1 && k == -1) break;
		memset(mp, 0, sizeof(mp));
		memset(row, 0, sizeof(row));
		cnt = 0;
		getchar();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mp[i][j] = getchar();
			}
			getchar();
		}
		//Print();
		dfs(0, 0);
		printf("%d\n", cnt);
	}
	return 0;
}
