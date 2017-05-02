#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mp[15][15];
int n, cnt = 0;
int mark[15][15];
int p[15][15];


void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", mp[i][j]);
		}
		printf("\n");
	}
}

void check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mark[i][j] == 1) cnt++;
		}
	}
	printf("%d\n", cnt);
}

void unite(int i, int j, int a, int b) {
	if (a == -1 || a == n || b == -1 || a == n) {
		mark[i][j] = 1;
		//printf("%d %d\n", i, j);
	}
	pi[a][b] = i;
	pj[a][b] = j;
	
}



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", mp[i]);
	}
	Print();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			if (mp[i][j] == 'L') unite(i, j, i, j-1);
			if (mp[i][j] == 'R') unite(i, j, i, j+1);
			if (mp[i][j] == 'U') unite(i, j, i-1, j);
			if (mp[i][j] == 'D') unite(i, j, i+1, j);
		}
	}
	check();
	return 0;
}
