#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int a[15], b[15], c[15];
int how_many[1010];
int j[15];

int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典4-2_Extraordinary Tired Students && UVa12108.txt", "r", stdin);
	#endif

	int n, i, k, flag, max, rnd = 0;
	while (scanf("%d", &n) == 1 && n) {
		rnd++;
		memset(how_many, 0, sizeof(how_many));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(j, 0, sizeof(j));
		flag = 0;
		max = 0;
		for (i = 0; i < n; i++) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
		}
		i = 0;
		while (j[0] < 1000 && j[1] < 1000 && j[2] < 1000) {
			if (j[0] <= abs(j[1]) && j[0] <= abs(j[2]) && j[0] >= 0) i = 0;
			if (j[1] <= abs(j[0]) && j[1] <= abs(j[2]) && j[1] >= 0) i = 1;
			if (j[2] <= abs(j[0]) && j[2] <= abs(j[1]) && j[2] >= 0) i = 2;
			for (k = 0; k < a[i]; k++) {
				if (j[i] == 0) {
					if (c[i] > a[i]) {
						break;
					}
					else k = c[i]-1;
				}
				how_many[(j[i]++)]++;
			}
			if (how_many[j[i]-1] * 2 > n) {
				if (max <= j[0]) max = j[0];
				if (max <= j[1]) max = j[1];
				if (max <= j[2]) max = j[2];
				flag = max;
                break;
			}
			for (k = 0; k < b[i]; k++) {
				if (j[i] == 0) {
					if (c[i] > a[i]) k = -a[i]+c[i]-1;
				}
				j[i]++;
			}
		}

		if (flag) printf("Case %d: %d\n", rnd, flag);
		else printf("Case %d: -1\n", rnd);
	}
	return 0;
}
