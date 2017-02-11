#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string.h>
using namespace::std;
int A[30+2][30+2];
int mark[30+2][30+2];
int C[8], B[8];
queue <int> q;
void bfs(void);
int k, i, j, m, n, m1, m2, minnum;

int main()
{
	#ifdef LOCAL
	freopen("input_ScuACM_2016_SCU ACM 选拔赛（一）_E_明远湖.txt","r",stdin);
	#endif
	scanf("%d", &k);
	while (k--) {
		memset(mark, 0, sizeof(mark));
		minnum = 1000;
		scanf("%d%d%d%d",&m, &n, &m1, &m2);
		B[0] = m1, B[1] = m1, B[2] = -m1, B[3] = -m1, B[4] = m2, B[5] = m2, B[6] = -m2, B[7] = -m2;
		C[0] = m2, C[1] = -m2, C[2] = m2, C[3] = -m2, C[4] = m1, C[5] = -m1, C[6] = m1, C[7] = -m1;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &A[i][j]);
				if (A[i][j] == 3) {
					q.push(i);
					q.push(j);
					q.push(0);
					mark[i][j] == 1;
				}
			}
		}
		bfs();
		if (k) printf("%d\n",minnum);
		else printf("%d",minnum);
	}
	return 0;
}

void bfs(void) {
	int sx, sy, count;
	while (!q.empty()) {
		sx = q.front();
		q.pop();
		sy = q.front();
		q.pop();
		count = q.front();
		q.pop();
		if (A[sx][sy] == 4) {
			if (minnum > count) minnum = count;
		}
		for (int i = 0; i < 8; i++) {
			if (mark[sx+B[i]][sy+C[i]] != 1 && 0<=sx+B[i] && sx+B[i]<m && 0<=sy+C[i] && sy+C[i]<n && (A[sx+B[i]][sy+C[i]] == 1 || A[sx+B[i]][sy+C[i]] == 4)) {
				q.push(sx+B[i]);
				q.push(sy+C[i]);
				q.push(count+1);
				mark[sx+B[i]][sy+C[i]] = 1;
			}
		}
	}
}
